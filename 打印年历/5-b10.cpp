// 2253209 刘佳朋 信07
#include<iostream>
#include<iomanip>
using namespace std;

int max(int a, int b, int c)
{
	if (a >= b)
	{
		return a >= c ? a : c;
	}
	else
	{
		return b >= c ? b : c;
	}
}
int hangshu(int xingqiji, int duoshaotian)
{
	if ((duoshaotian + xingqiji) % 7 == 0)
	{
		return (duoshaotian + xingqiji) / 7;
	}
	else
	{
		return (duoshaotian + xingqiji) / 7 + 1;
	}
}
int pan_duan_run_nian(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
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
int main()
{
	int year, arr[12];
	cout << "请输入年份[1900-2100]" << endl;
	cin >> year;
	for (int i = 0; i < 12; i++)
	{
		arr[i] = zeller(year, i + 1, 1);
	}
	int day[12] = { 31,28+pan_duan_run_nian(year),31,30,31,30,31,31,30,31,30,31};
	cout << year << "年的日历:" << endl;
	cout << endl;
	cout << "            1月                             2月                             3月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	for (int i = 1;i<=max(hangshu(arr[0],day[0]), hangshu(arr[1], day[1]), hangshu(arr[2], day[2])); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 1)
			{
				for (int k = 0; k < 4 * arr[j]; k++)
				{
					cout << ' ';
				}
				for (int k = 1; k <= 7 - arr[j]; k++)
				{
					cout << setiosflags(ios::left) << setw(4) << k;
				}
			}
			else
			{
				for (int k = 7-arr[j]+1+7*(i-2); k <= 7 - arr[j] + 1 + 7 * (i - 2)+6; k++)
				{
					if (k <= day[j])
					{
						cout << setiosflags(ios::left) << setw(4) << k;
					}
					else
					{
						cout << "    ";
					}
				}
			}
			if (j != 2)
			{
				cout << "    ";
			}
			if ((j + 1) % 3 == 0)
			{
				cout << endl;
			}
		}
		if (i == max(hangshu(arr[0], day[0]), hangshu(arr[1], day[1]), hangshu(arr[2], day[2])))
		{
			cout << endl;
		}
	}
	cout << "            4月                             5月                             6月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	for (int i = 1; i <= max(hangshu(arr[3], day[3]), hangshu(arr[4], day[4]), hangshu(arr[5], day[5])); i++)
	{
		for (int j = 3; j < 6; j++)
		{
			if (i == 1)
			{
				for (int k = 0; k < 4 * arr[j]; k++)
				{
					cout << ' ';
				}
				for (int k = 1; k <= 7 - arr[j]; k++)
				{
					cout << setiosflags(ios::left) << setw(4) << k;
				}
			}
			else
			{
				for (int k = 7 - arr[j] + 1 + 7 * (i - 2); k <= 7 - arr[j] + 1 + 7 * (i - 2) + 6; k++)
				{
					if (k <= day[j])
					{
						cout << setiosflags(ios::left) << setw(4) << k;
					}
					else
					{
						cout << "    ";
					}
				}
			}
			if (j != 5)
			{
				cout << "    ";
			}
			if ((j + 1) % 3 == 0)
			{
				cout << endl;
			}
		}
		if (i == max(hangshu(arr[3], day[3]), hangshu(arr[4], day[4]), hangshu(arr[5], day[5])))
		{
			cout << endl;
		}
	}
	cout << "            7月                             8月                             9月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	for (int i = 1; i <= max(hangshu(arr[6], day[6]), hangshu(arr[7], day[7]), hangshu(arr[8], day[8])); i++)
	{
		for (int j = 6; j < 9; j++)
		{
			if (i == 1)
			{
				for (int k = 0; k < 4 * arr[j]; k++)
				{
					cout << ' ';
				}
				for (int k = 1; k <= 7 - arr[j]; k++)
				{
					cout << setiosflags(ios::left) << setw(4) << k;
				}
			}
			else
			{
				for (int k = 7 - arr[j] + 1 + 7 * (i - 2); k <= 7 - arr[j] + 1 + 7 * (i - 2) + 6; k++)
				{
					if (k <= day[j])
					{
						cout << setiosflags(ios::left) << setw(4) << k;
					}
					else
					{
						cout << "    ";
					}
				}
			}
			if (j != 8)
			{
				cout << "    ";
			}
			if ((j + 1) % 3 == 0)
			{
				cout << endl;
			}
		}
		if (i == max(hangshu(arr[6], day[6]), hangshu(arr[7], day[7]), hangshu(arr[8], day[8])))
		{
			cout << endl;
		}
	}
	cout << "           10月                            11月                            12月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	for (int i = 1; i <= max(hangshu(arr[9], day[9]), hangshu(arr[10], day[10]), hangshu(arr[11], day[11])); i++)
	{
		for (int j = 9; j < 12; j++)
		{
			if (i == 1)
			{
				for (int k = 0; k < 4 * arr[j]; k++)
				{
					cout << ' ';
				}
				for (int k = 1; k <= 7 - arr[j]; k++)
				{
					cout << setiosflags(ios::left) << setw(4) << k;
				}
			}
			else
			{
				for (int k = 7 - arr[j] + 1 + 7 * (i - 2); k <= 7 - arr[j] + 1 + 7 * (i - 2) + 6; k++)
				{
					if (k <= day[j])
					{
						cout << setiosflags(ios::left) << setw(4) << k;
					}
					else
					{
						cout << "    ";
					}
				}
			}
			if (j != 11)
			{
				cout << "    ";
			}
			if ((j + 1) % 3 == 0)
			{
				cout << endl;
			}
		}
		if (i == max(hangshu(arr[9], day[9]), hangshu(arr[10], day[10]), hangshu(arr[11], day[11])))
		{
			cout << endl;
		}
	}
	cout << endl;

	return 0;
}