// 2253209 刘佳朋 信07
#include<iostream>
#include<time.h>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";
void fun1(char mi_ma[],int chang_du,int a, char ch)
{
	for (int i = 0; i < a;)
	{
		int n = rand() % chang_du;
		if (mi_ma[n] == '\0')
		{
			mi_ma[n] = ch;
			i++;
		}
		else
		{
			continue;
		}
	}
}
void fun2(char mi_ma[], int chang_du,int da_xie,int xiao_xie,int shu_zi,int qi_ta)
{
	cout << chang_du << ' ' << da_xie << ' ' << xiao_xie << ' ' << shu_zi << ' ' << qi_ta << endl;
	for (int j = 0; j < 10; j++)
	{
		fun1(mi_ma, chang_du, da_xie, '1');
		fun1(mi_ma, chang_du, xiao_xie, '2');
		fun1(mi_ma, chang_du, shu_zi, '3');
		fun1(mi_ma, chang_du, qi_ta, '4');
		for (int i = 0; i < chang_du; i++)
		{
			if (mi_ma[i] == '\0')
			{
				mi_ma[i] = rand() % 4 + '1';
			}
		}
		for (int i = 0; i < chang_du; i++)
		{
			if (mi_ma[i] == '1')
			{
				mi_ma[i] = rand() % 26 + 'A';
			}
			else if (mi_ma[i] == '2')
			{
				mi_ma[i] = rand() % 26 + 'a';
			}
			else if (mi_ma[i] == '3')
			{
				mi_ma[i] = rand() % 10 + '0';
			}
			else
			{
				mi_ma[i] = other[rand() % 15];
			}
		}
		cout << mi_ma << endl;
		for (int i = 0; i < chang_du; i++)
		{
			mi_ma[i] = '\0';
		}
	}
}
int main()
{
	srand((unsigned int)(time(0)));
	int chang_du, da_xie, xiao_xie, shu_zi, qi_ta;
	char mi_ma[17] = {0};
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> chang_du >> da_xie >> xiao_xie >> shu_zi >> qi_ta;
	if (cin.fail())
	{
		cout << "输入非法" << endl;
	}
	else if (chang_du > 16 || chang_du < 12)
	{
		cout << "密码长度[" << chang_du << "]不正确" << endl;
	}
	else if (da_xie < 2||da_xie>chang_du)
	{
		cout << "大写字母个数[" << da_xie << "]不正确" << endl;
	}
	else if (xiao_xie < 2 || xiao_xie>chang_du)
	{
		cout << "小写字母个数[" << xiao_xie << "]不正确" << endl;
	}
	else if (shu_zi < 2 || shu_zi>chang_du)
	{
		cout << "数字个数[" << shu_zi << "]不正确" << endl;
	}
	else if (qi_ta < 2 || qi_ta>chang_du)
	{
		cout << "其它符号个数[" << qi_ta << "]不正确" << endl;
	}
	else if (da_xie + xiao_xie + shu_zi + qi_ta > chang_du)
	{
		cout << "所有字符类型之和[" << da_xie << '+' << xiao_xie << '+' << shu_zi << '+' << qi_ta << "]大于总密码长度[" << chang_du << ']' << endl;
	}
	else
	{
		fun2(mi_ma, chang_du,da_xie,xiao_xie,shu_zi,qi_ta);
	}

	return 0;
}