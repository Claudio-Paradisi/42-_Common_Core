#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	i;
	char	c;
	i = 0;
	if (ac == 2)
	{
		while(av[1][i])
		{
			c = av[1][i];
			if (c == '_')
			{
				i++;
				c = av[1][i];
				c -= 32;
			}
			ft_putchar(c);
			i++;
		}
	}
	ft_putchar('\n');
}
