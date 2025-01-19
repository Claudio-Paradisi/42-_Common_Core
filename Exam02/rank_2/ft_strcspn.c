/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:12:59 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/19 14:25:33 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t ft_strcspn(const char *s, const char *reject)
{
	size_t	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while(s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (reject[j] == s[i])
				return (count);
			j++;
		}
		count++;
		i++;
	}
	return (count);
}

/*int	main()
{
	char *s1 = "ciao";
	char *s2 = "ciao";

	printf("mia funzione: %zu\n", ft_strcspn(s1, s2));
	printf("funzione originale: %zu\n", strcspn(s1, s2));
	return (0);	
}*/
