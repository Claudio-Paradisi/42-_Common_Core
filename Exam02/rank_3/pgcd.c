#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	hcd;
	int	n1;
	int	n2;

	if (ac == 3)
	{
		n1 = atoi(av[1]);
		n2 = atoi(av[2]);

		if (n1 > n2)
			hcd = n2;
		else if (n2 > n1)
			hcd = n1;
		else
		{
			printf("%d\n", n1);
			return (0);
		}
		while (hcd > 0)
		{
			if (n1 % hcd == 0 && n2 % hcd == 0)
				break ;
			hcd--;
		}
		printf("%d", hcd);
	}
	printf("\n");
	return (0);
}
