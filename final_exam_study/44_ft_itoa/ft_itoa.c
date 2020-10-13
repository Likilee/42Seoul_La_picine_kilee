#include <stdlib.h>

char	*ft_itoa(int nbr)
{	
	long num;
	char *arr;
	char *arr_rev;
	int	i;
	int	j;
	
	arr = (char *)malloc(12);
	arr_rev = (char *)malloc(12);
	num = nbr;
	i = 0;
	j = 0;
	if (num < 0)
	{
		arr[0] = '-';
		num *= -1;
		++j;
	}
	while (num != 0)
	{
		arr_rev[i++] = num % 10 + '0';
		num = num / 10;
	}
	while (--i >= 0)
	{
		arr[j] = arr_rev[i];
		++j;
	}
	arr[j] = '\0';
	return (arr);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	int i;
	char *num;

	i = 0;
	if (ac == 2)
	{
		i = atoi(av[1]);
		num = ft_itoa(i);
		printf("%s", num);
	}
	printf("\n");
	return (0);
}
	
	
