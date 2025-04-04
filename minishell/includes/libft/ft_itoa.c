/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:38:19 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/24 14:44:28 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
/ a function that takes an integer and converts it in a string
*/
/*
/ a function to count how many digits the number has
/ so that we can use the malloc correctly
*/
static int	ft_nbr_len(long nbr)
{
	int	count;

	count = 0;
	if (nbr <= 0)
	{
		count++;
		if (nbr < 0)
			nbr = -nbr;
	}
	while (nbr != 0)
	{
		count++;
		nbr = nbr / 10;
	}
	return (count);
}
/*
/ a function that initializes the string with the first char '0'
*/

static char	*ft_init_str(int len)
{
	char	*str;

	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '0';
	return (str);
}
/*
/ the main function where the number is converted in a string
*/

char	*ft_itoa(int n)
{
	char	*buffer;
	int		len;
	int		i;
	long	nbr;

	nbr = n;
	len = ft_nbr_len(nbr);
	i = len - 1;
	buffer = ft_init_str(len);
	if (!buffer)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	while (nbr != 0)
	{
		buffer[i] = ((nbr % 10) + '0');
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		buffer[0] = '-';
	buffer[len] = '\0';
	return (buffer);
}
