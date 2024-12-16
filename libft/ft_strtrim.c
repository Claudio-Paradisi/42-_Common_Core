/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:13:15 by cparadis          #+#    #+#             */
/*   Updated: 2024/12/15 12:47:37 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*buffer;

	i = 0;
	k = 0;
	buffer = (char *)malloc(ft_strlen(s1) + 1);
	if (!buffer)
		return (NULL);
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (set[j] == s1[i])
				break ;
			j++;
		}
		if (set[j] == '\0')
			buffer[k++] = s1[i];
		i++;
	}
	buffer[k] = '\0';
	return (buffer);
}
