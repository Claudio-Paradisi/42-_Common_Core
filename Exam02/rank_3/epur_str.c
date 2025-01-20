#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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
	if (ac == 2)
	{
		i = 0;
		while (ft_is_space(av[1][i]))
			i++;
		while (av[1][i])
		{
			c = av[1][i];
			if (ft_is_space(c) && (ft_is_space(av[1][i + 1]) || 
						av[1][i + 1] == '\0'))
				i++;
			else
			{	
				ft_putchar(c);
				i++;
			}
		}
	}
	ft_putchar('\n');
	return (0);
}
