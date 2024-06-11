// 2253209 刘佳朋 信07
#include<iostream>
using namespace std;

int main()
{
	int shudu[9][9],temp[9][9], a[9], h = 1, l = 1, k1 = 1, k2 = 1, k3 = 1, k4 = 1, k5 = 1, k6 = 1, k7 = 1, k8 = 1, k9 = 1;
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> shudu[i][j];
			if (cin.fail())
			{
				cout<< "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
			}
			else if (shudu[i][j]>9||shudu[i][j]<1)
			{
				cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
				j--;
				continue;
			}
			else
			{
				;
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			temp[i][j] = shudu[i][j];
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 9 - j - 1; k++)
			{
				if (shudu[i][k] > shudu[i][k + 1])
				{
					int temp = shudu[i][k];
					shudu[i][k] = shudu[i][k + 1];
					shudu[i][k + 1] = temp;
				}
			}
		}
	}
	for(int i = 0;i<9;i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (shudu[i][j] != shudu[i][j + 1])
			{
				;
			}
			else
			{
				h = 0;
				break;
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			shudu[i][j] = temp[i][j];
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 9 - j - 1; k++)
			{
				if (shudu[k][i] > shudu[k+1][i])
				{
					int temp = shudu[k][i];
					shudu[k][i] = shudu[k+1][i];
					shudu[k+1][i] = temp;
				}
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (shudu[j][i] != shudu[j+1][i])
			{
				;
			}
			else
			{
				l = 0;
				break;
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			shudu[i][j] = temp[i][j];
		}
	}
	for (int i = 0;i<3;i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a[3 * i + j] = shudu[i][j];
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		if (a[i] != a[i + 1])
		{
			;
		}
		else
		{
			k1 = 0;
			break;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a[3 * i + j] = shudu[i][j+3];
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		if (a[i] != a[i + 1])
		{
			;
		}
		else
		{
			k2 = 0;
			break;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a[3 * i + j] = shudu[i][j+6];
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		if (a[i] != a[i + 1])
		{
			;
		}
		else
		{
			k3 = 0;
			break;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a[3 * i + j] = shudu[i+3][j];
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		if (a[i] != a[i + 1])
		{
			;
		}
		else
		{
			k4 = 0;
			break;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a[3 * i + j] = shudu[i+6][j];
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		if (a[i] != a[i + 1])
		{
			;
		}
		else
		{
			k5 = 0;
			break;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a[3 * i + j] = shudu[i+3][j+3];
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		if (a[i] != a[i + 1])
		{
			;
		}
		else
		{
			k6 = 0;
			break;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a[3 * i + j] = shudu[i+3][j+6];
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		if (a[i] != a[i + 1])
		{
			;
		}
		else
		{
			k7 = 0;
			break;
		}
	}for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a[3 * i + j] = shudu[i+6][j+3];
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		if (a[i] != a[i + 1])
		{
			;
		}
		else
		{
			k8 = 0;
			break;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a[3 * i + j] = shudu[i+6][j+6];
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		if (a[i] != a[i + 1])
		{
			;
		}
		else
		{
			k9 = 0;
			break;
		}
	}
	if (h && l && k1 && k2 && k3 && k4 && k5 && k6 && k7 && k8 && k9)
	{
		cout << "是数独的解" << endl;
	}
	else
	{
		cout << "不是数独的解" << endl;
	}

	return 0;
}