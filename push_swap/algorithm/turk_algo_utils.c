/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:04:05 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/01 15:54:57 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	set_target_a(t_list *a, t_list *b)
{
	t_list	*current_b;
	t_list	*target;
	long	closer_small_nbr;

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
			a->target_node = get_max_node(&b);
		else
			a->target_node = target;
		a = a->next;
	}
}

static void set_target_b(t_list *a, t_list *b)
{
	t_list *current_a;
	t_list *target;
	long	closer_big_nbr;

	while (b)
	{
		closer_big_nbr = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < closer_big_nbr)
			{
				closer_big_nbr = current_a->nbr;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (closer_big_nbr == LONG_MAX)
			b->target_node = get_min_node(&a);
		else
			b->target_node = target;
		b = b->next;
	}
}

static void	set_push_cost(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
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
	set_target_a(a, b);
	set_push_cost(a, b);
	set_cheapest(a);
}

void	init_list_b(t_list *a, t_list *b)
{
	set_current_index(a);
	set_current_index(b);
	set_target_b(a, b);
}