#pragma once

#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//����InitBoard����
void InitBoard(char board[ROW][COL], int row, int col);

//����DisplayBoard����----��ӡ����
void DisplayBoard(char board[ROW][COL],int row, int col);

//�����������
void PlayeMove(char board[ROW][COL], int row, int col);

//��������
void ComputerMove(char board[ROW][COL], int row, int col);

//�ж��Ƿ�Ӯ
//���Ӯ--'*'
//����Ӯ--'#'
//����---'C'
//ƽ��---'Q'
char IsWin(char board[ROW][COL], int row, int col);

//�ж��Ƿ�ƽ��
int IsFun(char board[ROW][COL], int row, int col);
