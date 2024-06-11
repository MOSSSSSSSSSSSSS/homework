// 2253209 信07 刘佳朋
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int zeller(int y, int m, int d)
{
	if (m == 1 || m == 2)
	{
		m += 12;
		y--;
	}
	int w, c1, c2;
	c1 = y / 100;
	c2 = y - c1 * 100;
	w = c2 + c2 / 4 + c1 / 4 - 2 * c1 + 13 * (m + 1) / 5 + d - 1;
	if (w <= 0)
	{
		for (int i = 1; w <= 0;)
		{
			w += i * 7;
		}
	}
	w %= 7;
	return w;
}
int main()
{
	int y, m, d, w;
	while (1)
	{
		printf("请输入年[1900-2100]、月、日：\n");
		if (scanf("%d %d %d", &y, &m, &d)!=3)
		{
			while (getchar() != '\n')
			{
				;
			}
			printf("输入错误，请重新输入\n");
		}
		else if (y < 1900 || y>2100)
		{
			printf("年份不正确，请重新输入\n");

		}
		else if (m > 12 || m < 1)
		{
			printf("月份不正确，请重新输入\n");
		}
		else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		{
			if (d < 1 || d>31)
			{
				printf("日不正确，请重新输入\n");
			}
			else
			{
				break;
			}
		}
		else if (m == 4 || m == 6 || m == 9 || m == 11)
		{
			if (d < 1 || d>30)
			{
				printf("日不正确，请重新输入\n");
			}
			else
			{
				break;
			}
		}
		else if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		{
			if (d < 1 || d>29)
			{
				printf("日不正确，请重新输入\n");
			}
			else
			{
				break;
			}
		}
		else
		{
			if (d < 1 || d>28)
			{
				printf("日不正确，请重新输入\n");
			}
			else
			{
				break;
			}
		}
	}
	w = zeller(y, m, d);
	switch (w)
	{
	case 0:
		printf("星期日\n");
		break;
	case 1:
		printf("星期一\n");
		break;
	case 2:
		printf("星期二\n");
		break;
	case 3:
		printf("星期三\n");
		break;
	case 4:
		printf("星期四\n");
		break;
	case 5:
		printf("星期五\n");
		break;
	case 6:
		printf("星期六\n");
		break;
	}
	return 0;
}