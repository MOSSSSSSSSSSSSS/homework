// 2253209 ��07 ������
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double num;
	cout << "������[0-100��)֮�������:" << endl;
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
	cout << "��д�����:" << endl;
	if (num != 0.001)
	{
		switch (a)
		{
			case 0:
				;
				break;
			case 1:
				cout << "Ҽʰ";
				break;
			case 2:
				cout << "��ʰ";
				break;
			case 3:
				cout << "��ʰ";
				break;
			case 4:
				cout << "��ʰ";
				break;
			case 5:
				cout << "��ʰ";
				break;
			case 6:
				cout << "½ʰ";
				break;
			case 7:
				cout << "��ʰ";
				break;
			case 8:
				cout << "��ʰ";
				break;
			case 9:
				cout << "��ʰ";
				break;
		}
		switch (b)
		{
			case 0:
				;
				break;
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "����";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "����";
				break;
			case 8:
				cout << "����";
				break;
			case 9:
				cout << "����";
				break;
		}
		if (a != 0 && b == 0)
		{
			cout << "��";
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
						cout << "��";
					}
				}
				break;
			case 1:
				cout << "ҼǪ";
				break;
			case 2:
				cout << "��Ǫ";
				break;
			case 3:
				cout << "��Ǫ";
				break;
			case 4:
				cout << "��Ǫ";
				break;
			case 5:
				cout << "��Ǫ";
				break;
			case 6:
				cout << "½Ǫ";
				break;
			case 7:
				cout << "��Ǫ";
				break;
			case 8:
				cout << "��Ǫ";
				break;
			case 9:
				cout << "��Ǫ";
				break;
		}
		switch (d)
		{
			case 0:
				if (c != 0&&(e!=0||f!=0))
				{
					cout << "��";
				}
				break;
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "���";
				break;
			case 8:
				cout << "�ư�";
				break;
			case 9:
				cout << "����";
				break;
		}
		switch (e)
		{
			case 0:
				if (c != 0 && d != 0 && f != 0 || c == 0 && d != 0 && f != 0)
				{
					cout << "��";
				}
				break;
			case 1:
				cout << "Ҽʰ";
				break;
			case 2:
				cout << "��ʰ";
				break;
			case 3:
				cout << "��ʰ";
				break;
			case 4:
				cout << "��ʰ";
				break;
			case 5:
				cout << "��ʰ";
				break;
			case 6:
				cout << "½ʰ";
				break;
			case 7:
				cout << "��ʰ";
				break;
			case 8:
				cout << "��ʰ";
				break;
			case 9:
				cout << "��ʰ";
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
					cout << "��";
				}
				break;
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "����";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "����";
				break;
			case 8:
				cout << "����";
				break;
			case 9:
				cout << "����";
				break;
		}
		switch (g)
		{
			case 0:
				if ((c != 0 && d != 0 && f != 0 || c == 0 && d != 0 && f != 0) || (c != 0 && (e != 0 || f != 0)) || (a != 0 || b != 0) && (c != 0 || d != 0 || g != 0 || h != 0 || i != 0 || j != 0) || (h != 0 || i != 0 || j != 0) && (c != 0 || d != 0 || e != 0 || f != 0))
				{
					cout << "��";
				}
				break;
			case 1:
				cout << "ҼǪ";
				break;
			case 2:
				cout << "��Ǫ";
				break;
			case 3:
				cout << "��Ǫ";
				break;
			case 4:
				cout << "��Ǫ";
				break;
			case 5:
				cout << "��Ǫ";
				break;
			case 6:
				cout << "½Ǫ";
				break;
			case 7:
				cout << "��Ǫ";
				break;
			case 8:
				cout << "��Ǫ";
				break;
			case 9:
				cout << "��Ǫ";
				break;
		}
		switch (h)
		{
			case 0:
				if (g != 0 && (i != 0 || j != 0))
				{
					cout << "��";
				}
				break;
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "���";
				break;
			case 8:
				cout << "�ư�";
				break;
			case 9:
				cout << "����";
				break;
		}
		switch (i)
		{
			case 0:
				if (g != 0 && h != 0 && j != 0 || g == 0 && h != 0 && j != 0)
				{
					cout << "��";
				}
				break;
			case 1:
				cout << "Ҽʰ";
				break;
			case 2:
				cout << "��ʰ";
				break;
			case 3:
				cout << "��ʰ";
				break;
			case 4:
				cout << "��ʰ";
				break;
			case 5:
				cout << "��ʰ";
				break;
			case 6:
				cout << "½ʰ";
				break;
			case 7:
				cout << "��ʰ";
				break;
			case 8:
				cout << "��ʰ";
				break;
			case 9:
				cout << "��ʰ";
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
					cout << "Բ";
				}
				break;
			case 1:
				cout << "ҼԲ";
				break;
			case 2:
				cout << "��Բ";
				break;
			case 3:
				cout << "��Բ";
				break;
			case 4:
				cout << "��Բ";
				break;
			case 5:
				cout << "��Բ";
				break;
			case 6:
				cout << "½Բ";
				break;
			case 7:
				cout << "��Բ";
				break;
			case 8:
				cout << "��Բ";
				break;
			case 9:
				cout << "��Բ";
				break;
		}
		switch (k)
		{
			case 0:
				if (l != 0 && num > 1)
				{
					cout << "��";
				}
				break;
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "���";
				break;
			case 8:
				cout << "�ƽ�";
				break;
			case 9:
				cout << "����";
				break;
		}
		switch (l)
		{
			case 0:
				cout << "��" << endl;
				break;
			case 1:
				cout << "Ҽ��" << endl;
				break;
			case 2:
				cout << "����" << endl;
				break;
			case 3:
				cout << "����" << endl;
				break;
			case 4:
				cout << "����" << endl;
				break;
			case 5:
				cout << "���" << endl;
				break;
			case 6:
				cout << "½��" << endl;
				break;
			case 7:
				cout << "���" << endl;
				break;
			case 8:
				cout << "�Ʒ�" << endl;
				break;
			case 9:
				cout << "����" << endl;
				break;
		}
	}
	else
	{
		cout << "��Բ��" << endl;
	}

	return 0;
}