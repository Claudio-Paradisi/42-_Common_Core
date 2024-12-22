
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;
	
	if (!new)
		return ;
	current = ft_lstlast(*lst);
	if (!current)
	{
		*lst = new;
		return ;
	}
	current->next = new;
}
