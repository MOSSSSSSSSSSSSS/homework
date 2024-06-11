// 2253209 信07 刘佳朋
#include<iostream>
#include<iomanip>
#include"cmd_console_tools.h"
#include<Windows.h>
#include<conio.h>
#include"popstar.h"
#define HANG 3
#define LIE 6
using namespace std;

int pan_duan_he_fa(int x,int y,int line, int column,char option,int star[][10],int n)
{
	if (option == 'D'||option == 'F')
	{
		if (x >= 4 && x <= LIE * column + 3 && y >= 3 && y <= HANG * line + 2)
			return 1;
		else
			return 0;
	}
	else if(option == 'E'||n)
	{
		if (x >= 4 && x <= (LIE+2) * column + 3 && y >= 3 && y <= (HANG+1) * line + 2&&(x-3)%(LIE+2)!=0 && (x - 2) % (LIE + 2) != 0&&(y-2)%(HANG+1)!=0)
			return 1;
		else
			return 0;
	}
	else
	{
		if (x >= 4 && x <= (LIE + 2) * column + 3 && y >= 3 && y <= (HANG + 1) * line + 2 && (x - 3) % (LIE + 2) != 0 && (x - 2) % (LIE + 2) != 0 && (y - 2) % (HANG + 1) != 0&&star[(y - 3)/(HANG+1)][(x - 4)/(LIE+2)]!=0)
			return 1;
		else
			return 0;
	}
}
void chu_shi_zhuang_tai_lan(int line,int column,int hang,int lie,int n)
{
	cct_gotoxy(0, 0);
	cout << "屏幕当前设置为：" << hang * line + 8 +(n==1?0:line-1)<< "行" << lie * column + 7+(n==1?0:(column-1)*2) << "列" << endl;
	cct_gotoxy(0, ((n == 2) ? (HANG + 1) : HANG) * line + 4);
	cout << "箭头键/鼠标键移动，回车键/单击左键选择，Q/单击右键结束";
}
void jian_pan(int keycode2, int &x, int &y,int hang,int lie,int line ,int column)
{
	if (keycode2 == 72)
	{
		if ((y - 3) / hang == 0)
			y = (line - 1) * hang + 3;
		else
			y -= hang;
	}
	else if (keycode2 == 80)
	{
		if ((y - 3) / hang == line - 1)
			y = 3;
		else
			y += hang;
	}
	else if (keycode2 == 75)
	{
		if ((x - 4) / lie == 0)
			x = (column - 1) * lie + 4;
		else
			x -= lie;
	}
	else if (keycode2 == 77)
	{
		if ((x - 4) / lie == column - 1)
			x = 4;
		else
			x += lie;
	}
	else
		;
}
void yi_ge_se_kuai(int hang,int lie,int star[][10],int i,int j,int n,int temp,int d,int d2)
{
	if(n==0)
		star[i][j] = rand() % 5 + 1;
	if(n==0||n==2)
		cct_setcolor(star[i][j] + 8, 0);//回到原来的颜色背景原色，前景黑色，但不重新随机
	else if(n==1)
		cct_setcolor(star[i][j] + 8, 7);//光标移到某个地方
	else if (n == 3)
		cct_setcolor(temp+8, 7);
	else if (n == 4)
		cct_setcolor(temp + 8, 0);//回到原来的颜色背景原色，前景黑色，但不重新随机
	else if (n == 5)
		cct_setcolor(15, 15);
	else if(n == 6)
		cct_setcolor(temp + 8, 15);
	cct_gotoxy(4 + j * lie-d2, 3 + i * hang+d);
	cout << "╔";
	for (int i = 0; i < LIE / 2 - 2; i++)
		cout << "═";
	cout << "╗";
	for (int k = 0; k < HANG - 2; k++)
	{
		cct_gotoxy(4 + j * lie - d2, 4 + i * hang + k+d);
		cout << "║";
		for (int i = 0; i < LIE / 2 - 2; i++)
			cout << "  ";
		cout << "║";
	}
	cct_gotoxy(4 + j * lie - d2, 4+i*hang+HANG-2+d);
	cout << "╚";
	for (int i = 0; i < LIE / 2 - 2; i++)
		cout << "═";
	cout << "╝";
	cct_gotoxy(4 + j * lie+LIE/2-1-d2, 3 + i * hang+(HANG-1)/2+d);
	cout << "★";
	cct_setcolor(0, 7);
}
void wai_kuang_jia(int line,int column,int hang,int lie,int n)
{
	cct_setconsoleborder(lie * column + 7 + (n == 1 ? 0 : (column - 1) * 2), hang * line + 8+ (n == 1 ? 0 : line - 1), -1, -1);
	if (n == 1)
	{
		cout << endl << ' ';
		for (int i = 0; i < column; i++)
		{
			cout << setw(6) << i;
		}
	}
	else if (n == 2)
	{
		cout <<endl<< setw(7) << 0;
		for (int i = 1; i < column; i++)
		{
			cout << setw(8) << i;
		}
	}
	cout << endl << "  ";
	cct_setcolor(15, 0);
	cout << "╔";
	for (int i = 0; i < column; i++)
	{
		cout << "═══";
		if (n == 2 && i != column - 1)
			cout << "╦";
		Sleep(5);
	}
	cout << "╗";
	cct_setcolor(0, 7);
	cout << endl;
	for (int i = 0; i < line; i++)
	{
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "║";
		for (int j = 0; j < column; j++)
		{
			cout << "      ";
			if (n == 2 && j != column - 1)
				cout << "║";
			Sleep(5);
		}
		cout << "║";
		cct_setcolor(0, 7);
		cout << endl << char('A' + i) << ' ';
		cct_setcolor(15, 0);
		cout << "║";
		for (int j = 0; j < column; j++)
		{
			cout << "      ";
			if (n == 2 && j != column - 1)
				cout << "║";
			Sleep(5);
		}
		cout << "║";
		cct_setcolor(0, 7);
		cout << endl << "  ";
		cct_setcolor(15, 0);
		cout << "║";
		for (int j = 0; j < column; j++)
		{
			cout << "      ";
			if (n == 2 && j != column - 1)
				cout << "║";
			Sleep(5);
		}
		cout << "║";
		cct_setcolor(0, 7);
		cout << endl;
		if (n == 2&&i!=line-1)
		{
			cout << "  ";
			cct_setcolor(15, 0);
			cout << "╠";
			for (int j = 0; j < column; j++)
			{
				cout << "═══";
				if (j != column - 1)
					cout << "╬";
			}
			cout << "╣";
			cct_setcolor(0, 7);
			cout << endl;
		}
	}
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "╚";
	for (int i = 0; i < column; i++)
	{
		cout << "═══";
		if (n == 2 && i != column - 1)
			cout << "╩";
		Sleep(5);
	}
	cout << "╝";
	cct_setcolor(0, 7);
	cout << endl;
}
void se_kuai_yi_dong(int star[][10], int line, int column,char option,int star2[][10])
{
	for (int i = 0; i < column; i++)
	{
		for (int j = line-1; j >=0; j--)
		{
			if (star[j][i] == 0 && j >= 1 )
			{
				for (int k = j - 1; k >= 0; k--)
				{
					if (star[k][i] != 0)
					{
						int temp = star[k][i];
						yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, k, i, 5, 0, 0);
						Sleep(1);
						for (int m = 1; m < (j - k) * (option == 'G' ? (HANG + 1) : HANG); m++)
						{
							yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, k, i, 4, temp, m);
							Sleep(1);
							yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, k, i, 5, 0, m);
							if (option == 'G')
								cct_showstr(4 + i * (LIE + 2), 4 + k * (HANG + 1) + HANG - 2 + 1 + (m / 4)*(HANG+1), "═", 15, 0, LIE / 2);
						}
						yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, k, i, 4, temp, (option == 'G' ? (HANG + 1) : HANG) *(j-k));
						Sleep(1);
						star[k][i] = star[j][i];
						star[j][i] = temp;
						temp = star2[k][i];
						star2[k][i] = star2[j][i];
						star2[j][i] = temp;
						break;
					}
				}
			}
		}
	}
	int a, num = 0;
	for (int i = column - 1; i >= 0; i--)
	{
		for (int j = 0; j < line; j++)
		{
			if (star[j][i] == 0)
				a = 1;
			else
			{
				a = 0;
				break;
			}
		}
		if (a == 1)
			num++;
		else
			break;
	}
	for (int i = column - num - 1; i >= 0; i--)
	{
		for (int j = 0; j < line; j++)
		{
			if (star[j][i] == 0)
				a = 1;
			else
			{
				a = 0;
				break;
			}
		}
		if (a)
		{
			for (int j = i + 1; j < column - num; j++)
			{
				for (int k = line - 1; star[k][j]!=0&&k>=0;k--)
				{
					yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, k, j, 5, 0,0, 0);
					Sleep(1);
					for (int m = 2; m < (option == 'G' ? (LIE + 2) : LIE); m+=2)
					{
						yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, k, j, 2, 0, 0, m);
						Sleep(1);
						yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, k, j, 5, 0, 0, m);
						if (option == 'G')
						{
							cct_showstr(4 + j * (LIE + 2)-2, 3 + k * (HANG + 1), "║", 15, 0, 1);
							cct_showstr(4 + j * (LIE + 2) - 2 , 4 + k * (HANG + 1), "║", 15, 0, 1);
							cct_showstr(4 + j * (LIE + 2) - 2 , 5 + k * (HANG + 1), "║", 15, 0, 1);
						}
					}
					yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, k, j, 2, 0, 0, (option == 'G' ? (LIE + 2) : LIE));
					Sleep(1);
				}
			}
			for (int j = 0; j < column - i - 1 - num; j++)
			{
				for (int k = 0; k < line; k++)
				{
					star[k][i+j] = star[k][i+j+1];
					star2[k][i + j] = star2[k][i + j + 1];
				}
			}
			for (int j = 0; j < line; j++)
			{
				star[j][column - 1 - num] = 0;
				star2[j][column - 1 - num] = 1;
			}
			num++;
		}
	}
}