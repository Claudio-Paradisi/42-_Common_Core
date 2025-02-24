/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_up_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:04:51 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/24 18:04:59 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
/ this function prints a hexadecimal number in uppercase
*/
void    ft_puthex_up_count(unsigned int n_hex, int *count)
{
    unsigned long long nbr;

    nbr = n_hex;
    ft_putnbr_base_count(nbr, UP_HEX_BASE, count);
}