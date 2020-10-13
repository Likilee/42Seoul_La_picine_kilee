#include <stdlib.h>
#include <stdio.h>


int		is_prime(int num)
{
	long long i;

	if (num % 2 == 0)
		return (0);
	i = 3;
	while (i * i < num)
	{
		if (num % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int num;
	int i;

	if (argc == 2)
	{
		if ((num = atoi(argv[1])) < 0)
		{
			printf("Not Possitive number");
			return (0);
		}

		if (num == 1)
		{
			printf("1\n");
			return (0);
		}
		if (is_prime(num))
		{
			printf("%d\n", num);
			return (0);
		}
		i = 2;
		while (1)
		{
			if (num % i == 0)
			{
				printf("%d", i);
				num /= i;
				if (num != 1)
					printf("*");
			}
			else if (i == 2)
				++i;
			else
				i += 2;
			if (num == 1)
				break;
		}
		printf("\n");
	}
	else
		printf("\n");
	return (0);
}
