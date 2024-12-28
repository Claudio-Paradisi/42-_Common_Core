#include "ft_printf.h"

void	ft_putnbr_base_count(unsigned long long n, char *base, int *count)
{
	size_t len;

	len = ft_strlen(base);
	if (n >= len)
		ft_putnbr_base_count(n / len, base, count);
	ft_putchar_count(base[n % len], count);
}
