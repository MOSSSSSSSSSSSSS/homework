#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

const int MAXN = 10000 + 5;

int main()
{
	int n;
	int x[MAXN];
	int y[MAXN];
	int a[MAXN];
	int b[MAXN];
	int j, k, ans = -1;
	scanf("%d", &n);
	for (int i = 0;i<n; i++)
	{
		scanf("%d %d %d %d", &x[i], &y[i], &a[i], &b[i]);
	}
	scanf("%d %d", &j, &k);
	for (int i = 0;i<n; i++)
	{
		if (x[i] <= j && x[i] + a[i] >= j && y[i] <= k && y[i] + b[i] >= k)
			ans = i + 1;
	}
	printf("%d\n", ans);

	return 0;
}