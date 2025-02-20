/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:57:51 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/20 18:56:39 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

static void 	fill_node(t_list **a, int nbr)
{
	t_list *node;
	t_list *last_node;
	
	if (!a)
		return ;
	node = malloc(sizeof(t_list));
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

static void		init_list(t_list **a, char **av, int check)
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

int		main(int ac, char **av)
{
	t_list *a;
	//t_list *b;

	a = NULL;
	//b = NULL;
	ft_printf("inzio programma\n");
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
	{
		ft_printf("entro in if se 2 argomenti\n");
		av = ft_split(av[1], ' ');
		if (!av)
		{
			free_matrix(av);
			ft_printf("error creating the matrix");
			return (1);
		}
		ft_printf("se non esco il problema é in init\n");
		init_list(&a, av, TRUE);
		free_matrix(av);
		ft_printf("esco da if\n");
	}
	else
	{
		ft_printf("entro in init\n");
		init_list(&a, (av + 1),FALSE);
		ft_printf("esco da init init\n");
	}
	ft_printf("%d\n", a->nbr);
	//check it works
	/*while (a)
	{
		ft_printf("%d\n", a->nbr);
		a = a->next;
	}
	if (ac == 2)*/
		
	free_list(&a);
	return (0);
}