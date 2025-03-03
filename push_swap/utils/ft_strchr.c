/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:03:34 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/03 16:33:54 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
