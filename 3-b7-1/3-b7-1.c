// 2253209 ��07 ������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	double num;
	int s, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0;
	printf("����������ֵ��\n");
	scanf("%lf", &num);
	if (num >= 50)
	{
		a = 1;
		num -= 50;
	}
	if (num >= 40)
	{
		b = 2;
		num -= 40;
	}
	if (num >= 30)
	{
		b = 1;
		c = 1;
		num -= 30;
	}
	if (num >= 20)
	{
		b = 1;
		num -= 20;
	}
	if (num >= 10)
	{
		c = 1;
		num -= 10;
	}
	if (num >= 5)
	{
		d = 1;
		num -= 5;
	}
	if (num >= 1)
	{
		e = (int)(num);
		num -= e;
	}
	if (num >= 0.5)
	{
		f = 1;
		num -= 0.5;
	}
	if (num >= 0.1)
	{
		g = (int)(num * 10);
		num -= g * 0.1;
	}
	if (num >= 0.05)
	{
		h = 1;
		num -= 0.05;
	}
	if (num >= 0.02)
	{
		i = (int)(num / 0.02);
		num -= i * 0.02;
	}
	if (num - 0.01 >= 0)
	{
		j = 1;
	}
	s = a + b + c + d + e + f + g + h + i + j;
	printf("��%d�����㣬�������£�\n", s);
	if (a != 0)
	{
		printf("50Ԫ : %d��\n", a);
	}
	if (b != 0)
	{
		printf("20Ԫ : %d��\n", b);
	}
	if (c != 0)
	{
		printf("10Ԫ : %d��\n", c);
	}
	if (d != 0)
	{
		printf("5Ԫ  : %d��\n", d);
	}
	if (e != 0)
	{
		printf("1Ԫ  : %d��\n", e);
	}
	if (f != 0)
	{
		printf("5��  : %d��\n", f);
	}
	if (g != 0)
	{
		printf("1��  : %d��\n", g);
	}
	if (h != 0)
	{
		printf("5��  : %d��\n", h);
	}
	if (i != 0)
	{
		printf("2��  : %d��\n", i);
	}
	if (j != 0)
	{
		printf("1��  : %d��\n", j);
	}
	return 0;
}