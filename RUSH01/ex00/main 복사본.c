
#include <unistd.h>

//글로벌 변수 선언
char g_temp_row[4] = {'1', '2', '3', '4'}; // 수열 만들기용 1234로 초기화하고 싶은데 분리를 못하겠습닏 ㅜㅜ
char g_row_index[24][4]; // 수열 인덱스 저장용
char grid[4][4];
int inum; // g_row_index 용 넘버


// 예외상황 - 31자 안되면 리턴 0, 되면 1
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

// 예외상황 - 홀수자리에 1~4 정수, 짝수자리에 ' ' 또는 '\t' 있는지 확인
int		check_num(char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		if (!(((i % 2 == 0) && (str[i] >= '1' && str[i] <= '4')) || ((i % 2 == 1) && (str[i] == ' ' || str[i] == '\t'))))
				return (0);
		i++;
	}
	return (1);
}



// 에러 메세지 출력 후 한줄 띄기,
void    print_ERROR(void)
{
    write(1, "ERROR\n", 6);
}


//perm 보조 함수 : swap 함수 구현 - g변수 g_temp_row[] 의 a번 b번 값 바꾸기.
void swap(int a, int b)
{
    int temp;
    temp = g_temp_row[a];
    g_temp_row[a] = g_temp_row[b];
    g_temp_row[b] = temp;
} 

// 1~4 순열 만들어서 g_row_index에 저장 - 이건 그냥 메인에서 한번호출해서 순열 인덱스만들어주는 애임.
void perm(int depth)
    {
        int i;
        int j;

        i = 0;
        if (depth == 4) // 한번 depth 가 k로 도달하면 사이클이 돌았음. 출력함. 
        {
            j = 0;    
            while (j <= 4)
            {
                g_row_index[inum][j] = g_temp_row[j]; 
                j++;
            }
            inum++;
            return;
        } 
        i = depth;
        while (i < 4)//for (int i = depth; i < 4; i++)
        { 
            swap(i, depth); 
            perm(depth + 1); 
            swap(i, depth);
            i++;
        }
    }

/*
void    dfs(int level)
{
    if (level == 4)
    {
        
        isok() // 완성된 isok 함수에 통과 되면 
    }    
}
*/

int     count(int a, int b, int c, int d)
{
    int counter;
    
    counter = 0;
    if (counter < a)
        counter++;
    if (counter < b)
        counter++;
    if (counter < c)
        counter++;
    if (counter < d)
        counter++;
    return counter;
}


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
        perm(0);
        int k = 0;
        while( k <= 23)
        {
            write(1, g_row_index[k], 4);
            write (1, "\n", 1);
            k++;
        }
        write (1, "\n", 1);

        k = count(g_row_index[2][0], g_row_index[2][1], g_row_index[2][2], g_row_index[2][3]);
        char c;
        c = k + '0';
        write (1, &c, 1);
    	//write(1, "hi", 2)
	}
	return (0);
}

