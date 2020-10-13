/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <gnsdlrl@daum.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:31:46 by kilee             #+#    #+#             */
/*   Updated: 2020/08/09 03:13:24 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_grid[81][4][4];
char	g_pair[8][2];
char	g_pattern[4][6][4];

//g_pattern 입력부
void	table(void)
{
	g_pattern[0][0] = "1234"; //41_1
	g_pattern[1][0] = "1324"; //31_1
	g_pattern[1][1] = "2134"; //31_2
	g_pattern[1][2] = "2314"; //31_3
	g_pattern[2][0] = "1243"; //32_1
	g_pattern[2][1] = "1342"; //32_2
	g_pattern[2][2] = "2341"; //32_3 
	g_pattern[3][0] = "3124"; //21_1
	g_pattern[3][1] = "3241"; //21_2
	g_pattern[4][0] = "1423"; // 22_1
	g_pattern[4][1] = "2143"; // 22_2
	g_pattern[4][2] = "2413"; // 22_3
	g_pattern[4][3] = "3142"; // 22_4
	g_pattern[4][4] = "3241"; // 22_5
	g_pattern[4][5] = "3412"; // 22_6
	g_pattern[5][0] = "1432"; // 23_1
	g_pattern[5][1] = "2431"; // 23_2
	g_pattern[5][2] = "3421"; // 23_3
	g_pattern[6][0] = "4123"; // 12_1
	g_pattern[6][1] = "4213"; // 12_2
	g_pattern[7][0] = "4132"; // 13_1
	g_pattern[7][1] = "4231"; // 13_2
	g_pattern[7][2] = "4312"; // 13_3
	g_pattern[8][0] = "4321"; // 14_1
}

char	*pattern_checker(char *pair)  // 받아온 pair에 일치하는 패턴의 첫번째 값의 주소 반환
{
	if (*pair == "41")
		return g_pattern[0];
	else if (*pair == "31")
		return g_pattern[1];
	else if (*pair == "32")
		return g_pattern[2];
	else if (*pair == "21")
		return g_pattern[3];
	else if (*pair == "22")
		return g_pattern[4];
	else if (*pair == "23")
		return g_pattern[5];
	else if (*pair == "12")
		return g_pattern[6];
	else if (*pair == "13")
		return g_pattern[7];
	else
		return g_pattern[8];
}


// 	void	 pattern_input(char **pair) 


//	예외상황 체크! 
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

void  make_pair(char argv[1])
{
	int i;

	i = 0;
	while (i <= 7)
	{
		if (i <= 3 )
		{
			*g_pair[i] = argv[1][16 + 2 * i];
			g_pair[i]++;
			*g_pair[i] = argv[1][25 + 2 * i];
		}
		else
		{
			*g_pair[i] = argv[1][1 + 2 * (i - 4)];	// 
			g_pair[i]++;
			*g_pair[i] = argv[1][9 + 2 * (i - 4)];
		}
		i++;
	}
	return;
}



/*
char **fill_grid(int cdx)
{
	//cdx가 마지막 행까지 수행하고 여기까지 오면 찾기 완료
	if (cdx == n)
	{
		count++;
		return;
	}
	else if
*/		




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
		table();
		make_pair(argv[1]);
		// write (1, "hi", 2);
	}
	return (0);
}
