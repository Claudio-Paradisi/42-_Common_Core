/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:29:35 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/10 11:45:41 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void    init_pipes(t_pipex *pipex)
{
    int     i;

    if (pipex->cmd_count < 2)
        return ;
    i = 0;
    pipex->pipes = malloc(sizeof(int *) * (pipex->cmd_count - 1));
    if (!pipex->pipes)
        msg_error(4);
    while (i < pipex->cmd_count - 1)
    {
        pipex->pipes[i] = malloc(sizeof(int) * 2);
        if (!pipex->pipes[i])
            msg_error(4);
        if (pipe(pipex->pipes[i]) == -1)
            msg_error(4);
        i++;
    }
}

void    free_pipes(t_pipex *pipex)
{
    int i;

    if (!pipex->pipes)
        return;
    i = 0;
    while (i < pipex->cmd_count - 1)
    {
        if (pipex->pipes[i])  // controlla se il puntatore è valido
        {
            close(pipex->pipes[i][0]);
            close(pipex->pipes[i][1]);
            free(pipex->pipes[i]);
            pipex->pipes[i] = NULL;  // imposta a NULL dopo aver liberato
        }
        i++;
    }
    free(pipex->pipes);
    pipex->pipes = NULL;  // imposta a NULL dopo aver liberato
}
