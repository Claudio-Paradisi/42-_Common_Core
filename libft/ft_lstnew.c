/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:31:30 by cparadis          #+#    #+#             */
/*   Updated: 2024/12/23 12:31:54 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
