/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 10:47:48 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/24 17:58:49 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

void	init_game(t_game *game, char *av)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error\nmlx_library not inizialized\n");
		free(game);
		exit (1);
	}
	game->steps = 0;
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free(game);
		ft_printf("Error\nMemory allocatio\n");
		exit(1);
	}
	init_map(game, av);
	ft_memset(&game->assets, 0, sizeof(t_assets));
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (ft_printf("Error\nArgument number not valid!\n"));
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (ft_printf("Error\nMemory allocation error\n"));
	init_game(game, av[1]);
	game->window = mlx_new_window(game->mlx, game->map->width * TILE_SIZE,
			game->map->height * TILE_SIZE, "so_long");
	if (!game->window)
	{
		ft_printf("Error\n mlx_new_window returned NULL\n");
		exit(1);
	}
	load_assets(game);
	draw_background(game);
	mlx_hook(game->window, KeyRelease, KeyReleaseMask, &handle_keypress, game);
	mlx_hook(game->window, DestroyNotify,
		StructureNotifyMask, &on_destroy, game);
	mlx_loop(game->mlx);
	return (0);
}
