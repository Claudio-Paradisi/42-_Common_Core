/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:48:49 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/24 10:38:38 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
/	a function that duplicate a string with malloc
*/
char	*ft_strdup(const char *str)
{
	size_t		i;
	size_t		len;
	char		*buffer;

	i = 0;
	len = ft_strlen(str);
	buffer = (char *)malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (i < len)
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[len] = '\0';
	return (buffer);
}
