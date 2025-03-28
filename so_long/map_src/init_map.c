/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:48:42 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/25 11:26:26 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	count_elements(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (map->grid[++y])
	{
		x = -1;
		while (map->grid[y][++x])
		{
			if (map->grid[y][x] == 'C')
				map->collectibles++;
			if (map->grid[y][x] == 'E')
			{
				map->exit_x = x;
				map->exit_y = y;
				map->exits++;
			}
			if (map->grid[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
			}
		}
	}
}

void	init_map(t_game *game, char *av)
{
	game->map->grid = NULL;
	game->map->grid = read_map(av);
	if (!is_map_playable(game->map->grid) || !is_dot_ber(av))
	{
		ft_printf("Error\nMap is not playable\n");
		on_destroy(game);
		exit(1);
	}
	game->map->width = ft_strlen(game->map->grid[0]);
	game->map->height = ft_matrixlen(game->map->grid);
	game->map->collectibles = 0;
	game->map->exits = 0;
	game->map->player_x = 0;
	game->map->player_y = 0;
	game->map->key_dir = DOWN;
	game->map->exit_x = 0;
	game->map->exit_y = 0;
	count_elements(game->map);
}
