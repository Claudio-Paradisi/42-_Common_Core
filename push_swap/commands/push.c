/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:11:04 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/26 14:56:08 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	push(t_list **dest, t_list **src)
{
	t_list	*node_to_push;

	if (!*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*dest)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_list **b, t_list **a)
{
	push(b, a);
	ft_printf("pb\n");
}