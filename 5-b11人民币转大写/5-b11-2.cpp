/* ��07 2253209 ������ */
#include <iostream>
#include <string>
//�ɰ���������Ҫ��ͷ�ļ�
using namespace std;

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
void daxie(int x)
{
	result = result + chnstr[2 * x] + chnstr[2 * x + 1];
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    /* --���������Ҫ������ --*/
    double num;
    int a, b, c, d, e, f, g, h, i, j, k, l;
    cout << "������[0-100��)֮�������:" << endl;
    cin >> num;
	num += 0.001;
	a = int(num / 1e9) % 10;
	b = int(num / 1e8) % 10;
	c = int(num / 1e7) % 10;
	d = int(num / 1e6) % 10;
	e = int(num / 1e5) % 10;
	f = int(num / 1e4) % 10;
	g = int(num / 1e3) % 10;
	h = int(num / 1e2) % 10;
	i = int(num / 10) % 10;
	j = int(num - a * 1e9) % 10;
	k = int(num * 10 - a * 1e10 - b * 1e9) % 10;
	l = int(num * 100 - a * 1e11 - b * 1e10 - c * 1e9) % 10;
	cout << "��д�����:" << endl;
	if (num == 0.001)
	{
		daxie(0);
		result += "Բ��";
	}
	else
	{
		if (a == 0)
		{
			;
		}
		else
		{
			daxie(a);
			result += "ʰ";
		}
		if (b == 0)
		{
			;
		}
		else
		{
			daxie(b);
		}
		if (a + b != 0)
		{
			result+="��";
		}
		if (c == 0)
		{
			if (a + b != 0 && d != 0)
			{
				daxie(c);
			}
			else
			{
				;
			}
		}
		else
		{
			daxie(c);
			result+="Ǫ";
		}
		if (d == 0)
		{
			if (a + b + c != 0 && e != 0)
			{
				daxie(d);
			}
			else
			{
				;
			}
		}
		else
		{
			daxie(d);
			result+="��";
		}
		if (e == 0)
		{
			if (a + b + c + d != 0 && f != 0)
			{
				daxie(e);
			}
			else
			{
				;
			}
		}
		else
		{
			daxie(e);
			result+="ʰ";
		}
		if (f == 0)
		{
			;
		}
		else
		{
			daxie(f);
		}
		if (c + d + e + f != 0)
		{
			result += "��";
		}
		if (g == 0)
		{
			if (a + b + c + d + e + f != 0 && h != 0)
			{
				daxie(g);
			}
			else
			{
				;
			}
		}
		else
		{
			daxie(g);
			result += "Ǫ";
		}
		if (h == 0)
		{
			if (a + b + c + d + e + f + g != 0 && i != 0)
			{
				daxie(h);
			}
			else
			{
				;
			}
		}
		else
		{
			daxie(h);
			result += "��";
		}
		if (i == 0)
		{
			if (a + b + c + d + e + f + g + h != 0 && j != 0)
			{
				daxie(i);
			}
			else
			{
				;
			}
		}
		else
		{
			daxie(i);
			result += "ʰ";
		}
		if (j == 0)
		{
			;
		}
		else
		{
			daxie(j);
		}
		if (a + b + c + d + e + f + g + h + i + j != 0)
		{
			result += "Բ";
		}
		if (k == 0)
		{
			if (a + b + c + d + e + f + g + h + i + j != 0 && l != 0)
			{
				daxie(k);
			}
			else
			{
				;
			}
		}
		else
		{
			daxie(k);
			result += "��";
		}
		if (l == 0)
		{
			result += "��";
		}
		else
		{
			daxie(l);
			result += "��" ;
		}
	}

    cout << result << endl;  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
    return 0;
}
