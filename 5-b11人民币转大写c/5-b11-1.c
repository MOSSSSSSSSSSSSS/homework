/* ��07 2253209 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
//�ɰ���������Ҫ��ͷ�ļ�

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void daxie(char arr[],int x)
{
	sprintf(arr, "%c%c", chnstr[2*x], chnstr[2*x+1]);
	strcat(result, arr);
}
int main()
{
    /* --���������Ҫ������ --*/
    printf("������[0-100��)֮�������:\n");
    double num;
    int a, b, c, d, e, f, g, h, i, j, k, l;
	char arr[3] = { 0,0,0 };
    scanf("%lf", &num);
    num += 0.001;
	a = (int)(num / 1e9) % 10;
	b = (int)(num / 1e8) % 10;
	c = (int)(num / 1e7) % 10;
	d = (int)(num / 1e6) % 10;
	e = (int)(num / 1e5) % 10;
	f = (int)(num / 1e4) % 10;
	g = (int)(num / 1e3) % 10;
	h = (int)(num / 1e2) % 10;
	i = (int)(num / 10) % 10;
	j = (int)(num - a * 1e9) % 10;
	k = (int)(num * 10 - a * 1e10 - b * 1e9) % 10;
	l = (int)(num * 100 - a * 1e11 - b * 1e10 - c * 1e9) % 10;
	printf("��д�����:\n");
	if (num == 0.001)
	{
		daxie(arr, 0);
		strcat(result, "Բ��");
	}
	else
	{
		if (a == 0)
		{
			;
		}
		else
		{
			daxie(arr, a);
			strcat(result, "ʰ");
		}
		if (b == 0)
		{
			;
		}
		else
		{
			daxie(arr,b);
		}
		if (a + b != 0)
		{
			strcat(result, "��");
		}
		if (c == 0)
		{
			if (a + b != 0 && d != 0)
			{
				daxie(arr,c);
			}
			else
			{
				;
			}
		}
		else
		{
			daxie(arr, c);
			strcat(result, "Ǫ");
		}
		if (d == 0)
		{
			if (a + b + c != 0 && e != 0)
			{
				daxie(arr,d);
			}
			else
			{
				;
			}
		}
		else
		{
			daxie(arr,d);
			strcat(result, "��");
		}
		if (e == 0)
		{
			if (a + b + c + d != 0 && f != 0)
			{
				daxie(arr,e);
			}
			else
			{
				;
			}
		}
		else
		{
			daxie(arr,e);
			strcat(result, "ʰ");
		}
		if (f == 0)
		{
			;
		}
		else
		{
			daxie(arr,f);
		}
		if (c + d + e + f != 0)
		{
			strcat(result, "��");
		}
		if (g == 0)
		{
			if (a + b + c + d + e + f != 0 && h != 0)
			{
				daxie(arr,g);
			}
			else
			{
				;
			}
		}
		else
		{
			daxie(arr,g);
			strcat(result, "Ǫ");
		}
		if (h == 0)
		{
			if (a + b + c + d + e + f + g != 0 && i != 0)
			{
				daxie(arr,h);
			}
			else
			{
				;
			}
		}
		else
		{
			daxie(arr,h);
			strcat(result, "��");
		}
		if (i == 0)
		{
			if (a + b + c + d + e + f + g + h != 0 && j != 0)
			{
				daxie(arr,i);
			}
			else
			{
				;
			}
		}
		else
		{
			daxie(arr,i);
			strcat(result, "ʰ");
		}
		if (j == 0)
		{
			;
		}
		else
		{
			daxie(arr,j);
		}
		if (a + b + c + d + e + f + g + h + i + j != 0)
		{
			strcat(result, "Բ");
		}
		if (k == 0)
		{
			if (a + b + c + d + e + f + g + h + i + j != 0 && l != 0)
			{
				daxie(arr,k);
			}
			else
			{
				;
			}
		}
		else
		{
			daxie(arr,k);
			strcat(result, "��");
		}
		if (l == 0)
		{
			strcat(result, "��");
		}
		else
		{
			daxie(arr,l);
			strcat(result, "��");
		}
	}
    printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
    return 0;
}
