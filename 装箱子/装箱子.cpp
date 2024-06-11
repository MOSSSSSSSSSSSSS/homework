#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int v0, n, v[35], dp[35][20005];

int main()
{
	scanf("%d %d", &v0,&n);
	for (int i = 1; i <= n; i++)
		scanf("%d" ,& v[i]);
	for (int j = 1; j <= v0; j++)
		dp[0][j] = j;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= v0; j++)
		{
			if (j >= v[i])
				dp[i][j] = min(dp[i - 1][j - v[i]], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	printf("%d\n", dp[n][v0]);
}