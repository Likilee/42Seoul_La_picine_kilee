#include "ft_list.h"

void free_data(void *data)
{
	free(data);
}

int main(void)
{
	int size = 2;
	char **strs = (char **)malloc(sizeof(char *) * size);
	strs[0] = (char *)malloc(sizeof(char) * 6);
	for (int i = 0; "hello"[i]; i++)
		strs[0][i] = "hello"[i];
	strs[0][5] = 0;
	strs[1] = (char *)malloc(sizeof(char) * 6);
	for (int i = 0; "world"[i]; i++)
		strs[1][i] = "world"[i];
	strs[1][5] = 0;
	/*
	strs[2] = "good";
	strs[3] = "bye";
	*/


	t_list *begin_list = ft_list_push_strs(size, strs);
	t_list *curr = begin_list;
	while (curr)
	{
		printf("%s\n", curr->data);
		curr = curr->next;
	}
	ft_list_clear(begin_list, &free_data);
	while (curr)
	{
		printf("%s\n", curr->data);
		curr = curr->next;
	}
	return (0);
}
