#include <stdlib.h>
#include <stdio.h>

int			is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		**ft_split(char *str)
{
	int i;
	int j;
	int k;
	char	**split;

	i = 0;
	j = 0;
	if (!(split = (char **)malloc(sizeof(char *) * 300)))
		return (NULL);
	while (is_space(str[i]))
		++i;
	while (str[i])
	{
		if(!(split[j] = (char *)malloc(sizeof(char) * 5000)))
			return (NULL);
		k = 0;
		while (!is_space(str[i]) && str[i])
			split[j][k++] = str[i++];
		split[j][k] = '\0';
		while (is_space(str[i]))
				++i;
		++j;
	}
	split[j] = NULL;
	return (split);
}

int		main(int argc, char **argv)
{
	char **split;
	int	i;

	i = 0;
	if (argc == 2)
	{
		split = ft_split(argv[1]);
		while (split[i])
			printf("%s\n", split[i++]);
	}
	return (0);
}


