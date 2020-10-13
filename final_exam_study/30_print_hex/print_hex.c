#include <unistd.h>


long	ft_atoll(char *str)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	while (str[i])
	{
		num = num * 10 + str[i] - '0';
		++i;
	}
	return (num);
}

char	ft_trans(num)
{
	char c;

	if (num < 10)
		c = num + '0';
	else
		c = 'a' + num - 10;
	return (c);
}

void	print_hex(long num)
{
	char c;
	if (num == 0)
		return ;
	print_hex(num / 16);
	c = ft_trans(num % 16);
	write (1, &c, 1);
}

int		main(int argc, char **argv)
{
	long	num;

	if (argc == 2)
	{
		num = ft_atoll(argv[1]);
		print_hex(num);
	}
	write(1, "\n", 1);

	return (0);
}

