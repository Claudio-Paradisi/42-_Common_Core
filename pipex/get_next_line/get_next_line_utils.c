/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:55:14 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/14 13:40:29 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

char	*gnl_strndup(char *str, size_t size)
{
	size_t		i;
	char		*dup;

	i = 0;
	dup = (char *)malloc((size + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (i < size)
	{
		dup[i] = str[i];
		i++;
	}
	dup[size] = '\0';
	return (dup);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char		*line;
	size_t		len;
	size_t		i;
	size_t		j;

	i = 0;
	len = gnl_strlen(s1) + gnl_strlen(s2);
	line = (char *)malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (s1 && s1[i])
	{
		line[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		line[i + j] = s2[j];
		j++;
	}
	line[i + j] = '\0';
	free(s1);
	return (line);
}

char	*gnl_free_line(char *line)
{
	free(line);
	return (NULL);
}
