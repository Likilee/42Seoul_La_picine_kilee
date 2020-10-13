
#include "ft_list.h"

int main(void)
{
	/*
	t_list **begin_list = (t_list **)malloc(sizeof(t_list *));
	printf("size = %d\n", ft_list_size(*begin_list));
	ft_list_push_front(begin_list, "world!");
	printf("size = %d\n", ft_list_size(*begin_list));
	ft_list_push_front(begin_list, "hello");
	printf("size = %d\n", ft_list_size(*begin_list));
	ft_list_push_back(begin_list, "good");
	t_list *curr = *begin_list;
	while (curr)
	{
		printf("%s\n", curr->data);
		curr = curr->next;
	}
	curr = ft_list_last(*begin_list);
	printf("last data = %s\n", curr->data);
	*/

	int size = 4;
	char **strs = (char **)malloc(sizeof(char *) * size);
	strs[0] = "hello";
	strs[1] = "world";
	strs[2] = "good";
	strs[3] = "bye";

	t_list **begin_list = (t_list **)malloc(sizeof(t_list *));
	*begin_list = ft_list_push_strs(size, strs);
	t_list *curr = *begin_list;
	while (curr)
	{
		printf("%s\n", curr->data);
		curr = curr->next;
	}

	curr = ft_list_at(*begin_list, 0);
	printf("0 -> %s\n", curr->data);
	curr = ft_list_at(*begin_list, 3);
	printf("3 -> %s\n", curr->data);

	return (0);
}
