// 2253209 信07 刘佳朋
#include<iostream>
using namespace std;

int pan_duan(char *p,char *p2)
{
	for (;p<p2; p++, p2--)
	{
		if (*p == *p2)
		{
			continue;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	char *p2;
	char arr[82] = { 0 };
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(arr, 82, stdin);
	for (p2 = arr;; p2++)
	{
		if (*p2 == 10)
		{
			*p2 = 0;
			p2--;
			break;
		}
	}
	if (pan_duan(arr,p2))
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}


	return 0;
}