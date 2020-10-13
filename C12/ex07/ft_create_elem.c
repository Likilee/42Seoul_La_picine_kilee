/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:50:25 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/09/15 12:14:52 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list		*ft_create_elem(void *data)
{
	t_list	*new_elem;

	if((new_elem = (t_list*)malloc(sizeof(t_list) * 1)) == 0)
		return (NULL);
	new_elem->data = data;
	(*new_elem).next = NULL;
	return (new_elem);
}
