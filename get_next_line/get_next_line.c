/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:55:34 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/24 17:00:12 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
/ a function that regardless of the BUFFER SIZE returns a full line of a fd
/ each times it's called 
*/

/*
/ check_stash function takes our static buffer and the pointer of the new line position
/ it returns true if the string has the new line or false if there isn't
*/
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
			/*
			/ we set bsn_pos to i + 1 because the line we return with gnl
			/ includes the \n
			*/
			*bsn_pos = i + 1;
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

/*
/ once a line is returned we have to delete every char we returned from the stash
/ so that next time gnl is called we can deliver the next line 
*/
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

/*
/ this function put to the string line every char it needs to return
*/
char	*join_stash(char *line, char *stash, int check, int bsn_pos)
{
	/*
	/ we declare a temp string to avoid memory leaks
	*/
	char	*temp;

	temp = gnl_strndup(stash, bsn_pos);
	/*
	/ if check is true it means that we are calling the function inside the loop
	/ of read_text and so it may be called more than once until it finds a \n, 
	/ else if check is false it means we are calling it outside the read_text
	/ function because stash has already a new line ready to be returned  
	*/
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
/*
/ this is the function where we read from the fd, we read BUFFER_SIZE bytes
/ until read function returns 0 or until a /n is found in our stash  
*/
char	*read_text(char *stash, char *line, size_t bsn_pos, int fd)
{
	int	byte_read;

	/*
	/we set byte_read to 1 so that we can enter in the loop
	*/
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, stash, BUFFER_SIZE);
		if (byte_read < 0)
			return (gnl_free_line(line));
		stash[byte_read] = '\0';
		/*
		/ if we enter in this condition it means that when we read we found a \n
		/ so we must return the line, it's not a problem to exit the loop because
		/ thanks to the offset of the read function next time we call it it will
		/ start to read from the next byte it stopped   
		*/
		if (check_stash(stash, &bsn_pos))
		{
			line = join_stash(line, stash, TRUE, bsn_pos);
			return (line);
		}
		line = gnl_strjoin(line, stash);
		if (!line)
			return (NULL);
		/*
		/ this condition is for when you have a file with text without \n.
		/ whithout this condition the text would be returned twice
		*/
		if (!check_stash(stash, &bsn_pos))
			upgrade_stash(stash);
	}
	if ((byte_read < 0 || (byte_read == 0 && line[0] == '\0')))
		return (gnl_free_line(line));
	return (line);
}

/*
/ in our main function we declare 3 variables, a pointer to char line that
/ will be the line we return, a static array of char stash where we store 
/ anything we read and a size_t bsn_pos (back slash n position) 
*/
char	*get_next_line(int fd)
{
	char		*line;
	static char	stash[BUFFER_SIZE + 1];
	size_t		bsn_pos;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	bsn_pos = 0;
	line = NULL;
	/*
	/ first thing first we check if stash has already a \n if so it means
	/ we have already a line we are able to return (obviously the first time
	/ we call gnl it will never enter in this condition)
	*/
	if (check_stash(stash, &bsn_pos))
	{
		line = join_stash(line, stash, FALSE, bsn_pos);
		return (line);
	}
	/*
	/ since stash it's a static variable it may have already some char from the
	/ previous time gnl has been called so we give everything to our string line
	/ and we set stash to null (the first time gnl is called line will be a: "")
	*/
	line = gnl_strndup(stash, gnl_strlen(stash));
	if (!line)
		return (NULL);
	stash[0] = '\0';
	line = read_text(stash, line, bsn_pos, fd);
	return (line);
}

/*int main()
{
    int fd = open("testo2.txt", O_RDONLY);
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
}*/
