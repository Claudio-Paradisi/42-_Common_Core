/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:55:34 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/06 16:50:07 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char	*read_text(int fd, char *stash)
{
	size_t	byte_read;
	char	*buffer;
	int	i;
	int	j;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	byte_read = read(fd, buffer, BUFFER_SIZE);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			break ;
	}
	j = 0;
	while (buffer[i])
	{
		stash[j] = buffer[i + j];
		i++;
		j++;	
	}
	stash[j] = '\0';
}
char	*get_next_line(int fd)
{
	char 			*buffer;
	char 			*line;
	static char 		stash[BUFFER_SIZE + 1];
	size_t 			ret_read;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = NULL;
	line = NULL;
	stash = NULL;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
}

