/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:00:39 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/19 15:27:09 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*it goes in seg fault but it should work*/

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

char	*ft_strrev(char *str)
{
	int	len;
	char	temp;
	int	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		temp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = temp;
		i++;
		len--;
	}
	return (str);
}

/*int	main()
{
	char	*str = "abacacacaccc";
	printf("str reversed: %s\n", ft_strrev(str));

	return 0;
}*/
