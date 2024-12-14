/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:28:46 by cparadis          #+#    #+#             */
/*   Updated: 2024/12/11 12:29:52 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*buffer_a;
	unsigned char	*buffer_b;
	size_t			i;

	buffer_a = (unsigned char *)dest;
	buffer_b = (unsigned char *)src;
	i = n;
	if (buffer_a < buffer_b)
		ft_memcpy(buffer_a, buffer_b, i);
	if (buffer_a > buffer_b)
	{
		while (i > 0)
		{
			buffer_a[i] = buffer_b[i];
			i--;
		}
	}
	return (dest);
}
