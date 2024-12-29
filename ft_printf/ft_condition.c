#include "ft_printf.h"

void	ft_condition(const char c, int *count, va_list args)
{
	if (c == 'c')
		ft_putchar_count((char)va_arg(args, int), count);
	else if (c == 's')
		ft_putstr_count(va_arg(args, char *), count);
	else if (c == 'd' || c == 'i')
		ft_putint_count(va_arg(args, int), count);
	else if (c == 'u')
		ft_putuns_int_count(va_arg(args, unsigned int), count);
	else if (c == 'x')
		ft_puthex_low_count(va_arg(args, unsigned int), count);
	else if (c == 'X')
		ft_puthex_up_count(va_arg(args, unsigned int), count);	
	else if (c == 'p')
		ft_putptr_count(va_arg(args, void *), count);
	else if (c == '%')
		ft_putchar_count('%', count);
}