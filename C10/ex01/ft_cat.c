/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:27:54 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/09/14 16:51:21 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_BUF 10000
#define PROGRAM_NAME "ft_cat"

void	ft_cat_print_stdin(void)
{
	char	buf[MAX_BUF];
	int		read_size;

	while ((read_size = read(0, buf, MAX_BUF)) > 0)
		write(1, buf, read_size);
}

void	ft_cat_print_file(char *file_name)
{
	int		fd;
	char	*err_msg;
	int		length;
	char	buf[MAX_BUF];

	if ((fd = open(file_name, O_RDONLY)) < 0)
	{
		length = 0;
		err_msg = strerror(errno);
		while (file_name[length])
			length++;
		write(1, PROGRAM_NAME, sizeof(PROGRAM_NAME));
		write(1, ": ", 2);
		write(1, file_name, length);
		write(1, ": ", 2);
		length = 0;
		while (err_msg[length])
			length++;
		write(1, err_msg, length);
		write(1, "\n", 1);
	}
	else
		while ((length = read(fd, buf, MAX_BUF)) > 0)
			write(1, buf, length);
	close(fd);
}

int		main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		ft_cat_print_stdin();
	else if (argc > 1)
		while (argv[i])
			ft_cat_print_file(argv[i++]);
	return (0);
}
