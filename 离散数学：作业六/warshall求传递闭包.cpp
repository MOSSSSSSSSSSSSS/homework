#include<iostream>
using namespace std;

const int N = 100;
int g[N][N];// ����
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
	cout << "��������ͼ�Ķ�����Ŀ" << endl;
	cin >> n;
	cout << "��������ʾ" << endl;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> g[i][j];
	warshall();
	cout << "���ݱհ�Ϊ��" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << g[i][j];
		cout << endl;
	}

	return 0;
}