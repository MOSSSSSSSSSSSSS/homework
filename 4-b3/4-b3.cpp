// 2253209 信07 刘佳朋
#include<iostream>
#include<iomanip>
using namespace std;
int zeller(int y, int m,int d)
{
	if (m == 1 || m == 2)
	{
		m += 12;
		y--;
	}
	int w, c1, c2;
	c1 = y / 100;
	c2 = y - c1 * 100;
	w = c2 + c2 / 4 + c1 / 4 - 2 * c1 + 13 * (m + 1) / 5 + d - 1;
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
void calendar(int y,int m,int w)
{
	cout << endl;
	cout << y << "年" << m << "月" << endl;
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;
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
}
int main()
{
	int y, m,d=1;
	while (1)
	{
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> y >> m;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(65536,'\n');
			cout << "输入错误，请重新输入" << endl;
		}
		else if (y < 1900 || y>2100)
		{
			cout << "年份不正确，请重新输入" << endl;
		}
		else if (m < 1 || m>12)
		{
			cout << "月份不正确，请重新输入" << endl;
		}
		else
		{
			break;
		}
	}
	calendar(y, m, zeller(y, m, d));

	return 0;
}