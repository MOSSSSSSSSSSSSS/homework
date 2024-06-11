#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int t, m, val[105], w[105], dp[105][1005];
int main()
{
	scanf("%d %d", &t, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d %d", &w[i], &val[i]);
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j<=t; j++)
		{
			if (j >= w[i])
				dp[i][j] = max(dp[i - 1][j - w[i]] + val[i], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	printf("%d\n", dp[m][t]);
}