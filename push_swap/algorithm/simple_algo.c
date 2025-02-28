/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:49:55 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/28 14:03:11 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sort_two(t_list **a)
{
	sa(a);
}

void    sort_three(t_list **a)
{
    t_list *biggest_node;

    biggest_node = get_max_node(a);
    if (biggest_node->nbr == (*a)->nbr)
        ra(a);
    else if (biggest_node->nbr == (*a)->next->nbr)
        rra(a);
    if ((*a)->nbr > (*a)->next->nbr)
        sa(a);    
}