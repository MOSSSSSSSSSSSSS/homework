#include<iostream>
using namespace std;

const int MAX = 106;

int main()
{
	int prices[MAX] = {0}, ans[MAX] = {0},prices_length = 0 ;
	int stk[MAX] = { 0 }, stk_top = 0;//ģ�ⵥ��ջ���Ż���ջ�д�����±ꡣ����Ϊ������ұߵ�һ�������������
	cin >> prices_length;
	for (int i = 1; i <= prices_length; i++)
		cin >> prices[i];
	for (int i = prices_length; i >= 1; i--)
	{
		while (stk_top && prices[stk[stk_top]] <= prices[i])stk_top--;//�����Ҫ��ջ������ջ��������ջ����������
		if (stk_top)ans[i] = stk[stk_top]-i;//�����������һ��������ջ�л����������Ǵ𰸣����û�д���0
		stk[++stk_top] = i;//��ջ
	}
	for (int i = 1; i <= prices_length; i++)
		cout << ans[i] << ' ';

	return 0;
}