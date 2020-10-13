#include "ft_list.h"

int main(void)
{


	int size = 4;
	char **strs = (char **)malloc(sizeof(char *) * size);
	strs[0] = "hello";
	strs[1] = "world";
	strs[2] = "good";
	strs[3] = "bye";

	t_list *curr = ft_list_push_strs(size, strs);
	while (curr)
	{
		printf("%s\n", curr->data);
		curr = curr->next;
	}
	return (0);
}
