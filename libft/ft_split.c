/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:57:55 by cparadis          #+#    #+#             */
/*   Updated: 2024/12/16 17:48:12 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_char(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_add_str(const char *s, char c, size_t *i)
{
	char	*buffer;
	size_t	j;

	buffer = NULL;
	while (s[*i] == c)
		(*i)++;
	if (s[*i] != '\0')
	{
		j = 0;
		while (s[*i + j] && s[*i + j] != c)
			(j)++;
		buffer = malloc(j + 1);
		if (!buffer)
			return (NULL);
		j = 0;
		while (s[*i] && s[*i] != c)
			buffer[(j)++] = s[(*i)++];
		buffer[j] = '\0';
	}
	return (buffer);
}

static void	*ft_free_matrix(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	j;
	char	**buffer;

	i = 0;
	j = 0;
	buffer = malloc((count_char(s, c) + 1) * sizeof(char *));
	if (!buffer)
		return (NULL);
	while (s[i])
	{
		buffer[j] = ft_add_str(s, c, &i);
		if (!buffer[j])
		{
			ft_free_matrix(buffer);
			return (buffer);
		}
		j++;
	}
	buffer[j] = NULL;
	return (buffer);
}

int main(int ac, char **av)
{
	int i = 0;
	if (ac > 1)
	{
		char **matrice = ft_split(av[1], av[2][0]);
		while (matrice[i])
		{
			printf("%s\n", matrice[i]);
			free(matrice[i]);
			i++;
		}
		free(matrice);
	}
}
