/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 10:49:22 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/24 15:53:54 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/libft/libft.h"
# include "../includes/minilibx-linux/mlx.h"
# include "../includes/minilibx-linux/mlx_int.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define FALSE 0
# define TRUE 1

# define TILE_SIZE 32

# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			player_x;
	int			player_y;
	int			collectibles;
	int			exits;
	int			key_dir;
	int			exit_x;
	int			exit_y;
}				t_map;

typedef struct s_my_img
{
	void		*img;
	char		*address;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_my_img;

typedef struct s_assets
{
	t_my_img	grass;
	t_my_img	background;
	t_my_img	wall;
	t_my_img	collect;
	t_my_img	exit;
	t_my_img	player_up;
	t_my_img	player_down;
	t_my_img	player_left;
	t_my_img	player_right;
	t_my_img	zero;
	t_my_img	one;
	t_my_img	two;
	t_my_img	three;
	t_my_img	four;
	t_my_img	five;
	t_my_img	six;
	t_my_img	seven;
	t_my_img	eight;
	t_my_img	nine;
}				t_assets;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			steps;
	t_map		*map;
	t_assets	assets;
}				t_game;

char			**read_map(char *file);
int				is_rectangle(char **map);
int				is_enclosed(char **map);
int				has_everything(char **map);
int				is_map_solvable(char **map);
int				is_map_playable(char **map);
int				is_dot_ber(char *av);
int				within_max_width(char **map);
int				within_max_height(char **map);

void			init_map(t_game *game, char *av);
void			load_assets(t_game *game);
void			load_asset(t_game *game, t_my_img *img, char *path);
void			load_numbers(t_game *game);

void			draw_background(t_game *game);
void			draw_steps(t_game *game, int *x, int *y);
void			move_player(t_game *game, int dx, int dy);

int				on_destroy(t_game *game);
int				handle_keypress(int keycode, t_game *game);
#endif