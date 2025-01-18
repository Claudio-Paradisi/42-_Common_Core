/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:52:36 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/15 14:05:22 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	count; //count sara' lettera della stringa - 'a'o 'A' + 1 o 1 di default

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] >= 'a' && av[1][i]	<= 'z')
				count = av[1][i] - 'a' + 1;
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
					count = av[1][i] - 'A' + 1;
			else
				count = 1;
			while (count--)
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}