// 2253209 ¡ıº—≈Û –≈07
#include<iostream>
using namespace std;

int main()
{
	char mi_ma[17] = {0};
	int chang_du, da_xie, xiao_xie, shu_zi, qi_ta;
	int da_xie2 = 0, xiao_xie2 = 0, shu_zi2 = 0, qi_ta2 = 0;
	while (getchar()!='\n')
	{
		;
	}
	cin >> chang_du >> da_xie >> xiao_xie >> shu_zi >> qi_ta;
	if(chang_du > 16 || chang_du < 12|| da_xie < 2 || da_xie>chang_du|| xiao_xie < 2 || xiao_xie>chang_du|| shu_zi < 2 || shu_zi>chang_du|| qi_ta < 2 || qi_ta>chang_du|| da_xie + xiao_xie + shu_zi + qi_ta > chang_du)
	{
		cout << "¥ÌŒÛ" << endl;
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			cin >> mi_ma;
			for (int j = 0; mi_ma[j] != '\0'; j++)
			{
				if (mi_ma[j] >= 'A' && mi_ma[j] <= 'Z')
				{
					da_xie2++;
				}
				else if (mi_ma[j] >= 'a' && mi_ma[j] <= 'z')
				{
					xiao_xie2++;
				}
				else if (mi_ma[j] >= '0' && mi_ma[j] <= '9')
				{
					shu_zi2++;
				}
				else if(mi_ma[j]== '!'|| mi_ma[j] == '@' || mi_ma[j] == '#' || mi_ma[j] == '$' || mi_ma[j] == '%' || mi_ma[j] == '^' || mi_ma[j] == '&' || mi_ma[j] == '*' || mi_ma[j] == '-' || mi_ma[j] == '_' || mi_ma[j] == '=' || mi_ma[j] == '+' || mi_ma[j] == ',' || mi_ma[j] == '.' || mi_ma[j] == '?' )
				{
					qi_ta2++;
				}
			}
			if (da_xie2 < da_xie || xiao_xie2 < xiao_xie || shu_zi2 < shu_zi || qi_ta2 < qi_ta || da_xie2 + xiao_xie2 + shu_zi2 + qi_ta2 != chang_du)
			{
				cout << "¥ÌŒÛ" << endl;
				break;
			}
			else
			{
				if (i == 9)
				{
					cout << "’˝»∑" << endl;
				}
				else
				{
					da_xie2 = 0;
					xiao_xie2 = 0;
					shu_zi2 = 0;
					qi_ta2 = 0;
					continue;
				}
			}
		}
	}

	return 0;
}