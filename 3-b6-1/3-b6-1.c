// 2253209 ��07 ������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	double num;
	printf("������[0-100��)֮�������:\n");
	scanf("%lf", &num);
	num = num + 0.001;
	int a, b, c, d, e, f, g, h, i, j, k, l;
	a = (int)(num / 1e9) % 10;
	b = (int)(num / 1e8) % 10;
	c = (int)(num / 1e7) % 10;
	d = (int)(num / 1e6) % 10;
	e = (int)(num / 1e5) % 10;
	f = (int)(num / 1e4) % 10;
	g = (int)(num / 1e3) % 10;
	h = (int)(num / 1e2) % 10;
	i = (int)(num / 10) % 10;
	j = (int)(num - 1e9 * a) % 10;
	k = (int)(num * 10 - 1e10 * a - 1e9 * b) % 10;
	l = (int)(num * 100 - 1e11 * a - 1e10 * b - 1e9 * c) % 10;
	printf("��д�����:\n");
	if (num != 0.001)
	{
		switch (a)
		{
			case 0:
				;
				break;
			case 1:
				printf("Ҽʰ");
				break;
			case 2:
				printf("��ʰ");
				break;
			case 3:
				printf("��ʰ");
				break;
			case 4:
				printf("��ʰ");
				break;
			case 5:
				printf("��ʰ");
				break;
			case 6:
				printf("½ʰ");
				break;
			case 7:
				printf("��ʰ");
				break;
			case 8:
				printf("��ʰ");
				break;
			case 9:
				printf("��ʰ");
				break;
		}
		switch (b)
		{
			case 0:
				;
				break;
			case 1:
				printf("Ҽ��");
				break;
			case 2:
				printf("����");
				break;
			case 3:
				printf("����");
				break;
			case 4:
				printf("����");
				break;
			case 5:
				printf("����");
				break;
			case 6:
				printf("½��");
				break;
			case 7:
				printf("����");
				break;
			case 8:
				printf("����");
				break;
			case 9:
				printf("����");
				break;
		}
		if (a != 0 && b == 0)
		{
			printf("��");
		}
		switch (c)
		{
			case 0:
				if ((a != 0 || b != 0) && (c != 0 || d != 0 || g != 0 || h != 0 || i != 0 || j != 0))
				{
					if (c == 0 && d == 0 && e == 0 && f == 0)
					{
						;
					}
					else
					{
						printf("��");
					}
				}
				break;
			case 1:
				printf("ҼǪ");
				break;
			case 2:
				printf("��Ǫ");
				break;
			case 3:
				printf("��Ǫ");
				break;
			case 4:
				printf("��Ǫ");
				break;
			case 5:
				printf("��Ǫ");
				break;
			case 6:
				printf("½Ǫ");
				break;
			case 7:
				printf("��Ǫ");
				break;
			case 8:
				printf("��Ǫ");
				break;
			case 9:
				printf("��Ǫ");
				break;
		}
		switch (d)
		{
			case 0:
				if (c != 0 && (e != 0 || f != 0))
				{
					printf("��");
				}
				break;
			case 1:
				printf("Ҽ��");
				break;
			case 2:
				printf("����");
				break;
			case 3:
				printf("����");
				break;
			case 4:
				printf("����");
				break;
			case 5:
				printf("���");
				break;
			case 6:
				printf("½��");
				break;
			case 7:
				printf("���");
				break;
			case 8:
				printf("�ư�");
				break;
			case 9:
				printf("����");
				break;
		}
		switch (e)
		{
			case 0:
				if (c != 0 && d != 0 && f != 0 || c == 0 && d != 0 && f != 0)
				{
					printf("��");
				}
				break;
			case 1:
				printf("Ҽʰ");
				break;
			case 2:
				printf("��ʰ");
				break;
			case 3:
				printf("��ʰ");
				break;
			case 4:
				printf("��ʰ");
				break;
			case 5:
				printf("��ʰ");
				break;
			case 6:
				printf("½ʰ");
				break;
			case 7:
				printf("��ʰ");
				break;
			case 8:
				printf("��ʰ");
				break;
			case 9:
				printf("��ʰ");
				break;
		}
		switch (f)
		{
			case 0:
				if (c == 0 && d == 0 && e == 0)
				{
					;
				}
				else
				{
					printf("��");
				}
				break;
			case 1:
				printf("Ҽ��");
				break;
			case 2:
				printf("����");
				break;
			case 3:
				printf("����");
				break;
			case 4:
				printf("����");
				break;
			case 5:
				printf("����");
				break;
			case 6:
				printf("½��");
				break;
			case 7:
				printf("����");
				break;
			case 8:
				printf("����");
				break;
			case 9:
				printf("����");
				break;
		}
		switch (g)
		{
			case 0:
				if ((c != 0 && d != 0 && f != 0 || c == 0 && d != 0 && f != 0) || (c != 0 && (e != 0 || f != 0)) || (a != 0 || b != 0) && (c != 0 || d != 0 || g != 0 || h != 0 || i != 0 || j != 0) || (h != 0 || i != 0 || j != 0) && (c != 0 || d != 0 || e != 0 || f != 0))
				{
					printf("��");
				}
				break;
			case 1:
				printf("ҼǪ");
				break;
			case 2:
				printf("��Ǫ");
				break;
			case 3:
				printf("��Ǫ");
				break;
			case 4:
				printf("��Ǫ");
				break;
			case 5:
				printf("��Ǫ");
				break;
			case 6:
				printf("½Ǫ");
				break;
			case 7:
				printf("��Ǫ");
				break;
			case 8:
				printf("��Ǫ");
				break;
			case 9:
				printf("��Ǫ");
				break;
		}
		switch (h)
		{
			case 0:
				if (g != 0 && (i != 0 || j != 0))
				{
					printf("��");
				}
				break;
			case 1:
				printf("Ҽ��");
				break;
			case 2:
				printf("����");
				break;
			case 3:
				printf("����");
				break;
			case 4:
				printf("����");
				break;
			case 5:
				printf("���");
				break;
			case 6:
				printf("½��");
				break;
			case 7:
				printf("���");
				break;
			case 8:
				printf("�ư�");
				break;
			case 9:
				printf("����");
				break;
		}
		switch (i)
		{
			case 0:
				if (g != 0 && h != 0 && j != 0 || g == 0 && h != 0 && j != 0)
				{
					printf("��");
				}
				break;
			case 1:
				printf("Ҽʰ");
				break;
			case 2:
				printf("��ʰ");
				break;
			case 3:
				printf("��ʰ");
				break;
			case 4:
				printf("��ʰ");
				break;
			case 5:
				printf("��ʰ");
				break;
			case 6:
				printf("½ʰ");
				break;
			case 7:
				printf("��ʰ");
				break;
			case 8:
				printf("��ʰ");
				break;
			case 9:
				printf("��ʰ");
				break;
		}
		switch (j)
		{
			case 0:
				if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0)
				{
					;
				}
				else
				{
					printf("Բ");
				}
				break;
			case 1:
				printf("ҼԲ");
				break;
			case 2:
				printf("��Բ");
				break;
			case 3:
				printf("��Բ");
				break;
			case 4:
				printf("��Բ");
				break;
			case 5:
				printf("��Բ");
				break;
			case 6:
				printf("½Բ");
				break;
			case 7:
				printf("��Բ");
				break;
			case 8:
				printf("��Բ");
				break;
			case 9:
				printf("��Բ");
				break;
		}
		switch (k)
		{
			case 0:
				if (l != 0 && num > 1)
				{
					printf("��");
				}
				break;
			case 1:
				printf("Ҽ��");
				break;
			case 2:
				printf("����");
				break;
			case 3:
				printf("����");
				break;
			case 4:
				printf("����");
				break;
			case 5:
				printf("���");
				break;
			case 6:
				printf("½��");
				break;
			case 7:
				printf("���");
				break;
			case 8:
				printf("�ƽ�");
				break;
			case 9:
				printf("����");
				break;
		}
		switch (l)
		{
			case 0:
				printf("��\n");
				break;
			case 1:
				printf("Ҽ��\n");
				break;
			case 2:
				printf("����\n");
				break;
			case 3:
				printf("����\n");
				break;
			case 4:
				printf("����\n");
				break;
			case 5:
				printf("���\n");
				break;
			case 6:
				printf("½��\n");
				break;
			case 7:
				printf("���\n");
				break;
			case 8:
				printf("�Ʒ�\n");
				break;
			case 9:
				printf("����\n");
				break;
		}
	}
	else
	{
		printf("��Բ��\n");
	}

	return 0;
}