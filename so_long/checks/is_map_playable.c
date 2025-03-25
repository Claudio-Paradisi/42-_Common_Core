/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_playable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:59:38 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/25 14:33:40 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static int	check_collect_and_exit(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
			{
				ft_freematrix(map);
				return (FALSE);
			}
			x++;
		}
		y++;
	}
	ft_freematrix(map);
	return (TRUE);
}

int	is_map_solvable(char **map)
{
	int		x;
	int		y;
	int		result;
	char	**map_copy;

	map_copy = ft_matrixdup(map);
	if (!map_copy)
		return (FALSE);
	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == 'P')
				ft_floodfill(map_copy, x, y);
			x++;
		}
		y++;
	}
	result = check_collect_and_exit(map_copy);
	return (result);
}

int	is_dot_ber(char *av)
{
	if (ft_strncmp(ft_strrchr(av, '.'), ".ber", 4) != 0)
		return (FALSE);
	return (TRUE);
}

int	has_right_chars(char **map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
			if (c != '0' && c != '1' && c != 'P' && c != 'E'
				&& c != 'C')
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	is_map_playable(char **map)
{
	if (!has_right_chars(map) || !is_enclosed(map) || !is_rectangle(map)
		|| !has_everything(map) || !is_map_solvable(map))
		return (FALSE);
	if (!within_max_height(map) || !within_max_width(map))
		return (FALSE);
	return (TRUE);
}
