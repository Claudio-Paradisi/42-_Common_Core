/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:40:42 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/24 18:07:14 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
/ this recursive function allows us to print any kind of base number byte per byte
*/

void	ft_putnbr_base_count(unsigned long long n, char *base, int *count)
{
	size_t	len;

	len = ft_strlen(base);
	if (n >= len)
		ft_putnbr_base_count(n / len, base, count);
	ft_putchar_count(base[n % len], count);
}
