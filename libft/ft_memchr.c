/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:58:16 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/24 10:57:17 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
/ a reproduction of the memchr function
*/
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
