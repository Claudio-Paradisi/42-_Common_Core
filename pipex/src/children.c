/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:31:49 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/13 18:23:08 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

static char		*join_cmd_path(char **cmd_paths, char *cmd)
{
	char	*temp;
	char	*full_cmd;

	if (!cmd || !cmd_paths)
		return (NULL);
	while (*cmd_paths)
	{
		temp = ft_strjoin(*cmd_paths, "/");
		full_cmd = ft_strjoin(temp, cmd);
		free(temp);
		printf("Executing command: %s\n", *cmd_paths);
		if (!full_cmd)
			return (NULL);
		if (access(full_cmd, 0) == 0)
			return (full_cmd);
		free(full_cmd);
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
	pipex->cmd = join_cmd_path(pipex->cmd_paths, pipex->cmd_args[i][0]);
	if (!pipex->cmd)
		cleanup_pipex(pipex, 3);
	execve(pipex->cmd, pipex->cmd_args[i], envp);
	cleanup_pipex(pipex, 6);
}
