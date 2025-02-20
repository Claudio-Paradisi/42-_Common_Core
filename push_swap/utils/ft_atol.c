/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:25:36 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/20 15:42:38 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

long	ft_atol(char *str)
{
	long 	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while(ft_isspace(*str))
		str++;
	if (ft_issign(*str))
	{
		if(*str == '-')
			sign = -1;
		str++;
	}
	while(ft_isdigit(*str))
	{
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	return (nbr * sign);
}