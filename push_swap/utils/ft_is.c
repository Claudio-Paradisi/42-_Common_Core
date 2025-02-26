/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:12:24 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/26 12:03:17 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_issign(int c)
{
	if (c == '+' || c == '-')
		return (TRUE);
	return (FALSE);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 7 && c <= 13))
		return (TRUE);
	return (FALSE);
}
