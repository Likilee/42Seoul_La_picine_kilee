/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:06:32 by kilee             #+#    #+#             */
/*   Updated: 2020/08/12 17:29:21 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char		get_hex(unsigned char c)
{
	if (c < 10)
		c += 48;
	else
		c += 87;
	return (c);
}

void				print_others(unsigned char c)
{
	unsigned char aski_num;

	write(1, "\\", 1);
	aski_num = get_hex(c / 16);
	write(1, &aski_num, 1);
	aski_num = get_hex(c % 16);
	write(1, &aski_num, 1);
}

void				ft_putstr_non_printable(char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
			print_others(str[i]);
		i++;
	}
}
