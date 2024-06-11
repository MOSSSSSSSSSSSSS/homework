// 2253209 信07 刘佳朋
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int pan_duan_run_nian(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int ji_suan_tian_shu(int a,int month,int day)
{
	int sum=0,i;
	int array[12] = { 31,28 + a,31,30,31,30,31,31,30,31,30,31 };
	for (i = 0; i < month-1; i++)
	{
		sum += array[i];
	}
	sum += day;
	return sum;
}
int main()
{
	int year, month, day;
	printf("请输入年，月，日\n");
	scanf("%d %d %d", &year, &month, &day);
	if (month >= 13 || month <= 0)
	{
		printf("输入错误-月份不正确\n");
		return 0;
	}
	else
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day > 31 || day < 1)
			{
				printf("输入错误-日与月的关系非法\n");
				return 0;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day > 30 || day < 1)
			{
				printf("输入错误-日与月的关系非法\n");
				return 0;
			}
		}
		else
		{
			if (pan_duan_run_nian(year))
			{
				if (day < 1 || day>29)
				{
					printf("输入错误-日与月的关系非法\n");
					return 0;
				}
			}
			else
			{
				if (day < 1 || day>28)
				{
					printf("输入错误-日与月的关系非法\n");
					return 0;
				}
			}
		}
	}
	printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, ji_suan_tian_shu(pan_duan_run_nian(year), month, day));

	return 0;
}