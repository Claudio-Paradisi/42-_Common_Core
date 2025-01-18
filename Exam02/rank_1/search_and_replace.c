/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:19:59 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/15 15:30:50 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	i;
	char	c;
	char	d;

	i = 0;
	if (ac == 4)
	{
		c = av[2][0];
		d = av[3][0];
		while (av[1][i])
		{
			if(av[1][i] == c)
				av[1][i] = d;
			ft_putchar(av[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
}
