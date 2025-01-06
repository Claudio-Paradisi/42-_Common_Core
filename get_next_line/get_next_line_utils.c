/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:55:14 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/06 16:33:08 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
        while (*s)
        {
                count++;
                s++;
        }
	return(count);
}

char    *ft_strchr(const char *str, int c)
{
        size_t  i;
        char    *dest;

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

char    *ft_strdup(const char *str)
{
        size_t          i;
        size_t          len;
        char            *buffer;

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

char    *ft_substr(const char *s, unsigned int start, size_t len)
{
        char                    *buffer;
        size_t                  i;
        size_t                  s_len;

        i = 0;
        if (!s)
                return (NULL);
        s_len = ft_strlen(s);
        if (start >= s_len || len == 0)
                return (ft_strdup(""));
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


char    *ft_strljoin(char *s1, char *s2, size_t start, size_t bs_n_len)
{
        char    *buffer;
        size_t  len;
        size_t  i;
        size_t  j;

        if (!s2)
                return (NULL);
        i = 0;
        len = (s1 ? ft_strlen(s1) : 0) + ft_strlen(s2);
        buffer = (char *)malloc((len + 1) * sizeof(char));
        if (!buffer)
                return (NULL);
        while (s1 && s1[i])
        {
                buffer[i] = s1[i];
                i++;
        }
        j = 0;
        while (s2[j] && i <= bs_n_len)
        {
                buffer[i + j] = s2[j + start];
                j++;
        }
        buffer[i + j] = '\0';
        free(s1);
        return (buffer);
}