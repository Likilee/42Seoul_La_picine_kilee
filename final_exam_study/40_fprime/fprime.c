#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

int		is_prime(int num)
{
	int i;

	i = 2;
	if (num < 2)
		return (0);
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		++i;
	}
	return (1);
}

int		next_prime(int num)
{
	int i;

	i = num + 1;
	while (i < 46341)
	{
		if(is_prime(i))
			return (i);
		++i;
	}
	return (num);
}

int		main(int argc, char **argv)
{
	int num;
	int factor;

	if (argc == 2)
	{
		factor = 2;
		if ((num = atoi(argv[1])) > 0)
		{
			if (num == 1)
				printf("1");
			while (num != 1)
			{
				while (!(num % factor == 0))
					factor = next_prime(factor);
				printf("%d",factor);
				num /= factor;
				if(num != 1)
					printf("*");
			}	
		}
	}
	printf("\n");
	return (0);
}

