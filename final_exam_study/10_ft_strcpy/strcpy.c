#include <string.h>
#include <stdio.h>

char	*ft_strcpy(char *s1, char *s2);

int main(int argc, char **argv)
{
	char	chararray[6];
	char	ft_chararray[6];

	if (argc < 2)
		return (0);
	strcpy(chararray,argv[1]);
	ft_strcpy(ft_chararray, argv[1]);
//	printf("%s\n", chararray);
	printf("%s", ft_chararray);
	return (0);
}
