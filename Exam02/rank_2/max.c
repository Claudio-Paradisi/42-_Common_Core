#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	if (len > 0)
	{
		nbr = tab[0];
		while (i < len)
		{
			if(tab[i] > nbr)
				nbr = tab[i];
			i++;	
		}
	}
	return (nbr);
}

/*int	main()
{
	int array[5] = {100, 2, 3, -8000, 4};

	printf("%d\n", max(array, 0));
	return 0;
}*/
