/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:26:07 by cparadis          #+#    #+#             */
/*   Updated: 2024/12/12 17:52:05 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*buffer;
	size_t 	len;
	size_t	i;
	
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	buffer = (char *)malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		buffer[i] = s1[i];
		i++;
	}
	ft_strlcat(buffer, s2, (len + 1));
	return  (buffer);
}
