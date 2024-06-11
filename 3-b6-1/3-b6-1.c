// 2253209 ÐÅ07 Áõ¼ÑÅó
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	double num;
	printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n");
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
	printf("´óÐ´½á¹ûÊÇ:\n");
	if (num != 0.001)
	{
		switch (a)
		{
			case 0:
				;
				break;
			case 1:
				printf("Ò¼Ê°");
				break;
			case 2:
				printf("·¡Ê°");
				break;
			case 3:
				printf("ÈþÊ°");
				break;
			case 4:
				printf("ËÁÊ°");
				break;
			case 5:
				printf("ÎéÊ°");
				break;
			case 6:
				printf("Â½Ê°");
				break;
			case 7:
				printf("ÆâÊ°");
				break;
			case 8:
				printf("°ÆÊ°");
				break;
			case 9:
				printf("¾ÁÊ°");
				break;
		}
		switch (b)
		{
			case 0:
				;
				break;
			case 1:
				printf("Ò¼ÒÚ");
				break;
			case 2:
				printf("·¡ÒÚ");
				break;
			case 3:
				printf("ÈþÒÚ");
				break;
			case 4:
				printf("ËÁÒÚ");
				break;
			case 5:
				printf("ÎéÒÚ");
				break;
			case 6:
				printf("Â½ÒÚ");
				break;
			case 7:
				printf("ÆâÒÚ");
				break;
			case 8:
				printf("°ÆÒÚ");
				break;
			case 9:
				printf("¾ÁÒÚ");
				break;
		}
		if (a != 0 && b == 0)
		{
			printf("ÒÚ");
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
						printf("Áã");
					}
				}
				break;
			case 1:
				printf("Ò¼Çª");
				break;
			case 2:
				printf("·¡Çª");
				break;
			case 3:
				printf("ÈþÇª");
				break;
			case 4:
				printf("ËÁÇª");
				break;
			case 5:
				printf("ÎéÇª");
				break;
			case 6:
				printf("Â½Çª");
				break;
			case 7:
				printf("ÆâÇª");
				break;
			case 8:
				printf("°ÆÇª");
				break;
			case 9:
				printf("¾ÁÇª");
				break;
		}
		switch (d)
		{
			case 0:
				if (c != 0 && (e != 0 || f != 0))
				{
					printf("Áã");
				}
				break;
			case 1:
				printf("Ò¼°Û");
				break;
			case 2:
				printf("·¡°Û");
				break;
			case 3:
				printf("Èþ°Û");
				break;
			case 4:
				printf("ËÁ°Û");
				break;
			case 5:
				printf("Îé°Û");
				break;
			case 6:
				printf("Â½°Û");
				break;
			case 7:
				printf("Æâ°Û");
				break;
			case 8:
				printf("°Æ°Û");
				break;
			case 9:
				printf("¾Á°Û");
				break;
		}
		switch (e)
		{
			case 0:
				if (c != 0 && d != 0 && f != 0 || c == 0 && d != 0 && f != 0)
				{
					printf("Áã");
				}
				break;
			case 1:
				printf("Ò¼Ê°");
				break;
			case 2:
				printf("·¡Ê°");
				break;
			case 3:
				printf("ÈþÊ°");
				break;
			case 4:
				printf("ËÁÊ°");
				break;
			case 5:
				printf("ÎéÊ°");
				break;
			case 6:
				printf("Â½Ê°");
				break;
			case 7:
				printf("ÆâÊ°");
				break;
			case 8:
				printf("°ÆÊ°");
				break;
			case 9:
				printf("¾ÁÊ°");
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
					printf("Íò");
				}
				break;
			case 1:
				printf("Ò¼Íò");
				break;
			case 2:
				printf("·¡Íò");
				break;
			case 3:
				printf("ÈþÍò");
				break;
			case 4:
				printf("ËÁÍò");
				break;
			case 5:
				printf("ÎéÍò");
				break;
			case 6:
				printf("Â½Íò");
				break;
			case 7:
				printf("ÆâÍò");
				break;
			case 8:
				printf("°ÆÍò");
				break;
			case 9:
				printf("¾ÁÍò");
				break;
		}
		switch (g)
		{
			case 0:
				if ((c != 0 && d != 0 && f != 0 || c == 0 && d != 0 && f != 0) || (c != 0 && (e != 0 || f != 0)) || (a != 0 || b != 0) && (c != 0 || d != 0 || g != 0 || h != 0 || i != 0 || j != 0) || (h != 0 || i != 0 || j != 0) && (c != 0 || d != 0 || e != 0 || f != 0))
				{
					printf("Áã");
				}
				break;
			case 1:
				printf("Ò¼Çª");
				break;
			case 2:
				printf("·¡Çª");
				break;
			case 3:
				printf("ÈþÇª");
				break;
			case 4:
				printf("ËÁÇª");
				break;
			case 5:
				printf("ÎéÇª");
				break;
			case 6:
				printf("Â½Çª");
				break;
			case 7:
				printf("ÆâÇª");
				break;
			case 8:
				printf("°ÆÇª");
				break;
			case 9:
				printf("¾ÁÇª");
				break;
		}
		switch (h)
		{
			case 0:
				if (g != 0 && (i != 0 || j != 0))
				{
					printf("Áã");
				}
				break;
			case 1:
				printf("Ò¼°Û");
				break;
			case 2:
				printf("·¡°Û");
				break;
			case 3:
				printf("Èþ°Û");
				break;
			case 4:
				printf("ËÁ°Û");
				break;
			case 5:
				printf("Îé°Û");
				break;
			case 6:
				printf("Â½°Û");
				break;
			case 7:
				printf("Æâ°Û");
				break;
			case 8:
				printf("°Æ°Û");
				break;
			case 9:
				printf("¾Á°Û");
				break;
		}
		switch (i)
		{
			case 0:
				if (g != 0 && h != 0 && j != 0 || g == 0 && h != 0 && j != 0)
				{
					printf("Áã");
				}
				break;
			case 1:
				printf("Ò¼Ê°");
				break;
			case 2:
				printf("·¡Ê°");
				break;
			case 3:
				printf("ÈþÊ°");
				break;
			case 4:
				printf("ËÁÊ°");
				break;
			case 5:
				printf("ÎéÊ°");
				break;
			case 6:
				printf("Â½Ê°");
				break;
			case 7:
				printf("ÆâÊ°");
				break;
			case 8:
				printf("°ÆÊ°");
				break;
			case 9:
				printf("¾ÁÊ°");
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
					printf("Ô²");
				}
				break;
			case 1:
				printf("Ò¼Ô²");
				break;
			case 2:
				printf("·¡Ô²");
				break;
			case 3:
				printf("ÈþÔ²");
				break;
			case 4:
				printf("ËÁÔ²");
				break;
			case 5:
				printf("ÎéÔ²");
				break;
			case 6:
				printf("Â½Ô²");
				break;
			case 7:
				printf("ÆâÔ²");
				break;
			case 8:
				printf("°ÆÔ²");
				break;
			case 9:
				printf("¾ÁÔ²");
				break;
		}
		switch (k)
		{
			case 0:
				if (l != 0 && num > 1)
				{
					printf("Áã");
				}
				break;
			case 1:
				printf("Ò¼½Ç");
				break;
			case 2:
				printf("·¡½Ç");
				break;
			case 3:
				printf("Èþ½Ç");
				break;
			case 4:
				printf("ËÁ½Ç");
				break;
			case 5:
				printf("Îé½Ç");
				break;
			case 6:
				printf("Â½½Ç");
				break;
			case 7:
				printf("Æâ½Ç");
				break;
			case 8:
				printf("°Æ½Ç");
				break;
			case 9:
				printf("¾Á½Ç");
				break;
		}
		switch (l)
		{
			case 0:
				printf("Õû\n");
				break;
			case 1:
				printf("Ò¼·Ö\n");
				break;
			case 2:
				printf("·¡·Ö\n");
				break;
			case 3:
				printf("Èþ·Ö\n");
				break;
			case 4:
				printf("ËÁ·Ö\n");
				break;
			case 5:
				printf("Îé·Ö\n");
				break;
			case 6:
				printf("Â½·Ö\n");
				break;
			case 7:
				printf("Æâ·Ö\n");
				break;
			case 8:
				printf("°Æ·Ö\n");
				break;
			case 9:
				printf("¾Á·Ö\n");
				break;
		}
	}
	else
	{
		printf("ÁãÔ²Õû\n");
	}

	return 0;
}