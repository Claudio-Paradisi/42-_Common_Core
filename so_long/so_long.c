/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 10:47:48 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/21 19:59:39 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

//da tenere chiude finestra e libera memoria
int on_destroy(t_game *game)
{
	ft_printf("finestra chiusa");
	if (game->assets.background.img)
		mlx_destroy_image(game->mlx, game->assets.background.img);
	if (game->assets.grass.img)
		mlx_destroy_image(game->mlx, game->assets.grass.img);
	if (game->assets.wall.img)
		mlx_destroy_image(game->mlx, game->assets.wall.img);
	if (game->assets.collect.img)
		mlx_destroy_image(game->mlx, game->assets.collect.img);
	if (game->assets.player.img)
		mlx_destroy_image(game->mlx, game->assets.player.img);
	if (game->assets.exit.img)
		mlx_destroy_image(game->mlx, game->assets.exit.img);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	if (game->map)
	{
		if(game->map->grid)
			ft_freematrix(game->map->grid);
		free(game->map);
	}
	free(game->mlx);
	free(game);
	exit(1);
	return (0);
}

/*int on_hide(t_game *game)
{
    (void)game;
   	ft_strput("hai nascosto la finestra");
    return (0);
}

int on_in(t_game *game)
{
	(void)game;
	ft_strput("you are inside the window");
	return (0);
}

//prova eventi
int on_keypress(int key, t_game *game)
{
	//(void)game;
	if (key == 65307)
		on_destroy(game);
	return (0);
}
*/

void init_game(t_game *game, char *av)
{
	
	game->mlx = mlx_init();
	if(!game->mlx)
	{
		printf("Errore inizializzazione mlx_library\n");
		return ;
	}
	game->window = NULL;
	ft_printf("2\n");
	game->map = ft_calloc(1, sizeof(t_map));
	init_map(game, av);
	ft_printf("5\n");
	/*
	if (!game->window)
	{
		printf("Errore creazione finestra\n");
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free(game);
		return 1;
	}*/
}
int	main(int ac, char **av)
{
	t_game *game;
	
	if (ac != 2)
		return(ft_printf("argument number not valid!\n"));
	ft_printf("1\n");
	game = ft_calloc(1, sizeof(t_game));
	init_game(game, av[1]);
	ft_printf("game->mlx: %p\n", game->mlx);
	ft_printf("Map Width: %d, Map Height: %d\n", game->map->width, game->map->height);
	game->window = mlx_new_window(game->mlx, game->map->width * TILE_SIZE, 
		game->map->height * TILE_SIZE, "test_map");
	ft_printf("game->window: %p\n", game->window);
	ft_printf("6\n");
	load_assets(game);
	ft_printf("7\n");
	draw_background(game);
	ft_printf("8\n");
		
		
		/*mlx_hook(game->window, KeyRelease, KeyReleaseMask, &on_keypress, game);
		mlx_hook(game->window, EnterNotify, EnterWindowMask, &on_in ,game);*/
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask, &on_destroy, game);
	mlx_loop(game->mlx);
	return (0);
}