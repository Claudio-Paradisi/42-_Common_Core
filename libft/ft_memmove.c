/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:28:46 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/24 10:57:54 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
/ a reproduction of the memmove function
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*buffer_a;
	const unsigned char	*buffer_b;

	if (!dest && !src)
		return (NULL);
	buffer_a = (unsigned char *)dest;
	buffer_b = (const unsigned char *)src;
	if (buffer_a < buffer_b || buffer_a >= buffer_b + n)
		return (ft_memcpy(buffer_a, buffer_b, n));
	else
	{
		buffer_a += n;
		buffer_b += n;
		while (n--)
		{
			*(--buffer_a) = *(--buffer_b);
		}
	}
	return (dest);
}
