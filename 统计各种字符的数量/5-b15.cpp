// 2253209 ������ ��07
#include<iostream>
using namespace std;

int main()
{
	int da_xie=0, xiao_xie=0, shu_zi=0, kong_ge=0, qi_ta=0;
	char str[3][128] = {0};
	for (int i = 1; i <= 3; i++)
	{
		cout << "�������"<<i<<"��" << endl;
		cin.getline(str[i - 1], 127 );
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			if ('a' <= str[i][j] && str[i][j] <= 'z')
			{
				xiao_xie++;
			}
			else if ('A' <= str[i][j] && str[i][j] <= 'Z')
			{
				da_xie++;
			}
			else if ('0' <= str[i][j] && str[i][j] <= '9')
			{
				shu_zi++;
			}
			else if (str[i][j] == ' ')
			{
				kong_ge++;
			}
			else
			{
				if (str[i][j] == '\0')
				{
					break;
				}
				else
				{
					qi_ta++;
				}
			}
		}
	}
	cout << "��д : " << da_xie<<endl;
	cout << "Сд : " << xiao_xie << endl;
	cout << "���� : " << shu_zi << endl;
	cout << "�ո� : " << kong_ge << endl;
	cout << "���� : " << qi_ta << endl;

	return 0;
}