
int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		++i;
	return (i);
}

#include <stdio.h>

int		main(int argc, char **argv)
{
	int arr[ft_strlen(argv[1])];
 	if(argc != 2)
		return (0);
	arr[1] = '1';
	printf("%d", arr[0]);
	return (0);
}
