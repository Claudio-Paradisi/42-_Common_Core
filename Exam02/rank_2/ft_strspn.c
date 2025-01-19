/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:28:12 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/19 16:07:47 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	size_t	j;
	int	found;

	i = 0;
	while(s[i])
	{
		found = 0;
		j = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break ;
			}
			j++;
		}
		
		if (!found)
			break ;
		i++;
	}
	return (i);
}

/*int	main()
{
	char *s1 = "ciaot";
	char *s2 = "caot";
	printf("mia funzione: %zu\n", ft_strspn(s1, s2));
	printf("funzione originale: %zu\n", strspn(s1, s2));
	return 0;
}*/
