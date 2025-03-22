/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 10:47:48 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/22 18:03:51 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

/*int on_expose(t_game *game)
{
    ft_printf("Expose event!\n");
    draw_background(game); // Ridisegna lo sfondo se necessario
    return (0);
}*/

void init_game(t_game *game, char *av)
{
	game->mlx = mlx_init();
	if(!game->mlx)
	{
		ft_printf("Errore inizializzazione mlx_library\n");
		free(game);
		exit (1);
	}
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
        free(game);
        ft_printf("Memory allocation error\n");
		exit(1);
    }
	init_map(game, av);
	ft_memset(&game->assets, 0, sizeof(t_assets));
}

int	main(int ac, char **av)
{
	t_game *game;
	
	if (ac != 2)
		return(ft_printf("argument number not valid!\n"));
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (ft_printf("Memory allocation error\n"));
	init_game(game, av[1]);
	game->window = mlx_new_window(game->mlx, game->map->width * TILE_SIZE, 
		game->map->height * TILE_SIZE, "test_map");
	if (!game->window)
	{
		ft_printf("Errore: mlx_new_window ha restituito NULL\n");
		exit(1);
	}
	load_assets(game);
	draw_background(game);
	//mlx_hook(game->window, Expose, ExposureMask, &on_expose, game);
	mlx_hook(game->window, KeyRelease, KeyReleaseMask, &handle_keypress, game);
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask, &on_destroy, game);
	mlx_loop(game->mlx);
	return (0);
}