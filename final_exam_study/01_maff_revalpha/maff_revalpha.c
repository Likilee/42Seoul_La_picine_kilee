#include <unistd.h>

int	main(void)
{
	char c;
	char C;
	c = 'z';
	C = 'Z';
	while (c >= 'a')
	{
		if (c & 1)
			write(1, &C, 1);
		else
			write(1, &c, 1);
		--c;
		--C;
	}
	write(1, "\n", 1);
	return (0);
}

