#define _CRT_SECURE_NO_WARNINGS 1
#include"caiishuzi.h"
void caishuzigame()
{
	int a = 0;
	int ret = (rand() % 100);
	
	while (printf("����������ѡ������"),scanf("%d", &a),1)
	{
		if (a < ret)
		{
			printf("��С��");
		}
		else if (a>ret)
		{
			printf("�´���");
		}
		else
		{
			printf("�¶���");
			break;
		}
	}
}