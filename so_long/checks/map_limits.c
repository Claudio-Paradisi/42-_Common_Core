/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_limits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:46:40 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/24 16:57:57 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	within_max_width(char **map)
{
	if (ft_strlen(map[0]) > 1000)
		return (FALSE);
	return (TRUE);
}

int	within_max_height(char **map)
{
	if (ft_matrixlen(map) > 80)
		return (FALSE);
	return (TRUE);
}
