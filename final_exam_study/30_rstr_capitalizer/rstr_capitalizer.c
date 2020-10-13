#include <unistd.h>

int		is_what(char c)
{
	if (c == ' ' || c == '\t' || c == '\0')
		return (0);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (2);
	return (-1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int		main(int argc, char **argv)
{
	int	len;
	int i;
	int j;

	if (argc > 1)
	{
		i = 1;
		while (argv[i])
		{
			len = ft_strlen(argv[i]);
			j = 0;
			while (j < len)
			{
				if (is_what(argv[i][j]) == 2 && is_what(argv[i][j+1]) != 0)
					argv[i][j] += 32;
				else if (is_what(argv[i][j]) == 1 && is_what(argv[i][j+1]) == 0)
					argv[i][j] -= 32;
				++j;
			}
			write(1, argv[i], len);
			write(1, "\n", 1);
			++i;
		}
	}
	else 
		write(1, "\n", 1);
	return (0);
}
	
