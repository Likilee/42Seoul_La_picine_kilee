#include <stdlib.h>
#include <stdio.h>

// ex) fdasf df asfsda gasgasd 

int			ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

int			is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		*ft_epur(char *str)
{
	int 	i;
	int		j;
	int 	len;
	char	*dest;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * len + 1);
	while(is_space(str[i]) == 1)
		++i;
	while (i < len)
	{
		if (is_space(str[i]) == 0)
			dest[j++] = str[i++];
		else
		{
			while (is_space(str[i]) == 1)
				++i;
			if (str[i] != '\0')
				dest[j++] = ' ';
		}
	}
	dest[j] = '\0';
	return (dest);
}

int			count_word(char *str)
{
	int count;
	int i;

	i = 0;
	count = 1;
	while (str[i])
	{ 
		if (str[i] == ' ')
			++count;
		++i;
	}
	if (i == 0)
		--count;
	return (count);
}

void		ft_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while(i < n)
	{
		dest[i] = *src;
		++i;
		++src;
	}
	dest[i] = '\0';
}

char		**ft_split(char *str)
{
	char	**words;
	char	*dest;
	int		count;
	int		len;
	int		i;
	int		start;

	dest = ft_epur(str);
	count = count_word(dest);
	words = (char **)malloc(sizeof(char *) * count + 1);
	words[count] = NULL;
	
	i = 0;
	start = 0;
	while (i < count)
	{	
		start += len;
		len = 0;
		while (dest[start + len] != ' ' || dest[start + len] != '\0')
			++len;
		words[i] = (char *)malloc(sizeof(char) * len + 1);
		ft_strncpy(words[i], &dest[start], len);
		++i;
	}
	return (words);
}

int			main(int argc, char **argv)
{
	char	*dest;
	char	**splited;
	int		count;
	int		i;

	if (argc == 2)
	{
		dest = ft_epur(argv[1]);
		printf("%s", dest);
		count = count_word(dest);
		printf("%d", count);
	splited = ft_split(argv[1]);
		i = 0;
	while (i < count - 1)
		printf("%s\n", splited[i++]);
	}
	return (0);
}
