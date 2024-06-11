// 2253209 ĞÅ07 Áõ¼ÑÅó
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double num;
	cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:" << endl;
	cin >> num;
	num = num + 0.001;
	int a, b, c, d, e, f, g, h, i, j, k, l;
	a = int(num / 1e9) % 10;
	b = int(num / 1e8)% 10;
	c = int(num / 1e7) % 10;
	d = int(num / 1e6) % 10;
	e = int(num / 1e5) % 10;
	f = int(num / 1e4) % 10;
	g = int(num / 1e3) % 10;
	h = int(num / 1e2) % 10;
	i = int(num / 10) % 10;
	j = int(num-1e9*a) % 10;
	k = int(num * 10-1e10*a-1e9*b) % 10;
	l = int(num * 100 - 1e11 * a - 1e10 * b-1e9*c) % 10;
	cout << "´óĞ´½á¹ûÊÇ:" << endl;
	if (num != 0.001)
	{
		switch (a)
		{
			case 0:
				;
				break;
			case 1:
				cout << "Ò¼Ê°";
				break;
			case 2:
				cout << "·¡Ê°";
				break;
			case 3:
				cout << "ÈşÊ°";
				break;
			case 4:
				cout << "ËÁÊ°";
				break;
			case 5:
				cout << "ÎéÊ°";
				break;
			case 6:
				cout << "Â½Ê°";
				break;
			case 7:
				cout << "ÆâÊ°";
				break;
			case 8:
				cout << "°ÆÊ°";
				break;
			case 9:
				cout << "¾ÁÊ°";
				break;
		}
		switch (b)
		{
			case 0:
				;
				break;
			case 1:
				cout << "Ò¼ÒÚ";
				break;
			case 2:
				cout << "·¡ÒÚ";
				break;
			case 3:
				cout << "ÈşÒÚ";
				break;
			case 4:
				cout << "ËÁÒÚ";
				break;
			case 5:
				cout << "ÎéÒÚ";
				break;
			case 6:
				cout << "Â½ÒÚ";
				break;
			case 7:
				cout << "ÆâÒÚ";
				break;
			case 8:
				cout << "°ÆÒÚ";
				break;
			case 9:
				cout << "¾ÁÒÚ";
				break;
		}
		if (a != 0 && b == 0)
		{
			cout << "ÒÚ";
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
						cout << "Áã";
					}
				}
				break;
			case 1:
				cout << "Ò¼Çª";
				break;
			case 2:
				cout << "·¡Çª";
				break;
			case 3:
				cout << "ÈşÇª";
				break;
			case 4:
				cout << "ËÁÇª";
				break;
			case 5:
				cout << "ÎéÇª";
				break;
			case 6:
				cout << "Â½Çª";
				break;
			case 7:
				cout << "ÆâÇª";
				break;
			case 8:
				cout << "°ÆÇª";
				break;
			case 9:
				cout << "¾ÁÇª";
				break;
		}
		switch (d)
		{
			case 0:
				if (c != 0&&(e!=0||f!=0))
				{
					cout << "Áã";
				}
				break;
			case 1:
				cout << "Ò¼°Û";
				break;
			case 2:
				cout << "·¡°Û";
				break;
			case 3:
				cout << "Èş°Û";
				break;
			case 4:
				cout << "ËÁ°Û";
				break;
			case 5:
				cout << "Îé°Û";
				break;
			case 6:
				cout << "Â½°Û";
				break;
			case 7:
				cout << "Æâ°Û";
				break;
			case 8:
				cout << "°Æ°Û";
				break;
			case 9:
				cout << "¾Á°Û";
				break;
		}
		switch (e)
		{
			case 0:
				if (c != 0 && d != 0 && f != 0 || c == 0 && d != 0 && f != 0)
				{
					cout << "Áã";
				}
				break;
			case 1:
				cout << "Ò¼Ê°";
				break;
			case 2:
				cout << "·¡Ê°";
				break;
			case 3:
				cout << "ÈşÊ°";
				break;
			case 4:
				cout << "ËÁÊ°";
				break;
			case 5:
				cout << "ÎéÊ°";
				break;
			case 6:
				cout << "Â½Ê°";
				break;
			case 7:
				cout << "ÆâÊ°";
				break;
			case 8:
				cout << "°ÆÊ°";
				break;
			case 9:
				cout << "¾ÁÊ°";
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
					cout << "Íò";
				}
				break;
			case 1:
				cout << "Ò¼Íò";
				break;
			case 2:
				cout << "·¡Íò";
				break;
			case 3:
				cout << "ÈşÍò";
				break;
			case 4:
				cout << "ËÁÍò";
				break;
			case 5:
				cout << "ÎéÍò";
				break;
			case 6:
				cout << "Â½Íò";
				break;
			case 7:
				cout << "ÆâÍò";
				break;
			case 8:
				cout << "°ÆÍò";
				break;
			case 9:
				cout << "¾ÁÍò";
				break;
		}
		switch (g)
		{
			case 0:
				if ((c != 0 && d != 0 && f != 0 || c == 0 && d != 0 && f != 0) || (c != 0 && (e != 0 || f != 0)) || (a != 0 || b != 0) && (c != 0 || d != 0 || g != 0 || h != 0 || i != 0 || j != 0) || (h != 0 || i != 0 || j != 0) && (c != 0 || d != 0 || e != 0 || f != 0))
				{
					cout << "Áã";
				}
				break;
			case 1:
				cout << "Ò¼Çª";
				break;
			case 2:
				cout << "·¡Çª";
				break;
			case 3:
				cout << "ÈşÇª";
				break;
			case 4:
				cout << "ËÁÇª";
				break;
			case 5:
				cout << "ÎéÇª";
				break;
			case 6:
				cout << "Â½Çª";
				break;
			case 7:
				cout << "ÆâÇª";
				break;
			case 8:
				cout << "°ÆÇª";
				break;
			case 9:
				cout << "¾ÁÇª";
				break;
		}
		switch (h)
		{
			case 0:
				if (g != 0 && (i != 0 || j != 0))
				{
					cout << "Áã";
				}
				break;
			case 1:
				cout << "Ò¼°Û";
				break;
			case 2:
				cout << "·¡°Û";
				break;
			case 3:
				cout << "Èş°Û";
				break;
			case 4:
				cout << "ËÁ°Û";
				break;
			case 5:
				cout << "Îé°Û";
				break;
			case 6:
				cout << "Â½°Û";
				break;
			case 7:
				cout << "Æâ°Û";
				break;
			case 8:
				cout << "°Æ°Û";
				break;
			case 9:
				cout << "¾Á°Û";
				break;
		}
		switch (i)
		{
			case 0:
				if (g != 0 && h != 0 && j != 0 || g == 0 && h != 0 && j != 0)
				{
					cout << "Áã";
				}
				break;
			case 1:
				cout << "Ò¼Ê°";
				break;
			case 2:
				cout << "·¡Ê°";
				break;
			case 3:
				cout << "ÈşÊ°";
				break;
			case 4:
				cout << "ËÁÊ°";
				break;
			case 5:
				cout << "ÎéÊ°";
				break;
			case 6:
				cout << "Â½Ê°";
				break;
			case 7:
				cout << "ÆâÊ°";
				break;
			case 8:
				cout << "°ÆÊ°";
				break;
			case 9:
				cout << "¾ÁÊ°";
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
					cout << "Ô²";
				}
				break;
			case 1:
				cout << "Ò¼Ô²";
				break;
			case 2:
				cout << "·¡Ô²";
				break;
			case 3:
				cout << "ÈşÔ²";
				break;
			case 4:
				cout << "ËÁÔ²";
				break;
			case 5:
				cout << "ÎéÔ²";
				break;
			case 6:
				cout << "Â½Ô²";
				break;
			case 7:
				cout << "ÆâÔ²";
				break;
			case 8:
				cout << "°ÆÔ²";
				break;
			case 9:
				cout << "¾ÁÔ²";
				break;
		}
		switch (k)
		{
			case 0:
				if (l != 0 && num > 1)
				{
					cout << "Áã";
				}
				break;
			case 1:
				cout << "Ò¼½Ç";
				break;
			case 2:
				cout << "·¡½Ç";
				break;
			case 3:
				cout << "Èş½Ç";
				break;
			case 4:
				cout << "ËÁ½Ç";
				break;
			case 5:
				cout << "Îé½Ç";
				break;
			case 6:
				cout << "Â½½Ç";
				break;
			case 7:
				cout << "Æâ½Ç";
				break;
			case 8:
				cout << "°Æ½Ç";
				break;
			case 9:
				cout << "¾Á½Ç";
				break;
		}
		switch (l)
		{
			case 0:
				cout << "Õû" << endl;
				break;
			case 1:
				cout << "Ò¼·Ö" << endl;
				break;
			case 2:
				cout << "·¡·Ö" << endl;
				break;
			case 3:
				cout << "Èş·Ö" << endl;
				break;
			case 4:
				cout << "ËÁ·Ö" << endl;
				break;
			case 5:
				cout << "Îé·Ö" << endl;
				break;
			case 6:
				cout << "Â½·Ö" << endl;
				break;
			case 7:
				cout << "Æâ·Ö" << endl;
				break;
			case 8:
				cout << "°Æ·Ö" << endl;
				break;
			case 9:
				cout << "¾Á·Ö" << endl;
				break;
		}
	}
	else
	{
		cout << "ÁãÔ²Õû" << endl;
	}

	return 0;
}