#include <unistd.h>

int	ft_strlen(char *str)
{
	int	count;
	
	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	len;
	int	start;
	int	end;
	if (ac == 2)
	{
		len = ft_strlen(av[1]) - 1;
		while (len >= 0 && av[1][len] == ' ' || av[1][len] == '\t')
			len--;
		end = len;
		while (len >= 0 && av[1][len] != ' ' && av[1][len] != '\t')
			len--;
		start = len + 1;
		while (start <= end)
		{
			ft_putchar(av[1][start]);
			start++;
		}
	}
	ft_putchar('\n');
	return 0;
}
