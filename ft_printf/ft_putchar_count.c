#include "ft_printf.h"

void	ft_putchar_count(const char c, int *count)
{
	(*count)++;
	write(1, &c, 1);
}
