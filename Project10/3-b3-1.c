// 2253209 ��07 ������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define ll long long

int main()
{
	double num;
	int a, b, c, d, e, f, g, h, i, k, l;
	ll j;
	printf("������[0-100��)֮�������:\n");
	scanf("%lf", &num);
	num = num + 0.001;
	a = (int)(num / 1000000000) % 10;
	b = (int)(num / 100000000) % 10;
	c = (int)(num / 10000000) % 10;
	d = (int)(num / 1000000) % 10;
	e = (int)(num / 100000) % 10;
	f = (int)(num / 10000) % 10;
	g = (int)(num / 1000) % 10;
	h = (int)(num / 100) % 10;
	i = (int)(num / 10) % 10;
	j = (int)(num - 1000000000 * a-100000000*b-10000000*c-1000000*d-100000*e-10000*f);
	k = (int)(num * 10 - 10000000000 * a - 1000000000 * b) % 10;
	l = (int)(num * 100 - 100000000000 * a - 10000000000 * b - 1000000000 * c) % 10;
	printf(" % .20f", num);
	printf("ʮ��λ : %d\n", a);
	printf("��λ   : %d\n", b);
	printf("ǧ��λ : %d\n", c);
	printf("����λ : %d\n", d);
	printf("ʮ��λ : %d\n", e);
	printf("��λ   : %d\n", f);
	printf("ǧλ   : %d\n", g);
	printf("��λ   : %d\n", h);
	printf("ʮλ   : %d\n", i);
	printf("Բ     : %d\n", j);
	printf("��     : %d\n", k);
	printf("��     : %d\n", l);

	return 0;
}
