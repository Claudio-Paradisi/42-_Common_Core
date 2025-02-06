/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:29:35 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/06 15:52:52 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void    init_pipes(t_pipex *pipex)
{
    int     i;

    i = 0;
    pipex->pipes = malloc(sizeof(int *) * (pipex->cmd_count - 1));
    while (i < pipex->cmd_count - 1)
    {
        pipex->pipes[i] = malloc(sizeof(int) * 2);
        if (pipe(pipex->pipes[i]) == -1)
            msg_error(4);
        i++;
    }
}

void    free_pipes(t_pipex *pipex)
{
    int     i;

    i = 0;
    while (i < pipex->cmd_count - 1)
    {
        close(pipex->pipes[i][0]);
        close(pipex->pipes[i][1]);
        free(pipex->pipes[i]);
        i++;
    }
    free(pipex->pipes);
}