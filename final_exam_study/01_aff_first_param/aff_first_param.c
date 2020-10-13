#include <unistd.h>

int	main(int argc, char **argv)
{
	int length;

	length = 0;
	if (argc > 1)
	{
		while(argv[1][length])
			++length;
		write(1, argv[1], length); 
	}
	write (1, "\n", 1);
	return (0);
}
