/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:47:47 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/01 13:50:11 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_list	*get_max_node(t_list **list)
{
	t_list	*max;
	t_list	*temp;

	temp = *list;
	max = ft_lstlast(temp);
	while (temp)
	{
		if (max->nbr < temp->nbr)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

t_list *get_min_node(t_list **list)
{
	t_list *min;
	t_list *temp;

	temp = *list;
	min = ft_lstlast(temp);
	while (temp)
	{
		if (min->nbr > temp->nbr)
			min = temp;
		temp = temp->next;
	}
	return (min);
}
void	set_current_index(t_list *list)
{
	int	i;
	int	half;

	if (!list)
		return ;
	i = 0;
	half = ft_lstsize(list) / 2;
	while (list)
	{
		list->index = i;
		if (list->index <= half)
			list->above_median = TRUE;
		else
			list->above_median = FALSE;
		list = list->next;
		i++;
	}
}

void	set_cheapest(t_list *list)
{
	long cheapest_nbr;
	t_list *cheapest_node;

	if (!list)
		return ;
	cheapest_nbr = LONG_MAX;
	while (list)
	{
		if (list->push_cost < cheapest_nbr)
		{
			cheapest_nbr = list->push_cost;
			cheapest_node = list;
		}
		list = list->next;
	}
	cheapest_node->cheapest = TRUE;
}

t_list *get_cheapest_node(t_list *list)
{
	t_list *cheapest_node;

	cheapest_node = NULL;
	while (list)
	{
		if (list->cheapest)
		{
			cheapest_node = list;
			return (cheapest_node);
		}
		list = list->next;
	}
	return (cheapest_node);
}