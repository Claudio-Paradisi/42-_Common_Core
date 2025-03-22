/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 10:03:27 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/22 19:44:28 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static void destroy_player(t_game *game)
{
	if (game->assets.player_right.img)
		mlx_destroy_image(game->mlx, game->assets.player_right.img);
	if (game->assets.player_left.img)
		mlx_destroy_image(game->mlx, game->assets.player_left.img);
	if (game->assets.player_up.img)
		mlx_destroy_image(game->mlx, game->assets.player_up.img);
	if (game->assets.player_down.img)
		mlx_destroy_image(game->mlx, game->assets.player_down.img);
}

static void destroy_image(t_game *game)
{
	if (game->assets.background.img)
		mlx_destroy_image(game->mlx, game->assets.background.img);
	if (game->assets.grass.img)
		mlx_destroy_image(game->mlx, game->assets.grass.img);
	if (game->assets.wall.img)
		mlx_destroy_image(game->mlx, game->assets.wall.img);
	if (game->assets.collect.img)
		mlx_destroy_image(game->mlx, game->assets.collect.img);
	if (game->assets.exit.img)
		mlx_destroy_image(game->mlx, game->assets.exit.img);
	destroy_player(game);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
}

static void destroy_map(t_game *game)
{
	if (game->map)
	{
		if(game->map->grid)
			ft_freematrix(game->map->grid);
		free(game->map);
	}
}

int on_destroy(t_game *game)
{
	ft_printf("finestra chiusa\n");
	destroy_image(game);
	mlx_destroy_display(game->mlx);
	destroy_map(game);
	free(game->mlx);
	free(game);
	exit(0);
	return (0);
}