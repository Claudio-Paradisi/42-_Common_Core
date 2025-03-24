/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:10:07 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/24 14:47:00 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_matrixdup(char **matrix)
{
	int		i;
	char	**copy;

	if (!matrix)
		return (NULL);
	i = 0;
	copy = ft_calloc(ft_matrixlen(matrix) + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	while (matrix[i])
	{
		copy[i] = ft_strdup(matrix[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
