#include<iostream>
using namespace std;

const int MAX = 106;

int main()
{
	int prices_length = 0, prices[MAX] = { 0 }, max_profit = 0;
	cin >> prices_length;
	for (int i = 1; i <= prices_length; i++)
		cin >> prices[i];
	for (int i = 1; i <= prices_length; i++)// 枚举每个数，找出它右边最大的数
	{
		int res = 0;  //  i 的右边最大的数
		for (int j = i + 1; j <= prices_length; j++)
			res = max(res, prices[j]);
		max_profit = max(max_profit, res - prices[i]);// 求最大利润
	}
	cout << max_profit;

	return 0;
}