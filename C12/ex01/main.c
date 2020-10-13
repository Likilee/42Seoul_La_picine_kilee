#include <stdio.h>
#include "ft_list.h"

int main(void)
{
	t_list **begin_list = (t_list **)malloc(sizeof(t_list *));

	ft_list_push_front(begin_list, "world!");
	ft_list_push_front(begin_list, "hello");

	t_list *curr = *begin_list;
	while (curr)
	{
		printf("%s\n", curr->data);
		curr = curr->next;
	}
	return (0);
}
