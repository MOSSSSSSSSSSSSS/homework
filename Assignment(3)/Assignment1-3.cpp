
//做法：动态规划
// f[i]表示第i天结束后的最大利益
//第i天结束后有三种状态：f[i][0],f[i][1],f[i][2]分别表示目前持有一支股票,目前不持有任何股票，并且处于冷冻期中,目前不持有任何股票，并且不处于冷冻期中
//dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
//dp[i][1] = dp[i - 1][0] + prices[i];
//dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
//求出dp[n-1]后取max(dp[prices_length - 1][0],dp[prices_length-1][1], dp[prices_length-1][2])
#include<iostream>
using namespace std;

const int MAX = 5001;
int prices[MAX], prices_length;
int dp[MAX][3];   // dp数组需要初始化为0

int main()
{
	cin >> prices_length;
	for (int i = 1; i <= prices_length; i++)
		cin >> prices[i];
	for (int i = 1; i <= prices_length; i++)
	{
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
		dp[i][1] = dp[i - 1][0] + prices[i];
		dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
	}
	cout << max(dp[prices_length - 1][0],max(dp[prices_length-1][1], dp[prices_length-1][2]));

	return 0;
}