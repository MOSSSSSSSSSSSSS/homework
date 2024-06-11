// 2253209 信07 刘佳朋
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define pi 3.14159

int main()
{
	double d;
	float s;
	int a, b, c;
	printf("请输入三角形的两边及其夹角(角度)\n");
	scanf("%d %d %d", &a, &b, &c);
	d = c * pi / 180;
	s = 1.0 / 2 * a * b * sin(d);
	printf("三角形面积为 : %.3f\n", s);

	return 0;
}