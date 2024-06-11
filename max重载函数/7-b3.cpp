// 2253209 刘佳朋 信07
#include<iostream>
using namespace std;

void max(int a, int b)
{
	cout << "max=" << (a > b ? a : b) << endl;
}
void max(int a, int b, int c)
{
	a = (a > b ? a : b);
	cout << "max=" << (c > a ? c : a) << endl;
}
void max(int a, int b, int c, int d)
{
	a = (a > b ? a : b);
	c = (c > d ? c : d);
	cout << "max=" << (a > c ? a : c) << endl;
}
int fun(int arr[], int num)
{
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(65536, '\n');
			return 0;
		}
		else if (arr[i] <= 0)
		{
			cin.ignore(65536, '\n');
			return 0;
		}
	}
	return 1;
}

int main()
{
	int num,arr[4];
	while (1)
	{
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> num;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else if (num < 2 || num>4)
		{
			cout << "个数输入错误" << endl;
			return 0;
		}
		if (fun(arr, num))
			break;
		else
			continue;
	}
	if (num == 2)
		max(arr[0], arr[1]);
	else if (num == 3)
		max(arr[0], arr[1], arr[2]);
	else
		max(arr[0], arr[1], arr[2],arr[3]);


	return 0;
}