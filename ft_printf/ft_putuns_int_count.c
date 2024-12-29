/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_int_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:45:50 by cparadis          #+#    #+#             */
/*   Updated: 2024/12/29 13:51:28 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putuns_int_count(unsigned int n, int *count)
{
    unsigned long long nbr;

    nbr = n;
    ft_putnbr_base_count(nbr, DECIMAL_BASE, count);
}