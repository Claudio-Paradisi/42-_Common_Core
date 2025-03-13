/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 10:47:48 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/13 18:26:18 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

//da tenere chiude finestra e libera memoria
int on_destroy(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.img);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit(0);
	return (0);
}

//prova eventi
int on_keypress(int keysym, t_game *game)
{
	(void)game;
	printf("Pressed key: %d\n", keysym);
	return (0);
}

//da tenere? disegna pixel su immagine
void draw_pixel(t_my_img *img, int x, int y, int color)
{
	char *dest;

	dest = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}

int	main()
{
	t_game *game;
	
	game = ft_calloc(1, sizeof(t_game));
		game->mlx = mlx_init();
		if(!game->mlx)
		{
			printf("Errore inizializzazione mlx_library\n");
			return 1;
		}	
		game->window = mlx_new_window(game->mlx, 800, 600, "test_mlx_lib");
		if (!game->window)
		{
			printf("Errore creazione finestra\n");
			mlx_destroy_display(game->mlx);
			free(game->mlx);
			free(game);
			return 1;
		}
		
		game->img.img = mlx_new_image(game->mlx, 500, 400);
		game->img.address = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
		for (int i = 0; i < 100; i++)
		{
			if (i < 50)
    			draw_pixel(&game->img, i, 100, 0x00FFFFFF);
			else
				draw_pixel(&game->img, i, 100, get_opposite(0x00FF00FF));
		}
		mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
		
		mlx_hook(game->window, KeyRelease, KeyReleaseMask, &on_keypress, &game);
		mlx_hook(game->window, DestroyNotify, StructureNotifyMask, &on_destroy, game);
		mlx_loop(game->mlx);
	
	return (0);
}