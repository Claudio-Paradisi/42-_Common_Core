/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:53:31 by cparadis          #+#    #+#             */
/*   Updated: 2024/12/11 18:03:05 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*dest;

	i = ft_strlen(str);
	dest = NULL;
	while (i > 0)
	{
		if (str[i] == c)
		{
			dest = (char *)&str[i];
			return (dest);
		}
		i--;
	}
	return (dest);
}
