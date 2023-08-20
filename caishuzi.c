#define _CRT_SECURE_NO_WARNINGS 1
#include"caiishuzi.h"
void caishuzigame()
{
	int a = 0;
	int ret = (rand() % 100);
	
	while (printf("请输入你想选的数字"),scanf("%d", &a),1)
	{
		if (a < ret)
		{
			printf("猜小了");
		}
		else if (a>ret)
		{
			printf("猜大了");
		}
		else
		{
			printf("猜对了");
			break;
		}
	}
}