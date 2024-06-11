// 2253209 信07 刘佳朋
// 2253223  房子翔  2252090  王麒懿  2154054  李思远  2251082  张冠宇  1853649  王湄沙
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int xing(const char arr [][26])
{
	int n=0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (arr[i][j] == '*')
			{
				n++;
			}
			else
			{
				continue;
			}
		}
	}
	return n;
}
int shu(const char arr[][26])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			int temp = 0;
			if (arr[i][j] != '*')
			{
				if (i - 1 >= 0 && j - 1 >= 0)
				{
					if (arr[i - 1][j - 1] == '*')
					{
						temp++;
					}
				}
				if (i - 1 >= 0)
				{
					if (arr[i - 1][j] == '*')
					{
						temp++;
					}
				}
				if (j - 1 >= 0)
				{
					if (arr[i][j - 1] == '*')
					{
						temp++;
					}
				}
				if (i - 1 >= 0 && j + 1 <= 25)
				{
					if (arr[i - 1][j + 1] == '*')
					{
						temp++;
					}
				}
				if (i + 1 <= 9 && j + 1 <= 25)
				{
					if (arr[i + 1][j + 1] == '*')
					{
						temp++;
					}
				}
				if (i + 1 <= 9)
				{
					if (arr[i + 1][j] == '*')
					{
						temp++;
					}
				}
				if (j + 1 <= 25)
				{
					if (arr[i][j + 1] == '*')
					{
						temp++;
					}
				}
				if (i + 1 <= 9 && j - 1 >= 0)
				{
					if (arr[i + 1][j - 1] == '*')
					{
						temp++;
					}
				}
				if (temp != arr[i][j]-'0')
				{
					return 0;
				}
				else
				{
					continue;
				}
			}
			else
			{
				continue;
			}
		}
	}
	return 1;
}
int main()
{
	char arr[10][26];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			scanf("%c", &arr[i][j]);
			getchar();
		}
		getchar();
	}
	if (xing(arr) != 50)
	{
		printf("错误1\n");
	}
	else if(!shu(arr))
	{
		printf("错误2\n");
	}
	else
	{
		printf("正确\n");
	}

	return 0;
}