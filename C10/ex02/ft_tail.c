/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:02:28 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/09/14 18:23:09 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//tail -c 10 : 뒤에서 부터 10 바이트 읽기
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_BUF 1024
#define PROGRAM_NAME "ft_tail"
#define TOO_FEW_ARG "Too few argument input"
void	print_err_msg(char *file_name)
{
	char	*err_msg;
	int		length;

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

long	ft_get_file_size(char *file_name)
{
	long	context_size;
	int		read_size;
	char	buf[MAX_BUF];
	int		fd;

	context_size = 0;
	read_size = 0;
	fd = open(file_name, O_RDONLY);
	while ((read_size = read(fd, buf, MAX_BUF)) > 0)
		context_size += read_size;
	close(fd);
	return (context_size);
}

void	ft_tail_c(char *file_name, long byte_size)
{
	int		fd;
	long	context_size;
	char	*buf;
	long	read_start;

	if ((fd = open(file_name, O_RDONLY)) < 0)
		print_err_msg(file_name);
	else
	{
		context_size = ft_get_file_size(file_name);
		buf = (char*)malloc(sizeof(char) * context_size);
		if ((read_start = context_size - byte_size) < 0)
		{
			read_start = 0;
			byte_size = context_size;
		}
		read(fd, buf, context_size);
		buf += read_start;
		write(1, buf, byte_size);
	}
	close(fd);
}

long	ft_stoll(char *s)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	if (s[0] == '+' || s[0] == '-')
		i = 1;
	while (s[i])
	{
		num = num * 10 + s[i] - '0';
		++i;
	}
	return (num);
}

void	print_file_name(char *file_name)
{
	int	length;

	length = 0;
	while (file_name[length])
		++length;
	write(1, "==> ", 4);
	write(1, file_name, length);
	write(1, " <==\n", 5);
}

int		main(int argc, char **argv)
{
	long	byte_size;
	int		i;

	i = 3;
	if (argc < 4)
		write(1, TOO_FEW_ARG, sizeof(TOO_FEW_ARG));
	else
	{
		byte_size = ft_stoll(argv[2]);
		if (argc == 4)
			ft_tail_c(argv[3], byte_size);
		else
		{
			while (argv[i])
			{
				print_file_name(argv[i]);
				ft_tail_c(argv[i], byte_size);
				write(1, "\n", 1);
				++i;
			}
		}
	}
	return (0);
}
