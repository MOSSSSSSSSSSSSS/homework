// 2253209 ��07 ������
#include<iostream>
using namespace std;

int main()
{
	double num;
	int s,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0;
	cout << "����������ֵ��" << endl;
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
	cout << "��" << s << "�����㣬�������£�" << endl;
	if (a != 0)
	{
		cout << "50Ԫ : " << a << "��" << endl;
	}
	if (b != 0)
	{
		cout << "20Ԫ : " << b << "��" << endl;
	}
	if (c != 0)
	{
		cout << "10Ԫ : " << c << "��" << endl;
	}
	if (d != 0)
	{
		cout << "5Ԫ  : " << d << "��" << endl;
	}
	if (e != 0)
	{
		cout << "1Ԫ  : " << e << "��" << endl;
	}
	if (f != 0)
	{
		cout << "5��  : " << f << "��" << endl;
	}
	if (g != 0)
	{
		cout << "1��  : " << g << "��" << endl;
	}
	if (h != 0)
	{
		cout << "5��  : " << h << "��" << endl;
	}
	if (i != 0)
	{
		cout << "2��  : " << i << "��" << endl;
	}
	if (j != 0)
	{
		cout << "1��  : " << j << "��" << endl;
	}
	return 0;
}