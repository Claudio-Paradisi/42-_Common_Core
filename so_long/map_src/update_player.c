/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 11:05:16 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/24 16:30:06 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->map->player_x + dx;
	new_y = game->map->player_y + dy;
	if (game->map->grid[new_y][new_x] == '1')
		return ;
	if (game->map->grid[new_y][new_x] == 'C')
	{
		game->map->collectibles--;
		game->map->grid[new_y][new_x] = '0';
	}
	if (game->map->grid[new_y][new_x] == 'E' && game->map->collectibles == 0)
		on_destroy(game);
	if (game->steps > 999)
		on_destroy(game);
	game->map->grid[game->map->player_y][game->map->player_x] = '0';
	game->map->player_x = new_x;
	game->map->player_y = new_y;
	game->map->grid[new_y][new_x] = 'P';
	game->steps++;
	draw_background(game);
}
