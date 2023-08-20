#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#define POP 10
#define ROW 9
#define CLC 9
#define ROWS  ROW+2
#define CLCS  ROW+2
void nume();
void game();
void game1();
void chuangjian(char arr[ROWS][CLCS], char ch[ROWS][CLCS]);
void stme();
void fuzhi(char arr[ROWS][CLCS], int row, int clc,char str);
void dayin(char arr[ROWS][CLCS], int row, int clc);
void set(char ch[ROWS][CLCS], int rows, int clcs);
void watch(char arr[ROWS][CLCS],char ch[ROWS][CLCS], int row, int clc);