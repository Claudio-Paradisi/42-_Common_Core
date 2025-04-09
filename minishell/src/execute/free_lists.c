/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:29:34 by cparadis          #+#    #+#             */
/*   Updated: 2025/04/09 15:17:57 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void    free_pipex(t_pipe *pipex)
{
    ft_freematrix(pipex->paths);
    free(pipex);
}

void    free_cmd_list(t_cmd *cmd_list)
{
    t_cmd   *temp;

    while (cmd_list)
    {
        temp = cmd_list->next;
        ft_freematrix(cmd_list->args);
        free(cmd_list);
        cmd_list = temp;
    }
    temp = NULL;
}