/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:41:33 by cparadis          #+#    #+#             */
/*   Updated: 2025/04/09 12:42:22 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
#define EXECUTE_H

#include "../../includes/libft/libft.h"
#include <fcntl.h>
#include <sys/wait.h>

#define TRUE 1
#define FALSE 0


typedef struct s_cmd
{
    char    **args;        // {"ls", "-la", NULL}
    char    *infile;       // if there is '<'
    char    *outfile;      // if there is '>' o '>>'
    //char    *path;
    //char    **cmd_path;
    int     append;        // TRUE if '>>', 0 if '>'
    int     heredoc;       // TRUE if '<<'
    char    *delimiter;    // TRUE if heredoc
    struct s_cmd *next;    // to pass to the next pipe
}   t_cmd;

typedef struct s_pipe
{
    int prev_pipe[2];       //pipe array dealed
    int next_pipe[2];       //pipe array to deal
    int pid;                //process id
    int status;             //for wait function
    int has_prev;           //bool to change dealed pipes
    char **paths;           //path for commands
}   t_pipe;


//custom function
t_cmd       *mock_cmds(void); //has to be deleted
int         my_fork();
int         infile_open(t_cmd *cmd);
int         outfile_open(t_cmd *cmd);

// path finding
char	**get_paths_fromm_envp(char **envp);
char	*join_path(char *path, char *cmd);
char *get_cmd_path(char *cmd, char **paths);

//execution
void    execute_pipeline(t_cmd *cmd_list, char **envp);

//free
void    free_pipex(t_pipe *pipex);
void    free_cmd_list(t_cmd *cmd_list);

#endif