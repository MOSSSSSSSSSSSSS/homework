// 2253209 信07 刘佳朋
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<time.h>
#include<cstring>
#include<conio.h>
#include"cmd_console_tools.h"
#include"popstar.h"
using namespace std;

void yi_dong(int star[][10],int line,int column,int star2[][10])
{
	for (int i = 1; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (star[i][j] == 0)
			{
				for (int k = 0;i-k-1>=0&&star[i-k-1][j]!=0; k++)
				{
					int temp = star[i - k - 1][j];
					star[i - k - 1][j] = star[i - k][j];
					star[i - k][j] = temp;
				}
			}
		}
	}
	int a,num = 0;
	for (int i = 0; i < column - num; i++)
	{
		for (int j = 0; j < line; j++)
		{
			if (star[j][i] == 0)
				a=1;
			else
			{
				a = 0;
				break;
			}
		}
		if (a)
		{
			num++;
			for (int k = i ; k < column-1; k++)
			{
				for (int m = 0; m < line; m++)
				{
					star[m][k] = star[m][k + 1];
					star2[m][k] = star2[m][k + 1];
				}
			}
			for (int k = 0; k < line; k++)
			{
				star[k][column - 1] = 0;
				star2[k][column - 1] = 1;
			}
			i--;
		}
	}
}
int YNQ(char xy[])
{
	char a;
	int x, y;
	cout << "请确认是否把"<<xy[0]<<xy[1]<<"及周围的相同值消除(Y / N / Q)：";
	cct_getxy(x,y);
	do
	{
		cct_gotoxy(x, y);
		a = _getche();
	} while (a != 'y' && a != 'n' && a != 'q' && a != 'Y' && a != 'N' && a != 'Q');
	if (a == 'q' || a == 'Q')
		return 0;
	else if (a == 'y' || a == 'Y')
		return 1;
	else
		return 2;
}
void shu_zu(int line, int column, int star[][10], int n, int temp, int star2[][10])
{
	srand((unsigned int)(time(0)));
	char shu_zu_lei_xing[6][35];
	strcpy(shu_zu_lei_xing[0], "当前数组：");
	strcpy(shu_zu_lei_xing[1], "查找结果数组：");
	strcpy(shu_zu_lei_xing[2], "当前数组(不同色标识)：");
	strcpy(shu_zu_lei_xing[3], "相同值归并后的数组(不同色标识)：");
	strcpy(shu_zu_lei_xing[4], "下落后的数组：");
	strcpy(shu_zu_lei_xing[5], "当前数组：");
	cout << endl << shu_zu_lei_xing[n] << endl;
	cout << "  |";
	for (int i = 0; i < column; i++)
		cout << "  " << i;
	cout << endl << "--+" << setfill('-') << setw(column * 3 + 1) << '-' << endl;
	for (int i = 0; i < line; i++)
	{
		cout << char('A' + i) << " |";
		for (int j = 0; j < column; j++)
		{
			if (n == 0)
			{
				sui_ji(star, i, j);
				cout << "  " << star[i][j];
			}
			else if (n == 1)
			{
				if (star[i][j] == 0 && !star2[i][j])
				{
					cout << "  *";
				}
				else
					cout << "  " << star[i][j];
			}
			else
			{
				if (star[i][j] == 0 && !star2[i][j] || star[i][j] == 0 && (n == 4 || n == 5))
				{
					if (n == 5)
						star2[i][j] = 1;
					int x, y;
					cct_getxy(x, y);
					cct_showch(x + 2, y, char((n == 2 ? temp : 0) + '0'), 14, 0, 1);
					cct_setcolor(0, 7);
				}
				else
					cout << "  " << star[i][j];
			}
		}
		cout << endl;
	}
}