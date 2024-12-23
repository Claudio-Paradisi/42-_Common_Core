/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:57:55 by cparadis          #+#    #+#             */
/*   Updated: 2024/12/17 15:57:36 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static void	*ft_free_matrix(char **matrix, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (NULL);
}

static size_t	count_char(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			count++;
			while (*s != '\0' && *s != c)
				s++;
		}
		else
			s++;
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

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	j;
	char	**buffer;

	if (!s)
	return (NULL);
	i = 0;
	j = 0;
	buffer = ft_calloc((count_char(s, c) + 1), sizeof(char *));
	if (!buffer)
		return (NULL);
	while (s[i])
	{
		buffer[j] = ft_add_str(s, c, &i);
		if (!buffer)
			return (ft_free_matrix(buffer, j));
		j++;
	}
	buffer[j] = NULL;
	return (buffer);
}

/*int		main(int argc, const char *argv[])
{
	char	**tabstr;
	int		i;
	int		arg;

	if (argc == 1)
		return (0);
	i = 0;
	if ((arg = atoi(argv[1])) == 1)
	{
		if (!(tabstr = ft_split("          ", ' ')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (arg == 2)
	{
		if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (arg == 3)
	{
		if (!(tabstr = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (arg == 4)
	{
		if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (arg == 5)
	{
		if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (arg == 6)
	{
		if (!(tabstr = ft_split("", 'z')))
			ft_print_result("NULL");
		else
			if (!tabstr[0])
				ft_print_result("ok\n");
	}
	return (0);
}*/