// 2253209 ��07 ������
#include<iostream>
using namespace std;

int main()
{
	int num,a,b,c,d,e;
	cout << "������һ��[1..30000]�������:" << endl;
	cin >> num;
	a = num / 10000;
	b = (num - a * 10000) / 1000;
	c = (num - a * 10000 - b * 1000) / 100;
	d = (num - a * 10000 - b * 1000 - c * 100) / 10;
	e = num - a * 10000 - b * 1000 - c * 100 - d * 10;
	cout << "��λ : " << a << endl;
	cout << "ǧλ : " << b << endl;
	cout << "��λ : " << c << endl;
	cout << "ʮλ : " << d << endl;
	cout << "��λ : " << e << endl;
	
	return 0;
}