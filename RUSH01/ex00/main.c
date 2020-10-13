
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//글로벌 변수 선언
char g_temp_row[4] = {'1', '2', '3', '4'}; // 수열 만들기용 1234로 초기화하고 싶은데 분리를 못하겠습닏 ㅜㅜ
char g_row_index[24][4]; // 수열 인덱스 저장용
char g_grid[4][4];
int inum; // g_row_index 용 넘버
int finish; // 첫번 째 해만 찾으면 dfs 정지 시키기 위한 식별자.

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

char     count(char a, char b, char c, char d)   /// 인자 순서대로 건물높이로 보고 보이는 건물 갯수 세는거. ex)abcd가 1234 면 counter 는 4반환 
{
    char counter;
    char current;
    
    counter = '1';
    current = a;
    if (current < b)
    {
        counter++;
       current = b;
    }
    if (current < c)
    {
        counter++;
        current = c;
    }
    if (current < d)
    {
        counter++;
        current = d;
    }
    return counter;
}

int     isok(char **str) // 만들어진 그리드와 argv 값 비교
{
    int i;
    int j;

    i = 0;
    while (i <= 3)
    {
        j = 0; 
        if (str[1][2 * i] != count(g_grid[0][j], g_grid[1][j], g_grid[2][j], g_grid[3][j]))
                return 0;
        i++;
    }
    while (i <= 7)
    {
        j = 0; 
        if (str[1][2 * i] != count(g_grid[3][j], g_grid[2][j], g_grid[1][j], g_grid[0][j]))
                return 0;
        i++;
    }
    while (i <= 11)
    {
        j = 0; 
        if (str[1][2 * i] != count(g_grid[j][0], g_grid[j][1], g_grid[j][2], g_grid[j][3]))
                return 0;
        i++;
    }    
    while (i <= 15)
    {
        j = 0; 
        if (str[1][2 * i] != count(g_grid[j][3], g_grid[j][2], g_grid[j][1], g_grid[j][0]))
                return 0;
        i++;
    }
    return 1;
}   

void    print_grid(void)   // g_grid를 네모반듯 출력해보쟈!!!
{
    int col;
    int row;
    
    col = 0;
    row = 0;
    while(row < 4)
    {
        while (col < 4)
        {
            write (1, &g_grid[row][col], 1);
            if (col != 3)
                write (1, " ", 1); 
            col++;
        }
        write (1, "\n", 1);
        row++;
    }
}

void    dfs(int level, char **str) // 깊이탐색으로 가능 그리드 찾아내기!
{
    int i;
    int j;

    if (level == 4 && isok(str))
    {   
       if(isok(str)) // 완성된 그리드 argv[1] 값과 비교
        {
            print_grid(); //그리드 출력기
            finish = 1;
            printf("%d", level);
        }
        return;
    }
    else if (level != 4 && !isok(str)) // 만족한 그리드 안나왔을 때만! 계속 탐색
    {
        write(1, &level, 1);
        i = 0;
        while (i < 24)
        {   
            while (j < 4)
            {
                g_grid[level][j] = g_row_index[i][j];
                j++;
            }
        i++;
         //printf("%d", level);
        dfs(level + 1, str);
        }
    }
    else
        return;
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
        finish = 0;
        //testing
        
        print_grid();
        perm(0);
        int k = 0;
        while( k <= 23)
        {
            write(1, g_row_index[k], 4);
            write (1, "\n", 1);
            k++;
        }
        write (1, "\n", 1);

        write (1, g_row_index[4], 4);
        char c;
        c = count(g_row_index[4][0], g_row_index[4][1], g_row_index[4][2], g_row_index[4][3]);
        
        write (1, &c, 1);
    	//write(1, "hi", 2)
        
        print_grid();

        //real
        dfs(0, argv);
        
        if (finish == 0)
            print_ERROR();
	}
	return (0);
}

