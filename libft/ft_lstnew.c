
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*buffer;

	buffer = malloc(sizeof(t_list));
	if (!buffer)
		return (NULL);
	buffer->content = content;
	buffer->next = NULL;

	return (buffer);
}
