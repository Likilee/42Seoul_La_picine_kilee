#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while(str[len])
		++len;
	return (len);
}

int		main(int ac, char **av)
{
	int	len;
	char **board;
	int i;
	int j;
	int k;
	int m;
	int i_k;
	int j_k;

	if (ac > 1)
	{
		len = ft_strlen(av[1]);
		board = (char **)malloc(sizeof(char*) * len);
		i = 0;
		while (i < len)
			board[i++] = (char *)malloc(sizeof(char) * len);
		i = 1;
		while (i <= len)
		{
			j = 0;
			while(j < len)
			{
				if (av[i][j] == 'K')
				{
					i_k = i - 1;
					j_k = j;
				}
				else if (av[i][j] == 'P')
				{
					k = 0;
					while (k < len)
					{
						if (k == j - 1 || k == j + 1)
							board[i][k] = 1;
						++k;
					}
				}
				else if (av[i][j] == 'B')
				{
					m = 0;
					while (m < len)
					{
						k = 0;
						while (k < len)
						{
							if (m - i + 1 == k - j || m - i + 1 == j - k)
								board[m][k] = 1;
							++k;
						}
						++m;
					}
				}
				else if (av[i][j] == 'R')
				{
					m = 0;
					while (m < len)
					{
						k = 0;
						while (k < len)
						{
							if (m == i - 1 || k == j)
								board[m][k] = 1;
							++k;
						}
						++m;
					}
				}
				else if (av[i][j] == 'Q')
				{
					m = 0;
					while (m < len)
					{
						k = 0;
						while (k < len)
						{
							if (m - i + 1 == k - j || m - i + 1 == j - k
								|| m == i - 1|| k == j)
								board[m][k] = 1;
							++k;
						}
						++m;
					}
				}
				++j;
			}
			++i;
		}
		if (board[i_k][j_k] == 1)
			write(1, "Success", 7);
		else
			write(1, "Fail", 4);
		i = 0;
	/*	while (i < len)
		{
			write(1, board[i], len);
			write(1, "\n", 1);
			++i;
		}
	*/
		free(board);
	}
	write(1, "\n", 1);
	return (0);
}
