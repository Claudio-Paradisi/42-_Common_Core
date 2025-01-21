/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:21:57 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/21 13:14:19 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while(*str)
		write(1, str++, 1);
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

int	atoi(char *str)
{
	int	nbr;

	nbr = 0;
	while (*str)
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	return (nbr);
}

void	print_all(int i, int nbr, int res)
{
	ft_putnbr(i);
	ft_putstr(" x ");
	ft_putnbr(nbr);
	ft_putstr(" = ");
	ft_putnbr(res);
	ft_putchar('\n');
}

int	main(int ac, char **av)
{
	int	res;
	int	i;
	int	nbr;

	if (ac == 2)
	{
		i = 1;
		nbr = atoi(av[1]);
		while (i < 10)
		{
			res = i * nbr;
			print_all(i, nbr, res);
			i++;
		}
	}
	else
		ft_putchar('\n');
}
