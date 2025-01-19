/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:10:39 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/19 16:35:43 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	no_double(char *str, char c, int pos)
{
	int	i;
	
	i = 0;
	while (i < pos)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac == 3)
	{
		while(av[1][i])
		{
			j = 0;
			while (av[2][j])
			{
				if (av[1][i] == av[2][j] && no_double(av[1], av[1][i], i))
				{
					write(1, &av[1][i], 1);
					break ;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
