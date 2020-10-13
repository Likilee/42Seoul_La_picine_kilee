#include <unistd.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	int i;
	int j;
	int	start;
	int len;
	char *first;

	if (ac > 1)
	{
		i = 0;
		while (av[1][i] == ' ' || av[1][i] == '\t')
			++i;
		start = i;
		while (av[1][i] != ' ' && av[1][i] != '\t' && av[1][i])
			++i;
		len = i - start;
		first = (char *)malloc(sizeof(char) * len + 1);
		j = 0;
		while (start < i)
			first[j++] = av[1][start++];
		while (av[1][i] == ' ' || av[1][i] == '\t')
			++i;
		while (av[1][i] != '\0')
		{
			while (av[1][i] != ' ' && av[1][i] != '\t' && av[1][i])
				write(1, &av[1][i++], 1);
			while (av[1][i] == ' ' || av[1][i] == '\t')
				++i;
			write(1, " ", 1);
		}
		write(1, first, len);
		free(first);
	}
	write(1, "\n", 1);
	return (0);
}
