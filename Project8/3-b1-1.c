// 2253209 信07 刘佳朋
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define pi 3.14159

int main()
{
	double r, h,c,s,S,v1,v2;
	printf("请输入半径和高度\n");
	scanf("%lf %lf", &r, &h);
	c = 2 * pi * r;
	s = pi * r * r;
	S = 4 * pi * r * r;
	v1 = 4.0 / 3 * pi * r * r * r;
	v2 = s * h;
	printf("圆周长     : %.2f\n", c);
	printf("圆面积     : %.2f\n", s);
	printf("圆球表面积 : %.2f\n", S);
	printf("圆球体积   : %.2f\n", v1);
	printf("圆柱体积   : %.2f\n", v2);

	return 0;
}