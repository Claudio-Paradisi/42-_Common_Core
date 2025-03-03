/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_low_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:53:44 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/24 18:04:24 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
/ this function prints an hexadecimal number in lower case
*/
void    ft_puthex_low_count(unsigned int n_hex, int *count)
{
    unsigned long long nbr;

    nbr = n_hex;
    ft_putnbr_base_count(nbr, LOW_HEX_BASE, count);
}