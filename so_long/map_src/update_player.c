/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 11:05:16 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/25 11:39:08 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	message_destroy(t_game *game, int check)
{
	if (check)
	{
		ft_printf("Congratulation!!\nYou won!!\n");
		on_destroy(game);
	}
	else
	{
		ft_printf("Game Over!\nToo many steps!\n");
		on_destroy(game);
	}
}

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
		message_destroy(game, TRUE);
	if (game->steps > 420)
		message_destroy(game, FALSE);
	game->map->grid[game->map->player_y][game->map->player_x] = '0';
	game->map->player_x = new_x;
	game->map->player_y = new_y;
	game->map->grid[new_y][new_x] = 'P';
	game->steps++;
	draw_background(game);
}
