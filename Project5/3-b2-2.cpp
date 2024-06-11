// 2253209 信07 刘佳朋
#include<iostream>
using namespace std;

int main()
{
	int num,a,b,c,d,e;
	cout << "请输入一个[1..30000]间的整数:" << endl;
	cin >> num;
	a = num / 10000;
	b = (num - a * 10000) / 1000;
	c = (num - a * 10000 - b * 1000) / 100;
	d = (num - a * 10000 - b * 1000 - c * 100) / 10;
	e = num - a * 10000 - b * 1000 - c * 100 - d * 10;
	cout << "万位 : " << a << endl;
	cout << "千位 : " << b << endl;
	cout << "百位 : " << c << endl;
	cout << "十位 : " << d << endl;
	cout << "个位 : " << e << endl;
	
	return 0;
}