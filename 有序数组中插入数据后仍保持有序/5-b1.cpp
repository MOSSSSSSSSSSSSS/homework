// 2253209 信07 刘佳朋
#include<iostream>
using namespace std;

int main()
{
	int i, j, array[21] = { 0 };
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	for (i = 0; i < 20; i++)
	{
		cin >> array[i];
		if (array[0] <= 0)
		{
			cout << "无有效输入" << endl;
			break;
		}
		if (array[i] <= 0)
		{
			break;
		}
	}
	cin.ignore(65536,'\n');
	cout << "原数组为：" << endl;
	for (i = 0; i < 20; i++)
	{
		if (array[i] > 0)
		{
			cout << array[i] << ' ';
		}
	}
	cout << endl;
	cout << "请输入要插入的正整数" << endl;
	cin >> array[20];
	for (i = 0; i < 20; i++)
	{
		if (array[i] >= array[20])
		{
			int temp = array[20];
			for (j = 20;j >= i + 1; j--)
			{
				array[j] = array[j - 1];
			}
			array[i] = temp;
			break;
		}
	}
	cout << "插入后的数组为：" << endl;
	for (i = 0; i < 21; i++)
	{
		if (array[i] > 0)
		{
			cout << array[i] << ' ';
		}
	}
	cout << endl;

	return 0;
}