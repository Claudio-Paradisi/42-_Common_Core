#include "ft_printf.h"

void	ft_putstr_count(const char *str, int *count)
{
	while (*str)
	{
		ft_putchar_count(*str, count);
		str++;
	}
}
