/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:31:49 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/03 19:00:36 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

static char		*join_cmd_path(char **cmd_paths, char *cmd)
{
	char	*temp;
	char	*buffer;

	while (*cmd_paths)
	{
		temp = ft_strjoin(*cmd_paths, "/");
		buffer = ft_strjoin(temp, cmd);
		free(temp);
		//printf("check command: %s\n", buffer);
		if (access(buffer, 0) == 0)
			return (buffer);
		free(buffer);
		cmd_paths++;
	}
	return (NULL);
}

void	first_child(t_pipex pipex, char **av, char **envp)
{
	/*int		i;

	i = 0;*/
	dup2(pipex.pipe_fd[1], STDOUT_FILENO);
	close(pipex.pipe_fd[0]);
	dup2(pipex.infile, STDIN_FILENO);
	close(pipex.pipe_fd[1]);
	pipex.cmd_args = ft_split(av[2], ' ');
	pipex.cmd = join_cmd_path(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		/*while(pipex.cmd_args[i])
		{
			free(pipex.cmd_args[i]);
			i++;
		}
		free(pipex.cmd_args);
		free(pipex.cmd);*/
		perror("Error in finding the command");
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
	perror("error in executing the command");
	exit(1);
}

void	second_child(t_pipex pipex, char **av, char **envp)
{
	/*int		i;

	i = 0;*/
	dup2(pipex.pipe_fd[0], STDIN_FILENO);
	close(pipex.pipe_fd[1]);
	dup2(pipex.outfile, STDOUT_FILENO);
	close(pipex.pipe_fd[0]);
	pipex.cmd_args = ft_split(av[3], ' ');
	pipex.cmd = join_cmd_path(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		/*while (pipex.cmd_args[i])
		{
			free(pipex.cmd_args[i]);
			i++;
		}
		free(pipex.cmd_args);
		free(pipex.cmd);*/
		perror("Error in finding the command in second child");
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
	perror("Error in executing the command in second child");
	exit(1);
}