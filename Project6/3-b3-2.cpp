// 2253209 信07 刘佳朋
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double num;
	cout << "请输出[0-100亿)之间的数字:" << endl;
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
	cout << "十亿位 : " << a << endl;
	cout << "亿位   : " << b << endl;
	cout << "千万位 : " << c << endl;
	cout << "百万位 : " << d << endl;
	cout << "十万位 : " << e << endl;
	cout << "万位   : " << f << endl;
	cout << "千位   : " << g << endl;
	cout << "百位   : " << h << endl;
	cout << "十位   : " << i << endl;
	cout << "圆     : " << j << endl;
	cout << "角     : " << k << endl;
	cout << "分     : " << l << endl;
	
	return 0;
}