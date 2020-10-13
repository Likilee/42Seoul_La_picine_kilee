#include "list.h"

void		swap(t_list *a, t_list *b)
{
	int	temp;

	temp = a->data;
	a->data = b->data;
	b->data = temp;
}


t_list		*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *a;
	t_list *b;

	a = lst;
	while(a)
	{
		b = a->next;
		while(b)
		{
			if(!cmp(a->data,b->data))
				swap(a,b);
			b = b->next;
		}
		a= a->next;
	}
	return (lst);
}

#include <stdlib.h>
#include <stdio.h>

int		ascending(int a, int b)
{
		return (a <= b);
}

int		main(void)
{
	t_list *l;
	int		i;
	t_list	*t;
	t_list	*b;

	i = 50;
	l = malloc(sizeof(t_list));
	t = l;
	b = l;
	while (i)
	{
		l->data = i % 3;
		l->next = malloc(sizeof(t_list));
		l = l->next;
		--i;
	}
	l->data = (int)"fromage";
	l->next = NULL;
	while (t)
	{
		printf("%d ", t->data);
		t = t->next;
		++i;
	}
	b = sort_list(b, ascending);
	while (b)
	{
		printf("%d ", b->data);
		b = b->next;
		++i;
	}
}
