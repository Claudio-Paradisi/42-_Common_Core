/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:47:47 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/27 16:42:54 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_list *max_node(t_list **list)
{
    t_list *max;
    t_list *temp;

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

void    set_current_index(t_list *list)
{
    int i;
    int half;

    if (!list)
        return ;
    i = 0;
    half = ft_lstsize(a) / 2;
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