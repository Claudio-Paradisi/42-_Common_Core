/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:30:48 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/26 15:08:37 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	rev_rotate(t_list **list)
{
	t_list	*last_node;

	if (!*list || !(*list)->next)
		return ;
	last_node = ft_lstlast(*list);
	last_node->prev->next = NULL;
	last_node->next = *list;
	last_node->prev = NULL;
	(*list)->prev = last_node;
	*list = last_node;
}

void	rra(t_list **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_list **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}