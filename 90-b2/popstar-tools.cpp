// 2253209 ��07 ������
#include<iostream>
#include<stdio.h>
#include"cmd_console_tools.h"
#include"popstar.h"
#include<conio.h>
#include<iomanip>
using namespace std;

void sui_ji(int star[][10],int i,int j)
{
	star[i][j] = rand() % 5 + 1;
}
void zan_ting()
{
	char arr[4] = {0};
	while (1)
	{
		cout<<endl << "��С�������������End����...                    ";
		cin.clear();
		cin.ignore(65536, '\n');
		cin.get(arr, 4, '\n');
		for (int i = 0; i < 3; i++)
		{
			if (arr[i] >= 'a' && arr[i] <= 'z')
				arr[i] -= 32;
		}
		if (arr[0] == 'E' && arr[1] == 'N' && arr[2] == 'D')
			break;
		else
			cout << "�����������������" << endl;
	}
}
int cha_zhao(int star[][10], int x, int y, int line, int column, int temp,int n)
{
	static int num;
	if (x - 1 >= 0)
	{
		if (star[x - 1][y] == temp)
		{
			star[x - 1][y] = 0;
			num++;
			cha_zhao(star, x - 1, y, line, column,temp,2);
		}
	}
	if (y - 1 >= 0)
	{
		if (star[x][y-1] == temp)
		{
			star[x][y-1] = 0;
			num++;
			cha_zhao(star, x , y-1, line, column,temp,2);
		}
	}
	if (y + 1 <= column-1)
	{
		if (star[x][y + 1] == temp)
		{
			star[x][y+1] = 0;
			num++;
			cha_zhao(star, x, y + 1, line, column,temp,2);
		}
	}
	if (x + 1 <= line - 1)
	{
		if (star[x+1][y] == temp)
		{
			star[x+1][y] = 0;
			num++;
			cha_zhao(star, x+1, y, line, column,temp,2);
		}
	}
	if (n == 1)
	{
		int num2 = num;
		num = 0;
		return num2;
	}
	else
		return 0;
}
int shu_ru(int star[][10],int line,int column,char xy[],int &num)
{
	int i = 0,temp;
	int x, y;
	while (1)
	{
		cout << endl << "������ĸ+������ʽ[����c2]����������꣺";
		cct_getxy(x, y);
		while (1)
		{
			cin.clear();
			cin.ignore(65536, '\n');
			cin.get(xy, 3, '\n');
			if (xy[0] >= 'a' || xy[0] <= 'z')
				xy[0] -= 32;
			if (xy[0] >= 'A' && xy[0] <= 'A' + line - 1 && xy[1] >= '0' && xy[1] <= '0' + column - 1)
				break;
			else
			{
				cct_showch(x, y, ' ', 0, 7, 20);
				cout << endl << "�����������������.";
				cct_gotoxy(x, y);
			}
		}
		cout << "����Ϊ" << xy[0] << "��" << xy[1] << "��" << endl;
		temp = star[xy[0] - 'A'][xy[1] - '0'];
		if(temp)
			num = cha_zhao(star, xy[0] - 'A', xy[1] - '0', line, column, star[xy[0] - 'A'][xy[1] - '0'], 1);
		else
		{
			cout << "����ľ�������λ��Ϊ0���Ƿ�λ�ã�������������";
			continue;
		}
		if (num)
		{
			break;
		}
		else
		{
			cout << "����ľ�������λ�ô���������ֵͬ������������";
		}
	}

	return temp;
}
void hui_che(int x)
{
	if (x == 1)
		cout << "���س������������������..." << endl;
	else
		cout << "�����������������س���������һ�ε�����..." << endl;
	while (_getch() != 13)
		;
}
void score(int num, int n)
{
	static int score;
	if (n == 1)
	{
		score += num * num * 5;
		cout << "���ε÷֣�" << setw(5) << num * num * 5 << " �ܵ÷֣�" << score << endl;
	}
	else if(n == 0)
		score = 0;
	else
	{
		cct_gotoxy(0, 0);
		if (num >= 10)
			cout << "�����÷֣�" << setw(5) << 0<< " �ܵ÷֣�" << score << endl;
		else
		{
			score += (10 - num) * 180;
			cout << "�����÷֣�" << setw(5) <<(10 - num) * 180 << " �ܵ÷֣�" << score << endl;
		}
	}
}
int pan_duan_tong_guan(int star[][10],int line,int column)
{
	int num = 1;
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (star[i][j] != 0)
			{
				num++;
				if (i - 1 >= 0)
				{
					if (star[i - 1][j] == star[i][j])
						return 0;
				}
				if (j - 1 >= 0)
				{
					if (star[i][j - 1] == star[i][j])
						return 0;
				}
				if (j + 1 <= column - 1)
				{
					if (star[i][j + 1] == star[i][j])
						return 0;
				}
				if (i + 1 <= line - 1)
				{
					if (star[i + 1][j] == star[i][j])
						return 0;
				}
			}
		}
	}
	return num;
}