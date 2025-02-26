/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:31:09 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/26 12:45:03 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	swap(t_list **ex_first_node)
{
	t_list	*new_first_node;

	if (!*ex_first_node || !(*ex_first_node)->next)
		return ;
	new_first_node = (*ex_first_node)->next;
	(*ex_first_node)->next = new_first_node->next;
	if (new_first_node->next)
		new_first_node->next->prev = *ex_first_node;
	new_first_node->prev = NULL;
	new_first_node->next = *ex_first_node;
	(*ex_first_node)->prev = new_first_node;
	*ex_first_node = new_first_node;
}

void	sa(t_list **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_list **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
