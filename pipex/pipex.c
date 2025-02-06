/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:31:58 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/06 16:01:01 by cparadis         ###   ########.fr       */
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
static void open_files(t_pipex *pipex, char **av)
{
    pipex->infile = open(av[1], O_RDONLY);
    if (pipex->infile < 0)
		msg_error(0);
	pipex->outfile = open(av[pipex->cmd_count + 2], O_TRUNC | O_CREAT | O_RDWR, 0644);
    if (pipex->outfile < 0)
		msg_error(1);
}

static void	processing(t_pipex *pipex, char **envp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	init_pipes(pipex);
	while (i < pipex->cmd_count)
	{
		pipex->pid = fork();
		if (pipex->pid == 0)
			execute_child(pipex, envp, i++);
	}
	free_pipes(&pipex);
	while (j < pipex->cmd_count)
	{
		wait(NULL);
		j++;
	}
}

int		main(int ac, char **av, char **envp)
{
	t_pipex pipex;
	int		i;

	i = -1;
	if (ac < 5)
		msg_error(2);
	pipex.cmd_count = ac - 3;
	open_files(&pipex, av);
	pipex.path = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.path, ':');
	pipex.cmd_args = malloc(sizeof(char **) * (pipex.cmd_count));
	while (++i < pipex.cmd_count)
		pipex.cmd_args[i] = ft_split(av[i + 2], ' ');
	processing(&pipex, envp);
	free_matrix(pipex.cmd_paths);
	free_matrix(*pipex.cmd_args);
	free(pipex.cmd_args);
	/*i = 0;
	init_pipes(&pipex);
	while (i < pipex.cmd_count)
	{
		pipex.pid = fork();
		if (pipex.pid == 0)
			execute_child(&pipex, envp, i++);
	}
	free_pipes(&pipex);
	i = 0;
	while (i++ < pipex.cmd_count)
		wait(NULL);*/
	return (0);
}