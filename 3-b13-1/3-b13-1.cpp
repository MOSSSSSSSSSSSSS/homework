// 2253209 ��07 ������
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int y, m, w;
	while(1)
	{
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> y >> m;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(2048, '\n');
		}
		else if (y >= 2000 && y <= 2030 && m >= 1 && m <= 12)
		{
			break;
		}
		else
		{
			;
		}
		cout << "����Ƿ�������������" << endl;
	}
	while (1)
	{
		cout << "������2000��6��1�յ�����(0-6��ʾ������-������) : ";
		cin >> w;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(2048, '\n');
		}
		else if (w>=0&&w<=6)
		{
			break;
		}
		else
		{
			;
		}
		cout << "����Ƿ�������������" << endl;
	}
	cout << endl;
	cout << y << "��" << m << "��" << "������Ϊ:" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		for (int k = 1; k <= 31; k++)
		{
			if ((k - 8 + w) % 7 == 0)
			{
				cout << setw(4) << k;
			}
			else if (k == 1)
			{
				cout << setw(4 + w * 8) << k;
			}
			else
			{
				cout << setw(8) << k;
			}
			if ((k + w) % 7 == 0)
			{
				cout << endl;
			}
		}
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		for (int k = 1; k <= 30; k++)
		{
			if ((k - 8 + w) % 7 == 0)
			{
				cout << setw(4) << k;
			}
			else if (k == 1)
			{
				cout << setw(4 + w * 8) << k;
			}
			else
			{
				cout << setw(8) << k;
			}
			if ((k + w) % 7 == 0)
			{
				cout << endl;
			}
		}
	}
	else
	{
		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		{
			for (int k = 1; k <= 29; k++)
			{
				if ((k - 8 + w) % 7 == 0)
				{
					cout << setw(4) << k;
				}
				else if (k == 1)
				{
					cout << setw(4 + w * 8) << k;
				}
				else
				{
					cout << setw(8) << k;
				}
				if ((k + w) % 7 == 0)
				{
					cout << endl;
				}
			}
		}
		else
		{
			for (int k = 1; k <= 28; k++)
			{
				if ((k - 8 + w) % 7 == 0)
				{
					cout << setw(4) << k;
				}
				else if (k == 1)
				{
					cout << setw(4 + w * 8) << k;
				}
				else
				{
					cout << setw(8) << k;
				}
				if ((k + w) % 7 == 0)
				{
					cout << endl;
				}
			}
		}
	}
	
	return 0;
}