/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:16:49 by kilee             #+#    #+#             */
/*   Updated: 2020/08/11 15:27:41 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i_s;
	int		i_f;

	if (!to_find[0])
		return (str);
	i_s = 0;
	while (str[i_s])
	{
		i_f = 0;
		if (str[i_s] == to_find[i_f])
		{
			while (to_find[i_f] == str[i_s + i_f])
			{
				i_f++;
				if (!to_find[i_f])
					return (&str[i_s]);
			}
		}
		i_s++;
	}
	return (0);
}
