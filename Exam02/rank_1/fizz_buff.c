/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizz_buff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:10:34 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/04 16:26:30 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *s)
{
	while(*s)
	{
		ft_putchar(*s);
		s++;
	}
}
void	ft_putnbr(int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}
int	main()
{
	int array[100];
	int i;

	i = 0;
	while (i < 100)
	{
		array[i] = i + 1;
		if (array[i] % 3 == 0 && array[i] % 5 != 0)
			ft_putstr("fizz");
		else if (array[i] % 3 != 0 && array[i] % 5 == 0)
			ft_putstr("buzz");
		else if (array[i] % 3 == 0 && array[i] % 5 == 0)
			ft_putstr("fizzbuzz");
		else
			ft_putnbr(array[i]);
		write(1, "\n", 1);
		i++;
	}
}
