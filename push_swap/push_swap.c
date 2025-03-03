/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:57:51 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/03 17:58:42 by cparadis         ###   ########.fr       */
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

static void handle_arguments(t_list **a, char *str)
{
	char **matrix;
	long nbr;
	int	i;

	i = 0;
	matrix = ft_split(str, ' ');
	if (!matrix)
		ft_error(a, "matrix creation failed", 1, matrix);
	while (matrix[i])
	{
		if (syntax_error(matrix[i]))
				ft_error(a, "Syntax error!", 1, matrix);
		nbr = ft_atol(matrix[i]);
		if (has_double(*a, nbr) || has_overflow(nbr))
			ft_error(a, "Error! overflow or a double numbers!", 1, matrix);
		fill_node(a, (int)nbr);
		i++;
	}
	free_matrix(matrix);
}

static void	init_list(t_list **a, char **av)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (ft_strchr(av[i], ' '))
			handle_arguments(a, av[i]);
		else
		{
			if (syntax_error(av[i]))
				ft_error(a, "Syntax error!", 0, av);
			nbr = ft_atol(av[i]);
			if (has_double(*a, nbr) || has_overflow(nbr))
				ft_error(a, "Error! overflow or a double numbers!", 0, av);
			fill_node(a, (int)nbr);
		}
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
	init_list(&a, (av + 1));
	algorithm(&a, &b);
	/*//prova visiva codice
	t_list *temp = a;
	while (temp)
	{
		ft_printf("%d\n", temp->nbr);
		temp = temp->next;
	}*/
	free_list(&a);
	return (0);
}
