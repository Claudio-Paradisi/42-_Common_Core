/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:27:27 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/19 14:42:18 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}
char	*ft_strdup(char *src)
{
	char	*buffer;
	size_t	len;
	int	i;
	
	if (!src)
		return (NULL);
	len = ft_strlen(src);
	buffer = (char *)malloc(len + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while(src[i])
	{
		buffer[i] = src[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

/*int	main()
{
	char *s1 = NULL;
	char *miastr = ft_strdup(s1);
	char *origstr =  strdup(s1);
	printf("mia funzione: %s\n", miastr);
	printf("funzione originale: %s\n", origstr);
	free(miastr);
	free(origstr);
	return 0;
}*/

