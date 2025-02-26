/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:21:24 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/26 15:07:12 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	is_sorted(t_list **list)
{
	t_list *i;
    t_list *j;

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