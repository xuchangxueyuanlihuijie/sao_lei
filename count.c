#define _CRT_SECURE_NO_WARNINGS 1
#include"count.h"
double chengfa(double*pmp, int i)
{
	return( *pmp * *(pmp + 1));
}
double chufa(double* pmp, int i)
{
	return (*pmp/ *(pmp+ 1));
}
double jianfa(double*pmp, int i)
{
	return (*pmp - *(pmp + 1));
}
double jiafa(double*pmp, int i)
{
	return (*pmp + *(pmp + 1));
}
void count2()
{
	printf("请输入你想要计算的算数（仅限于加减乘除）");
	double sum = 0;
	double arr[100] = {0};
	char b[50] = { 0 };
	int i = 0;
	int vio = 0;
	int cow= 0;
	int j = 0;
	int w= 0;
	int p = 0;
	int e = 0;
	int m = 0;
	double mpm = 0;
	printf("请输入算数\n");
	while (1)
	{
		
		scanf("%lf", &arr[i]);
		b[i]=getchar();
		if (b[i] != '(')
			vio++;
		if (b[i]!= ')')
			cow++;
		if (b[i] == '\n')
		{
			break;
		}
		i++;
	}
	for (j = 0; j <= i; j++)
	{
		printf("%lf", arr[j]);
		printf("%c", b[j]);
	}
	
	//if (b[vio]=='(' &&b[cow]!=')')
	//{
	//	j = vio;
	//	while (j < cow)
	//	{
	//		if (b[j] == '*')
	//		{
	//			double mpl = chengfa(&arr[j], j);
	//			arr[j + 1] = mpl;
	//			memmove(&arr[j], &arr[j + 1], sizeof(arr[0])*(&arr[cow + 1] - &arr[j]));
	//			memmove(&b[j], &b[j + 1], sizeof(b[0])*(&b[cow+ 1] - &b[j]));
	//			j--;
	//		}
	//		if (b[j] == '/')
	//		{
	//			double ply = 0;
	//			ply = chufa(&arr[j], j);
	//			arr[j + 1] = ply;
	//			memmove(&arr[j], &arr[j + 1], sizeof(arr[0])*(&arr[cow + 1] - &arr[j]));
	//			memmove(&b[j], &b[j + 1], sizeof(b[0])*(&b[cow] - &b[j]));
	//			j--; 
	//		}
	//		j++;
	//		if (b[j] == '\n')
	//		{
	//			break;
	//		}

	//	}
	//	while (w < i)
	//	{
	//		if (b[w] == '-')
	//		{
	//			double tmp = 0;
	//			tmp = jianfa(&arr[w], w);
	//			arr[w + 1] = tmp;
	//			memmove(&arr[w], &arr[w + 1], sizeof(arr[0])*(&arr[i + 1] - &arr[w]));
	//			memmove(&b[w], &b[w + 1], sizeof(b[0])*(&b[i + 1] - &b[w]));
	//			w--;
	//		}

	//		if (b[w] == '+')
	//		{
	//			mpm = jiafa(&arr[w], w);
	//			arr[w + 1] = mpm;
	//			memmove(&arr[w], &arr[w + 1], sizeof(arr[0])*(&arr[i + 1] - &arr[w]));
	//			memmove(&b[w], &b[w + 1], sizeof(b[0])*(&b[i + 1] - &b[w]));
	//			w--;
	//		}
	//		w++;
	//		if (b[w] == '\n')
	//		{
	//			break;
	//		}
	//	}
	//}
	//else if (b[vio] !='('  && b[cow] ==')')
	//{
	//	printf("没有完整的括号将按照没括号处理");
	//}
	//else if (b[vio] == '(' && b[cow] != ')')
	//{
	//	printf("没有完整的括号将按照没括号处理");
	//}
	//else
	//{
	//	;
	//}
	j = 0;
	while (j < cow)
	{
		if (b[j] == '*')
		{
			double mpl=chengfa(&arr[j], j);
			arr[j + 1] = mpl;
			memmove(&arr[j], &arr[j + 1], sizeof(arr[0])*(&arr[i+1] - &arr[j]));
			memmove(&b[j], &b[j + 1], sizeof(b[0])*(&b[i + 1] - &b[j]));
			j--;
		}
		if (b[j] == '/')
		{
			double ply = 0;
			ply= chufa(&arr[j], j);
			arr[j + 1] = ply;
			memmove(&arr[j], &arr[j + 1], sizeof(arr[0])*(&arr[i + 1] - &arr[j]));
			memmove(&b[j], &b[j + 1], sizeof(b[0])*(&b[i + 1] - &b[j]));
			j--;
		}
		j++;
		if (b[j] == ')')
		{
			break;
		}
	}
	while (w < i)
	{
		if (b[w] == '-')
		{
			double tmp = 0;
			tmp = jianfa(&arr[w], w);
			arr[w + 1] = tmp;
			memmove(&arr[w], &arr[w + 1], sizeof(arr[0])*(&arr[i + 1] - &arr[w]));
			memmove(&b[w], &b[w + 1], sizeof(b[0])*(&b[i + 1] - &b[w]));
			w--;
		}
		
		if (b[w] == '+')
		{
			mpm = jiafa(&arr[w], w);
			arr[w + 1] = mpm;
			memmove(&arr[w], &arr[w + 1], sizeof(arr[0])*(&arr[i + 1] - &arr[w]));
			memmove(&b[w], &b[w + 1], sizeof(b[0])*(&b[i + 1] - &b[w]));
			w--;
		}
		w++;
		if (b[w] == '\n')
		{
			break;
		}
	}
		printf("sum=%lf\n",arr[0]);
		system("pause");
}