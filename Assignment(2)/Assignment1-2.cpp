#include<iostream>
using namespace std;

const int MAX = 106;

int main()
{
	int prices_length = 0, prices[MAX] = { 0 }, max_profit = 0;
	cin >> prices_length;
	for (int i = 1; i <= prices_length; i++)
		cin >> prices[i];
	for (int i = 1; i <= prices_length; i++)// ö��ÿ�������ҳ����ұ�������
	{
		int res = 0;  //  i ���ұ�������
		for (int j = i + 1; j <= prices_length; j++)
			res = max(res, prices[j]);
		max_profit = max(max_profit, res - prices[i]);// ���������
	}
	cout << max_profit;

	return 0;
}