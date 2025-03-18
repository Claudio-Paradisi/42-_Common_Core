/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:59:26 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/17 14:56:33 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//funzioni per creare colori con bitwise

#include "header/so_long.h"

int crate_trgb(int t, int red, int green, int blue)
{
	return (t << 24 | red << 16 | green << 8 | blue);
}

int get_trgb(int trgb, char color)
{
	if (color == 't')
		return ((trgb >> 24) & 0xFF);
	if (color == 'r')
		return ((trgb >> 16) & 0xFF);
	if (color == 'g')
		return ((trgb >> 8) & 0xFF);
	else
		return (trgb & 0xFF);
}

int add_shade(double distance, int color)
{
	int t;
	int r;
	int g;
	int	b;
	
	t = get_trgb(color, 't');
	r = get_trgb(color, 'r') * (1 - distance);
	g = get_trgb(color, 'g') * (1 - distance);
	b = get_trgb(color, 'b') * (1 - distance);
	return (crate_trgb(t, r, g, b));
}

int get_opposite(int color)
{
	int t;
	int r;
	int g;
	int	b;
	
	t = get_trgb(color, 't');
	r = 255 - get_trgb(color, 'r');
	g = 255 - get_trgb(color, 'g');
	b = 255 - get_trgb(color, 'b');
	return (crate_trgb(t, r, g, b));
}
//da tenere? disegna pixel su immagine
void draw_pixel(t_my_img *img, int x, int y, int color)
{
	char *dest;

	dest = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}