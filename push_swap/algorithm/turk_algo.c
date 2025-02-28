/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:08:56 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/28 14:37:19 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	rotate_both(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node->target_node
			&& *a != cheapest_node)
			rr(a, b);
	set_current_index(*a);
	set_current_index(*b);		
}

static void	move_a_to_b(t_list **a, t_list **b)
{
	t_list *cheapest_node;

	cheapest_node = get_cheapest_node(*a);
	if (cheapest_node->above_median 
			&& cheapest_node->target_node->above_median)
			rotate_both(a, b, cheapest_node);
		else if (!(cheapest_node->above_median) 
			&& !(cheapest_node->target_node->above_median))
}

void	turk_algo(t_list **a, t_list **b)
{
	int	len_a;

	len_a = ft_lstsize(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(a,b);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(a,b);
	while (len_a-- > 3 )
	{
		init_list_a(*a, *b);
		move_a_to_b(a, b);
	}
}