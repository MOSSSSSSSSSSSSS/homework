// 2253209 ��07 ������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int num,a,b,c,d,e;
	printf("������һ��[1..30000]�������:\n");
	scanf("%d", &num);
	a = num / 10000;
	b = num / 1000 % 10;
	c = num / 100 % 10;
	d = num / 10 % 10;
	e = num % 10;
	printf("��λ : %d\n", a);
	printf("ǧλ : %d\n", b);
	printf("��λ : %d\n", c);
	printf("ʮλ : %d\n", d);
	printf("��λ : %d\n", e);

	return 0;
}