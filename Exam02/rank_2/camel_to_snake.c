/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:15:20 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/19 12:24:08 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * subject don't specify if we have to check the number of arguments are passed so we have to try it with the simulator if we will be lucky to find this exercise
 * */

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
		while (av[1][i])
		{
			c = av[1][i];
			if (c >= 'A' && c <= 'Z')
			{
				ft_putchar('_');
				c += 32;
			}
			ft_putchar(c);
			i++;
		}
	}
	ft_putchar('\n');
}
