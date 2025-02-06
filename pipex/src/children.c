/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:31:49 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/06 15:52:52 by cparadis         ###   ########.fr       */
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
		if (access(buffer, 0) == 0)
			return (buffer);
		free(buffer);
		cmd_paths++;
	}
	return (NULL);
}

void	execute_child(t_pipex *pipex, int i, char **envp)
{
	if (i == 0)
		dup2(pipex->infile, STDIN_FILENO);
	else
		dup2(pipex->pipes[i - 1][0], STDIN_FILENO);
	if (i == pipex->cmd_count - 1)
		dup2(pipex->outfile, STDOUT_FILENO);
	else
		dup2(pipex->pipes[i][1], STDOUT_FILENO);
	free_pipes(pipex);
	pipex->cmd = join_cmd_path(pipex->cmd_paths, pipex->cmd_args[0]);
	if (!pipex->cmd)
		msg_error(3);
	execve(pipex->cmd, pipex->cmd_args, envp);
	msg_error(4);
}
