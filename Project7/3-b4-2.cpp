// 2253209 信07 刘佳朋
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
	cout << "请输入三角形的两边及其夹角(角度)" << endl;
	cin >> a >> b >> c;
	d = c *pi/ 180 ;
	s = 1.0/ 2 * a * b * sin(d);
	cout << "三角形面积为 : " << setiosflags(ios::fixed) << setprecision(3) << s << endl;
	return 0;
}