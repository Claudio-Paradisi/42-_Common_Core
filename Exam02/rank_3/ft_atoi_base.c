#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int	nbr;
	int	sign;
	int	temp;

	nbr = 0;
	sign = 1;

	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while(*str)
	{
		if (*str >= '0' && *str <= '9')
			temp = *str - '0';
		if (*str >= 'a' && *str <= 'f')
			temp = *str -'a' + 10;
		if (*str >= 'A' && *str <= 'F')
			temp = *str - 'A' + 10;
		else
			break ;
		nbr = nbr * str_base + temp;
		str++;
	}
	return (nbr * sign);
}
