/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:01:35 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/24 14:45:19 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_floodfill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	ft_floodfill(map, x + 1, y);
	ft_floodfill(map, x - 1, y);
	ft_floodfill(map, x, y + 1);
	ft_floodfill(map, x, y - 1);
}
