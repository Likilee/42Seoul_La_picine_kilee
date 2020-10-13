#include "ft_list.h"

int main(void)
{
	t_list **begin_list = (t_list **)malloc(sizeof(t_list *));

	printf("size = %d\n", ft_list_size(*begin_list));
	ft_list_push_front(begin_list, "world!");
	printf("size = %d\n", ft_list_size(*begin_list));
	ft_list_push_front(begin_list, "hello");
	printf("size = %d\n", ft_list_size(*begin_list));

	t_list *curr = *begin_list;
	while (curr)
	{
		printf("%s\n", curr->data);
		curr = curr->next;
	}

	curr = ft_list_last(*begin_list);
	printf("last data = %s\n", curr->data);

	return (0);
}
