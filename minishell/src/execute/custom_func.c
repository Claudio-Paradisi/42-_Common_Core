/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:48:33 by cparadis          #+#    #+#             */
/*   Updated: 2025/04/08 16:48:09 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int my_fork()
{
    int pid;

    pid = fork();
    if (pid < 0)
    {
        //error_function
        ft_printf("error fork\n");
        exit(1);
    }
    return (pid);
}

int infile_open( t_cmd *cmd)
{
    int fd;
    char **default_args;

    default_args = ft_calloc(3, sizeof(char *));
    default_args[0] = "echo";
    default_args[1] = "-n";
    default_args[2] = NULL;
    fd = open(cmd->infile, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("error not valid infile \n");
        cmd->args = ft_matrixdup(default_args);
    }
    free(default_args);
    return (fd);
}

int outfile_open(t_cmd *cmd)
{
    int fd;

    if (cmd->append)
        fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
    else
        fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        //error function
        ft_printf("error outfile\n");
        exit(1);
    }
    return (fd);
}