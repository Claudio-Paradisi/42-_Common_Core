/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:58:16 by cparadis          #+#    #+#             */
/*   Updated: 2024/12/17 13:57:54 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*buffer;

	if (!str)
		return (NULL);
	i = 0;
	buffer = (unsigned char *)str;
	while (i < n)
	{
		if (buffer[i] == (unsigned char)c)
		{
			return ((void *)&buffer[i]);
		}
		i++;
	}
	return (NULL);
}
