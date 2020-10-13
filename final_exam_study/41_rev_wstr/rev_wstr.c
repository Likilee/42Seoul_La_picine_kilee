#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

int		main(int argc, char **argv)
{
	int		len;
	char	*rev;
	int		temp_s;
	int		e;
	int		s;
	int		rev_p;

	temp_s = 0;
	rev_p = 0;
	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		rev = (char *)malloc(sizeof(char) * len + 1);
		rev[len] = '\0';
		e = len;
		s = len;
		while (rev_p < len)
		{
			while (argv[1][s] != ' ' && argv[1][s] != '\t' && s >= 0)
				--s;
			temp_s = s + 1;
			while (temp_s < e)
			{
				rev[rev_p] = argv[1][temp_s];
				++temp_s;
				++rev_p;
			}
			if (rev_p != len)
				rev[rev_p++] = argv[1][s];
			e = s;
			--s;
		}
		write(1, rev, len);
		free(rev);
	}
	write (1, "\n", 1);
	return (0);
}
