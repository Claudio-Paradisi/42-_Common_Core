/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:28:43 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/01 16:44:38 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*current;

	if (!lst)
		return (0);
	count = 0;
	current = lst;
	while (current)
	{
		current = current->next;
		count++;
	}
	return (count);
}
