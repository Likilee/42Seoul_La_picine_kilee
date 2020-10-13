/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:50:03 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/09/15 12:55:57 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_elem;
	t_list	*current_last;

	new_elem = ft_create_elem(data);
	if (begin_list == NULL)
		*begin_list = new_elem;
	else
	{
		current_last = ft_list_last(*begin_list);
		current_last->next = new_elem;
	}
}
