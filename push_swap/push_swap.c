/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:57:51 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/01 16:59:13 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

static void	fill_node(t_list **a, int nbr)
{
	t_list	*node;
	t_list	*last_node;

	if (!a)
		return ;
	node = ft_calloc(1, sizeof(t_list));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = nbr;
	node->cheapest = FALSE;
	if (!(*a))
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_lstlast(*a);
		last_node->next = node;
		node->prev = last_node;
	}
}

static void	init_list(t_list **a, char **av, int check)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (syntax_error(av[i]))
			ft_error(a, "Syntax error!", check, av);
		nbr = ft_atol(av[i]);
		if (has_double(*a, nbr) || has_overflow(nbr))
			ft_error(a, "Error! overflow or a double numbers!", check, av);
		fill_node(a, (int)nbr);
		i++;
	}
}

static void	algorithm(t_list **a, t_list **b)
{
	if (is_sorted(a))
		return ;
	if (ft_lstsize(*a) == 2)
		sort_two(a);
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	else
		turk_algo(a, b);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (!av)
		{
			free_matrix(av);
			ft_printf("error creating the matrix");
			return (1);
		}
		init_list(&a, av, TRUE);
		free_matrix(av);
	}
	else
		init_list(&a, (av + 1), FALSE);
	algorithm(&a, &b);
	free_list(&a);
	return (0);
}
