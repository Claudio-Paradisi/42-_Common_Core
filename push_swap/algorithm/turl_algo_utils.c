/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turl_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:04:05 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/27 19:16:03 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void set_target(t_list *a, t_list *b)
{
	t_list *current_b;
	t_list *target;
	long 	closer_small_nbr;

	while (a)
	{
		closer_small_nbr = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > closer_small_nbr)
			{
				target = current_b;
				closer_small_nbr = current_b->nbr;
			}
			current_b = current_b->next;
		}
		if (closer_small_nbr == LONG_MIN)
			a->target_node = max_node(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

static void set_push_cost(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstlast(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);	
		a = a->next;	
	}
}

void	init_list_a(t_list *a, t_list *b)
{
	set_current_index(a);
	set_current_index(b);
	set_target(a, b);
}