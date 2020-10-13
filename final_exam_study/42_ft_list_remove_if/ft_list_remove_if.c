#include <stdlib.h>
#include "ft_list.h"

void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*target;
	t_list	*front;

	if (*begin_list == NULL)
		return ;
	while (cmp((*begin)->data, data_ref) == 0)
	{
		free((*begin_list)->data);
		target = *begin_list;
		*begin_list = (*begin_list)->next;
		free(target);
	}
	front = *begin_list;
	target = front->next;
	while (target != NULL)
	{
		if(cmp(target->data, data_ref) == 0)
		{
			free(target->data);
			front->next = target->next;
			free(target);
		}
		else 
			front = target;
		target = front->next;
	}	
}
