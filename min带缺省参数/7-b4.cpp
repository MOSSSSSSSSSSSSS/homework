// 2253209 ������ ��07
#include<iostream>
using namespace std;

void min(int a, int b, int c = 0, int d = 0)
{
	if (c == 0 && d == 0)
		cout << "min=" << (a > b ? b : a)<<endl;
	else if (c != 0 && d == 0)
	{
		a = (a < b ? a : b);
		cout << "min=" << (a > c ? c : a)<<endl;
	}
	else
	{
		a = (a < b ? a : b);
		c = (c < d ? c : d);
		cout << "min=" << (a > c ? c : a) << endl;
	}
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
	int num, arr[4];
	while (1)
	{
		cout << "���������num��num����������" << endl;
		cin >> num;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else if (num < 2 || num>4)
		{
			cout << "�����������" << endl;
			return 0;
		}
		if (fun(arr, num))
			break;
		else
			continue;
	}
	if (num == 2)
		min(arr[0], arr[1]);
	else if (num == 3)
		min(arr[0], arr[1], arr[2]);
	else
		min(arr[0], arr[1], arr[2], arr[3]);

	return 0;
}