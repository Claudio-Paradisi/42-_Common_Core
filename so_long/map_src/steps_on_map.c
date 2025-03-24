/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_on_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:07:00 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/24 16:29:05 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	load_numbers(t_game *game)
{
	load_asset(game, &game->assets.zero, "assets/images/numbers/0.32.xpm");
	load_asset(game, &game->assets.one, "assets/images/numbers/1.32.xpm");
	load_asset(game, &game->assets.two, "assets/images/numbers/2.32.xpm");
	load_asset(game, &game->assets.three, "assets/images/numbers/3.32.xpm");
	load_asset(game, &game->assets.four, "assets/images/numbers/4.32.xpm");
	load_asset(game, &game->assets.five, "assets/images/numbers/5.32.xpm");
	load_asset(game, &game->assets.six, "assets/images/numbers/6.32.xpm");
	load_asset(game, &game->assets.seven, "assets/images/numbers/7.32.xpm");
	load_asset(game, &game->assets.eight, "assets/images/numbers/8.32.xpm");
	load_asset(game, &game->assets.nine, "assets/images/numbers/9.32.xpm");
}
