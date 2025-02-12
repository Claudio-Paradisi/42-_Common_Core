/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:31:58 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/13 18:22:14 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/pipex.h"

static char 	*find_path(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp("PATH=", *envp, 5) == 0)
			return(*envp + 5);
		envp++;
	}
	return (NULL);
}
static void		open_files(t_pipex *pipex, char **av, int ac)
{
    pipex->infile = open(av[1], O_RDONLY);
    if (pipex->infile < 0)
		msg_error(0);
	pipex->outfile = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
    if (pipex->outfile < 0)
		msg_error(1);
}

static void		processing(t_pipex *pipex, char **envp)
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

static t_pipex		init_t_pipex(int ac, char **av, char **envp, int i)
{
	t_pipex pipex;
	
	pipex.cmd_count = ac - 3;
	pipex.here_doc = 0;
	open_files(&pipex, av, ac);
	pipex.path = find_path(envp);
	if (pipex.path)
    	pipex.cmd_paths = ft_split(pipex.path, ':');
	else
    	pipex.cmd_paths = NULL;
	pipex.cmd_args = ft_calloc(pipex.cmd_count + 1, sizeof(char **));
	if (!pipex.cmd_paths || !pipex.cmd_args)
        cleanup_pipex(&pipex, 3);
	while (++i < pipex.cmd_count)
        	pipex.cmd_args[i] = ft_split(av[i + 2], ' ');
	return (pipex);
}

int		main(int ac, char **av, char **envp)
{
	t_pipex pipex;
	int		i;
	
	i = -1;
	if (ac < 5)
		msg_error(2);
	if (ft_strncmp("here_doc", av[1], ft_strlen(av[1])) != 0)
	{
		pipex = init_t_pipex(ac, av, envp, i);
		processing(&pipex, envp);
		if (pipex.infile > 0)
        	close(pipex.infile);
    	if (pipex.outfile > 0)
        	close(pipex.outfile);
    	free_matrix(pipex.cmd_paths);
    	free_array_of_matrix(pipex.cmd_args);
	}
	else
		here_doc(&pipex, ac, av, envp);
	return (0);
}