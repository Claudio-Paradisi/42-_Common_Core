/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:58:09 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/01 16:52:46 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_list(t_list **list)
{
	t_list	*temp;
	t_list	*current;

	if (!list || !*list)
		return ;
	current = *list;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*list = NULL;
}
