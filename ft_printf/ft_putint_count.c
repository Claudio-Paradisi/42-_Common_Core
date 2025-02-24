/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:40:36 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/24 18:05:25 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
/ this function prints a decimal number
*/
void	ft_putint_count(int n, int *count)
{
	long long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar_count('-', count);
	}
	ft_putnbr_base_count((unsigned long long)nbr, DECIMAL_BASE, count);
}
