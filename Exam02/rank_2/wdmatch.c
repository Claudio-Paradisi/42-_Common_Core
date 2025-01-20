#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	check_char(int *pos, char c, char *str)
{
	while (str[*pos])
	{
		if (c == str[*pos])
		{
			(*pos)++;
			return (1);
		}
		(*pos)++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			if (check_char(&j, av[1][i], av[2]))
				i++;
			else
			{
				ft_putstr("\n");
				return (0);
			}
		}
		ft_putstr(av[1]);
	}
	ft_putstr("\n");
	return (0);
}
