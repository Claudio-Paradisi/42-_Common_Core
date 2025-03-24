/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_steps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:01:57 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/24 14:59:22 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static void	number_condition(t_game *game, int *x, int *y, int steps)
{
	if (steps % 10 == 4)
		mlx_put_image_to_window(game->mlx, game->window, game->assets.four.img,
			*(x) * TILE_SIZE, *(y) * TILE_SIZE);
	if (steps % 10 == 5)
		mlx_put_image_to_window(game->mlx, game->window, game->assets.five.img,
			*(x) * TILE_SIZE, *(y) * TILE_SIZE);
	if (steps % 10 == 6)
		mlx_put_image_to_window(game->mlx, game->window, game->assets.six.img,
			*(x) * TILE_SIZE, *(y) * TILE_SIZE);
	if (steps % 10 == 7)
		mlx_put_image_to_window(game->mlx, game->window, game->assets.seven.img,
			*(x) * TILE_SIZE, *(y) * TILE_SIZE);
	if (steps % 10 == 8)
		mlx_put_image_to_window(game->mlx, game->window, game->assets.eight.img,
			*(x) * TILE_SIZE, *(y) * TILE_SIZE);
	if (steps % 10 == 9)
		mlx_put_image_to_window(game->mlx, game->window, game->assets.nine.img,
			*(x) * TILE_SIZE, *(y) * TILE_SIZE);
}

void	draw_units(t_game *game, int *x, int *y, int steps)
{
	if (steps % 10 == 0)
		mlx_put_image_to_window(game->mlx, game->window, game->assets.zero.img,
			*(x) * TILE_SIZE, *(y) * TILE_SIZE);
	if (steps % 10 == 1)
		mlx_put_image_to_window(game->mlx, game->window, game->assets.one.img,
			*(x) * TILE_SIZE, *(y) * TILE_SIZE);
	if (steps % 10 == 2)
		mlx_put_image_to_window(game->mlx, game->window, game->assets.two.img,
			*(x) * TILE_SIZE, *(y) * TILE_SIZE);
	if (steps % 10 == 3)
		mlx_put_image_to_window(game->mlx, game->window, game->assets.three.img,
			*(x) * TILE_SIZE, *(y) * TILE_SIZE);
	number_condition(game, x, y, steps);
}

void	draw_steps(t_game *game, int *x, int *y)
{
	int	steps;
	int	i;

	i = *x;
	steps = game->steps;
	if ((*y != game->map->height - 1) || i != game->map->width - 1)
		return ;
	if (steps == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->assets.zero.img,
			*(x) * TILE_SIZE, *(y) * TILE_SIZE);
		return ;
	}
	while (steps)
	{
		draw_units(game, &i, y, steps);
		steps /= 10;
		i--;
	}
}
