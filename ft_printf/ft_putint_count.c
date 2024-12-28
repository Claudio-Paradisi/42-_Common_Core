#include "ft_printf.h"

void	ft_putint_count(int n, int *count)
{
	long long nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar_count('-', count);
	}
	ft_putnbr_base_count((unsigned long long)nbr, DECIMAL_BASE, count);
}
