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

int	check_stash(char *stash, size_t *bsn_pos)
{
	int	i;

	i = 0;
	if(!stash)
		return(FALSE);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
	{
		*bsn_pos = i;
		return (TRUE);
	}
	else
		return (FALSE);
}

void	upgrade_stash(char *stash)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	while (stash[i + j])
	{
		stash[j] = stash[i + j];
		i++;
		j++;
	}
	//return (stash);
}

char	*get_next_line(int fd)
{
	char 			*line;
	static char 		stash[BUFFER_SIZE + 1];
	size_t 			byte_read;
	size_t			bsn_pos;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	bsn_pos = 0;
	//controllo stash
	if (check_stash(stash, &bsn_pos))
	{
		line = gnl_strndup(stash, bsn_pos);
		upgrade_stash(stash);
		return (line);
	}
	line = gnl_strndup(stash, BUFFER_SIZE);
	while((byte_read = read(fd, stash, BUFFER_SIZE)) > 0)
	{
		if(check_stash(stash, &bsn_pos))
		{
			line = gnl_strndup(stash, bsn_pos);
			upgrade_stash(stash);
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
		{
			//controllo stash
			if (check_stash(stash, &bsn_pos))
			{
				line = gnl_strndup(stash, bsn_pos);
				upgrade_stash(stash);
				return (line);
			}
			else
				return (line);
		}
	}
}
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Assumendo che get_next_line sia già implementata.

int main()
{
    int fd = open("testo.txt", O_RDONLY);
    char *row;

    if (fd == -1) // Gestione errore apertura file
    {
        perror("Error opening file");
        return (1);
    }
    
    while ((row = get_next_line(fd)) != NULL) // Ciclo per leggere tutte le righe
    {
        printf("%s", row); // `get_next_line` dovrebbe includere già il newline, se presente
        free(row);         // Libera la memoria allocata per la riga
    }

    close(fd); // Chiudi il file

    return (0); // Indica che tutto è andato bene
}

