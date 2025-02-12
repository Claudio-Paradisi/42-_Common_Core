/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:31:58 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/10 18:01:49 by cparadis         ###   ########.fr       */
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
	open_files(&pipex, av, ac);
	pipex.path = find_path(envp);
	if (pipex.path)
    	pipex.cmd_paths = ft_split(pipex.path, ':');
	else
    	pipex.cmd_paths = NULL;
		//pipex.cmd_args = (char ***)malloc((pipex.cmd_count + 1) * sizeof(char **));
	pipex.cmd_args = ft_calloc(pipex.cmd_count + 1, sizeof(char **));
	if (!pipex.cmd_paths || !pipex.cmd_args)
        cleanup_pipex(&pipex, 1);
	while (++i < pipex.cmd_count)
	{
    	/*if (!av[i + 2] || !av[i + 2][0])  // Controlla se la stringa è vuota
    	{
        	pipex.cmd_args[i] = ft_calloc(1, sizeof(char *));
        	if (!pipex.cmd_args[i])
            	cleanup_pipex(&pipex, 1);
        	pipex.cmd_args[i][0] = NULL;
    	}
    	else*/
        	pipex.cmd_args[i] = ft_split(av[i + 2], ' ');
	}
	return (pipex);
}

int		main(int ac, char **av, char **envp)
{
	t_pipex pipex;
	int		i;
	
	i = -1;
	if (ac < 5)
		msg_error(2);
	/*while(++i < ac - 2)
		if(ft_strncmp("", av[i], 1) == 0 || ft_strncmp(" ", av[i], 2) == 0)
			msg_error(6);
	i = -1;
	pipex.cmd_count = ac - 3;
	open_files(&pipex, av, ac);
	pipex.path = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.path, ':');
	pipex.cmd_args = ft_calloc(pipex.cmd_count + 1, sizeof(char **));
	while (++i < pipex.cmd_count)
		pipex.cmd_args[i] = ft_split(av[i + 2], ' ');*/
	pipex = init_t_pipex(ac, av, envp, i);
	processing(&pipex, envp);
	if (pipex.infile > 0)
        close(pipex.infile);
    if (pipex.outfile > 0)
        close(pipex.outfile);
        
    // Libera la memoria ma non i pipes che sono già stati liberati
    free_matrix(pipex.cmd_paths);
    free_array_of_matrix(pipex.cmd_args);
	return (0);
}