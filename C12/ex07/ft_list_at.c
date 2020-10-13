/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:22:37 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/09/15 13:30:39 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*target;
	unsigned int	i;

	target = begin_list;
	i = 0;
	while (i < nbr)
	{
		if (target == NULL)
			return (NULL);
		target = target->next;
		++i;
	}
	return (target);
}
