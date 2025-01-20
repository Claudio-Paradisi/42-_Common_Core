#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	unsigned int power;

	power = 2;
	while (n % power == 0)
	{
		n /= power;
	}
	if (n != 1)
		return (0);
	return (1);
}

/*int main()
{
	int	num;
	int	is_power;
	num = 65538;
	is_power = is_power_of_2(num);
	printf("%d", is_power);
	return 0;
	
}*/
