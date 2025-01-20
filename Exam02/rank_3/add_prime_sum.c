#include <unistd.h>

int	ft_atoi(char *str)
{
	int	nbr;
	while (*str)
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	return (nbr);
}

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

int	is_prime(int nbr)
{
	int	i;

	i = 2;
	if (nbr <= 1)
		return (0);
	while (i * i <= nbr)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);	
}

int	main(int ac, char **av)
{
	int	nbr;
	int	sum;
	
	sum = 0;	
	if (ac == 2)
	{
		nbr = ft_atoi(av[1]);
		while (nbr > 0)
		{
			if(is_prime(nbr))
				sum += nbr;
			nbr--;
		}
	}
	ft_putnbr(sum);
	ft_putchar('\n');
	return (0);
}
