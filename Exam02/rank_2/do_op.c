/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:26:23 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/19 14:05:54 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*do not use write after a printf without a \n the write function will be executed first*/

int	ft_operation(int num1, char operator, int num2)
{
	int	result;

	if (operator == '+')
		result = num1 + num2;
	else if(operator == '-')
		result = num1 - num2;
	else if (operator == '*')
		result = num1 * num2;
	else if (operator == '/')
		result = num1 / num2;
	return (result);
}

int	main(int ac, char **av)
{
	int	num1;
	int	num2;
	char	c;
	int	result;
	num1 = atoi(av[1]);
	num2 = atoi(av[3]);
	if (ac == 4)
	{
		c = av[2][0];
		result = ft_operation(num1, c, num2);
		printf("%d", result);
	}
	printf("\n");
	return (0);
}
