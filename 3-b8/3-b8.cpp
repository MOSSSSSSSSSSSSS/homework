// 2253209 ��07 ������
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	int x,i;
	double s=1,j,a=1;
	cout << "������x��ֵ[-10 ~ +65]" << endl;
	cin >> x;
	while (x < -10 || x>65)
	{
		cout << "����Ƿ�������������" << endl;
		cout << "������x��ֵ[-10 ~ +65]" << endl;
		cin >> x;
	}
	for (i = 1;; i++)
	{
		for (j=i; j > 0;j--)
		{
			a *= x / j;
		}
		if (fabs(a) <1e-6)
		{
			break;
		}
		s += a;
		a = 1;
	}
	if (x != -10)
	{
		cout << setprecision(10) << "e^" << x << '=' << s << endl;
	}
	else
	{
		cout<<setiosflags(ios::scientific)<<setprecision(9) << "e^" << x << '=' << s << endl;
	}
	return 0;
}