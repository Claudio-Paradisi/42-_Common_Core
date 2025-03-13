/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 10:49:22 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/13 18:22:14 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"

typedef struct s_my_img
{
	void *img;
	char *address;
	int bits_per_pixel;
	int line_length;
	int endian;
}				t_my_img;

typedef struct s_game
{
	void *mlx;
	void *window;
	t_my_img img;
}				t_game;


void	*ft_calloc(size_t nmemb, size_t size);
int crate_trgb(int t, int red, int green, int blue);
int get_trgb(int trgb, char color);
int add_shade(double distance, int color);
int get_opposite(int color);

#endif