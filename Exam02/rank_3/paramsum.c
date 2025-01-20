#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

int	main(int ac, char **av)
{
	int	count;

	count = 0;
	if (ac > 1)
	{
		count--;
		while (*av)
		{
			count++;
			av++;
		}
	}
	ft_putnbr(count);
	ft_putchar('\n');
}
