/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:40:46 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/01 16:56:17 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_count(const char *str, int *count)
{
	if (!str)
	{
		ft_putstr_count("(null)", count);
		return ;
	}
	while (*str)
	{
		ft_putchar_count(*str, count);
		str++;
	}
}
