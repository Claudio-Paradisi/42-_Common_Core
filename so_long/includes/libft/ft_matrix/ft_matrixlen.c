/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:34:01 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/17 18:01:56 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t ft_matrixlen(char **matrix)
{
	size_t	i;
	
	i = 0;
	while (matrix[i])
		i++;
	return (i);
}