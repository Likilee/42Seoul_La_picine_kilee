#include <stdlib.h>
#include <stdio.h>

int		*ft_range(int start, int end)
{
	int size;
	int	*arr;
	int i;

	i = 0;
	if (start > end)
	{
		size = start - end + 1;
		arr = (int *)malloc(sizeof(int) * size);
		while (i < size)
		{
			arr[i] = start;
			start -= 1;
			++i;
		}
	}
	else if (end > start)
	{
		size = end - start + 1;
		arr = (int *)malloc(sizeof(int) * size);
		while (i < size)
		{
			arr[i] = start;
			start += 1;
			++i;
		}
	}
	else
	{
		arr = (int *)malloc(sizeof(int) * 1);
		arr[0] = start;
	}
	return (arr);
}

int		main(int ac, char **av)
{
	if (ac == 3)
	{
		int a;
		int b;
		int *arr;
		int size;

		a = atoi(av[1]);
		b = atoi(av[2]);
		arr = ft_range(a,b);
		size = b - a + 1;
		int i = 0;
		while (i < size)
		{
			printf("%d, ", arr[i]);
			++i;
		}
	}
	printf("\n");
	return (0);
}
