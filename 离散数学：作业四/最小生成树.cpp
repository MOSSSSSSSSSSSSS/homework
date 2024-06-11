#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 100;
int fa[N];//并查集
struct edge {
	int a, b, w;
};
vector<edge> edges;
int n, m;
int temp;
int find(int x)
{
	if (fa[x] != x)fa[x] = find(fa[x]);
	return fa[x];
} // 并查集查找操作
bool cmp(edge a, edge b)
{
	return a.w < b.w;
}
void kruskal()
{
	int cnt = 0; // 有n-1条边就退出
	int sum = 0; // 总耗费
	for (int i = 0; i < m; i++)
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		int f1 = find(a), f2 = find(b);
		if (f1 != f2)  //  不在一个集合 , 是最小生成树一条边
		{
			cout << "最小耗费是:" << a << ' ' << b << endl;
			fa[f1] = f2;//合并
			sum += w;
			cnt++;
			if (cnt == n - 1)break;
		}
	}
	cout << "总耗费:" << sum << endl;
	return;
}

int main()
{
	printf("请输入所求图的顶点数目和边的数目(以空格分隔各个数，输入两个0结束):\n"); //输入所求的顶点数目和边数
	while (scanf("%d%d", &n, &temp))
	{
		if (temp != 0 && n != 0)
		{
			for (int i = 1; i <= n; i++)
				fa[i] = i;//初始化
			printf("请输入两条边的节点序号以及它们的权值(以空格分隔各个数):\n");
			for (int i = 1; i <= temp; i++)
			{
				int u, v, w;
				cin >> u >> v >> w;	  //输入边数以及它们的权值
				edges.push_back({ u,v,w });
			}
			m = temp;
		}
		else if (n == 0 && temp == 0)
			break;
	}
	sort(edges.begin(), edges.end(), cmp);
	kruskal();
	return 0;
}
