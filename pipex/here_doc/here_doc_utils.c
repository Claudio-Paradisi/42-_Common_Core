/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:27:02 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/03 12:09:06 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

/*
/ in this function we create the temporary infile we'll use as a input
/ for the first command
*/

int		create_hd_infile(char *limiter)
{
	char 	*line;
	int		fd;

	fd = open("here_doc_temp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		msg_error(1);
	/*
	/ we enter in an endless loop wher we get everything we write in the
	/ STDIN with our get_next_line function and we write it on the fd of our
	/ temporary file
	/ when we find (write) the LIMITER we break our loop 
	*/
	while (1)
	{
		write(1, "here_doc> ", 10);
		line = get_next_line(0);
		if (!line)
			break ;
		/*
		/ this is the check to find the LIMITER
		/ it has to be exactly the same and must end with /n
		*/
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0 &&
				line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, fd);
		free(line);
	}
	/*
	/ once we finish to write we close the fd and we return a fd with
	/ only read access
	*/
	close(fd);
	return (open("here_doc_temp", O_RDONLY));
}