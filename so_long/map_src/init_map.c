/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:48:42 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/19 16:07:11 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int count_elements(t_map *map)
{
    int y;
    int x;

    y = 0;
    while (map->grid[y])
    {
        x = 0;
        while (map->grid[y][x])
        {
            if(map->grid[y][x] == 'C')
                map->collectibles++;
             if(map->grid[y][x] == 'E')
                map->exits++;
            if(map->grid[y][x] == 'P')
            {
                map->player_x = x;
                map->player_y = y;
            }
            x++;
        }
        y++;
    }
}

void init_map(t_game *game, char *av)
{
    ft_printf("3\n");
    game->map->grid = read_map(av);
    ft_printf("4\n");
    if (!is_map_playable(game->map->grid))
    {
        on_destroy(game);
        ft_printf("errore mappa non giocabile");
        exit(1);
    }
    game->map->width = ft_strlen(game->map->grid[0]);
    game->map->height = ft_matrixlen(game->map->grid);
}