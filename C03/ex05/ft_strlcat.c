/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:02:35 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/08/12 19:38:49 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i_d;
	unsigned int	i_s;

	i_d = 0;
	i_s = 0;
	while (dest[i_d])
		i_d++;
	while (i_d + i_s + 1 < size && src[i_s])
	{
		dest[i_d + i_s] = src[i_s];
		i_s++;
	}
	dest[i_d + i_s] = '\0';
	while (src[i_s])
		i_s++;
	if (size < i_d)
		return (size + i_s);
	else
		return (i_d + i_s);
}
