// 2253209 –≈07 ¡ıº—≈Û
#include<iostream>
#define pi 3.14159
#include<iomanip>
using namespace std;

int main()
{
	double a = 9999999999.99;
	cout << int(a-1000000000*9);
	cout << typeid(1000000000*9).name();
	return 0;
}