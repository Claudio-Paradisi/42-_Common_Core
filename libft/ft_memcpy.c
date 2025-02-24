/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:30:18 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/24 10:57:42 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
/ a reproduction of the memcpy function
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*buffer;
	unsigned char	*buffer_two;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (dest);
	buffer = (unsigned char *)dest;
	buffer_two = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		buffer[i] = buffer_two[i];
		i++;
	}
	return (dest);
}
