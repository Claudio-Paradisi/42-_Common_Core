/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:40:24 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/24 18:03:19 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
/ this function prints any char and increments count
*/
void	ft_putchar_count(const char c, int *count)
{
	(*count)++;
	write(1, &c, 1);
}
