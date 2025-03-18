/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:48:47 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/24 10:57:30 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
/ a reproduction of the memcmp function
*/
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
