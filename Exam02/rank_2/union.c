#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	no_double(char *str, char c, int pos)
{
	int	i;
	
	i = 0;
	while (i < pos)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	no_double_in_av1(char *str, char c)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 3)
	{	
		while (av[1][i])
		{
			if(no_double(av[1], av[1][i], i))
				ft_putchar(av[1][i]);
			i++;
		}
		i = 0;
		while(av[2][i])
		{
			if (no_double(av[2], av[2][i], i) && 
					no_double_in_av1(av[1], av[2][i]))
				ft_putchar(av[2][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
