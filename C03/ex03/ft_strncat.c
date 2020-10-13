/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:06:47 by kilee             #+#    #+#             */
/*   Updated: 2020/08/12 19:25:20 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i_d;
	unsigned int i_s;

	i_d = 0;
	i_s = 0;
	while (dest[i_d])
		i_d++;
	while (src[i_s] && i_s < nb)
	{
		dest[i_d + i_s] = src[i_s];
		i_s++;
	}
	dest[i_d + i_s] = '\0';
	return (dest);
}
