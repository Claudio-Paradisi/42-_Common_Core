/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:53:31 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/24 11:18:57 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
/ a reproduction of the strrchr function
*/
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = NULL;
	while (str[i])
	{
		if (str[i] == (char)c)
			dest = (char *)&str[i];
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (dest);
}
