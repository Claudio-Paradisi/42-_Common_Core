#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	i;
	int	*array;

	i = 0;
	if (end > start)
	{
		array = (int *)malloc((end - start) * sizeof(int) + 1);
		if(!array)
			return (NULL);
		while(start <= end)
		{
			array[i] = start;
			i++;
			start++;
		}
	}
	else if(start > end)
	{
		array = (int *)malloc((start - end) * sizeof(int) + 1);
		if (!array)
			return (NULL);
		while (start >= end)
		{
			array[i] = start;
			i++;
			start--;
		}
	}
	else if(start == end)
	{
		array = (int *)malloc(sizeof(int));
		array[0] = start;
	}
	return (array);
}
/*
int main()
{
	int start = 0;
	int end = -5;
	int i;
	int *array;

	i = 0;
	array =ft_range(start, end);
	while (i < 6)
	{
		printf("%d, ",array[i]);
		i++;
	}
	free(array);

	return 0;
}*/
