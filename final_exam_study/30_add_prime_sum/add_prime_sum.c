#include <unistd.h>
#include <stdlib.h>

int		ft_atoi(char *str)
{
	int i;
	int symbol;
	int	num;

	i = 0;
	symbol = 1;
	num = 0;
	if (str[0] == '+')
		++i;
	else if (str[0] == '-')
	{
		symbol = -1;
		++i;
	}
	while (str[i])
	{
		num = num * 10 + str[i] - '0';
		++i;
	}
	return (num);
}

int		is_prime(int num)
{
	int i;

	i = 2;
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		++i;
	}
	return (1);
}

long	prime_sum(int num)
{
	long	sum;
	char	*che;
	int		i;
	int		n;

	sum = 0;
	che = (char*)malloc(sizeof(char) * num + 1);
	che[0] = 0;
	che[1] = 0;
	i = 2;
	while (i <= num)
		che[i++] = 1;
	i = 2;
	if (num < 2)
		return (0);
	else
	{
		while (i <= num)
		{
			if (che[i] == 1 && is_prime(i) == 1)
			{
				sum += i;
				n = 2;
				while (i * n < num)
				{
					che[i * n] = 0;
					++n;
				}
			}
			++i;
		}
	}
	return (sum);
}

void	sum_printer(long sum)
{
	char c;
	if (sum == 0)
		return ;
	sum_printer(sum / 10);
	c = sum % 10 + '0';
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int 	num;
	long	sum;

	if (argc != 2)
		write(1, "0", 1);
	else if (ft_atoi(argv[1]) < 2)
		write(1, "0", 1);
	else
	{
		num = ft_atoi(argv[1]);
		sum = prime_sum(num);
		sum_printer(sum);
	}
	write(1, "\n", 1);
	return (0);
}

