/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:15:19 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/26 12:46:42 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	rotate(t_list **list)
{
	t_list	*last_node;
	t_list	*first_node;

	if (!*list || !(*list)->next)
		return ;
	first_node = *list;
	last_node = ft_lstlast(*list);
	*list = first_node->next;
	(*list)->prev = NULL;
	last_node->next = first_node;
	first_node->next = NULL;
	first_node->prev = last_node;
}

void	ra(t_list **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_list **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}