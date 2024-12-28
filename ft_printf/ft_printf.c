#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list args;
	int	count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			ft_condition(*str, &count, args);
		}
		else
			ft_putchar_count(*str, &count);
		str++;
	}
	va_end(args);
	return (count);
}

int main()
{
	printf("%d\n", ft_printf("la mia printf è %d", 2147483688));
	printf("%d\n", printf("la printf originale è %d", 2147483648));
	return 0;
}
