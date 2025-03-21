/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:50:05 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/21 19:26:02 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static void    load_asset(t_game *game, t_my_img *img, char *path)
{
    int width;
    int height;

    ft_printf("7a\n");
    img->img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
    if (!img->img)
    {
        ft_printf("error failed to load image: %s\n", path);
        on_destroy(game);
    }
    img->address = mlx_get_data_addr(img->img, &img->bits_per_pixel,
                                    &img->line_length, &img->endian);
}

void    load_assets(t_game *game)
{
    load_asset(game, &game->assets.background,
    "assets/images/grass/Grass.xpm");
    load_asset(game, &game->assets.grass,
    "assets/images/grass/Background32.xpm");
    load_asset(game, &game->assets.player,
    "assets/images/player/PlayerS.xpm");
    load_asset(game, &game->assets.wall,
    "assets/images/wall/WallBush32.xpm");
    load_asset(game, &game->assets.collect,
    "assets/images/collect/Collectable32.xpm");
    load_asset(game, &game->assets.exit,
    "assets/images/exit/Exit32(1).xpm");
    /*
    / da richiamare anche per altre img
    */
}

static void draw_assets(t_game *game, int *x, int *y)
{
    if (game->map->grid[*y][*x] == '1')
        mlx_put_image_to_window(game->mlx, game->window,
        game->assets.wall.img, *(x) * TILE_SIZE, *(y) * TILE_SIZE);
    if (game->map->grid[*y][*x] == 'C')
        mlx_put_image_to_window(game->mlx, game->window,
        game->assets.collect.img, *(x) * TILE_SIZE, *(y) * TILE_SIZE);
    if (game->map->grid[*y][*x] == 'E')
        mlx_put_image_to_window(game->mlx, game->window,
        game->assets.exit.img, *(x) * TILE_SIZE, *(y) * TILE_SIZE);
    if (game->map->grid[*y][*x] == 'P')
        mlx_put_image_to_window(game->mlx, game->window,
        game->assets.player.img, *(x) * TILE_SIZE, *(y) * TILE_SIZE);
}

void draw_background(t_game *game)
{
    int x;
    int y;

    y = 0;
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