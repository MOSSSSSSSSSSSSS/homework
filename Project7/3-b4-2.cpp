// 2253209 ��07 ������
#include<iostream>
#define pi 3.14159
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
	int a, b, c;
	double d;
	float s;
	cout << "�����������ε����߼���н�(�Ƕ�)" << endl;
	cin >> a >> b >> c;
	d = c *pi/ 180 ;
	s = 1.0/ 2 * a * b * sin(d);
	cout << "���������Ϊ : " << setiosflags(ios::fixed) << setprecision(3) << s << endl;
	return 0;
}