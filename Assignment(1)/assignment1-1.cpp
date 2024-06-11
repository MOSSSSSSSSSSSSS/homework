#include<iostream>
using namespace std;

const int MAX = 106;

int main()
{
	int prices[MAX] = {0}, ans[MAX] = {0},prices_length = 0 ;
	int stk[MAX] = { 0 }, stk_top = 0;//模拟单调栈来优化，栈中存的是下标。（因为求的是右边第一个比它大的数）
	cin >> prices_length;
	for (int i = 1; i <= prices_length; i++)
		cin >> prices[i];
	for (int i = prices_length; i >= 1; i--)
	{
		while (stk_top && prices[stk[stk_top]] <= prices[i])stk_top--;//如果将要入栈的数比栈顶的数大，栈顶的数弹出
		if (stk_top)ans[i] = stk[stk_top]-i;//如果进行完上一步操作后栈中还有数，就是答案，如果没有答案是0
		stk[++stk_top] = i;//入栈
	}
	for (int i = 1; i <= prices_length; i++)
		cout << ans[i] << ' ';

	return 0;
}