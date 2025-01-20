#include <unistd.h>

int	check_char(int *pos, char c, char *str)
{
	while(str[*pos])
	{
		if (c == str[*pos])
			return (1);
		(*pos)++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	char	c;

	i = 0;
	j = 0;

	if (ac == 3)
	{
		while(av[1][i])
		{
			c = av[1][i];
			if(!check_char(&j, c, av[2]))
			{
				write(1, "0", 1);
				break ;
			}
			i++;
		}
		if (av[1][i] == '\0')
			write(1, "1", 1);
	}
	write(1, "\n", 1);
	return (0);
}
