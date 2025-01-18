/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:06:29 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/14 15:05:02 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_stash(char *stash, size_t *bsn_pos)
{
	size_t	i;

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

void	upgrade_stash(char *stash)
{
	size_t	i;
	size_t	j;

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
	while (j < BUFFER_SIZE + 1)
	{
		stash[j] = '\0';
		j++;
	}
}

char	*join_stash(char *line, char *stash, int check, int bsn_pos)
{
	char	*temp;

	temp = gnl_strndup(stash, bsn_pos);
	if (check)
	{
		line = gnl_strjoin(line, temp);
		if (!line)
			return (NULL);
	}
	else
	{
		line = gnl_strndup(stash, bsn_pos);
		if (!line)
			return (NULL);
	}
	free(temp);
	upgrade_stash(stash);
	return (line);
}

char	*read_text(char *stash, char *line, size_t bsn_pos, int fd)
{
	int	byte_read;

	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, stash, BUFFER_SIZE);
		if (byte_read < 0)
			return (gnl_free_line(line));
		stash[byte_read] = '\0';
		if (check_stash(stash, &bsn_pos))
		{
			line = join_stash(line, stash, TRUE, bsn_pos);
			return (line);
		}
		line = gnl_strjoin(line, stash);
		if (!line)
			return (NULL);
		if (!check_stash(stash, &bsn_pos))
			upgrade_stash(stash);
	}
	if ((byte_read < 0 || (byte_read == 0 && line[0] == '\0')))
		return (gnl_free_line(line));
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	stash[1024][BUFFER_SIZE + 1];
	size_t		bsn_pos;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	bsn_pos = 0;
	line = NULL;
	if (check_stash(*stash, &bsn_pos))
	{
		line = join_stash(line, *stash, FALSE, bsn_pos);
		return (line);
	}
	line = gnl_strndup(*stash, gnl_strlen(*stash));
	if (!line)
		return (NULL);
	*stash[0] = '\0';
	line = read_text(*stash, line, bsn_pos, fd);
	return (line);
}

/*int     main(void)
{
        int fd;
        int fd_2;
        char *line;
        char *line2;
        int count = 1;

        fd = open("testo.txt", O_RDONLY);
        fd_2 = open("testo2.txt", O_RDONLY);
        if (fd < 0)
        {
                perror("Errore apertura file");
                return (1);
        }

        while (1)
        {
                line2 = get_next_line(fd_2);
                line = get_next_line(fd);
                if (line)
                        printf("%d) %s", count, line);
                if (line2)
                        printf("%d) %s", count, line2);
                free(line);
                free(line2);
                count++;
                if (!line && !line2)
                        break ;
        }
        //fd = open("file2.txt", O_RDONLY);
        close(fd);
        close(fd_2);
        return (0);
}*/
