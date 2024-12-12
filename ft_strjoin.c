/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:26:07 by cparadis          #+#    #+#             */
/*   Updated: 2024/12/12 17:52:05 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	unsigned int 	len;
	unsigned int	i;
	
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	buffer = (char *)malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (i++ < ft_strlen(s1))
		buffer[i] = s1[i];
	i = 0;
	while((ft_strlen(s1) + i++) < len)
		buffer[ft_strlen(s1) + i] = s2[i];
	buffer[len] = '\0';
	return  (buffer);
}

int main(int ac, char **av)
{
	if (ac > 1){
		char *ciao = ft_strjoin(av[1], av[2]);
		printf("%s\n", ciao);
		free(ciao);
	}
		return 0;
}
