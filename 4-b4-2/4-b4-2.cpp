/* 2253209 刘佳朋 信07 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
char menu()
{
	char a;
	cout << "1.用I、J、K、L键控制上下左右(大小写均可，边界停止)" << endl;
	cout << "2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)" << endl;
	cout << "3.用箭头键控制上下左右，边界停止" << endl;
	cout << "4.用箭头键控制上下左右，边界回绕" << endl;
	cout << "5.用I、J、K、L键控制上下左右(大小写均可，边界停止,按左箭头键不准向下移动)" << endl;
	cout << "6.用I、J、K、L键控制上下左右(大小写均可，边界回绕,按左箭头键不准向下移动)" << endl;
	cout << "0.退出" << endl;
	cout << "[请选择0-6] ";
	a = _getch();


	return a;
}
void move_by_ijkl(char b)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	char a;
	int x = 35, y = 9;
	if (b == '1')
	{
		while (1)
		{
			a = _getch();

			if (a == 'i' || a == 'I')
			{
				if (y > 1)
				{
					y--;
				}
				else
				{
					;
				}
			}
			else if (a == 'j' || a == 'J')
			{
				if (x > 1)
				{
					x--;
				}
				else
				{
					;
				}
			}
			else if (a == 'k'||a=='K')
			{
				if (y < 17)
				{
					y++;
				}
				else
				{
					;
				}
			}
			else if (a == 'l' || a == 'L')
			{
				if (x < 69)
				{
					x++;
				}
				else
				{
					;
				}
			}
			else if (a == ' ')
			{
				showch(hout, x, y, ' ');
			}
			else if (a == 'q' || a == 'Q')
			{
				gotoxy(hout,0,23 );
				cout << "游戏结束，按回车键返回菜单.";
				break;
			}
			else
			{
				;
			}
			gotoxy(hout, x, y);
		}
	}
	else if(b=='2')
	{
		while (1)
		{
			a = _getch();
			if (a == 'i' || a == 'I')
			{
				if (y > 1)
				{
					y--;
				}
				else
				{
					y=17;
				}
			}
			else if (a == 'j' || a == 'J')
			{
				if (x > 1)
				{
					x--;
				}
				else
				{
					x=69;
				}
			}
			else if (a == 'k' || a == 'K')
			{
				if (y < 17)
				{
					y++;
				}
				else
				{
					y=1;
				}
			}
			else if (a == 'l' || a == 'L')
			{
				if (x < 69)
				{
					x++;
				}
				else
				{
					x=1;
				}
			}
			else if (a == ' ')
			{
				showch(hout, x, y, ' ');
			}
			else if (a == 'q' || a == 'Q')
			{
				gotoxy(hout, 0, 23);
				cout << "游戏结束，按回车键返回菜单.";
				break;
			}
			else
			{
				;
			}
			gotoxy(hout, x, y);
		}
	}
	else if (b == '5')
	{
		char a2;
		while (1)
		{
			a = _getch();
			if (a == -32)
			{
				a2 = _getch();
			}
			else
			{
				if (a == 'i' || a == 'I')
				{
					if (y > 1)
					{
						y--;
					}
					else
					{
						;
					}
				}
				else if (a == 'j' || a == 'J')
				{
					if (x > 1)
					{
						x--;
					}
					else
					{
						;
					}
				}
				else if (a == 'k' || a == 'K')
				{
					if (y < 17)
					{
						y++;
					}
					else
					{
						;
					}
				}
				else if (a == 'l' || a == 'L')
				{
					if (x < 69)
					{
						x++;
					}
					else
					{
						;
					}
				}
				else if (a == ' ')
				{
					showch(hout, x, y, ' ');
				}
				else if (a == 'q' || a == 'Q')
				{
					gotoxy(hout, 0, 23);
					cout << "游戏结束，按回车键返回菜单.";
					break;
				}
				else
				{
					;
				}
				gotoxy(hout, x, y);
			}
		}
	}
	else if (b == '6')
	{
		char a2;
		while (1)
		{
			a = _getch();
			if (a == -32)
			{
				a2 = _getch();
			}
			else
			{
				if (a == 'i' || a == 'I')
				{
					if (y > 1)
					{
						y--;
					}
					else
					{
						y = 17;
					}
				}
				else if (a == 'j' || a == 'J')
				{
					if (x > 1)
					{
						x--;
					}
					else
					{
						x = 69;
					}
				}
				else if (a == 'k' || a == 'K')
				{
					if (y < 17)
					{
						y++;
					}
					else
					{
						y = 1;
					}
				}
				else if (a == 'l' || a == 'L')
				{
					if (x < 69)
					{
						x++;
					}
					else
					{
						x = 1;
					}
				}
				else if (a == ' ')
				{
					showch(hout, x, y, ' ');
				}
				else if (a == 'q' || a == 'Q')
				{
					gotoxy(hout, 0, 23);
					cout << "游戏结束，按回车键返回菜单.";
					break;
				}
				else
				{
					;
				}
				gotoxy(hout, x, y);
			}
		}
	}
}
void move_by_arrow(char b)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	int a;
	int x = 35, y = 9;
	if (b == '3')
	{
		while (1)
		{
			a = _getch();
			if (a ==72)
			{
				if (y > 1)
				{
					y--;
				}
				else
				{
					;
				}
			}
			else if (a == 75)
			{
				if (x > 1)
				{
					x--;
				}
				else
				{
					;
				}
			}
			else if (a == 80)
			{
				if (y < 17)
				{
					y++;
				}
				else
				{
					;
				}
			}
			else if (a == 77)
			{
				if (x < 69)
				{
					x++;
				}
				else
				{
					;
				}
			}
			else if (a == ' ')
			{
				showch(hout, x, y, ' ');
			}
			else if (a == 'q' || a == 'Q')
			{
				gotoxy(hout, 0, 23);
				cout << "游戏结束，按回车键返回菜单.";
				break;
			}
			else
			{
				;
			}
			gotoxy(hout, x, y);
		}
	}
	else
	{
		while (1)
		{
			a = _getch();
			if (a == 72)
			{
				if (y > 1)
				{
					y--;
				}
				else
				{
					y = 17;
				}
			}
			else if (a == 75)
			{
				if (x > 1)
				{
					x--;
				}
				else
				{
					x = 69;
				}
			}
			else if (a == 80)
			{
				if (y < 17)
				{
					y++;
				}
				else
				{
					y = 1;
				}
			}
			else if (a == 77)
			{
				if (x < 69)
				{
					x++;
				}
				else
				{
					x = 1;
				}
			}
			else if (a == ' ')
			{
				showch(hout, x, y, ' ');
			}
			else if (a == 'q' || a == 'Q')
			{
				gotoxy(hout, 0, 23);
				cout << "游戏结束，按回车键返回菜单.";
				break;
			}
			else
			{
				;
			}
			gotoxy(hout, x, y);
		}
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/

int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));
	char a;
	while (1)
	{
		cls(hout);
		a = menu();
		if (a == '0')
		{
			cout << 0<<endl;
			return 0;
		}
		else
		{
			cls(hout);
			init_border(hout);
			gotoxy(hout, 35, 9);
			if (a == '1' || a == '2' || a == '5' || a == '6')
			{
				move_by_ijkl(a);
			}
			else if (a == '3' || a == '4')
			{
				move_by_arrow(a);
			}
		}
		while (1)
		{
			a = _getch();
			if (int(a) == 13)
			{
				break;
			}
			else
			{
				;
			}
		}
	}

		return 0;
}
//思考1:_getch()函数如果输入的是上下左右的方向键，F1~F9，Delete等功能键，会调用两次，并且有两个返回值，第二次返回真实键值，最终函数中接收按键值的char型变量a应该是第二次返回的真实键值
//例如左箭头键第二次返回75，和K的ascⅡ码相同，就会产生和按K同样的效果
//思考2:不一定，有可能不到20个字母，rand（）%69+1是x坐标，rand（）%17+1是y坐标，当某一次循环中rand（）产生的随机数%69和%17产生的余数和前几次循环中某一次的相同，就会在相同位置再次打印一个字母，
//覆盖掉原来的字母，总数就小于20