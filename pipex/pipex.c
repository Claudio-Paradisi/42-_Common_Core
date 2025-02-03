/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:31:58 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/03 18:56:00 by cparadis         ###   ########.fr       */
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

int		main(int ac, char **av, char **envp)
{
	t_pipex pipex;
	int		i;

	i = 0;
	if (ac != 5)
	{
		perror("too many or too few arguments ¯\\_(ツ)_/¯\n");
		return(1);
	}
	else
	{
		pipex.infile = open(av[1], O_RDONLY);
		if (pipex.infile < 0)
		{
			perror("Error in opening the input file ¯\\_(ツ)_/¯\n");
			return (1);
		}
		//pipex.outfile = open(av[ac-1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
		pipex.outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (pipex.outfile < 0)
		{
			perror("Error in opening the output file ¯\\_(ツ)_/¯\n");
			return (1);
		}
		if (pipe(pipex.pipe_fd) < 0)
		{
			perror("Error opening pipe");
			return (2);
		}
		pipex.path = find_path(envp);
		pipex.cmd_paths = ft_split(pipex.path, ':');
		pipex.pid1 = fork();
		if (pipex.pid1 == 0)
			first_child(pipex, av, envp);
		pipex.pid2 = fork();
		if (pipex.pid2 == 0)
		{
			printf("sono entrato nel secondo figlio");
			second_child(pipex, av, envp);
		}
		close(pipex.pipe_fd[0]);
		close(pipex.pipe_fd[1]);
		waitpid(pipex.pid1, NULL, 0);
		waitpid(pipex.pid2, NULL, 0);
		close(pipex.infile);
		close(pipex.outfile);
		while (pipex.cmd_paths[i])
		{
			free(pipex.cmd_paths[i]);
			i++;
		}
		free(pipex.cmd_paths);
	}
	return (0);
}