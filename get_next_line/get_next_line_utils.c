/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:55:14 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/09 18:47:53 by cparadis         ###   ########.fr       */
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
	return(count);
}

char    *gnl_strndup(char *str, size_t size)
{
	size_t          i;
	char            *dup;

	i = 0;
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}
/*
char    *gnl_substr(const char *s, unsigned int start, size_t len)
{
        char                    *buffer;
        size_t                  i;
        size_t                  s_len;

        i = 0;
        if (!s)
                return (NULL);
        s_len = gtl_strlen(s);
//        if (start >= s_len || len == 0)
//                return (gtl_strdup(""));
        if (start + len > s_len)
                len = s_len - start;
        buffer = malloc(len + 1);
        if (!buffer)
                return (NULL);
        i = 0;
        while (i < len)
        {
                buffer[i] = s[start + i];
                i++;
        }
        buffer[i] = '\0';
        return (buffer);
}
*/

char    *gnl_strjoin(char *s1, char *s2)
{
	char    *line;
	size_t  len;
	size_t  i;
	size_t  j;

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
	free(s2);
	return (line);
}
