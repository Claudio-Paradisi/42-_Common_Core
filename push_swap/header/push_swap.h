/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:44:34 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/26 14:02:43 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <limits.h>

# define FALSE 0
# define TRUE 1

typedef struct s_list
{
	int				nbr;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

void				*ft_calloc(size_t nmemb, size_t size);
char				**ft_split(const char *s, char c);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
int					ft_issign(int c);
int					ft_isdigit(int c);
int					ft_isspace(int c);
long				ft_atol(char *str);

int					syntax_error(char *str);
int					has_double(t_list *a, long nbr);
int					has_overflow(long nbr);
void				free_matrix(char **matrix);
void				free_list(t_list **list);
void				ft_error(t_list **a, char *str, int check, char **av);

void				pa(t_list **a, t_list **b);
void				pb(t_list **b, t_list **a);
void				sa(t_list **a);
void				sb(t_list **b);
void				ss(t_list **a, t_list **b);
void				ra(t_list **a);
void				rb(t_list **b);
void				rr(t_list **a, t_list **b);
void				rra(t_list **a);
void				rrb(t_list **b);
void				rrr(t_list **a, t_list **b);

int					is_sorted(t_list **list);
t_list				*max_node(t_list **list);
void				sort_two(t_list **a);
void				sort_three(t_list **a);
#endif