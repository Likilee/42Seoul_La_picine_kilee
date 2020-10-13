#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(const char *str)
{
	int len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

int		to_int(char c)
{
	int num;
	
	if (c >= '0' && c <= '9')
		num = c - '0';
	else if(c <= 'Z')
		num = c - 55;
	else
		num = c - 87;
	return (num);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int sign;
	int	i;
	int	num;
	int len;

	i = 0;
	num = 0;
	sign = 1;
	len = ft_strlen(str);
	printf("%d", i);
	if (str[0] == '-')
	{
		sign = -1;
		++i;
	}
	while(i < len)
	{
		num = num * str_base + to_int(str[i]);
		++i;
	}
	return (num * sign);
}


int		main(int ac, char **av)
{
	if (ac == 3)
		printf("result: %d\n", ft_atoi_base(av[1], atoi(av[2])));//
	return (0);
}
