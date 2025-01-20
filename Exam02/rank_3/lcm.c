#include <stdio.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	num;

	num = 1;
	if(!a || !b)
		return (0);
	while(num % a != 0 || num % b != 0)
		num++;
	return (num);
}

/*int	main()
{
	printf("%d\n", lcm(5, 10));
	return (0);
}*/
