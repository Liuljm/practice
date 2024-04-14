#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//����InitBoard����
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

//����DisplayBoard����---��ӡ����
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
//			//1.��ӡ����
//			printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
//			//2.��ӡ�ָ���
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
		//1.��ӡ����
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col -1)
			{
                printf("|");
			}   	
		}
		printf("\n");
        //2.��ӡ�ָ���
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

//������庯��
void PlayeMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("�����>��\n");
	while (1)
	{
		printf("��������Ҫ�µ�λ�ã�");
		scanf("%d%d", &x, &y);
		//�ж�λ���Ƿ�Ϸ�
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�������ѱ�ռ�ã����������룡");
			}
		}
		else
		{
			printf("�������λ�ò��Ϸ������������룡\n");
		}
	}
	
}


//�������庯��
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("������>:\n");
	while (1)
	{
		x = rand()%row;
		y = rand()%col;
		//�ж�
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//�ж�Ӯ����
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//������
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//������
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	//�ж��Ƿ���������---�ж��Ƿ�ƽ��
	if (1 == IsFun(board, row, col))
	{
		return 'Q';
	}
	return 'C';
}

//�ж��Ƿ�ƽ��---�ж��Ƿ���������
int IsFun(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return -1;//û��
			}
		}
	}
	return 1;//����
}