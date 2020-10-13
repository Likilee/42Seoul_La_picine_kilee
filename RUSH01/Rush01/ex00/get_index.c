/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <gnsdlrl@daum.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 15:32:14 by kilee             #+#    #+#             */
/*   Updated: 2020/08/08 16:29:28 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*rm_space(char *no_space, char *origin)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (origin[j])
	{
		if (origin[j] != ' ')
		{
			no_space[i] = origin[j];
			i++;
		}
	    j++;
	}
	return (no_space);
}

int		main(int argc, char **argv)
{
	char no_space[17];
	if (argc != 2)
		write (1, "\n", 1);
	else
		write (1, rm_space(no_space, argv[1]), 16);
	return (0);
}
