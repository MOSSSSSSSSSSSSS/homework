// 2253209 信07 刘佳朋
#include<iostream>
using namespace std;

int main()
{
	int i,j, n = 0, score[1000];
	for (i = 0; i < 1000; i++)
	{
		score[i] = -1;
	}
	cout<<"请输入成绩（最多1000个），负数结束输入"<<endl;
	for (i = 0; i < 1000; i++)
	{
		cin >> score[i];
		if (score[0] < 0)
		{
			cout<<"无有效输入"<<endl;
			break;
		}
		if (score[i] < 0)
		{
			break;
		}
	}
	cout<<"输入的数组为:"<<endl;
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
	cout << "分数与名次的对应关系为:" << endl;
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