// 2253209 ��07 ������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define pi 3.14159

int main()
{
	double d;
	float s;
	int a, b, c;
	printf("�����������ε����߼���н�(�Ƕ�)\n");
	scanf("%d %d %d", &a, &b, &c);
	d = c * pi / 180;
	s = 1.0 / 2 * a * b * sin(d);
	printf("���������Ϊ : %.3f\n", s);

	return 0;
}