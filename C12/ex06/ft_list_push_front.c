/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:58:07 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/09/15 12:31:32 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_elem;

	if ((new_elem = ft_create_elem(data)) == 0)
		return ;
	if (begin_list != NULL)
		new_elem->next = *begin_list;
	*begin_list = new_elem;
}
