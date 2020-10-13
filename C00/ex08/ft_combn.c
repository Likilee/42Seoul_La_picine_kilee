nclude <unistd.h>


void	ft_putchar(int n)
{
	char c;

	c = n + '0';
	write(1, &c, 1);
}

int	ft_putstr(int* num, int i, int n)
{
	if (num[i] <= 9)
	{
		ft_putchar(num[i]);
		num[i + 1]++;
		if (i != n)
			ft_putstr(num, i + 1, n);
	}
	else
	{
		num[i - 1]++;
		num[i] = num[i - 1] + 1;
	}
	return *num;
}

int*	make_num(int n)
{
	int i;
	int* num;

	i = 0;
	while (i < n)
	{
		num[i] = 0;
		i++;
	}
	return *num;
}		

void	ft_printer(int n)
{
	int i;
	i = 0;
	
	make_num(n);	
	while (num[0] <= 9)
	{
		ft_putstr(num, i, n); 
		write(1, ", ", 2);
	}
}

int	main(void)
{
	ft_printer(2);
}
