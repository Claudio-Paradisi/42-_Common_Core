/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:08:56 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/27 17:05:32 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
	}
}