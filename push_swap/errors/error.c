/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:04:54 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/03 18:03:46 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	syntax_error(char *str)
{
	if (!ft_isdigit(*str) && !ft_issign(*str))
		return (TRUE);
	if (ft_issign(*str) && !ft_isdigit(*(str + 1)))
		return (TRUE);
	str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (TRUE);
		str++;
	}
	return (FALSE);
}

int	has_double(t_list *a, long nbr)
{
	t_list	*temp;

	temp = a;
	while (temp)
	{
		if (temp->nbr == nbr)
			return (TRUE);
		temp = temp->next;
	}
	return (FALSE);
}

int	has_overflow(long nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (TRUE);
	return (FALSE);
}

void	ft_error(t_list **a, char *str, int check, char **av)
{
	if (check)
		free_matrix(av);
	free_list(a);
	ft_printf("%s\n", str);
	exit(1);
}
