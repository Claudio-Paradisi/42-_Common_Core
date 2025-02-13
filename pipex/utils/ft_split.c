/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:06:17 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/12 11:14:33 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

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

static char	*char_skipper(char *s, char c, char x)
{
	if (x == '=')
	{
		while (*s == c && *s)
			s++;
	}
	else if (x == '!')
	{
		while (*s != c && *s)
			s++;
	}
	return (s);
}

static void 	splitting(size_t words, const char *s, char c, char **phrase)
{
	int		i;
	int		k;
	char 	*start;

	i = 0;
	while (words-- > 0)
	{
		k = 0;
		s = char_skipper((char *)s, c, '=');
		start = (char *)s;
		s = char_skipper((char *)s, c, '!');
		phrase[i] = ft_calloc((s - start) + 1, sizeof(char));
		if (!phrase[i])
		{
			free_matrix(phrase);
			phrase = (NULL);
			return ;
		}
		while (start < s)
			phrase[i][k++] = *start++;
		phrase[i++][k] = '\0';
	}
	phrase[i] = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**phrase;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	 if (words == 0)
    {
        phrase = ft_calloc(1, sizeof(char *));
        if (!phrase)
            return (NULL);
        phrase[0] = NULL;
        return (phrase);
    }
	phrase = ft_calloc(words + 1, sizeof(char *));
	if (!phrase)
		return (NULL);
	splitting(words, s, c, phrase);
	return (phrase);
}
