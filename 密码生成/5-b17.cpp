// 2253209 ������ ��07
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
	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
	cin >> chang_du >> da_xie >> xiao_xie >> shu_zi >> qi_ta;
	if (cin.fail())
	{
		cout << "����Ƿ�" << endl;
	}
	else if (chang_du > 16 || chang_du < 12)
	{
		cout << "���볤��[" << chang_du << "]����ȷ" << endl;
	}
	else if (da_xie < 2||da_xie>chang_du)
	{
		cout << "��д��ĸ����[" << da_xie << "]����ȷ" << endl;
	}
	else if (xiao_xie < 2 || xiao_xie>chang_du)
	{
		cout << "Сд��ĸ����[" << xiao_xie << "]����ȷ" << endl;
	}
	else if (shu_zi < 2 || shu_zi>chang_du)
	{
		cout << "���ָ���[" << shu_zi << "]����ȷ" << endl;
	}
	else if (qi_ta < 2 || qi_ta>chang_du)
	{
		cout << "�������Ÿ���[" << qi_ta << "]����ȷ" << endl;
	}
	else if (da_xie + xiao_xie + shu_zi + qi_ta > chang_du)
	{
		cout << "�����ַ�����֮��[" << da_xie << '+' << xiao_xie << '+' << shu_zi << '+' << qi_ta << "]���������볤��[" << chang_du << ']' << endl;
	}
	else
	{
		fun2(mi_ma, chang_du,da_xie,xiao_xie,shu_zi,qi_ta);
	}

	return 0;
}