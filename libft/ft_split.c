/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:06:17 by cparadis          #+#    #+#             */
/*   Updated: 2024/12/18 19:12:38 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	**ft_split(const char *s, char c)
{
	char	*start;
	int		i;
	int		k;
	char	**phrase;
	size_t	words;

	words = count_words(s, c);
	i = 0;
	phrase = (char **)malloc(sizeof(char *) * (words + 1));
	if (!phrase)
		return (0);
	while (words-- > 0)
	{
		k = 0;
		s = char_skipper((char *)s, c, '=');
		start = (char *)s;
		s = char_skipper((char *)s, c, '!');
		phrase[i] = (char *)malloc(sizeof(char) * ((s - start) + 1));
		while (start < s)
			phrase[i][k++] = *start++;
		phrase[i++][k] = '\0';
	}
	phrase[i] = NULL;
	return (phrase);
}
