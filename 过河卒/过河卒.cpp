#include<iostream>
#include<algorithm>
using namespace std;

const int fx[9] = { 0,-2,-1,1,2,2,1,-1,-2 };
const int fy[9] = { 0,-1,-2,-2,-1,1,2,2,1 };

#define ll long long
ll Fun[21][21];
int fun2(int x, int y,int hx, int hy)
{
	for (int i = 0; i < 9; i++)
	{
		if (x == hx + fx[i] && y == hy + fy[i])
		{
			return 1;
		}
		else
		{
			continue;
		}
	}
	return 0;
}
ll fun(int x,int y,int hx,int hy)
{
	if (Fun[x][y] != -1)
	{
		return Fun[x][y];
	}
	else
	{
		if (fun2(x, y, hx, hy))
		{
			Fun[x][y] = 0;
		}
		else if (x == 0 || y == 0)
		{
			if (x == 0 && y == 0)
			{
				Fun[x][y] = 1;
			}
			else if (x == 0 && fun(x,y-1,hx,hy) || y == 0 && fun(x-1,y,hx,hy))
			{
				Fun[x][y] = 1;
			}
			else
			{
				Fun[x][y] = 0;
			}
		}
		else
		{
			Fun[x][y] = fun(x - 1, y, hx, hy) + fun(x, y - 1, hx, hy);
		}
		return Fun[x][y];
	}
}

int main()
{
	int n, m, hx, hy;
	cin >> n >> m >> hx >> hy;
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			Fun[i][j] = -1;
		}
	}
	cout << fun(n, m, hx, hy) << endl;
}