// 2253209 ��07 ������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define pi 3.14159

int main()
{
	double r, h,c,s,S,v1,v2;
	printf("������뾶�͸߶�\n");
	scanf("%lf %lf", &r, &h);
	c = 2 * pi * r;
	s = pi * r * r;
	S = 4 * pi * r * r;
	v1 = 4.0 / 3 * pi * r * r * r;
	v2 = s * h;
	printf("Բ�ܳ�     : %.2f\n", c);
	printf("Բ���     : %.2f\n", s);
	printf("Բ������ : %.2f\n", S);
	printf("Բ�����   : %.2f\n", v1);
	printf("Բ�����   : %.2f\n", v2);

	return 0;
}