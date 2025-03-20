/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:50:05 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/20 15:59:25 by cparadis         ###   ########.fr       */
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
    "assets/images/grass/grass64.xpm");
    /*
    / da richiamare anche per altre img
    */
}

void draw_background(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < (game->map->height * TILE_SIZE))
    {
        x = 0;
        while (x < (game->map->width * TILE_SIZE))
        {
            mlx_put_image_to_window(game->mlx, game->window,
            game->assets.background.img, x, y);
            x += TILE_SIZE;
        }
        y += TILE_SIZE;
    }
}