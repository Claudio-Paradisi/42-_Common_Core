/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:21:24 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/01 16:46:02 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	is_sorted(t_list **list)
{
	t_list	*i;
	t_list	*j;

	i = *list;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->nbr > j->nbr)
				return (FALSE);
			j = j->next;
		}
		i = i->next;
	}
	return (TRUE);
}

void	ready_for_push(t_list **list, t_list *top_node, int check)
{
	while (*list != top_node)
	{
		if (check)
		{
			if (top_node->above_median)
				ra(list);
			else
				rra(list);
		}
		else
		{
			if (top_node->above_median)
				rb(list);
			else
				rrb(list);
		}
	}
}

void	set_min_on_top(t_list **a)
{
	t_list	*min;

	min = get_min_node(a);
	while ((*a)->nbr != min->nbr)
	{
		if (min->above_median)
			ra(a);
		else
			rra(a);
	}
}
