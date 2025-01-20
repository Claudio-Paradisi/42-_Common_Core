#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	char	c;
	char	x;

	i = 0;
	if (ac == 2)
	{
		while(ft_is_space(av[1][i]))
			i++;
		while (av[1][i])
		{
			c = av[1][i];
			x = av[1][i + 1];
			if (ft_is_space(c) && (ft_is_space(x) || x == '\0'))
			{
				i++;
				continue ;
			}
			else
			{
				if (ft_is_space(c))
					ft_putstr("   ");
				else
					ft_putchar(c);
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
