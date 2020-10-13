#include <unistd.h>

void	put_nbr(int num)
{
	char c;
	if (num == 0)
		return ;
	put_nbr(num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int count;
 
	if (argc < 2)
		write(1, "0", 1);
	else
	{
		count = 1;
		while(argv[count])
			++count;
		count -= 1;
		put_nbr(count);
	}
	write(1, "\n", 1);
}
