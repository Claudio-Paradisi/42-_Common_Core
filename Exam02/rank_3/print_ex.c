#include <unistd.h>

/*note for myself: putnbr_base doesn't need the "+ '0'"*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr_hex(int  nbr)
{
	char *base = "0123456789abcdef";

	if (nbr >= 16)
		ft_putnbr_hex(nbr / 16);
	ft_putchar(base[nbr % 16]);
}

int	ft_atoi(char *str)
{
	int	num;

	num = 0;
	while(*str)
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num);
}

int	main(int ac, char **av)
{
	int	hex_num;

	if (ac == 2)
	{
		hex_num = ft_atoi(av[1]);
		ft_putnbr_hex(hex_num);
	}
	ft_putchar('\n');
}
