/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:31:49 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/03 11:51:31 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

/*
/ this functions returns a string ready to be put inside the
/ execve function
*/
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
		if (!full_cmd)
			return (NULL);
		if (access(full_cmd, 0) == 0)
			return (full_cmd);
		free(full_cmd);
		cmd_paths++;
	}
	return (NULL);
}
/*
/ this is probably the most important function
/ it executes the shell command 
*/
void	execute_child(t_pipex *pipex, int i, char **envp)
{
	/*
	/ if i is 0 it means we are working with the infile
	/ if i is cmd_count -1 it means we are working with the outfile
	/ else we are working with the pipes
	/ dup2 takes the fd and it changes it with a new one 
	*/
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
	/*
	/ with execve we execute the command
	/ if it works the process will end at this line
	/ otherwise (it returns -1) we have to free our struct
	*/
	execve(pipex->cmd, pipex->cmd_args[i], envp);
	cleanup_pipex(pipex, 6);
}
