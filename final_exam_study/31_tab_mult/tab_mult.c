#include <unistd.h>

int		ft_atoi(char *str)
{
	int num;
	int i;

	num = 0;
	i = 0;
	while(str[i])
	{
		num = num * 10 + str[i] - '0';
		++i;
	}
	return (num);
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while(str[len])
		++len;
	return (len);
}

void	put_nbr(int num)
{
	char c;
	
	if (num == 0)
		return ;
	c = num % 10 + '0';
	put_nbr(num / 10);
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		num;
	char	counter;
	int		len;

	if (argc == 2)
	{
		i = 1;
		len = ft_strlen(argv[1]);
		num = ft_atoi(argv[1]);
		while (i < 10)
		{
			counter = i + '0';
			write(1, &counter, 1);
			write(1, " x ", 3);
			write(1, argv[1], len);
			write(1, " = ", 3);
			put_nbr(num * i);
			write(1, "\n", 1);
			++i;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}

