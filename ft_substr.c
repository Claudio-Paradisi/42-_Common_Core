/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:06:06 by cparadis          #+#    #+#             */
/*   Updated: 2024/12/12 17:09:27 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*buffer;
	unsigned int	i;

	i = 0;
	buffer = (char *)malloc((len + 1) * sizeof(char));
	if (!buffer || start > ft_strlen(s))
		return (NULL);
	while (start < len && s[start + i] != '\0')
	{
		buffer[i] = s[start + i];
		i++;
	}
	buffer[len] = '\0';
	return (buffer);
}
