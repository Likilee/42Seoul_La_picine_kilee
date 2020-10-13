#include <unistd.h>

int		is_it(char c)
{
	if (c == ' ' || c == '\t')
		return (0);
	else if (c == '\0')
		return (-1);
	return (1);
}

int		main(int argc, char **argv)
{
	int i;


	if (argc == 2)
	{
		i = 0;
		while (is_it(argv[1][i]) == 0)
			++i;
		while (argv[1][i])
		{
			if (is_it(argv[1][i]) == 1)
			{
				write(1, &argv[1][i], 1);
				++i;
			}
			else
			{
				while(is_it(argv[1][i]) == 0)
					++i;
				if(is_it(argv[1][i]) == 1)
					write(1, "   ", 3);
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
