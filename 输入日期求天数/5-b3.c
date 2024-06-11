// 2253209 ��07 ������
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
	printf("�������꣬�£���\n");
	scanf("%d %d %d", &year, &month, &day);
	if (month >= 13 || month <= 0)
	{
		printf("�������-�·ݲ���ȷ\n");
		return 0;
	}
	else
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day > 31 || day < 1)
			{
				printf("�������-�����µĹ�ϵ�Ƿ�\n");
				return 0;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day > 30 || day < 1)
			{
				printf("�������-�����µĹ�ϵ�Ƿ�\n");
				return 0;
			}
		}
		else
		{
			if (pan_duan_run_nian(year))
			{
				if (day < 1 || day>29)
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
					return 0;
				}
			}
			else
			{
				if (day < 1 || day>28)
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
					return 0;
				}
			}
		}
	}
	printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, ji_suan_tian_shu(pan_duan_run_nian(year), month, day));

	return 0;
}