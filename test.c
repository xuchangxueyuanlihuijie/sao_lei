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
			printf("����������\n");
		}
		fflush(stdin);//��ջ���������س��ȷ�����ѭ����ν���Ӱ����Ϸ����
	}
	return 0;
}
void nume2()
{
	printf("*************************\n");
	printf("***********�˵���********\n");
	printf("***a.ɨ��*******b.count***\n");
	printf("***c.������****q.�˳�*****\n");
	printf("**************************\n");
}
