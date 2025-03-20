/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 10:49:22 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/20 15:59:25 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/minilibx-linux/mlx.h"
#include "../includes/minilibx-linux/mlx_int.h"
# include "../includes/libft/libft.h"

#define FALSE 0
#define TRUE 1

#define TILE_SIZE	64

typedef struct s_map
{
    char **grid;  
    int width;    
    int height;   
    int player_x; 
    int player_y; 
    int collectibles; 
    int exits;    
}               t_map;

typedef struct s_my_img
{
	void *img;
	char *address;
	int bits_per_pixel;
	int line_length;
	int endian;
}				t_my_img;

typedef struct s_assets
{
	t_my_img background;
	t_my_img wall;
	t_my_img collect;
	t_my_img exit;
	t_my_img player;
}				t_assets;


typedef struct s_game
{
	void *mlx;
	void *window;
	t_map *map;
	t_assets assets;
}				t_game;


void		*ft_calloc(size_t nmemb, size_t size);
int			crate_trgb(int t, int red, int green, int blue);
int 		get_trgb(int trgb, char color);
int			add_shade(double distance, int color);
int			get_opposite(int color);

char 		**read_map(char *file);
int 		is_rectangle(char **map);
int 		is_enclosed(char **map);
int 		has_everything(char **map);
int 		is_map_solvable(char **map);
int			is_map_playable(char **map);

void 		init_map(t_game *game, char *av);
void    	load_assets(t_game *game);
void 		draw_background(t_game *game);

int 		on_destroy(t_game *game);
#endif