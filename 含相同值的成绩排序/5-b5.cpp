// 2253209 ��07 ������
#include<iostream>
using namespace std;

int main()
{
	int i,j, n = 0, score[1000];
	for (i = 0; i < 1000; i++)
	{
		score[i] = -1;
	}
	cout<<"������ɼ������1000������������������"<<endl;
	for (i = 0; i < 1000; i++)
	{
		cin >> score[i];
		if (score[0] < 0)
		{
			cout<<"����Ч����"<<endl;
			break;
		}
		if (score[i] < 0)
		{
			break;
		}
	}
	cout<<"���������Ϊ:"<<endl;
	for (i = 0; i < 1000; i++)
	{
		if (score[i] >= 0)
		{
			cout << score[i] << ' ';
			n++;
			if (n % 10 == 0)
			{
				cout << endl;
			}
		}
	}
	if (n % 10 != 0)
	{
		cout << endl;
	}
	cout << "���������εĶ�Ӧ��ϵΪ:" << endl;
	for (i = 0; i < 1000 - 1; i++)
	{
		for (j = 0; j < 1000 - i - 1; j++)
		{
			if (score[j] <= score[j + 1])
			{
				int temp = score[j];
				score[j] = score[j + 1];
				score[j + 1] = temp;
			}
		}
	}
	n = 1;
	for (i = 0; i < 1000; i++)
	{
		if (score[i] >= 0)
		{
			if (score[i] == score[i + 1])
			{
				n++;
			}
			else
			{
				for (j = i - n + 1; j < i+1; j++)
				{
					cout << score[j] << ' ' << i - n + 2 << endl;
				}
				n = 1;
			}
		}
		else
		{
			break;
		}
	}

	return 0;
}