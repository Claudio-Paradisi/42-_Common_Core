/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_condition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:07:42 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/24 18:01:52 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
/ based on the char we have we call a specific function that will print
/ a specific data
*/
void	ft_condition(const char c, int *count, va_list args)
{
	if (c == 'c')
		ft_putchar_count((char)va_arg(args, int), count);
	else if (c == 's')
		ft_putstr_count(va_arg(args, char *), count);
	else if (c == 'd' || c == 'i')
		ft_putint_count(va_arg(args, int), count);
	else if (c == 'u')
		ft_putuns_int_count(va_arg(args, unsigned int), count);
	else if (c == 'x')
		ft_puthex_low_count(va_arg(args, unsigned int), count);
	else if (c == 'X')
		ft_puthex_up_count(va_arg(args, unsigned int), count);
	else if (c == 'p')
		ft_putptr_count(va_arg(args, void *), count);
	else if (c == '%')
		ft_putchar_count('%', count);
}
