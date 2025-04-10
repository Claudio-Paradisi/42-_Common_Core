/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:44:49 by cparadis          #+#    #+#             */
/*   Updated: 2025/04/09 12:43:58 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minishell.h"

int main(int ac, char **av, char **envp)
{
    if (ac == 1 || (ac == 2 && !av[1]))
    {
        t_cmd *cmd_list = mock_cmds();
        execute_pipeline(cmd_list, envp);
        free_cmd_list(cmd_list);
    }
    return (0);
}