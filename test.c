#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
#include"count.h"
#include"caiishuzi.h"
void nume2();
int main()
{	
	srand((unsigned int)time(NULL));
	char m= 0;
	while(nume2(),m = getchar(),getchar(),m!='q')
	{
		switch (m)
		{
		case 'a':
		case'A':
			game1();
			break;
		break;
		case 'b':
		case 'B':
			count2();
			break;
		break;
		case 'c':
		case 'C':
			caishuzigame();
			break;
		default:
			printf("请重新输入\n");
		}
		fflush(stdin);//清空缓冲区以免回车等符号是循环多次进行影响游戏体验
	}
	return 0;
}
void nume2()
{
	printf("*************************\n");
	printf("***********菜单栏********\n");
	printf("***a.扫雷*******b.count***\n");
	printf("***c.猜数字****q.退出*****\n");
	printf("**************************\n");
}
