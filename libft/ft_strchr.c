/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:03:34 by cparadis          #+#    #+#             */
/*   Updated: 2024/12/11 18:42:28 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			dest = (char *)&str[i];
			return (dest);
		}
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (dest);
}
