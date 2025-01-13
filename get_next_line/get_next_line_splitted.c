/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_splitted.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:55:43 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/13 18:26:45 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "get_next_line.h"

int check_stash(char *stash, size_t *bsn_pos)
{
    size_t  i;

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
    //stash[j] = '\0';
    while (j < BUFFER_SIZE + 1)
    {
        stash[j] = '\0';
        j++;
    }
}

char    *join_stash(char *line, char *stash, int check, int bsn_pos)
{
    char *temp;

    temp = gnl_strndup(stash, bsn_pos);
    if (check)
    {
        //line = gnl_strjoin(line, gnl_strndup(stash, bsn_pos));
        line = gnl_strjoin(line, temp);
        if (!line)
            return (NULL);
    }
    else
    {
        line = gnl_strndup(stash, bsn_pos);
        //line = temp;
        if (!line)
            return (NULL);
    }
    free(temp);
    upgrade_stash(stash);
    return (line);
}

char    *read_text(char *stash, char *line, size_t bsn_pos, int fd)
{
    int  byte_read;

    byte_read = 1;
    while (byte_read > 0)
    {
        byte_read = read(fd, stash, BUFFER_SIZE);
        if (byte_read < 0)
            return (gnl_free_line(line));
        /*{
            free(line);
            return (NULL);
        }*/
        stash[byte_read] = '\0';
        if (check_stash(stash, &bsn_pos))
        {
            /*line = gnl_strjoin(line ,gnl_strndup(stash, bsn_pos));
		    if (!line)
                return (NULL);
		    upgrade_stash(stash);*/
            line = join_stash(line, stash, TRUE, bsn_pos);
		    return (line);
        }
        line = gnl_strjoin(line, stash);
        if (!line)
            return (NULL);
        if(!check_stash(stash, &bsn_pos))
			upgrade_stash(stash);
    }
    if ((byte_read < 0 || (byte_read == 0 && line[0] == '\0')))
        return(gnl_free_line(line));
	/*{
		free(line);
		return (NULL);
	}*/
    return (line);
}

char	*get_next_line(int fd)
{
	char 				*line;
	static char 		stash[BUFFER_SIZE + 1];
	//size_t 				byte_read;
	size_t				bsn_pos;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	bsn_pos = 0;
	line = NULL;
	if (check_stash(stash, &bsn_pos))
	{
		/*line = gnl_strndup(stash, bsn_pos);
		if (!line)
            return (NULL);
		upgrade_stash(stash);*/
        line = join_stash(line, stash, FALSE, bsn_pos);
		return (line);
	}
    line = gnl_strndup(stash, gnl_strlen(stash));
	if (!line)
		return (NULL);
	stash[0] = '\0';
    line = read_text(stash, line, bsn_pos, fd);
    return (line);
}

int main()
{
    int fd = open("testo.txt", O_RDONLY);
    //int fd = 42;
    char *row;
    int i = 1;
    
    while ((row = get_next_line(fd)) != NULL)
    {
        printf("%d chiamata: %s",i, row);
    	free(row); 
		i++;
	}        
	printf("\n%d chiamata supplementare: %s\n",i, row);
	printf("%d chiamata supplementare: %s",++i, row);
    close(fd); 
    return (0); 
}