/* 信07 2253209 刘佳朋 */
#include<iostream>
#include"hanoi.h"
#include"cmd_console_tools.h"
#include<conio.h>
using namespace std;
/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
int main()
{
	int n;//n表示层数,speed表示移动速度
	char qsz, zjz, mbz,x,y,z;//x，y，z记录起始柱，中间柱，目标住，因为在递归函数中qsz，zjz，mbz的值发生变化
	int xuan_xiang;
	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);
	while (1) 
	{
		xuan_xiang = menu();
		if (xuan_xiang == 5)
		{
			cct_cls();
			hua_zhu_zi();
			cct_gotoxy(0, 39);
			cout << "按回车键继续";
			while (1)
			{
				if (_getch() == 13)
				{
					break;
				}
				else
				{
					;
				}
			}
		}
		else if (xuan_xiang == 0)
		{
			for (int i = 0; i < 24; i++)
			{
				cout << endl;
			}
			return 0;
		}
		else
		{
			shu_ru_can_shu(&qsz, &zjz, &mbz, &n, xuan_xiang);
			x = qsz;
			y = zjz;
			z = mbz;
			if (xuan_xiang == 1 || xuan_xiang == 2 || xuan_xiang == 3 || xuan_xiang == 4)
			{
				di_gui(qsz, zjz, mbz, n, xuan_xiang, x, y, z);
				cout <<endl<< "按回车键继续";
				while (1)
				{
					if (_getch() == 13)
					{
						break;
					}
					else
					{
						;
					}
				}
			}
			else if (xuan_xiang == 6 || xuan_xiang == 7 || xuan_xiang == 8 || xuan_xiang == 9)
			{
				hua_zhu_zi();
				hua_yuan_pan(qsz, n);
				if (xuan_xiang == 7)
				{
					if (n % 2 == 0)
					{
						yuan_pan_yi_dong(qsz, mbz, zjz, x, y, z, 7);
					}
					else
					{
						yuan_pan_yi_dong(qsz, zjz, mbz, x, y, z, 7);
					}
				}
				else if (xuan_xiang == 8)
				{
					di_gui(qsz, zjz, mbz, n, xuan_xiang, x, y, z);
				}
				else if (xuan_xiang == 9)
				{
					you_xi_mo_shi(n, x, y, z);
				}
				cct_gotoxy(0, 39 );
				cout << "按回车键继续";
				while (1)
				{
					if (_getch() == 13)
					{
						break;
					}
					else
					{
						;
					}
				}
			}
		}
		gui_ling();
	}
	
	return 0;
}
