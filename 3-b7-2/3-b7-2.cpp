// 2253209 信07 刘佳朋
#include<iostream>
using namespace std;

int main()
{
	double num;
	int s,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0;
	cout << "请输入找零值：" << endl;
	cin >> num;
	if (num >= 50)
	{
		a = 1;
		num -= 50;
	}
	if (num >= 40)
	{
		b = 2;
		num -= 40;
	}
	if (num >= 30)
	{
		b = 1;
		c = 1;
		num -= 30;
	}
	if (num >= 20)
	{
		b = 1;
		num -= 20;
	}
	if (num >= 10)
	{
		c = 1;
		num -= 10;
	}
	if (num >= 5)
	{
		d = 1;
		num -= 5;
	}
	if (num >= 1)
	{
		e = int(num);
		num -= e;
	}
	if (num >= 0.5)
	{
		f = 1;
		num -= 0.5;
	}
	if (num >= 0.1)
	{
		g = int(num * 10);
		num -= g * 0.1;
	}
	if (num >= 0.05)
	{
		h = 1;
		num -= 0.05;
	}
	if (num >= 0.02)
	{
		i = int(num / 0.02);
		num -= i * 0.02;
	}
	if (num - 0.01 >= 0)
	{
		j = 1;
	}
	s = a + b + c + d + e + f + g + h + i + j;
	cout << "共" << s << "张找零，具体如下：" << endl;
	if (a != 0)
	{
		cout << "50元 : " << a << "张" << endl;
	}
	if (b != 0)
	{
		cout << "20元 : " << b << "张" << endl;
	}
	if (c != 0)
	{
		cout << "10元 : " << c << "张" << endl;
	}
	if (d != 0)
	{
		cout << "5元  : " << d << "张" << endl;
	}
	if (e != 0)
	{
		cout << "1元  : " << e << "张" << endl;
	}
	if (f != 0)
	{
		cout << "5角  : " << f << "张" << endl;
	}
	if (g != 0)
	{
		cout << "1角  : " << g << "张" << endl;
	}
	if (h != 0)
	{
		cout << "5分  : " << h << "张" << endl;
	}
	if (i != 0)
	{
		cout << "2分  : " << i << "张" << endl;
	}
	if (j != 0)
	{
		cout << "1分  : " << j << "张" << endl;
	}
	return 0;
}