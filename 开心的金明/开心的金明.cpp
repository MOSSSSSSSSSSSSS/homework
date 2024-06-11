#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int n, m, p[30], val[30], dp[30][30005];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d %d", &p[i], &val[i]);
	for (int i = 1;i<=m;i++)
	{
		for (int j = 0;j<=n;j++)
		{
			if (j >= p[i])
				dp[i][j] = max(dp[i - 1][j - p[i]] + p[i] * val[i], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	printf("%d", dp[m][n]);
}