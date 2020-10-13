/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:15:38 by kilee             #+#    #+#             */
/*   Updated: 2020/08/21 12:48:54 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char			*cut_16(char *dst, void *str, int size)
{
	int		i;
	int		j;
	char	*str_ch;

	i = 0;
	j = 0;
	str_ch = (char*)str;
	while (i < 16)
	{
		if (size >= 16)
			dst[i] = str_ch[i];
		else if (i < size)
			dst[i] = str_ch[i];
		else
			dst[i] = '\0';
		i++;
	}
	return (dst);
}

char			*trans_room_char(char *room2, void *addr)
{
	long long	nb_addr;
	long long	room[16];
	int			i;

	nb_addr = (long long)addr;
	i = 15;
	while (i >= 0)
	{
		room[i] = nb_addr % 16;
		nb_addr = nb_addr / 16;
		i--;
	}
	i = 0;
	while (i <= 15)
	{
		if (room[i] >= 10)
			room2[i] = room[i] + 87;
		else
			room2[i] = room[i] + 48;
		i++;
	}
	return (room2);
}

void			print_hex(char c)
{
	int		hex[2];
	char	hex_c[2];

	hex[0] = c / 16;
	hex[1] = c % 16;
	if (hex[1] >= 10)
		hex_c[1] = hex[1] + 87;
	else
		hex_c[1] = hex[1] + 48;
	hex_c[0] = hex[0] + 48;
	write(1, hex_c, 2);
}

void			printer(char *dst, int sign_size)
{
	int		i;

	i = 0;
	while (dst[i] && i < 16)
	{
		print_hex(dst[i++]);
		if (i < sign_size)
			print_hex(dst[i++]);
		write(1, " ", 1);
	}
	i = 0;
	if (sign_size < 16)
	{
		while (i++ < 16 - sign_size)
			write(1, " ", 1);
	}
	i = 0;
	while (i < 16 && i < sign_size)
	{
		if (dst[i] >= 32 && dst[i] <= 126)
			write(1, &dst[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void			*ft_print_memory(void *addr, unsigned int size)
{
	char			char_room[16];
	char			dst[16];
	int				sign_size;

	if (size == 0)
		return (addr);
	sign_size = (int)size;
	while (sign_size >= 0)
	{
		cut_16(dst, addr, sign_size);
		write(1, trans_room_char(char_room, addr), 16);
		write(1, ": ", 2);
		printer(dst, sign_size);
		write(1, "\n", 1);
		addr += 16;
		sign_size -= 16;
	}
	return (addr);
}

#include <stdio.h>

void	*ft_print_memory(void *addr, unsigned int size);

int main()
{
	char str[70];
	char a = '!';
	for(int i = 0; i < 70; i++)
		str[i] = a++;
	ft_print_memory((void *)str, 70);

	char str2[92];
	int ttemp[23] = {0x426f6e6a, 0x6f757220, 0x6c657320, 0x616d696e, 0x63686573, 0x090a0963, 0x20206573, 0x7420666f, 0x7509746f, 0x75740963, 0x65207175, 0x206f6e20, 0x70657574, 0x20666169, 0x72652061, 0x76656309, 0x0a097072, 0x696e745f, 0x6d656d6f, 0x72790a0a, 0x0a096c6f, 0x6c2e6c6f, 0x6c0a2000};
	for(int i = 0; i < 24; i++){
		str2[4 * i] = ttemp[i] / 16 / 16 / 16 / 16 / 16 / 16;
		str2[4 * i + 1] = ttemp[i] / 16 / 16 / 16 / 16;
		str2[4 * i + 2] = ttemp[i] / 16 / 16;
		str2[4 * i + 3] = ttemp[i];
	}
	ft_print_memory((void *)str2, 92);
	ft_print_memory((void *)str2, 91);

	return 0;
}