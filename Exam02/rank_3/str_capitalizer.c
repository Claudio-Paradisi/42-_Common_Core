/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:37:29 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/21 12:14:39 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_first_char(char *str, int pos)
{
	if (str[pos - 1] == ' ' || str[pos - 1] == '\t')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	char	c;

	i = 1;
	if (ac > 1)
	{
		while(av[i])
		{
			j = 0;
			if (av[i][0] >= 'a' && av[i][0] <= 'z')
                                {
                                        av[i][0] -= 32;
                                        ft_putchar(av[i][0]);
                                        j++;
                                }

			while(av[i][j])
			{
				c = av[i][j];
				if(c >= 'a' && c <= 'z' && is_first_char(av[i], j))
					c -= 32;
				else if(c >= 'A' && c <= 'Z' && !is_first_char(av[i], j))
					c += 32;
				ft_putchar(c);
				j++;
			}
			i++;
			ft_putchar('\n');
		}
	}
	else
		ft_putchar('\n');
	return 0;
}
