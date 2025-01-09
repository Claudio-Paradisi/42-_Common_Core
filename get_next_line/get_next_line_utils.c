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

size_t	gnl_strlen(const char *s)
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

/*char    *gtl_strdup(const char *str)
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

char    *gnl_strljoin(char *s1, char *s2, size_t start, size_t bs_n_len)
{
        char    *buffer;
        size_t  len;
        size_t  i;
        size_t  j;

        if (!s2)
                return (NULL);
        i = 0;
        len = (s1 ? gnl_strlen(s1) : 0) + gnl_strlen(s2);
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

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	
	if (*s)
		return (0);
	count = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			count++;
			while (*s != c && *s != '\0')
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char	*char_skipper(char *s, char c, int check)
{
	if (check == TRUE)
	{
		while (*s == c && *s)
			s++;
	}
	else if (check == FALSE)
	{
		while (*s != c && *s)
			s++;
	}
	return (s);
}

char	**gnl_split(const char *s, char c)
{
	char	*start;
	int		i;
	int		k;
	char	**matrix;
	size_t	words;

	words = count_words(s, c);
	i = 0;
	matrix = (char **)malloc(sizeof(char *) * (words + 1));
	if (!matrix)
		return (0);
	while (words-- > 0)
	{
		k = 0;
		s = char_skipper((char *)s, c, TRUE);
		start = (char *)s;
		s = char_skipper((char *)s, c, FALSE);
		matrix[i] = (char *)malloc(sizeof(char) * ((s - start) + 2));
		while (start < s)
			matrix[i][k++] = *start++;
		matrix[i][k] = '\n';
		matrix[i++][k + 1] = '\0';
	}
	matrix[i] = NULL;
	return (matrix);
}
