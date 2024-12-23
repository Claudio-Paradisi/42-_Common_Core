/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:48:47 by cparadis          #+#    #+#             */
/*   Updated: 2024/12/17 14:19:45 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*buffer_a;
	unsigned char	*buffer_b;

	buffer_a = (unsigned char *)s1;
	buffer_b = (unsigned char *)s2;
	while (*buffer_a == *buffer_b && n)
	{
		++buffer_a;
		++buffer_b;
		--n;
	}
	if (n)
		return (*buffer_a - *buffer_b);
	return (0);
}
