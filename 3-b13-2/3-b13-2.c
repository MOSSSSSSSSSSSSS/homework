// 2253209 信07 刘佳朋
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int y, m, w;
	while (1)
	{
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		if (scanf("%d %d", &y, &m)==0)
		{
			while (getchar() != '\n')
			{
				;
			}
		}
		else if (y >= 2000 && y <= 2030 && m >= 1 && m <= 12)
		{
			break;
		}
		else
		{
			;
		}
		printf("输入非法，请重新输入\n");
	}
	while (1)
	{
		printf("请输入2000年6月1日的星期(0-6表示星期日-星期六) : ");
		if (scanf("%d", &w)==0)
		{
			while (getchar() != '\n')
			{
				;
			}
		}
		else if (w >= 0 && w <= 6)
		{
			break;
		}
		else
		{
			;
		}
		printf("输入非法，请重新输入\n");
	}
	printf("\n");
	printf("%d年%d月的月历为:\n", y, m);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		for (int k = 1; k <= 31; k++)
		{
			if ((k - 8 + w) % 7 == 0)
			{
				printf("%4d", k);
			}
			else if (k == 1)
			{
				if (w == 0)
				{
					printf("%4d", k);
				}
				else if (w == 1)
				{
					printf("%12d", k);
				}
				else if (w == 2)
				{
					printf("%20d", k);
				}
				else if (w == 3)
				{
					printf("%28d", k);
				}
				else if (w == 4)
				{
					printf("%36d", k);
				}
				else if (w == 5)
				{
					printf("%44d", k);
				}
				else
				{
					printf("%52d", k);
				}
			}
			else
			{
				printf("%8d", k);
			}
			if ((k + w) % 7 == 0)
			{
				printf("\n");
			}
		}
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		for (int k = 1; k <= 30; k++)
		{
			if ((k - 8 + w) % 7 == 0)
			{
				printf("%4d", k);
			}
			else if (k == 1)
			{
				if (w == 0)
				{
					printf("%4d", k);
				}
				else if (w == 1)
				{
					printf("%12d", k);
				}
				else if (w == 2)
				{
					printf("%20d", k);
				}
				else if (w == 3)
				{
					printf("%28d", k);
				}
				else if (w == 4)
				{
					printf("%36d", k);
				}
				else if (w == 5)
				{
					printf("%44d", k);
				}
				else
				{
					printf("%52d", k);
				}
			}
			else
			{
				printf("%8d", k);
			}
			if ((k + w) % 7 == 0)
			{
				printf("\n");
			}
		}
	}
	else
	{
		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		{
			for (int k = 1; k <= 29; k++)
			{
				if ((k - 8 + w) % 7 == 0)
				{
					printf("%4d", k);
				}
				else if (k == 1)
				{
					if (w == 0)
					{
						printf("%4d", k);
					}
					else if (w == 1)
					{
						printf("%12d", k);
					}
					else if (w == 2)
					{
						printf("%20d", k);
					}
					else if (w == 3)
					{
						printf("%28d", k);
					}
					else if (w == 4)
					{
						printf("%36d", k);
					}
					else if (w == 5)
					{
						printf("%44d", k);
					}
					else
					{
						printf("%52d", k);
					}
				}
				else
				{
					printf("%8d", k);
				}
				if ((k + w) % 7 == 0)
				{
					printf("\n");
				}
			}
		}
		else
		{
			for (int k = 1; k <= 28; k++)
			{
				if ((k - 8 + w) % 7 == 0)
				{
					printf("%4d", k);
				}
				else if (k == 1)
				{
					if (w == 0)
					{
						printf("%4d", k);
					}
					else if (w == 1)
					{
						printf("%12d", k);
					}
					else if (w == 2)
					{
						printf("%20d", k);
					}
					else if (w == 3)
					{
						printf("%28d", k);
					}
					else if (w == 4)
					{
						printf("%36d", k);
					}
					else if (w == 5)
					{
						printf("%44d", k);
					}
					else
					{
						printf("%52d", k);
					}
				}
				else
				{
					printf("%8d", k);
				}
				if ((k + w) % 7 == 0)
				{
					printf("\n");
				}
			}
		}
	}

	return 0;
}