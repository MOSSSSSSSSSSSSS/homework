// 2253209 ��07 ������
#include<iostream>
using namespace std;

int main()
{
	int i, j, array[21] = { 0 };
	cout << "��������������������������20������0������������" << endl;
	for (i = 0; i < 20; i++)
	{
		cin >> array[i];
		if (array[0] <= 0)
		{
			cout << "����Ч����" << endl;
			break;
		}
		if (array[i] <= 0)
		{
			break;
		}
	}
	cin.ignore(65536,'\n');
	cout << "ԭ����Ϊ��" << endl;
	for (i = 0; i < 20; i++)
	{
		if (array[i] > 0)
		{
			cout << array[i] << ' ';
		}
	}
	cout << endl;
	cout << "������Ҫ�����������" << endl;
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
	cout << "����������Ϊ��" << endl;
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