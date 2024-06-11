#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 100;
int fa[N];//���鼯
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
} // ���鼯���Ҳ���
bool cmp(edge a, edge b)
{
	return a.w < b.w;
}
void kruskal()
{
	int cnt = 0; // ��n-1���߾��˳�
	int sum = 0; // �ܺķ�
	for (int i = 0; i < m; i++)
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		int f1 = find(a), f2 = find(b);
		if (f1 != f2)  //  ����һ������ , ����С������һ����
		{
			cout << "��С�ķ���:" << a << ' ' << b << endl;
			fa[f1] = f2;//�ϲ�
			sum += w;
			cnt++;
			if (cnt == n - 1)break;
		}
	}
	cout << "�ܺķ�:" << sum << endl;
	return;
}

int main()
{
	printf("����������ͼ�Ķ�����Ŀ�ͱߵ���Ŀ(�Կո�ָ�����������������0����):\n"); //��������Ķ�����Ŀ�ͱ���
	while (scanf("%d%d", &n, &temp))
	{
		if (temp != 0 && n != 0)
		{
			for (int i = 1; i <= n; i++)
				fa[i] = i;//��ʼ��
			printf("�����������ߵĽڵ�����Լ����ǵ�Ȩֵ(�Կո�ָ�������):\n");
			for (int i = 1; i <= temp; i++)
			{
				int u, v, w;
				cin >> u >> v >> w;	  //��������Լ����ǵ�Ȩֵ
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
