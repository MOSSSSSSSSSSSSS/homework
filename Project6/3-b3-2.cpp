// 2253209 ��07 ������
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double num;
	cout << "�����[0-100��)֮�������:" << endl;
	cin >>num;
	num = num + 0.001;
	int a, b, c, d, e, f, g, h, i, j, k,l;
	a = num / 1e9;
	b = (num - a * 1e9) / 1e8;
	c = (num - a * 1e9 - b * 1e8) / 1e7;
	d = (num - a * 1e9 - b * 1e8 - c * 1e7) / 1e6;
	e = (num - a * 1e9 - b * 1e8 - c * 1e7 - d * 1e6) / 1e5;
	f = (num - a * 1e9 - b * 1e8 - c * 1e7 - d * 1e6 - e * 1e5) / 1e4;
	g = (num - a * 1e9 - b * 1e8 - c * 1e7 - d * 1e6 - e * 1e5 - f * 1e4) / 1e3;
	h = (num - a * 1e9 - b * 1e8 - c * 1e7 - d * 1e6 - e * 1e5 - f * 1e4 - g * 1e3) / 1e2;
	i = (num - a * 1e9 - b * 1e8 - c * 1e7 - d * 1e6 - e * 1e5 - f * 1e4 - g * 1e3 - h * 1e2) / 10;
	j = num - a * 1e9 - b * 1e8 - c * 1e7 - d * 1e6 - e * 1e5 - f * 1e4 - g * 1e3 - h * 1e2 - i * 10;
	k = (num - a * 1e9 - b * 1e8 - c * 1e7 - d * 1e6 - e * 1e5 - f * 1e4 - g * 1e3 - h * 1e2 - i * 10 - j) * 10;
	l = (num - a * 1e9 - b * 1e8 - c * 1e7 - d * 1e6 - e * 1e5 - f * 1e4 - g * 1e3 - h * 1e2 - i * 10 - j - k * 0.1) * 100;
	cout << "ʮ��λ : " << a << endl;
	cout << "��λ   : " << b << endl;
	cout << "ǧ��λ : " << c << endl;
	cout << "����λ : " << d << endl;
	cout << "ʮ��λ : " << e << endl;
	cout << "��λ   : " << f << endl;
	cout << "ǧλ   : " << g << endl;
	cout << "��λ   : " << h << endl;
	cout << "ʮλ   : " << i << endl;
	cout << "Բ     : " << j << endl;
	cout << "��     : " << k << endl;
	cout << "��     : " << l << endl;
	
	return 0;
}