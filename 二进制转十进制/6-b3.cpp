// 2253209 刘佳朋 信07
#include<iostream>
using namespace std;

unsigned int zhuan_huan(char* p,char *a,int n)
{
	unsigned int x = (unsigned int)(*p - '0');
	if (p == a)
	{
		return x;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			x *= 2;
		}
		return x + zhuan_huan(++p, a, n - 1);
	}
}
int main()
{
	int n;       
	char arr[33] = {0};
	char* p = arr;
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin >> arr;
	for (;;p++)
	{
		if (*p == 0)
		{
			n = p - arr-1;
			break;
		}
	}
	cout << zhuan_huan(arr, --p, n) << endl;


	return 0;
}
