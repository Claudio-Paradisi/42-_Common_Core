/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 10:47:48 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/20 15:17:59 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

//da tenere chiude finestra e libera memoria
int on_destroy(t_game *game)
{
	ft_printf("finestra chiusa");
	if (game->assets.background.img)
		mlx_destroy_image(game->mlx, game->assets.background.img);
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
	game->window = mlx_new_window(game->mlx, game->map->width * TILE_SIZE, 
		game->map->height * TILE_SIZE, "test_map");
	ft_printf("6\n");
	load_assets(game);
	ft_printf("7\n");
	draw_background(game);
	ft_printf("8\n");
		/*game->img.img = mlx_new_image(game->mlx, 500, 400);
		game->img.address = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
		for (int i = 0; i < 100; i++)
		{
			if (i < 50)
    			draw_pixel(&game->img, i, 100, 0x00FFFFFF);
			else
				draw_pixel(&game->img, i, 100, get_opposite(0x00FF00FF));
		}
		mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
		
		mlx_hook(game->window, KeyRelease, KeyReleaseMask, &on_keypress, game);
		mlx_hook(game->window, EnterNotify, EnterWindowMask, &on_in ,game);*/
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask, &on_destroy, game);
	mlx_loop(game->mlx);
	return (0);
}