/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 10:01:38 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/22 10:21:59 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
		on_destroy(game);
	else if (keycode == W || keycode == UP)
		move_player(game, 0, -1);
	else if (keycode == S || keycode == DOWN)
		move_player(game, 0, 1);
	else if (keycode == A || keycode == LEFT)
		move_player(game, -1, 0);
	else if (keycode == D|| keycode == RIGHT)
		move_player(game, 1, 0);
	return (0);
}