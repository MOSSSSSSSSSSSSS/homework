// 2253209 ��07 ������
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
		printf("��������[1900-2100]���¡��գ�\n");
		if (scanf("%d %d %d", &y, &m, &d)!=3)
		{
			while (getchar() != '\n')
			{
				;
			}
			printf("�����������������\n");
		}
		else if (y < 1900 || y>2100)
		{
			printf("��ݲ���ȷ������������\n");

		}
		else if (m > 12 || m < 1)
		{
			printf("�·ݲ���ȷ������������\n");
		}
		else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		{
			if (d < 1 || d>31)
			{
				printf("�ղ���ȷ������������\n");
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
				printf("�ղ���ȷ������������\n");
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
				printf("�ղ���ȷ������������\n");
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
				printf("�ղ���ȷ������������\n");
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
		printf("������\n");
		break;
	case 1:
		printf("����һ\n");
		break;
	case 2:
		printf("���ڶ�\n");
		break;
	case 3:
		printf("������\n");
		break;
	case 4:
		printf("������\n");
		break;
	case 5:
		printf("������\n");
		break;
	case 6:
		printf("������\n");
		break;
	}
	return 0;
}