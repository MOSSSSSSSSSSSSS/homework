#include<iostream>
using namespace std;

const int N = 100;
int g[N][N];// 矩阵
int n;

void warshall()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				g[i][j] |= (g[i][k] && g[k][j]);
}

int main()
{
	cout << "输入所求图的顶点数目" << endl;
	cin >> n;
	cout << "输入矩阵表示" << endl;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> g[i][j];
	warshall();
	cout << "传递闭包为：" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << g[i][j];
		cout << endl;
	}

	return 0;
}