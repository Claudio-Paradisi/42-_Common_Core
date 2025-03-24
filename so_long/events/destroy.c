/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 10:03:27 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/24 14:39:50 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static void	destroy_player(t_game *game)
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

static void	destroy_numbers(t_game *game)
{
	if (game->assets.zero.img)
		mlx_destroy_image(game->mlx, game->assets.zero.img);
	if (game->assets.one.img)
		mlx_destroy_image(game->mlx, game->assets.one.img);
	if (game->assets.two.img)
		mlx_destroy_image(game->mlx, game->assets.two.img);
	if (game->assets.three.img)
		mlx_destroy_image(game->mlx, game->assets.three.img);
	if (game->assets.four.img)
		mlx_destroy_image(game->mlx, game->assets.four.img);
	if (game->assets.five.img)
		mlx_destroy_image(game->mlx, game->assets.five.img);
	if (game->assets.six.img)
		mlx_destroy_image(game->mlx, game->assets.six.img);
	if (game->assets.seven.img)
		mlx_destroy_image(game->mlx, game->assets.seven.img);
	if (game->assets.eight.img)
		mlx_destroy_image(game->mlx, game->assets.eight.img);
	if (game->assets.nine.img)
		mlx_destroy_image(game->mlx, game->assets.nine.img);
}

static void	destroy_image(t_game *game)
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
	destroy_numbers(game);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
}

static void	destroy_map(t_game *game)
{
	if (game->map)
	{
		if (game->map->grid)
			ft_freematrix(game->map->grid);
		free(game->map);
	}
}

int	on_destroy(t_game *game)
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
