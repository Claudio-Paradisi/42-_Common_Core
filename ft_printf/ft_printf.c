/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:40:13 by cparadis          #+#    #+#             */
/*   Updated: 2024/12/29 13:51:28 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list args;
	int	count;

	count = 0;
	va_start(args, str);
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
	va_end(args);
	return (count);
}

int main()
{
	int ciao = 5;
	int ciaone = 8;
	int *ptr = &ciao;
	int *ptr2 = &ciaone;
	printf("%d\n", ft_printf("la mia printf è %p", ptr2));
	printf("%d\n", printf("la sua printf è %p", ptr2));
	return 0;
}
