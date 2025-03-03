/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:31:58 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/03 12:01:06 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

/*
/ here_doc emulate this command line: << LIMITER cmd | cmd >> outfile
/ we have to take the input from the STDIN so long we don't find 
/ a line with the LIMITER (the limiter rapresents the EOF) 
*/

static char 	*find_hd_path(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp("PATH=", *envp, 5) == 0)
			return(*envp + 5);
		envp++;
	}
	return (NULL);
}

/*
/ this time if the infile retruns -1 we have to exit the program
*/
static void		open_hd_files(t_pipex *pipex, char **av, int ac)
{
	/*
	/ the infile is a temporary file we have to create
	*/
    pipex->infile = create_hd_infile(av[2]);
    if (pipex->infile < 0)
		msg_error(0);
	pipex->outfile = open(av[ac - 1], O_APPEND | O_CREAT | O_RDWR, 0644);
    if (pipex->outfile < 0)
		msg_error(1);
}

static void		hd_processing(t_pipex *pipex, char **envp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	init_pipes(pipex);
	while (i < pipex->cmd_count)
	{
		pipex->pid = fork();
		if (pipex->pid < 0)
			msg_error(5);
		if (pipex->pid == 0)
			execute_child(pipex, i, envp);
		i++;
	}
	free_pipes(pipex);
	while (j < pipex->cmd_count)
	{
		wait(NULL);
		j++;
	}
}

static t_pipex		init_hd_pipex(int ac, char **av, char **envp, int i)
{
	t_pipex pipex;
	
	pipex.cmd_count = ac - 4;
	pipex.here_doc = 1;
	open_hd_files(&pipex, av, ac);
	pipex.path = find_hd_path(envp);
	if (pipex.path)
    	pipex.cmd_paths = ft_split(pipex.path, ':');
	else
    	pipex.cmd_paths = NULL;
	pipex.cmd_args = ft_calloc(pipex.cmd_count + 1, sizeof(char **));
	if (!pipex.cmd_paths || !pipex.cmd_args)
        cleanup_pipex(&pipex, 6);
	/*
	/ this is the only difference between the normal init_pipex
	/ we got 1 more argument to avoid in the cmd_args so we split i + 3
	*/
	while (++i < pipex.cmd_count)
        	pipex.cmd_args[i] = ft_split(av[i + 3], ' ');
	return (pipex);
}

void		here_doc(t_pipex *pipex, int ac, char **av, char **envp)
{
	int		i;

	i = -1;
	*pipex = init_hd_pipex(ac, av, envp, i);
	hd_processing(pipex, envp);
	if (pipex->infile > 0)
    	close(pipex->infile);
	if (pipex->outfile > 0)
    	close(pipex->outfile);
	free_matrix(pipex->cmd_paths);
	free_array_of_matrix(pipex->cmd_args);
	/*
	/ when we use here_doc we create temporary infile that we have to 
	/ delete once the program ends
	*/
	unlink("here_doc_temp");
}