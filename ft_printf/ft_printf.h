#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#define DECIMAL_BASE	"0123456789"
#define UP_HEX_BASE	"0123456789ABCDEF"
#define LOW_HEX_BASE	"0123456789abcdef"


int	ft_printf(const char *str, ...);

size_t	ft_strlen(const char *str);

void	ft_condition(const char c, int *count, va_list args);
void	ft_putchar_count(const char c, int *count);
void	ft_putstr_count(const char *str, int *count);
void	ft_putnbr_base_count(unsigned long long n, char *base, int *count);
void	ft_putint_count(int n, int *count);
#endif
