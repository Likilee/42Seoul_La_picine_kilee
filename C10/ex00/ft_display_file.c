/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:18:55 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/09/14 14:18:42 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024
#define NO_ARG_MSG "File name missing.\n"
#define TOO_MANY_ARGC_MSG "Too many arguments.\n"
#define CANT_READ_FILE_MSG "Cannot read file\n"

int		main(int argc, char **argv)
{
	int		open_file;
	char	blocks[BUF_SIZE];
	int		now_read;

	if (argc == 1)
		write(1, NO_ARG_MSG, sizeof(NO_ARG_MSG));
	else if (argc > 2)
		write(1, TOO_MANY_ARGC_MSG, sizeof(TOO_MANY_ARGC_MSG));
	else if (argc == 2)
	{
		if ((open_file = open(argv[1], O_RDONLY)) == -1)
			write(1, CANT_READ_FILE_MSG, sizeof(CANT_READ_FILE_MSG));
		else
			while ((now_read = read(open_file, blocks, sizeof(blocks))) > 0)
				write(1, blocks, now_read);
	}
	return (0);
}
