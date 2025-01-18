/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:09:55 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/15 14:29:21 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

char	*rev_print(char *str)
{
	int	i;
	
	i = ft_strlen(str);
	while (i--)
		write(1, &str[i], 1);
	return (str);
}

int	main()
{
	rev_print("tnirp esreveR");
	return 0;
}
