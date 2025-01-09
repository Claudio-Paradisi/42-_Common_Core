/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:40:42 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/09 17:50:47 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_count(unsigned long long n, char *base, int *count)
{
	size_t	len;

	len = ft_strlen(base);
	if (n >= len)
		ft_putnbr_base_count(n / len, base, count);
	ft_putchar_count(base[n % len], count);
}
