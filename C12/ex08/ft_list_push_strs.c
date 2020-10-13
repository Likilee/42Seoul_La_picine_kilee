#include "ft_list.h"

t_list		*ft_list_push_strs(int size, char **strs)
{
	t_list	**begin_list;
	int		i;
	if ((begin_list = (t_list **)malloc(sizeof(t_list *) * size)) == 0)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ft_list_push_front(begin_list, strs[i]);
		++i;
	}
	return (*begin_list);
}
