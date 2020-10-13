#include "ft_list.h"

void		ft_list_reverse(t_list **begin_list)
{
	t_list	**reverse_list;
	int		size;
	t_list	*curr;

	if ((size = ft_list_size(*begin_list)) == 0)
		return ;
	reverse_list = (t_list **)malloc(sizeof(t_list*) * size);
	curr = *begin_list;
	while (curr != NULL)
	{
		ft_list_push_front(reverse_list, curr->data);
		curr = curr->next;
	}
}
