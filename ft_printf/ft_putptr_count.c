/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:19:34 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/24 18:07:53 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
/ this function prints a memory address
*/
void    ft_putptr_count(void *ptr, int  *count)
{
    unsigned long long nbr;
    if (!ptr)
        return (ft_putstr_count("(nil)", count));
    nbr = (unsigned long long)ptr;
    ft_putstr_count("0x", count);
    ft_putnbr_base_count(nbr, LOW_HEX_BASE, count);
}