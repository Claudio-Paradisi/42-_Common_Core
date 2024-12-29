/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:40:19 by cparadis          #+#    #+#             */
/*   Updated: 2024/12/29 12:34:13 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define DECIMAL_BASE "0123456789"
# define UP_HEX_BASE "0123456789ABCDEF"
# define LOW_HEX_BASE "0123456789abcdef"

int		ft_printf(const char *str, ...);

size_t	ft_strlen(const char *str);

void	ft_condition(const char c, int *count, va_list args);
void	ft_putchar_count(const char c, int *count);
void	ft_putstr_count(const char *str, int *count);
void	ft_putnbr_base_count(unsigned long long n, char *base, int *count);
void	ft_putint_count(int n, int *count);
void	ft_putuns_int_count(unsigned int n, int *count);
void	ft_puthex_low_count(unsigned int n_hex, int *count);
void	ft_puthex_up_count(unsigned int n_hex, int *count);
void	ft_putptr_count(void *ptr, int *count);
#endif
