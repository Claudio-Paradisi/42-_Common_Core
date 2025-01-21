/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:52:59 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/21 11:31:55 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_last_char(char *s, char c, int pos)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		if (s[pos + 1] == ' ' || s[pos +1] == '\t' || s[pos + 1] == '\0')
			return (1);
	
	return (0);
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
			if (c >= 'a' && c <= 'z' && is_last_char(av[1], c, i))
				c -= 32;
			if (c >= 'A' && c <= 'Z' && !is_last_char(av[1], c, i))
				c += 32;
			ft_putchar(c);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
