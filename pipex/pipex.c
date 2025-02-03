/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:31:58 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/03 14:24:30 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/pipex.h"

static char 	*find_path(char **envp)
{
	while (envp)
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

	if (ac == 5)
	{
		pipex.infile = open(av[1], O_RDONLY);
		if (pipex.infile < 0)
			return (1);
		pipex.outfile = open(av[ac-1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
		if (pipex.outfile < 0)
			return (1);
		if (pipe(pipex.pipe_fd < 0))
			return (2);
		pipex.path = find_path(envp);
		printf("%s \n", pipex.path);
		pipex.cmd_paths = ft_split(pipex.path, ':');
		pipex.pid1 = fork();
		if (pipex.pid1 == 0)
		{
			dup2(pipe_fd[1]);
			close(pipe_fd[0]);
			
				
		}
		close(pipex.infile);
		close(pipex.outfile);
	}
	
	return (0);
}