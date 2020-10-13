/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:05:51 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/09/15 13:20:06 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*curr;
	t_list	*temp;

	curr = begin_list;
	while (curr != NULL)
	{
		free_fct(curr->data);
		temp = curr;
		free(curr);
		curr = temp->next;
	}
}
