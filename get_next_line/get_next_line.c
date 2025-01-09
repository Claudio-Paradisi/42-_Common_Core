/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:55:34 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/09 18:48:03 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int	check_stash(char *stash)
{
	int	i;
	int	j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	j = 0;
	//da fare in un altra funzione
	if (stash[i] == '\n')
	{
		while (stash[i + j])
		{
			stash[j] = stash[i + j];
			i++;
			j++;	
		}
	}
	else
		return (FALSE);
	return (TRUE);
}
char	*get_next_line(int fd)
{
	char 			*line;
	static char 		stash[BUFFER_SIZE + 1];
	size_t 			byte_read;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	//controllo stash
	line = strndup(stash, BUFFER_SIZE);
	while((byte_read = read(fd, stash, BUFFER_SIZE)) > 0)
	{
		if(check_stash(stash))
		{
			return (line);
		}
		line = gnl_strjoin(line, stash);
	}
	if (byte_read < 0)
	{
		free(line);
		return (NULL);
	}
	//eccezione riga esistente senza new line
	if (byte_read == 0)
	{
		if (!line)
			return (NULL);
		else
			//controllo stash
			return (line);
	}
}

