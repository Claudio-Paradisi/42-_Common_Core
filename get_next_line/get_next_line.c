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

char *get_next_line(int fd)
{
    char *buffer;
    char *line;
    static char *stash;
    size_t ret_read;
    char *newline_pos;

    if (BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
	buffer = NULL;
	line = NULL;
	//stash = NULL;
    // Alloca il buffer per il read
    buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);

    while ((ret_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[ret_read] = '\0';
        stash = ft_strljoin(stash, buffer, 0, ft_strlen(buffer)); // Aggiungi al contenuto di stash
		printf("%s", buffer);
        if ((newline_pos = ft_strchr(stash, '\n')) != NULL) // Trova il newline
        {
            line = ft_substr(stash, 0, newline_pos - stash + 1);  // Estrai la riga fino al newline
			printf("helo");
            stash = ft_strljoin(NULL, newline_pos + 1, 0, ft_strlen(newline_pos + 1)); // Aggiorna stash
            break;
        }
    }

    free(buffer);

    // Ritorna la linea trovata o NULL se non c'è più nulla
    if (!line && stash)
    {
        line = ft_strljoin(NULL, stash, 0, ft_strlen(stash));
		printf("%s", line);
        free(stash);
        stash = NULL;
    }

    return (line);
}

int	main()
{	
	int	fd = open("testo.txt", O_RDONLY);
	char	*row = get_next_line(fd);

	if (fd == -1) // Gestione errore apertura file
    {
        perror("Error opening file");
        return (1);
    }
	printf("%s", row);
	free(row);
	close(fd);
	return (0);
}
