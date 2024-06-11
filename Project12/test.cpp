#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<exception>
#include<vector>
#include<string>
using namespace std;

enum class new_enum :unsigned int {
	value1,
	value2,
	value3 = 100,
	value4 = 100
};
enum new_enum2{a,b,c,d};

int main()
{
	//if (a < new_enum::value3) {

	//}
	if (a < 111)
	{

	}
	if (new_enum::value3 < new_enum::value4)
	{

	}
	//cout << new_enum::value3;//报错
	cout << a;//不报错
	cout << (int)(new_enum::value3);//不报错

	return 0;
}