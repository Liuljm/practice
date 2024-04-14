#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//定义InitBoard函数
void InitBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] =' ';
		}
	}
}

//定义DisplayBoard函数---打印棋盘
//   |   |   
//---|---|---
//   |   |   
//---|---|---
//   |   |   
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	for (int i = 0; i < row; i++)
//	{
//		if (i != row - 1)
//		{
//			//1.打印数据
//			printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
//			//2.打印分割行
//			printf("---|---|---\n");
//		}
//		else
//		{
//			printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		}
//	}
//}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		//1.打印数据
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col -1)
			{
                printf("|");
			}   	
		}
		printf("\n");
        //2.打印分割行
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

//玩家下棋函数
void PlayeMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("玩家走>：\n");
	while (1)
	{
		printf("请输入你要下的位置：");
		scanf("%d%d", &x, &y);
		//判断位置是否合法
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标已被占用，请重新输入！");
			}
		}
		else
		{
			printf("你输入的位置不合法，请重新输入！\n");
		}
	}
	
}


//电脑下棋函数
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("电脑走>:\n");
	while (1)
	{
		x = rand()%row;
		y = rand()%col;
		//判断
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//判断赢函数
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//横三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//竖三列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	//判断是否铺满棋盘---判断是否平局
	if (1 == IsFun(board, row, col))
	{
		return 'Q';
	}
	return 'C';
}

//判断是否平局---判断是否铺满棋盘
int IsFun(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return -1;//没满
			}
		}
	}
	return 1;//满了
}