#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void nume()
{
	printf("***********************************************\n");
	printf("*****paly:1��������������*****exit:0���ַ�*****\n");
	printf("***********************************************\n");//�����˵�
}
void chuangjian(char arr[ROWS][CLCS], char ch[ROWS][CLCS])
{
	fuzhi(arr, ROWS, CLCS, '*');//���������鸳ֵ
	dayin(arr, ROW, CLC);//��ӡ���
	fuzhi(ch, ROWS, CLCS, '0');//�������鸳ֵ
	set(ch, ROWS, CLCS);//����
}

void game1()
{
	
	int maih = 0;
	int c = 0;
	fflush(stdin);//��ջ���������س��ȷ�����ѭ����ν���Ӱ����Ϸ����
	while (nume(),scanf("%d", &maih),getchar(),maih)//���ű��ʽ
	{
		game();//��Ϸ����
		maih = 0;
	}
	printf("�ݰݣ��ݰݣ�ĳ���� ToT");
	fflush(stdin);//��ջ���������س��ȷ�����ѭ����ν���Ӱ����Ϸ����
	system("pause");
}
void game()
{
	char arr[ROWS][CLCS] = { 0 };//�����Ժ�����ʾ���
	char ch[ROWS][CLCS] = { 0 };//������������
	static int a = 0;
	if (a < 1)
	stme();//����Ķ����
	fflush(stdin);//��ջ���������س��ȷ�����ѭ����ν���Ӱ����Ϸ����
	printf("���ˣ����ˣ���Ϸ��ʼ��\n");
	printf("����ϷΪɨ�ף�\n");
	chuangjian(arr, ch);//��������
	watch(arr,ch, ROW, CLC);//�ݹ���Ҳ��ж��Ƿ�ʤ��
	a++;
}
void stme()
{
	static v = 0;
	if (v < 1)
	{
	/*	printf("׼��\n");
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
void fuzhi(char arr[ROWS][CLCS],int row, int clc,char str)//��ֵ���Ÿ�����
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
void dayin(char arr[ROWS][CLCS], int row, int clc)//��ӡ����
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

void set(char ch[ROWS][CLCS], int rows, int clcs)//����POPΪ����
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
int count(char ch[ROWS][CLCS], int x, int y)//������������ж�����
{
	int count=0;
	return( ch[x + 1][y] + ch[x - 1][y - 1] + ch[x + 1][y - 1] + ch[x + 1][y + 1] + ch[x - 1][y] + ch[x][y + 1] + ch[x][y - 1] + ch[x - 1][y + 1] - 8 * '0');
}

void digui(char mn[ROW][CLC], char arr[ROWS][CLCS],char ch[ROWS][CLCS] ,int x, int y, int* win)//�ݹ齫��������ĸ���������Χ����Ϊ������꽫ԭ���ġ�*����Ϊ�ո�
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
void ple()//�ͷ�����
{
	static int tuer = 0;
	if (tuer < 1)
	{
		char a[30] = { 0 };
		system("shutdown -s -t 60");
		while (1)
		{
			printf("�����룺�������������һ���Ӻ�ػ�");
			scanf("%s", a);
			if (strcmp(a, "������") == 0)
			{
				system("shutdown -a");
				break;
			}
			else
				printf("�������������");
		}
		tuer++;

		printf("^ 0 ^ \n�������´β�������\n");
	}
	fflush(stdin);//��ջ���������س��ȷ�����ѭ����ν���Ӱ����Ϸ����
}
void biaojicishu(int *cou)//��Ǵ�ӡ�����߱�ǵĸ���
{
	printf("�����%d����ʣ����%d\n", (POP - *cou), *cou);
}
void biaoji(char arr[ROWS][CLCS],char ch[ROWS][CLCS],int* cou)//��Ǻ���
{
	int x = 0;
	int y = 0;
	while (printf("���:\n"),printf("����������ѡ�ı�����꣺(�����ַ��˳�)\n"),scanf("%d%d", &x, &y) == 2)
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
			printf("���������(�����Ѿ������)\n");
		}
		else if ((arr[x][y] == ' '||count(ch, x, y) != 0)&&x>0&&x<=ROW&&y>0&&y<=CLC)
		{
			printf("�����ѱ�ռ��\n");
		}
		else
		{
			printf("����Ƿ�\n");
		}
	}
	fflush(stdin);
	
}

void watch(char arr[ROWS][CLCS],char ch[ROWS][CLCS], int row, int clc)//�����жϺ���
{
		char zifu = 0;
		int x = 0;
		int y = 0;
		int win = 0;
		int cou = POP;
	    char mn[ROW][CLC] = { 0 };
		while (1)
		{
			printf("����������ѡ�����꣺(һ��Ҫ�ǵ�����+�ո�+���ַ����������ѡa\n(ȡ����ǿ��������������꼴��ȡ�����)\n");
			scanf("%d%d", &x, &y);
			zifu = getchar();//��������ַ�����������α����ĸ�ֵ�ͻ�ʧЧ�����������������оͽ���һ���س���������ѭ��
			if (zifu == 'a'||zifu=='A')
			{
				biaoji(arr, ch,&cou);
				fflush(stdin);//��ջ���������س��ȷ�����ѭ����ν���Ӱ����Ϸ����
			}
			if (x < 1 || x>ROW || y < 1 || y>CLC)
			{
				printf("���������룺\n");
				continue;
			}
			
			if (arr[x][y] !='*'&&arr[x][y]!='$')
			{
				printf("�������ù�\n");
				continue;
			}
			if (ch[x][y] == '0')//���������Ϊ��������ͽ���ݹ�
			{
				digui(mn, arr, ch, x, y, &win);

			}
			if (arr[x][y] == '$')//if��else if ���ǲ��й�ϵ����������������ȿ��ǵ�һ����������ж�Ҳ��������ǵ��ж�
			{
				arr[x][y] = '*';
				cou++;
				biaojicishu(&cou);
			}
			else if (ch[x][y] == '1')//���������û�б���Ҵ�����������ô�ͽ���Ϸ����ʧ��
			{
					printf("�㱻ը������Ϸ����\n");
					dayin(ch, ROW, CLC);//��ӡ���
					ple();//�ͷ�����
					fflush(stdin);//��ջ���������س��ȷ�����ѭ����ν���Ӱ����Ϸ����
					break;
			}
			dayin(arr, ROW, CLC);
			if (win==ROW*CLC-POP)//���е��ǺŻ��߱�Ƿ��Ŷ�������ɨ�����
			{
				printf("��ϲ��ɹ���\n");
				fflush(stdin);//��ջ���������س��ȷ�����ѭ����ν���Ӱ����Ϸ����
				break;
			}
			fflush(stdin);//��ջ���������س��ȷ�����ѭ����ν���Ӱ����Ϸ����
		}
}

