/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:18:13 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/06 17:13:35 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void    msg_error(int num)
{
    if (num == 0)
        perror("Error opening infile ¯\\_(ツ)_/¯\n");
    else if (num == 1)
        perror("Error opening outfile ¯\\_(ツ)_/¯\n");
    else if (num == 2)
        perror("Too few arguments ¯\\_(ツ)_/¯\n");
    else if (num == 3)
        perror("Command not found¯\\_(ツ)_/¯\n");
    else if (num == 4)
        perror("Error in creating the pipe ¯\\_(ツ)_/¯\n");
    else if (num == 5)
        perror("Error creating the child ¯\\_(ツ)_/¯\n");
    else if (num == 6)
        perror("Error opening outfilefile ¯\\_(ツ)_/¯\n");
    exit(EXIT_FAILURE);
}