/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:06:17 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/24 14:43:56 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
/ a function that creates an array of strings from a string
/ based to a char delimiter
*/
/*
/ a function that returns the number of strings the matrix will have
*/
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
/*
/ a function that will be called twice, once it will skip the delimiter and once
/ it will skip any other chars
*/

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
/*
/ the main function where the string is converted in a matrix
*/

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
