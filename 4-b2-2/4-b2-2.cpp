// 2253209 ��07 ������
#include<iostream>
using namespace std;

int zeller(int y, int m, int d)
{
	if (m == 1 || m == 2)
	{
		m += 12;
		y--;
	}
	int w, c1, c2;
	c1 = y / 100;
	c2 = y - c1 * 100;
	w = c2 + c2 / 4 + c1 / 4 - 2*c1 + 13*(m + 1) / 5 + d - 1;
	if (w <= 0)
	{
		for (int i = 1; w <= 0;)
		{
			w += i * 7;
		}
	}
	w %= 7;
	return w;
}
int main()
{
	int y, m, d, w;
	while (1)
	{
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> y >> m >> d;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "�����������������" << endl;
		}
		else if (y < 1900 || y>2100)
		{
			cout << "��ݲ���ȷ������������" << endl;

		}
		else if (m > 12 || m < 1)
		{
			cout << "�·ݲ���ȷ������������" << endl;
		}
		else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		{
			if (d < 1 || d>31)
			{
				cout << "�ղ���ȷ������������" << endl;
			}
			else
			{
				break;
			}
		}
		else if (m == 4 || m == 6 || m == 9 || m == 11)
		{
			if (d < 1 || d>30)
			{
				cout << "�ղ���ȷ������������" << endl;
			}
			else
			{
				break;
			}
		}
		else if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		{
			if (d < 1 || d>29)
			{
				cout << "�ղ���ȷ������������" << endl;
			}
			else
			{
				break;
			}
		}
		else
		{
			if (d < 1 || d>28)
			{
				cout << "�ղ���ȷ������������" << endl;
			}
			else
			{
				break;
			}
		}
	}
	w = zeller(y, m, d);
	switch (w)
	{
		case 0:
			cout << "������"<<endl;
			break;
		case 1:
			cout << "����һ" << endl;
			break;
		case 2:
			cout << "���ڶ�" << endl;
			break;
		case 3:
			cout << "������" << endl;
			break;
		case 4:
			cout << "������" << endl;
			break;
		case 5:
			cout << "������" << endl;
			break;
		case 6:
			cout << "������" << endl;
			break;
	}
	return 0;
}