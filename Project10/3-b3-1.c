// 2253209 信07 刘佳朋
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define ll long long

int main()
{
	double num;
	int a, b, c, d, e, f, g, h, i, k, l;
	ll j;
	printf("请输入[0-100亿)之间的数字:\n");
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
	printf("十亿位 : %d\n", a);
	printf("亿位   : %d\n", b);
	printf("千万位 : %d\n", c);
	printf("百万位 : %d\n", d);
	printf("十万位 : %d\n", e);
	printf("万位   : %d\n", f);
	printf("千位   : %d\n", g);
	printf("百位   : %d\n", h);
	printf("十位   : %d\n", i);
	printf("圆     : %d\n", j);
	printf("角     : %d\n", k);
	printf("分     : %d\n", l);

	return 0;
}
