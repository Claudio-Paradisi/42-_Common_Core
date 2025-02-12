/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:54:59 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/09 16:39:58 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void    free_matrix(char **matrix)
{
    int     i;

    if (!matrix)
        return ;
    i = 0;
    while (matrix[i])
    {
        free(matrix[i]);
        i++;
    }
    free(matrix);
}

void    free_array_of_matrix(char ***a_matrix)
{
    int     i;

    if (!a_matrix)
        return ;
    i = 0;
    while (a_matrix[i])
    {
        if (a_matrix[i])
            free_matrix(a_matrix[i]);
        i++;
    }
    free(a_matrix);
}