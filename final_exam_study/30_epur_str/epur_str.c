#include <unistd.h>


int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


int		main(int argc, char **argv)
{
	int end;
	int	length;

	end = 0;
	if (argc == 2)
	{
		length = ft_strlen(argv[1]);
		while (argv[1][end] == ' ' || argv[1][end] == '\t')
			++end;
		while (end < length)
		{
			if (argv[1][end] != ' ' && argv[1][end] != '\t')
			{
				write(1, &argv[1][end], 1);
				++end;
			}
			else
			{
				while(argv[1][end] == ' ' || argv[1][end] == '\t')
					++end;
				if (argv[1][end] != '\0')
					write (1, " ", 1);
			}
		}
	}
	write (1, "\n", 1);
	return (0);
}

