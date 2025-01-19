/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:03:20 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/19 12:13:41 by cparadis         ###   ########.fr       */
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
	
	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			c = av[1][i];
			if (c >= 'a' && c < 'z')
				c = 'a' - c + 'z';
			else if (c >= 'A' && c < 'Z')
                                c = 'A' - c + 'Z';
			else if (c == 'Z')
				c = 'A';
			else if (c == 'z')
				c = 'a';
			ft_putchar(c);
			i++;
		}
	}
	ft_putchar('\n');
}
