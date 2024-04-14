#pragma once

#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//声明InitBoard函数
void InitBoard(char board[ROW][COL], int row, int col);

//声明DisplayBoard函数----打印棋盘
void DisplayBoard(char board[ROW][COL],int row, int col);

//声明玩家下棋
void PlayeMove(char board[ROW][COL], int row, int col);

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//判断是否赢
//玩家赢--'*'
//电脑赢--'#'
//继续---'C'
//平局---'Q'
char IsWin(char board[ROW][COL], int row, int col);

//判断是否平局
int IsFun(char board[ROW][COL], int row, int col);
