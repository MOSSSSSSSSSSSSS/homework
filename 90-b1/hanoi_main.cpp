/* ��07 2253209 ������ */
#include<iostream>
#include"hanoi.h"
#include"cmd_console_tools.h"
#include<conio.h>
using namespace std;
/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

     ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */
int main()
{
	int n;//n��ʾ����,speed��ʾ�ƶ��ٶ�
	char qsz, zjz, mbz,x,y,z;//x��y��z��¼��ʼ�����м�����Ŀ��ס����Ϊ�ڵݹ麯����qsz��zjz��mbz��ֵ�����仯
	int xuan_xiang;
	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setconsoleborder(120, 40, 120, 9000);
	while (1) 
	{
		xuan_xiang = menu();
		if (xuan_xiang == 5)
		{
			cct_cls();
			hua_zhu_zi();
			cct_gotoxy(0, 39);
			cout << "���س�������";
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
				cout <<endl<< "���س�������";
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
				cout << "���س�������";
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
