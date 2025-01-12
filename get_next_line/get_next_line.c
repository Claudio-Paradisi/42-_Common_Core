/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:55:34 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/12 13:21:06 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int check_stash(char *stash, size_t *bsn_pos)
{
    size_t i;

    i = 0;
    if (!stash)
        return (FALSE);
    while (stash[i])
    {
        if (stash[i] == '\n')
        {
            *bsn_pos = i + 1;
            return (TRUE);
        }
        i++;
    }
    return (FALSE);
}

void    upgrade_stash(char *stash)
{
    size_t  i;
    size_t  j;

    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;
    j = 0;
    while (stash[i + j])
    {
        stash[j] = stash[i + j];
        j++;
    }
    stash[j] = '\0';
	// Azzeramento completo del resto dello stash per evitare dati "sporchi"
    while (j < BUFFER_SIZE + 1)
    {
        stash[j] = '\0';
        j++;
    }
}

char	*get_next_line(int fd)
{
	char 				*line;
	static char 		stash[BUFFER_SIZE + 1];
	char				*temp;
	size_t 				byte_read;
	size_t				bsn_pos;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	bsn_pos = 0;
	//temp = NULL;
	//line = NULL;
	//controllo stash
	/*if (stash[0] == '\0' && read(fd, stash, 0) < 0)
        return (NULL);*/
	if (check_stash(stash, &bsn_pos))
	{
		line = gnl_strndup(stash, bsn_pos);
		if (!line)
            return (NULL);
		upgrade_stash(stash);
		return (line);
	}
	//inizializzo  line con il contento di stash corrente
	line = gnl_strndup(stash, gnl_strlen(stash));
	//printf(" line: %s\n", line);
	if (!line)
		return (NULL);
	stash[0] = '\0';
	while((byte_read = read(fd, stash, BUFFER_SIZE)) > 0)
	{
		stash[byte_read] = '\0';
		//printf("Bytes read: %zu, stash: '%s', line so far: '%s'\n", byte_read, stash, line);
		if(check_stash(stash, &bsn_pos))
		{
			//printf("Newline found in stash.\n");
			temp = gnl_strndup(stash, bsn_pos);
			if (!temp)
			{
				free(line);
				return (NULL);
			}
			char * new_line = gnl_strjoin(line, temp);
			free(temp);
            if (!new_line)
                return (NULL);
			line = new_line;
			upgrade_stash(stash);
			return (line);
		}
		/*temp = gnl_strjoin(line, stash);
		if (!temp)
		{
			free(line);
			return (NULL);
		}
		free(line);
		line = temp;*/
		char *new_line = gnl_strjoin(line, stash);
        //free(line); // Libera la vecchia riga
        if (!new_line)
            return (NULL);
		if(!check_stash(stash, &bsn_pos))
			upgrade_stash(stash);
        line = new_line;
	}
	if (byte_read < 0)
	{
		free(line);
		return (NULL);
	}
	if (byte_read == 0 && line[0] == '\0')
    {
        free(line);
        return (NULL);
    }
	return (line);
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
    int i = 0;

    if (fd == -1) // Gestione errore apertura file
    {
        perror("Error opening file");
        return (1);
    }
    
    while ((row = get_next_line(fd)) != NULL) // Ciclo per leggere tutte le righe
    {
        printf("%d chiamata: %s",i, row); // `get_next_line` dovrebbe includere già il newline, se pr
    	free(row); 
		i++;
	}        // Libera la memoria allocata per la riga
    
	printf("%d chiamata supplementare: %s\n",i, row);
	printf("%d chiamata supplementare: %s",++i, row);

    close(fd); // Chiudi il file

    return (0); // Indica che tutto è andato bene
}

