/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:11:57 by cparadis          #+#    #+#             */
/*   Updated: 2025/04/09 16:01:56 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

/*
/ function to emulate the parsing which will send a list of commands
*/

t_cmd *mock_cmds(void)
{
    t_cmd *cmd1 = ft_calloc(1, sizeof(t_cmd));
    t_cmd *cmd2 = ft_calloc(1, sizeof(t_cmd));

    cmd1->args = ft_split("/usr/bin/ls -la", ' ');
    cmd1->infile = NULL;
    cmd1->outfile = NULL;
    cmd1->append = 0;
    cmd1->heredoc = 0;
    cmd1->delimiter = NULL;
    cmd1->next = cmd2;//cmd2;

    cmd2->args = ft_split("grep txt", ' ');
    cmd2->infile = NULL;
    cmd2->outfile = "out.txt";
    cmd2->append = 1;
    cmd2->heredoc = 0;
    cmd2->delimiter = NULL;
    cmd2->next = NULL;

    return cmd1;
}

/*
/ if there are infile or outfile we open them amd we redirect their fds
*/
void    open_and_redirect(t_cmd *cmd_list)
{
    int fd;
    
    if (cmd_list->infile)
    {
        fd = infile_open(cmd_list);
        dup2(fd, STDIN_FILENO);
        close(fd);
    }
    if (cmd_list->outfile)
    {
        fd = outfile_open(cmd_list);
        dup2(fd, STDOUT_FILENO);
        close(fd);
    }
}

/*
/ execution of the command inside the child process so that when the excution
/ ends it doesnt kill the whole program
*/
void    child_process(t_cmd *cmd_list, t_pipe *pipex, char **envp)
{
    char    *cmd_path;

    pipex->paths = get_paths_fromm_envp(envp);
    if (pipex->has_prev /*&& pipex->prev_pipe*/)
    {
        dup2(pipex->prev_pipe[0], STDIN_FILENO);
        close(pipex->prev_pipe[0]);
        close(pipex->prev_pipe[1]);
    }
    if (cmd_list->next /*&& pipex->next_pipe*/)
    {
        close(pipex->next_pipe[0]);
        dup2(pipex->next_pipe[1], STDOUT_FILENO);
        close(pipex->next_pipe[1]);
    }
    open_and_redirect(cmd_list);
    cmd_path = get_cmd_path(cmd_list->args[0], pipex->paths);
   
    execve(cmd_path, cmd_list->args, envp);
    free(cmd_path);
    free_pipex(pipex); //may need here as well
    free_cmd_list(cmd_list);
    perror("excve");
    exit(EXIT_FAILURE);
}

/*
/ main function for execution,  missing the check if the command is our build in
/ which doesn't need fork()
*/

void    execute_pipeline(t_cmd *cmd_list, char **envp)
{
    t_pipe *pipex;

    pipex = ft_calloc(1, sizeof(t_pipe));
    pipex->has_prev = 0;
    while (cmd_list)
    {
        if (cmd_list->next)
        {
            if (pipe(pipex->next_pipe) < 0)
            {
                //error function
                ft_printf("pipe\n");
                exit(1);
            }
        }
        pipex->pid = my_fork();
        if (pipex->pid == 0)  //child process
            child_process(cmd_list, pipex, envp);
        else                  //parent process
        {
            if (pipex->has_prev)
            {
                close(pipex->prev_pipe[0]);
                close(pipex->prev_pipe[1]);
            }
            if (cmd_list->next)
            {
                pipex->prev_pipe[0] = pipex->next_pipe[0];
                pipex->prev_pipe[1] = pipex->next_pipe[1];
                pipex->has_prev = 1;
            }
        }
        cmd_list = cmd_list->next;
    }
    while(wait(&pipex->status) > 0);
    free_pipex(pipex);
}