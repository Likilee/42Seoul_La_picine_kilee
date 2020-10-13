#include <unistd.h>

int		is_it(char c)
{
	if (c == ' ' || c == '\t')
		return (0);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (2);
	return (-1);
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

void	capital(char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	if (is_it(str[0]) == 1)
	{
		str[0] -= 32; 
		++i;
	}
	while (i < len)
	{
		if (is_it(str[i]) == 0 && is_it(str[i + 1]) == 1)
				str[i + 1] -= 32;
		else if (is_it(str[i]) != 0 && is_it(str[i + 1]) == 2)
				str[i + 1] += 32;
		++i;
	}
	write (1, str, len);
}

int		main(int argc, char **argv)
{
	int i;

	if (argc > 1)
	{
		i = 1;
		while(argv[i])
		{
			capital(argv[i]);
			write(1, "\n", 1);
			++i;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}

