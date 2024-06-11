// 2253209 ĞÅ07 Áõ¼ÑÅó
#include<iostream>
using namespace std;

void daxie(int x)
{
	switch (x)
	{
		case 0:
			cout << "Áã";
			break;
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èş";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
	}
}
int main()
{
	double num;
	int a, b, c, d, e, f, g, h, i, j, k, l;
	while (1)
	{
		cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:" << endl;
		cin >> num;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if (num < 0 || num >= 1e10)
		{
			;
		}
		else
		{
			break;
		}
	}
	num+=0.001;
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
	cout << "´óĞ´½á¹ûÊÇ:" << endl;
	if (num == 0.001)
	{
		cout << "ÁãÔ²Õû"<<endl;
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
			cout << "Ê°";
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
			cout << "ÒÚ";
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
			cout << "Çª";
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
			cout << "°Û";
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
			cout << "Ê°";
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
			cout << "Íò";
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
			cout << "Çª";
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
			cout << "°Û";
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
			cout << "Ê°";
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
			cout << "Ô²";
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
			cout << "½Ç";
		}
		if (l == 0)
		{
			cout << "Õû" << endl;
		}
		else
		{
			daxie(l);
			cout << "·Ö" << endl;
		}
	}
	return 0;
}