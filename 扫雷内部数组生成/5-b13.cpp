// 2253209 –≈07 ¡ıº—≈Û
#include<iostream>
#include<time.h> 
using namespace std;

int main()
{
	char arr[10][26] = {0};
	srand((unsigned int)(time(0)));
	for (int i = 0; i < 50; i++)
	{
		int x = rand() % 10;
		int y =	rand() % 26;
		if (arr[x][y] == '*')
		{
			i--;
		}
		else
		{
			arr[x][y] = '*';
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (arr[i][j]!='*')
			{
				arr[i][j] = '0';
				if (i - 1 >= 0 && j - 1 >= 0)
				{
					if (arr[i - 1][j - 1]=='*')
					{
						arr[i][j]++;
					}
				}
				if (i - 1 >= 0 )
				{
					if (arr[i - 1][j] == '*')
					{
						arr[i][j]++;
					}
				}
				if (j - 1 >= 0)
				{
					if (arr[i][j - 1] == '*')
					{
						arr[i][j]++;
					}
				}
				if (i - 1 >= 0 && j + 1 <=25)
				{
					if (arr[i - 1][j + 1] == '*')
					{
						arr[i][j]++;
					}
				}
				if (i + 1 <= 9 && j + 1 <= 25)
				{
					if (arr[i + 1][j + 1] == '*')
					{
						arr[i][j]++;
					}
				}
				if (i + 1 <= 9)
				{
					if (arr[i + 1][j] == '*')
					{
						arr[i][j]++;
					}
				}
				if (j + 1 <= 25)
				{
					if (arr[i][j + 1] == '*')
					{
						arr[i][j]++;
					}
				}
				if (i + 1 <= 9 && j - 1 >= 0)
				{
					if (arr[i + 1][j - 1] == '*')
					{
						arr[i][j]++;
					}
				}
			}
			else
			{
				continue;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
