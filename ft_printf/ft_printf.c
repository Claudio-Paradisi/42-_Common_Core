/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:40:13 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/24 17:59:21 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
/ a variadic function that prints in the standard output different types of data
/ and returns the number of bytes printed
*/
int	ft_printf(const char *str, ...)
{
	/*
	/ we declare our variadic list args and our int count which we will return
	/ at the end of the function, we initialize our list with the function
	/ va_start and our count at 0
	*/
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	/*
	/ we loop the string we take as a input and we print every char updating our
	/ count, if we find % we skip it and we call the function ft_condition
	*/
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			ft_condition(*str, &count, args);
		}
		else
			ft_putchar_count(*str, &count);
		str++;
	}
	/*
	/ we close our list with the function va_end and we return count
	*/
	va_end(args);
	return (count);
}
