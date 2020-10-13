/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 04:48:45 by kilee             #+#    #+#             */
/*   Updated: 2020/08/10 18:04:33 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_small_a(char now)
{
	if (now >= 'a' && now <= 'z')
		return (1);
	return (0);
}

int		is_big_a(char now)
{
	if (now >= 'A' && now <= 'Z')
		return (1);
	return (0);
}

int		is_others(char now)
{
	if (!((now >= 'a' && now <= 'z')
	|| (now >= 'A' && now <= 'Z')
	|| (now >= '0' && now <= '9')))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (is_small_a(str[i]) && is_others(str[i - 1]))
			str[i] -= 32;
		else if (is_big_a(str[i]) && !is_others(str[i - 1]))
			str[i] += 32;
		i++;
	}
	return (str);
}
