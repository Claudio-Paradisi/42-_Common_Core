/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:08:56 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/01 16:50:03 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	rotate_both(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	set_current_index(*a);
	set_current_index(*b);
}

static void	rev_rotate_both(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	set_current_index(*a);
	set_current_index(*b);
}

static void	move_a_to_b(t_list **a, t_list **b)
{
	t_list	*cheapest_node;

	cheapest_node = get_cheapest_node(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	ready_for_push(a, cheapest_node, TRUE);
	ready_for_push(b, cheapest_node->target_node, FALSE);
	pb(b, a);
}

static void	move_b_to_a(t_list **a, t_list **b)
{
	ready_for_push(a, (*b)->target_node, TRUE);
	pa(a, b);
}

void	turk_algo(t_list **a, t_list **b)
{
	int	len_a;

	len_a = ft_lstsize(*a);
	if (len_a-- > 3 && !is_sorted(a))
		pb(b, a);
	if (len_a-- > 3 && !is_sorted(a))
		pb(b, a);
	while (len_a-- > 3)
	{
		init_list_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_list_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_current_index(*a);
	set_min_on_top(a);
}
