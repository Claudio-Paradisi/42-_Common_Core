/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:36:02 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/17 18:22:38 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

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

int is_rectangle(char **map)
{
	int row;
	int col;
	int current_row;
	int i;

	row = ft_strlen(map[0]);
	col = ft_matrixlen(map);
	if (col < 3)
		return (FALSE);
	i = 0;
	while (map[i])
	{
		current_row = ft_strlen(map[i]);
		if (current_row == row)
			i++;
		else
			return (FALSE); 
	}
	return (TRUE);
}

int is_enclosed(char **map)
{
	size_t i;
	int j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		if (map[i][j] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (FALSE);
		if (i == 0 || i == (ft_matrixlen(map) - 1))
			while(map[i][j])
			{
				if (map[i][j] != '1')
					return (FALSE);
				j++;	
			}
		i++;
	}
	return (TRUE);
}

static void check_row(char *map, int *collect, int *player, int *exit)
{
	int i;
	
	i = 0;
	while(map[i])
	{
		if (map[i]== 'C')
			(*collect)++;
		if (map[i] == 'P')
			(*player)++;
		if (map[i]== 'E')
			(*exit)++;
		i++;
	}
}

int has_everything(char **map)
{
	int collect;
	int player;
	int exit;
	int i;

	collect = 0;
	player = 0;
	exit = 0;
	i = 0;
	while (map[i])
	{
		check_row(map[i], &collect, &player, &exit);
		i++;
	}
	if (collect < 1 || exit != 1 || player != 1)
		return (FALSE);
	return (TRUE);
}
