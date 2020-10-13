/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <gnsdlrl@daum.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:31:46 by kilee             #+#    #+#             */
/*   Updated: 2020/08/08 23:35:28 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_grid[4][4];

void	print_ERROR(void)
{
	write(1, "ERROR\n", 6);
}

int		check_len(char *str)
{
	int i;

	i=0;
	while (str[i])
		i++;
	if (i == 31)
		return 1;
	else
		return 0;
}

int		check_num(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (!((str[i] >= 49 && str[i] <= 52) || str[i] == 32))
				return (0);
		i++;
	}
	return (1);
}

char	**bit_masking(char **grid, int masking_num, int x, int y)
{
	

int		main(int argc, char **argv)
{
	if (argc != 2)
		print_ERROR();
	else if (argv[1] == '\0')
		print_ERROR();
	else if (!check_len(argv[1]))	
		print_ERROR();
	else if (!check_num(argv[1]))
		print_ERROR();
	else
	{
		while ()
		{
			

	//	write (1, "hi", 2);
	}
	return (0);
}
