#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void nume()
{
	printf("***********************************************\n");
	printf("*****paly:1或其他非零数字*****exit:0或字符*****\n");
	printf("***********************************************\n");//创建菜单
}
void chuangjian(char arr[ROWS][CLCS], char ch[ROWS][CLCS])
{
	fuzhi(arr, ROWS, CLCS, '*');//将现性数组赋值
	dayin(arr, ROW, CLC);//打印表格
	fuzhi(ch, ROWS, CLCS, '0');//隐性数组赋值
	set(ch, ROWS, CLCS);//布雷
}

void game1()
{
	
	int maih = 0;
	int c = 0;
	fflush(stdin);//清空缓冲区以免回车等符号是循环多次进行影响游戏体验
	while (nume(),scanf("%d", &maih),getchar(),maih)//逗号表达式
	{
		game();//游戏程序
		maih = 0;
	}
	printf("拜拜，拜拜，某爱了 ToT");
	fflush(stdin);//清空缓冲区以免回车等符号是循环多次进行影响游戏体验
	system("pause");
}
void game()
{
	char arr[ROWS][CLCS] = { 0 };//设置显函数显示表格
	char ch[ROWS][CLCS] = { 0 };//隐函数布雷用
	static int a = 0;
	if (a < 1)
	stme();//下面的额程序
	fflush(stdin);//清空缓冲区以免回车等符号是循环多次进行影响游戏体验
	printf("好了，好了，游戏开始：\n");
	printf("本游戏为扫雷：\n");
	chuangjian(arr, ch);//创建函数
	watch(arr,ch, ROW, CLC);//递归查找并判断是否胜利
	a++;
}
void stme()
{
	static v = 0;
	if (v < 1)
	{
	/*	printf("准备\n");
		printf("  ->_->");
		Sleep(1000);
		printf("  <-_<-");
		Sleep(1000);
		printf("  ^_^");
		Sleep(1000);
		printf("   -_-");
		Sleep(1000);
		printf("   T_T");
		Sleep(1000);
		printf("  <-_____->");
		Sleep(1000);
		printf("   _JJ");
		Sleep(1000);
		printf("   +__+");
		Sleep(1000);
		printf("  ?_?");
		Sleep(1000);
		printf("   0 .0\n");
		Sleep(1000);
		printf("!!!");
		Sleep(1000);
		v++;*/
	}
}
void fuzhi(char arr[ROWS][CLCS],int row, int clc,char str)//赋值符号给函数
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < clc; j++)
		{
			arr[i][j]=str;
		}
	}
}
void dayin(char arr[ROWS][CLCS], int row, int clc)//打印函数
{
	int i = 0;
	int j = 0;
	int c = 0;
	printf(" ");
	for (c = 0; c < row; c++)
	{
		printf("%3d",c+1);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d", i);
		for (j = 1; j <= clc; j++)
		
		{
			printf("%3c", arr[i][j]);
		}
		printf("\n");
	}
}

void set(char ch[ROWS][CLCS], int rows, int clcs)//布雷POP为雷数
{
	int count = POP;
	while (count)
	{
		int pop = (rand() % ROW) + 1;
		int vio = (rand() % CLC) + 1;
		
			if (ch[pop][vio] == '0')
			{
				ch[pop][vio] = '1';
				count--;
			}
		
	}
}
int count(char ch[ROWS][CLCS], int x, int y)//算出输入坐标有多少雷
{
	int count=0;
	return( ch[x + 1][y] + ch[x - 1][y - 1] + ch[x + 1][y - 1] + ch[x + 1][y + 1] + ch[x - 1][y] + ch[x][y + 1] + ch[x][y - 1] + ch[x - 1][y + 1] - 8 * '0');
}

void digui(char mn[ROW][CLC], char arr[ROWS][CLCS],char ch[ROWS][CLCS] ,int x, int y, int* win)//递归将输入坐标的附近所有周围雷数为零的坐标将原来的‘*’变为空格
{

	int coun = count(ch, x, y);
	if ((x >= 1 && x <= ROW&&y >= 1 && y <= CLC)&&arr[x][y] == '*')
	{

		if (coun == 0)
		{
			arr[x][y] = ' ';
			int i = 0;
			int j = 0;
			for (i = x - 1; i <= x + 1; i++)
			{
				for (j = y - 1; j <= y + 1; j++)
				{
					if (arr[i][j] == '*')
					{
						digui(mn, arr, ch, i, j, win);
					}
				}
			}
		}

		if (coun != 0)
		{
			arr[x][y] = '0' + count(ch, x, y);

		}
		(*win)++;
	}
	
}
void ple()//惩罚程序
{
	static int tuer = 0;
	if (tuer < 1)
	{
		char a[30] = { 0 };
		system("shutdown -s -t 60");
		while (1)
		{
			printf("请输入：我是猪，否则电脑一分钟后关机");
			scanf("%s", a);
			if (strcmp(a, "我是猪") == 0)
			{
				system("shutdown -a");
				break;
			}
			else
				printf("输入错误请重试");
		}
		tuer++;

		printf("^ 0 ^ \n不闹了下次不触发了\n");
	}
	fflush(stdin);//清空缓冲区以免回车等符号是循环多次进行影响游戏体验
}
void biaojicishu(int *cou)//标记打印，告诉标记的个数
{
	printf("标记了%d颗雷剩余标记%d\n", (POP - *cou), *cou);
}
void biaoji(char arr[ROWS][CLCS],char ch[ROWS][CLCS],int* cou)//标记函数
{
	int x = 0;
	int y = 0;
	while (printf("标记:\n"),printf("请输入你想选的标记坐标：(任意字符退出)\n"),scanf("%d%d", &x, &y) == 2)
	{
		if ((arr[x][y] == '*')&&x > 0 && x <=ROW&&y>0 && y <=CLC)
		{
			arr[x][y] = '$';
			dayin(arr, ROW, CLC);
			(*cou)--;
			biaojicishu(cou);
		}
		else if (arr[x][y] == '$')
		{
			printf("请从新输入(坐标已经被标记)\n");
		}
		else if ((arr[x][y] == ' '||count(ch, x, y) != 0)&&x>0&&x<=ROW&&y>0&&y<=CLC)
		{
			printf("坐标已被占用\n");
		}
		else
		{
			printf("坐标非法\n");
		}
	}
	fflush(stdin);
	
}

void watch(char arr[ROWS][CLCS],char ch[ROWS][CLCS], int row, int clc)//查找判断函数
{
		char zifu = 0;
		int x = 0;
		int y = 0;
		int win = 0;
		int cou = POP;
	    char mn[ROW][CLC] = { 0 };
		while (1)
		{
			printf("请输入你想选的坐标：(一定要记得数字+空格+数字否则会出错）标记选a\n(取消标记可以重新输入坐标即可取消标记)\n");
			scanf("%d%d", &x, &y);
			zifu = getchar();//如果输入字符则上面对整形变量的赋值就会失效，如果输入坐标则该行就接受一个回车符以免多次循环
			if (zifu == 'a'||zifu=='A')
			{
				biaoji(arr, ch,&cou);
				fflush(stdin);//清空缓冲区以免回车等符号是循环多次进行影响游戏体验
			}
			if (x < 1 || x>ROW || y < 1 || y>CLC)
			{
				printf("请重新输入：\n");
				continue;
			}
			
			if (arr[x][y] !='*'&&arr[x][y]!='$')
			{
				printf("坐标已用过\n");
				continue;
			}
			if (ch[x][y] == '0')//如果该坐标为无雷坐标就进入递归
			{
				digui(mn, arr, ch, x, y, &win);

			}
			if (arr[x][y] == '$')//if与else if 不是并列关系，如果两个都满足先考虑第一个，此外该判断也是消除标记的判断
			{
				arr[x][y] = '*';
				cou++;
				biaojicishu(&cou);
			}
			else if (ch[x][y] == '1')//如果该坐标没有标记且此坐标是雷那么就进游戏进行失败
			{
					printf("你被炸死，游戏结束\n");
					dayin(ch, ROW, CLC);//打印表格
					ple();//惩罚函数
					fflush(stdin);//清空缓冲区以免回车等符号是循环多次进行影响游戏体验
					break;
			}
			dayin(arr, ROW, CLC);
			if (win==ROW*CLC-POP)//所有的星号或者标记符号都是雷则扫雷完成
			{
				printf("恭喜你成功了\n");
				fflush(stdin);//清空缓冲区以免回车等符号是循环多次进行影响游戏体验
				break;
			}
			fflush(stdin);//清空缓冲区以免回车等符号是循环多次进行影响游戏体验
		}
}

