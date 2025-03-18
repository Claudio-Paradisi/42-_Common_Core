/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:54:12 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/18 12:26:21 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static void check_null_line(char *line, char *temp, int fd)
{
    if (line[0] == '\n')
    {
        if(temp)
            free(temp);
        free(line);
        close(fd);
        ft_printf("Not valid map");
        exit(1);
    }
}

char **read_map(char *file)
{
	int fd;
	char *line;
	char *temp;
	char **map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printf("file not found"), NULL);
	temp = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
        check_null_line(line, temp, fd);
		temp = gnl_strjoin(temp, line);
		free(line);
	}
	close(fd);
	if (!temp[0])
		return (ft_printf("file vuoto"), free(temp), NULL);
	map = ft_split(temp, '\n');
	free(temp);
	return (map);
}