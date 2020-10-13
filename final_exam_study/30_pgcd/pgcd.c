#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int a;
	int b;
	int p_max;
	int	pgcd;

	pgcd = 0;
	if (argc == 3)
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		if (a == b)
		{
			pgcd = a;
			printf("%d\n", pgcd);
			return (0);
		}
		else if (a < b)
			p_max = a;
		else
			p_max = b;
		if ((a % p_max == 0) && (b % p_max == 0))
			pgcd = p_max;
		else
		{
			p_max /= 2;
			while (p_max >= 1)
			{ 
				if ((a % p_max == 0) && (b % p_max == 0))
				{	
					pgcd = p_max;
					break;
				}
				--p_max;
			}
		}
		printf("%d", pgcd);
	}
	printf("\n");
	return (0);
}
