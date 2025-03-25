/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:50:05 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/25 11:24:34 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	load_asset(t_game *game, t_my_img *img, char *path)
{
	int	width;
	int	height;

	img->img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!img->img)
	{
		ft_printf("Error\nfailed to load image: %s\n", path);
		on_destroy(game);
	}
	img->address = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	load_assets(t_game *game)
{
	load_asset(game, &game->assets.background, "assets/images/grass/Grass.xpm");
	load_asset(game, &game->assets.grass,
		"assets/images/grass/Background32.xpm");
	load_asset(game, &game->assets.player_right,
		"assets/images/player/PlayerR.xpm");
	load_asset(game, &game->assets.player_left,
		"assets/images/player/PlayerL.xpm");
	load_asset(game, &game->assets.player_up,
		"assets/images/player/PlayerU.xpm");
	load_asset(game, &game->assets.player_down,
		"assets/images/player/PlayerD.xpm");
	load_asset(game, &game->assets.wall, "assets/images/wall/WallBush32.xpm");
	load_asset(game, &game->assets.collect,
		"assets/images/collect/Collectable32.xpm");
	load_asset(game, &game->assets.exit, "assets/images/exit/Exit32(1).xpm");
	load_numbers(game);
}

static void	draw_player(t_game *game, int *x, int *y)
{
	if (game->map->grid[*y][*x] == 'P')
	{
		if (game->map->key_dir == RIGHT || game->map->key_dir == D)
			mlx_put_image_to_window(game->mlx, game->window,
				game->assets.player_right.img,
				*(x) * TILE_SIZE, *(y) * TILE_SIZE);
		else if (game->map->key_dir == LEFT || game->map->key_dir == A)
			mlx_put_image_to_window(game->mlx, game->window,
				game->assets.player_left.img,
				*(x) * TILE_SIZE, *(y) * TILE_SIZE);
		else if (game->map->key_dir == UP || game->map->key_dir == W)
			mlx_put_image_to_window(game->mlx, game->window,
				game->assets.player_up.img,
				*(x) * TILE_SIZE, *(y) * TILE_SIZE);
		else if (game->map->key_dir == DOWN || game->map->key_dir == S)
			mlx_put_image_to_window(game->mlx, game->window,
				game->assets.player_down.img,
				*(x) * TILE_SIZE, *(y) * TILE_SIZE);
	}
}

static void	draw_assets(t_game *game, int *x, int *y)
{
	if (game->map->grid[*y][*x] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->assets.wall.img,
			*(x) * TILE_SIZE, *(y) * TILE_SIZE);
	if (game->map->grid[*y][*x] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->assets.collect.img, *(x) * TILE_SIZE, *(y) * TILE_SIZE);
	if (game->map->grid[*y][*x] == 'E' && game->map->collectibles == 0)
		mlx_put_image_to_window(game->mlx, game->window, game->assets.exit.img,
			*(x) * TILE_SIZE, *(y) * TILE_SIZE);
	draw_player(game, x, y);
	draw_steps(game, x, y);
}

void	draw_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	if (game->map->grid[game->map->exit_y][game->map->exit_x] != 'P')
		game->map->grid[game->map->exit_y][game->map->exit_x] = 'E';
	while (y < (game->map->height))
	{
		x = 0;
		while (x < (game->map->width))
		{
			if ((x) % 2 == 0 && (y - 1) % 3 == 0)
				mlx_put_image_to_window(game->mlx, game->window,
					game->assets.grass.img, x * TILE_SIZE, y * TILE_SIZE);
			else if ((x) % 3 == 0 && (y) % 3 == 0)
				mlx_put_image_to_window(game->mlx, game->window,
					game->assets.grass.img, x * TILE_SIZE, y * TILE_SIZE);
			else
				mlx_put_image_to_window(game->mlx, game->window,
					game->assets.background.img, x * TILE_SIZE, y * TILE_SIZE);
			draw_assets(game, &x, &y);
			x++;
		}
		y++;
	}
}
