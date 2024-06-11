// 2253209 信07 刘佳朋
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int y, m, d, s = 0;
	printf("请输入年，月，日\n");
	scanf("%d %d %d", &y, &m, &d);
	if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))
	{
		if (m >= 1 && m <= 12)
		{
			if ((m == 1 && d <= 31 || m == 2 && d <= 29 || m == 3 && d <= 31 || m == 4 && d <= 30 || m == 5 && d <= 31 || m == 6 && d <= 30 || m == 7 && d <= 31 || m == 8 && d <= 31 || m == 9 && d <= 30 || m == 10 && d <= 31 || m == 11 && d <= 30 || m == 12 && d <= 31) && d >= 1)
			{
				switch (m)
				{
					case 12:
						s += 30;
					case 11:
						s += 31;
					case 10:
						s += 30;
					case 9:
						s += 31;
					case 8:
						s += 31;
					case 7:
						s += 30;
					case 6:
						s += 31;
					case 5:
						s += 30;
					case 4:
						s += 31;
					case 3:
						s += 29;
					case 2:
						s += 31;
					case 1:
						s += d;
				}
				printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, s);
			}
			else
			{
				printf("输入错误-日与月的关系非法\n");
			}
		}
		else
		{
			printf("输入错误-月份不正确\n");
		}
	}
	else
	{
		if (m >= 1 && m <= 12)
		{
			if ((m == 1 && d <= 31 || m == 2 && d <= 28 || m == 3 && d <= 31 || m == 4 && d <= 30 || m == 5 && d <= 31 || m == 6 && d <= 30 || m == 7 && d <= 31 || m == 8 && d <= 31 || m == 9 && d <= 30 || m == 10 && d <= 31 || m == 11 && d <= 30 || m == 12 && d <= 31) && d >= 1)
			{
				switch (m)
				{
					case 12:
						s += 30;
					case 11:
						s += 31;
					case 10:
						s += 30;
					case 9:
						s += 31;
					case 8:
						s += 31;
					case 7:
						s += 30;
					case 6:
						s += 31;
					case 5:
						s += 30;
					case 4:
						s += 31;
					case 3:
						s += 28;
					case 2:
						s += 31;
					case 1:
						s += d;
				}
				printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, s);
			}
			else
			{
				printf("输入错误-日与月的关系非法\n");
			}
		}
		else
		{
			printf("输入错误-月份不正确\n");
		}
	}

	return 0;
}