/* ��07 2253209 ������ */
#include<iostream>
#include"cmd_console_tools.h"
#include<iomanip>
#include<conio.h>
#include<Windows.h>
using namespace std;
/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

     ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */
static int bu_shu = 1;
static int qszz[10], zjzz[10], mbzz[10], qszzz, zjzzz, mbzzz;
static int speed;
void gui_ling()
{
    bu_shu = 1;
    qszzz = 0;
    zjzzz = 0;
    mbzzz = 0;
    speed = 0;
    for (int i = 0; i < 10; i++)
    {
        qszz[i] = 0;
        zjzz[i] = 0;
        mbzz[i] = 0;
    }
}
void yuan_pan_yi_dong(char qsz,char zjz,char mbz,char x,char y,char z,int xuan_xiang)
{
    if (xuan_xiang == 1 || xuan_xiang == 2 || xuan_xiang == 3 || xuan_xiang == 4)
    {
        ;
    }
    else
    {
        if (xuan_xiang != 7 && xuan_xiang != 9)
        {
            if (speed == 0)
            {
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
            else
            {
                Sleep((6 - speed) * 200);
            }
        }
        if (qsz == x && mbz == z)
        {
            for (int i = 0; 15 - qszzz - i - 1 > 1; i++)
            {
                cct_showch((qsz - 'A') * 32 + 12 - qszz[qszzz - 1], 15 - qszzz - i, ' ', 0, 7, qszz[qszzz - 1] * 2 + 1);
                cct_showch((qsz - 'A') * 32 + 12, 15 - qszzz - i, ' ', 1, 7, 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
                cct_showch((qsz - 'A') * 32 + 12 - qszz[qszzz - 1], 15 - qszzz - i - 1, ' ', 2 + qszz[qszzz - 1], 7, qszz[qszzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
            }
            for (int i = 0; qsz > mbz ? ((qsz - 'A') * 32 + 12 - qszz[qszzz - 1] - i - 1 >= (mbz - 'A') * 32 + 12 - qszz[qszzz - 1]) : ((qsz - 'A') * 32 + 12 - qszz[qszzz - 1] + i + 1 <= (mbz - 'A') * 32 + 12 - qszz[qszzz - 1]); i++)
            {
                cct_showch(qsz > mbz ? ((qsz - 'A') * 32 + 12 - qszz[qszzz - 1] - i) : ((qsz - 'A') * 32 + 12 - qszz[qszzz - 1] + i), 2, ' ', 0, 7, qszz[qszzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
                cct_showch(qsz > mbz ? ((qsz - 'A') * 32 + 12 - qszz[qszzz - 1] - i - 1) : ((qsz - 'A') * 32 + 12 - qszz[qszzz - 1] + i + 1), 2, ' ', 2 + qszz[qszzz - 1], 7, qszz[qszzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
            }
            for (int i = 0; 3 + i <= 14 - mbzzz; i++)
            {
                cct_showch((mbz - 'A') * 32 + 12 - qszz[qszzz - 1], 2 + i, ' ', 0, 7, qszz[qszzz - 1] * 2 + 1);
                if (i != 0)
                {
                    cct_showch((mbz - 'A') * 32 + 12, 2 + i, ' ', 1, 7, 1);
                }
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
                cct_showch((mbz - 'A') * 32 + 12 - qszz[qszzz - 1], 3 + i, ' ', 2 + qszz[qszzz - 1], 7, qszz[qszzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
            }
        }
        else if (qsz == x && mbz == y)
        {
            for (int i = 0; 15 - qszzz - i - 1 > 1; i++)
            {
                cct_showch((qsz - 'A') * 32 + 12 - qszz[qszzz - 1], 15 - qszzz - i, ' ', 0, 7, qszz[qszzz - 1] * 2 + 1);
                cct_showch((qsz - 'A') * 32 + 12, 15 - qszzz - i, ' ', 1, 7, 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
                cct_showch((qsz - 'A') * 32 + 12 - qszz[qszzz - 1], 15 - qszzz - i - 1, ' ', 2 + qszz[qszzz - 1], 7, qszz[qszzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
            }
            for (int i = 0; qsz > mbz ? ((qsz - 'A') * 32 + 12 - qszz[qszzz - 1] - i - 1 >= (mbz - 'A') * 32 + 12 - qszz[qszzz - 1]) : ((qsz - 'A') * 32 + 12 - qszz[qszzz - 1] + i + 1 <= (mbz - 'A') * 32 + 12 - qszz[qszzz - 1]); i++)
            {
                cct_showch(qsz > mbz ? ((qsz - 'A') * 32 + 12 - qszz[qszzz - 1] - i) : ((qsz - 'A') * 32 + 12 - qszz[qszzz - 1] + i), 2, ' ', 0, 7, qszz[qszzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
                cct_showch(qsz > mbz ? ((qsz - 'A') * 32 + 12 - qszz[qszzz - 1] - i - 1) : ((qsz - 'A') * 32 + 12 - qszz[qszzz - 1] + i + 1), 2, ' ', 2 + qszz[qszzz - 1], 7, qszz[qszzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
            }
            for (int i = 0; 3 + i <= 14 - zjzzz; i++)
            {
                cct_showch((mbz - 'A') * 32 + 12 - qszz[qszzz - 1], 2 + i, ' ', 0, 7, qszz[qszzz - 1] * 2 + 1);
                if (i != 0)
                {
                    cct_showch((mbz - 'A') * 32 + 12, 2 + i, ' ', 1, 7, 1);
                }
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
                cct_showch((mbz - 'A') * 32 + 12 - qszz[qszzz - 1], 3 + i, ' ', 2 + qszz[qszzz - 1], 7, qszz[qszzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
            }
        }
        else if (qsz == y && mbz == x)
        {
            for (int i = 0; 15 - zjzzz - i - 1 > 1; i++)
            {
                cct_showch((qsz - 'A') * 32 + 12 - zjzz[zjzzz - 1], 15 - zjzzz - i, ' ', 0, 7, zjzz[zjzzz - 1] * 2 + 1);
                cct_showch((qsz - 'A') * 32 + 12, 15 - zjzzz - i, ' ', 1, 7, 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
                cct_showch((qsz - 'A') * 32 + 12 - zjzz[zjzzz - 1], 15 - zjzzz - i - 1, ' ', 2 + zjzz[zjzzz - 1], 7, zjzz[zjzzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
            }
            for (int i = 0; qsz > mbz ? ((qsz - 'A') * 32 + 12 - zjzz[zjzzz - 1] - i - 1 >= (mbz - 'A') * 32 + 12 - zjzz[zjzzz - 1]) : ((qsz - 'A') * 32 + 12 - zjzz[zjzzz - 1] + i + 1 <= (mbz - 'A') * 32 + 12 - zjzz[zjzzz - 1]); i++)
            {
                cct_showch(qsz > mbz ? ((qsz - 'A') * 32 + 12 - zjzz[zjzzz - 1] - i) : ((qsz - 'A') * 32 + 12 - zjzz[zjzzz - 1] + i), 2, ' ', 0, 7, zjzz[zjzzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
                cct_showch(qsz > mbz ? ((qsz - 'A') * 32 + 12 - zjzz[zjzzz - 1] - i - 1) : ((qsz - 'A') * 32 + 12 - zjzz[zjzzz - 1] + i + 1), 2, ' ', 2 + zjzz[zjzzz - 1], 7, zjzz[zjzzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
            }
            for (int i = 0; 3 + i <= 14 - qszzz; i++)
            {
                cct_showch((mbz - 'A') * 32 + 12 - zjzz[zjzzz - 1], 2 + i, ' ', 0, 7, zjzz[zjzzz - 1] * 2 + 1);
                if (i != 0)
                {
                    cct_showch((mbz - 'A') * 32 + 12, 2 + i, ' ', 1, 7, 1);
                }
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
                cct_showch((mbz - 'A') * 32 + 12 - zjzz[zjzzz - 1], 3 + i, ' ', 2 + zjzz[zjzzz - 1], 7, zjzz[zjzzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
            }
        }
        else if (qsz == y && mbz == z)
        {
            for (int i = 0; 15 - zjzzz - i - 1 > 1; i++)
            {
                cct_showch((qsz - 'A') * 32 + 12 - zjzz[zjzzz - 1], 15 - zjzzz - i, ' ', 0, 7, zjzz[zjzzz - 1] * 2 + 1);
                cct_showch((qsz - 'A') * 32 + 12, 15 - zjzzz - i, ' ', 1, 7, 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
                cct_showch((qsz - 'A') * 32 + 12 - zjzz[zjzzz - 1], 15 - zjzzz - i - 1, ' ', 2 + zjzz[zjzzz - 1], 7, zjzz[zjzzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
            }
            for (int i = 0; qsz > mbz ? ((qsz - 'A') * 32 + 12 - zjzz[zjzzz - 1] - i - 1 >= (mbz - 'A') * 32 + 12 - zjzz[zjzzz - 1]) : ((qsz - 'A') * 32 + 12 - zjzz[zjzzz - 1] + i + 1 <= (mbz - 'A') * 32 + 12 - zjzz[zjzzz - 1]); i++)
            {
                cct_showch(qsz > mbz ? ((qsz - 'A') * 32 + 12 - zjzz[zjzzz - 1] - i) : ((qsz - 'A') * 32 + 12 - zjzz[zjzzz - 1] + i), 2, ' ', 0, 7, zjzz[zjzzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
                cct_showch(qsz > mbz ? ((qsz - 'A') * 32 + 12 - zjzz[zjzzz - 1] - i - 1) : ((qsz - 'A') * 32 + 12 - zjzz[zjzzz - 1] + i + 1), 2, ' ', 2 + zjzz[zjzzz - 1], 7, zjzz[zjzzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
            }
            for (int i = 0; 3 + i <= 14 - mbzzz; i++)
            {
                cct_showch((mbz - 'A') * 32 + 12 - zjzz[zjzzz - 1], 2 + i, ' ', 0, 7, zjzz[zjzzz - 1] * 2 + 1);
                if (i != 0)
                {
                    cct_showch((mbz - 'A') * 32 + 12, 2 + i, ' ', 1, 7, 1);
                }
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
                cct_showch((mbz - 'A') * 32 + 12 - zjzz[zjzzz - 1], 3 + i, ' ', 2 + zjzz[zjzzz - 1], 7, zjzz[zjzzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
            }
        }
        else if (qsz == z && mbz == x)
        {
            for (int i = 0; 15 - mbzzz - i - 1 > 1; i++)
            {
                cct_showch((qsz - 'A') * 32 + 12 - mbzz[mbzzz - 1], 15 - mbzzz - i, ' ', 0, 7, mbzz[mbzzz - 1] * 2 + 1);
                cct_showch((qsz - 'A') * 32 + 12, 15 - mbzzz - i, ' ', 1, 7, 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
                cct_showch((qsz - 'A') * 32 + 12 - mbzz[mbzzz - 1], 15 - mbzzz - i - 1, ' ', 2 + mbzz[mbzzz - 1], 7, mbzz[mbzzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
            }
            for (int i = 0; qsz > mbz ? ((qsz - 'A') * 32 + 12 - mbzz[mbzzz - 1] - i - 1 >= (mbz - 'A') * 32 + 12 - mbzz[mbzzz - 1]) : ((qsz - 'A') * 32 + 12 - mbzz[mbzzz - 1] + i + 1 <= (mbz - 'A') * 32 + 12 - mbzz[mbzzz - 1]); i++)
            {
                cct_showch(qsz > mbz ? ((qsz - 'A') * 32 + 12 - mbzz[mbzzz - 1] - i) : ((qsz - 'A') * 32 + 12 - mbzz[mbzzz - 1] + i), 2, ' ', 0, 7, mbzz[mbzzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
                cct_showch(qsz > mbz ? ((qsz - 'A') * 32 + 12 - mbzz[mbzzz - 1] - i - 1) : ((qsz - 'A') * 32 + 12 - mbzz[mbzzz - 1] + i + 1), 2, ' ', 2 + mbzz[mbzzz - 1], 7, mbzz[mbzzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
            }
            for (int i = 0; 3 + i <= 14 - qszzz; i++)
            {
                cct_showch((mbz - 'A') * 32 + 12 - mbzz[mbzzz - 1], 2 + i, ' ', 0, 7, mbzz[mbzzz - 1] * 2 + 1);
                if (i != 0)
                {
                    cct_showch((mbz - 'A') * 32 + 12, 2 + i, ' ', 1, 7, 1);
                }
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
                cct_showch((mbz - 'A') * 32 + 12 - mbzz[mbzzz - 1], 3 + i, ' ', 2 + mbzz[mbzzz - 1], 7, mbzz[mbzzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
            }
        }
        else
        {
            for (int i = 0; 15 - mbzzz - i - 1 > 1; i++)
            {
                cct_showch((qsz - 'A') * 32 + 12 - mbzz[mbzzz - 1], 15 - mbzzz - i, ' ', 0, 7, mbzz[mbzzz - 1] * 2 + 1);
                cct_showch((qsz - 'A') * 32 + 12, 15 - mbzzz - i, ' ', 1, 7, 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
                cct_showch((qsz - 'A') * 32 + 12 - mbzz[mbzzz - 1], 15 - mbzzz - i - 1, ' ', 2 + mbzz[mbzzz - 1], 7, mbzz[mbzzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
            }
            for (int i = 0; qsz > mbz ? ((qsz - 'A') * 32 + 12 - mbzz[mbzzz - 1] - i - 1 >= (mbz - 'A') * 32 + 12 - mbzz[mbzzz - 1]) : ((qsz - 'A') * 32 + 12 - mbzz[mbzzz - 1] + i + 1 <= (mbz - 'A') * 32 + 12 - mbzz[mbzzz - 1]); i++)
            {
                cct_showch(qsz > mbz ? ((qsz - 'A') * 32 + 12 - mbzz[mbzzz - 1] - i) : ((qsz - 'A') * 32 + 12 - mbzz[mbzzz - 1] + i), 2, ' ', 0, 7, mbzz[mbzzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
                cct_showch(qsz > mbz ? ((qsz - 'A') * 32 + 12 - mbzz[mbzzz - 1] - i - 1) : ((qsz - 'A') * 32 + 12 - mbzz[mbzzz - 1] + i + 1), 2, ' ', 2 + mbzz[mbzzz - 1], 7, mbzz[mbzzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
            }
            for (int i = 0; 3 + i <= 14 - zjzzz; i++)
            {
                cct_showch((mbz - 'A') * 32 + 12 - mbzz[mbzzz - 1], 2 + i, ' ', 0, 7, mbzz[mbzzz - 1] * 2 + 1);
                if (i != 0)
                {
                    cct_showch((mbz - 'A') * 32 + 12, 2 + i, ' ', 1, 7, 1);
                }
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
                cct_showch((mbz - 'A') * 32 + 12 - mbzz[mbzzz - 1], 3 + i, ' ', 2 + mbzz[mbzzz - 1], 7, mbzz[mbzzz - 1] * 2 + 1);
                if (speed == 0)
                {
                    Sleep(14);
                }
                else
                {
                    Sleep((6 - speed) * 200);
                }
            }
        }
    }
    cct_setcolor(0, 7);
}
void hua_yuan_pan(char qsz, int n)
{
    for (int i = 0; i < n; i++)
    {
        cct_showch((qsz - 'A') * 32 + 12 - n + i, 14 - i, ' ', 2 + qszz[i], 7, 2 * n + 1 - 2 * i);
        Sleep(100);
    }
    cct_setcolor(0, 7);
}
void hua_zhu_zi()
{
    cct_showch(1, 15, ' ', 1, 7, 23);
    cct_showch(33, 15, ' ', 1, 7, 23);
    cct_showch(65, 15, ' ', 1, 7, 23);
    for (int i = 0; i < 12; i++)
    {
        cct_showch(12, 14 - i, ' ', 1, 7, 1);
        cct_showch(44, 14 - i, ' ', 1, 7, 1);
        cct_showch(76, 14 - i, ' ', 1, 7, 1);
        Sleep(100);
    }
    cct_setcolor(0, 7);
}
void zong_xiang_shu_zu(char qsz,char zjz,char mbz,char x,char y,char z,int temp)
{
    if (qsz == x && mbz == z)
    {
        cct_gotoxy((qsz - 64) * 10, 29 - qszzz);
        cout << "  ";
        cct_gotoxy((mbz - 64) * 10, 30 - mbzzz);
        cout << setw(2) << temp;
    }
    else if (qsz == x && mbz == y)
    {
        cct_gotoxy((qsz - 64) * 10, 29 - qszzz);
        cout << "  ";
        cct_gotoxy((mbz - 64) * 10, 30 - zjzzz);
        cout << setw(2) << temp;
    }
    else if (qsz == y && mbz == x)
    {
        cct_gotoxy((qsz - 64) * 10, 29 - zjzzz);
        cout << "  ";
        cct_gotoxy((mbz - 64) * 10, 30 - qszzz);
        cout << setw(2) << temp;
    }
    else if (qsz == y && mbz == z)
    {
        cct_gotoxy((qsz - 64) * 10, 29 - zjzzz);
        cout << "  ";
        cct_gotoxy((mbz - 64) * 10, 30 - mbzzz);
        cout << setw(2) << temp;
    }
    else if (qsz == z && mbz == x)
    {
        cct_gotoxy((qsz - 64) * 10, 29 - mbzzz);
        cout << "  ";
        cct_gotoxy((mbz - 64) * 10, 30 - qszzz);
        cout << setw(2) << temp;
    }
    else
    {
        cct_gotoxy((qsz - 64) * 10, 29 - mbzzz);
        cout << "  ";
        cct_gotoxy((mbz - 64) * 10, 30 - zjzzz);
        cout << setw(2) << temp;
    }
}
void heng_xiang_shu_zu(char x,char y,char z)
{
    if (x == 'A' && y == 'B')
    {
        cout << " A:";
        for (int i = 0; i < 10; i++)
        {
            if (qszz[i] > 0)
            {
                cout << setw(2) << qszz[i];
            }
            else
            {
                cout << "  ";
            }
        }
        cout << " B:";
        for (int i = 0; i < 10; i++)
        {
            if (zjzz[i] > 0)
            {
                cout << setw(2) << zjzz[i];
            }
            else
            {
                cout << "  ";
            }
        }
        cout << " C:";
        for (int i = 0; i < 10; i++)
        {
            if (mbzz[i] > 0)
            {
                cout << setw(2) << mbzz[i];
            }
            else
            {
                cout << "  ";
            }
        }
    }
    else if (x == 'A' && y == 'C')
    {
        cout << " A:";
        for (int i = 0; i < 10; i++)
        {
            if (qszz[i] > 0)
            {
                cout << setw(2) << qszz[i];
            }
            else
            {
                cout << "  ";
            }
        }
        cout << " B:";
        for (int i = 0; i < 10; i++)
        {
            if (mbzz[i] > 0)
            {
                cout << setw(2) << mbzz[i];
            }
            else
            {
                cout << "  ";
            }
        }
        cout << " C:";
        for (int i = 0; i < 10; i++)
        {
            if (zjzz[i] > 0)
            {
                cout << setw(2) << zjzz[i];
            }
            else
            {
                cout << "  ";
            }
        }
    }
    else if (x == 'B' && y == 'A')
    {
        cout << " A:";
        for (int i = 0; i < 10; i++)
        {
            if (zjzz[i] > 0)
            {
                cout << setw(2) << zjzz[i];
            }
            else
            {
                cout << "  ";
            }
        }
        cout << " B:";
        for (int i = 0; i < 10; i++)
        {
            if (qszz[i] > 0)
            {
                cout << setw(2) << qszz[i];
            }
            else
            {
                cout << "  ";
            }
        }
        cout << " C:";
        for (int i = 0; i < 10; i++)
        {
            if (mbzz[i] > 0)
            {
                cout << setw(2) << mbzz[i];
            }
            else
            {
                cout << "  ";
            }
        }
    }
    else if (x == 'B' && y == 'C')
    {
        cout << " A:";
        for (int i = 0; i < 10; i++)
        {
            if (mbzz[i] > 0)
            {
                cout << setw(2) << mbzz[i];
            }
            else
            {
                cout << "  ";
            }
        }
        cout << " B:";
        for (int i = 0; i < 10; i++)
        {
            if (qszz[i] > 0)
            {
                cout << setw(2) << qszz[i];
            }
            else
            {
                cout << "  ";
            }
        }
        cout << " C:";
        for (int i = 0; i < 10; i++)
        {
            if (zjzz[i] > 0)
            {
                cout << setw(2) << zjzz[i];
            }
            else
            {
                cout << "  ";
            }
        }
    }
    else if (x == 'C' && y == 'A')
    {
        cout << " A:";
        for (int i = 0; i < 10; i++)
        {
            if (zjzz[i] > 0)
            {
                cout << setw(2) << zjzz[i];
            }
            else
            {
                cout << "  ";
            }
        }
        cout << " B:";
        for (int i = 0; i < 10; i++)
        {
            if (mbzz[i] > 0)
            {
                cout << setw(2) << mbzz[i];
            }
            else
            {
                cout << "  ";
            }
        }
        cout << " C:";
        for (int i = 0; i < 10; i++)
        {
            if (qszz[i] > 0)
            {
                cout << setw(2) << qszz[i];
            }
            else
            {
                cout << "  ";
            }
        }
    }
    else
    {
        cout << " A:";
        for (int i = 0; i < 10; i++)
        {
            if (mbzz[i] > 0)
            {
                cout << setw(2) << mbzz[i];
            }
            else
            {
                cout << "  ";
            }
        }
        cout << " B:";
        for (int i = 0; i < 10; i++)
        {
            if (zjzz[i] > 0)
            {
                cout << setw(2) << zjzz[i];
            }
            else
            {
                cout << "  ";
            }
        }
        cout << " C:";
        for (int i = 0; i < 10; i++)
        {
            if (qszz[i] > 0)
            {
                cout << setw(2) << qszz[i];
            }
            else
            {
                cout << "  ";
            }
        }
    }
    cout << endl;
}
int nei_bu_shu_zu(char qsz, char zjz, char mbz,char x,char y,char z)
{
    int temp;
    if (qsz == x && mbz == z)
    {
        qszzz--;
        temp = qszz[qszzz];
        qszz[qszzz] = 0;
        mbzz[mbzzz] = temp;
        mbzzz++;
    }
    else if (qsz == x && mbz == y)
    {
        qszzz--;
        temp = qszz[qszzz];
        qszz[qszzz] = 0;
        zjzz[zjzzz] = temp;
        zjzzz++;
    }
    else if (qsz == y && mbz == x)
    {
        zjzzz--;
        temp = zjzz[zjzzz];
        zjzz[zjzzz] = 0;
        qszz[qszzz] = temp;
        qszzz++;
    }
    else if (qsz == y && mbz == z)
    {
        zjzzz--;
        temp = zjzz[zjzzz];
        zjzz[zjzzz] = 0;
        mbzz[mbzzz] = temp;
        mbzzz++;
    }
    else if (qsz == z && mbz == x)
    {
        mbzzz--;
        temp = mbzz[mbzzz];
        mbzz[mbzzz] = 0;
        qszz[qszzz] = temp;
        qszzz++;
    }
    else
    {
        mbzzz--;
        temp = mbzz[mbzzz];
        mbzz[mbzzz] = 0;
        zjzz[zjzzz] = temp;
        zjzzz++;
    }

    return temp;
}
void da_yin_bu_zhou(char qsz,char zjz,char mbz,int n,int xuan_xiang,char x,char y,char z)
{
    if (xuan_xiang == 1)
    {
        cout << setw(2) << n << '#' << ' ' << qsz << "-->" << mbz << endl;
    }
    else if (xuan_xiang == 2)
    {
        cout<<"��" << setw(5) << bu_shu << "��(" << setw(3) << 1 << '#' <<": " << qsz << "-->" << mbz << ')' << endl;
        bu_shu++;
    }
    else if (xuan_xiang == 3)
    {
        cout << "��" << setw(5) << bu_shu << "��(" << setw(3) << 1 << '#' << ": " << qsz << "-->" << mbz << ')';
        nei_bu_shu_zu(qsz, zjz, mbz, x, y, z);
        heng_xiang_shu_zu(x, y, z);
        bu_shu++;
    }
    else if (xuan_xiang == 4||xuan_xiang==8||xuan_xiang==9)
    {
        if (xuan_xiang == 4)
        {
            if (speed == 0)
            {
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
            else
            {
                Sleep((26 - speed * speed) * 100);
            }
        }
        cct_showch(20, 35, ' ', 0, 7, 70);
        cct_gotoxy(20, 35);
        cout << "��" << setw(5) << bu_shu << "��(" << setw(3) << 1 << '#' << ": " << qsz << "-->" << mbz << ')';
        zong_xiang_shu_zu(qsz, zjz, mbz, x, y, z, nei_bu_shu_zu(qsz,zjz,mbz,x,y,z));
        cct_gotoxy(50, 35);
        heng_xiang_shu_zu(x, y, z);
        bu_shu++;
    }
    else if (xuan_xiang == 7)
    {
        
    }
}
void di_gui(char qsz,char zjz,char mbz,int n,int xuan_xiang,char x,char y,char z)
{
    if (n==1)
    {
        yuan_pan_yi_dong(qsz, zjz, mbz, x, y, z,xuan_xiang);
        da_yin_bu_zhou(qsz, zjz, mbz, n, xuan_xiang,x,y,z);
    }
    else
    {
        di_gui(qsz, mbz, zjz, n - 1,xuan_xiang,x,y,z);
        yuan_pan_yi_dong(qsz, zjz, mbz, x, y, z, xuan_xiang);
        da_yin_bu_zhou(qsz, zjz, mbz, n, xuan_xiang,x,y,z);
        di_gui(zjz, qsz, mbz, n - 1,xuan_xiang,x,y,z);
    }
}
void shu_ru_can_shu(char *qsz,char *zjz,char *mbz,int *n,int xuan_xiang)
{
	cct_gotoxy(0, 15);
    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> *n;
        cin.ignore(65536, '\n');
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
        }
        else
        {
            if (*n < 1 || *n>10)
            {
                ;
            }
            else
            {
                break;
            }
        }
    }
    while (1)
    {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> *qsz;
        cin.ignore(65536, '\n');
        if (*qsz == 'a' || *qsz == 'b' || *qsz == 'c')
        {
            *qsz = *qsz - 32;
            break;
        }
        else if (*qsz == 'A' || *qsz == 'B' || *qsz == 'C')
        {
            break;
        }
        else
        {
            ;
        }
    }
    while (1)
    {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> *mbz;
        cin.ignore(65536, '\n');
        if (*mbz == 'a' || *mbz == 'b' || *mbz == 'c')
        {
            *mbz = *mbz - 32;
        }
        if (*mbz != 'A' && *mbz != 'B' && *mbz != 'C' || *mbz == *qsz)
        {
            ;
        }
        else
        {
            break;
        }
    }
    *zjz = 'A' + 'B' + 'C' - *qsz - *mbz;
    for (int i = 0; i < *n; i++)
    {
        qszz[i] = *n - i;
    }
    qszzz = *n;
    if (xuan_xiang == 4 || xuan_xiang == 8)
    {
        while (1)
        {
            cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���) ";
            cin >> speed;
            cin.ignore(65536, '\n');
            if (cin.fail())
            {
                cin.clear();
            }
            else if (speed > 5 || speed < 0)
            {
                ;
            }
            else
            {
                break;
            }
        }
    }
    if (xuan_xiang == 4 || xuan_xiang == 6 || xuan_xiang == 7 || xuan_xiang == 8 || xuan_xiang == 9)
    {
        cct_cls();
    }
    if (xuan_xiang == 4||xuan_xiang==8 || xuan_xiang == 9)
    {
        if (xuan_xiang == 4 || xuan_xiang == 8)
        {
            cout << "�� " << *qsz << " �ƶ��� " << *mbz << ", �� " << *n << " �㣬" << "��ʱ����Ϊ " << speed;
        }
        else if(xuan_xiang==9)
        {
            cout << "�� " << *qsz << " �ƶ��� " << *mbz << ", �� " << *n << " ��";
        }
        cct_gotoxy(20, 35);
        cout << "��ʼ:                A:";
        if (*qsz == 'A')
        {
            for (int i = 0; i < 10; i++)
            {
                if (qszz[i] > 0)
                {
                    cout << setw(2) << qszz[i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " B:                     C:                    ";
        }
        else if (*qsz == 'B')
        {
            cout << "                     B:";
            for (int i = 0; i < 10; i++)
            {
                if (qszz[i] > 0)
                {
                    cout << setw(2) << qszz[i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " C:                    ";
        }
        else
        {
            cout << "                     B:                     C:";
            for (int i = 0; i < 10; i++)
            {
                if (qszz[i] > 0)
                {
                    cout << setw(2) << qszz[i];
                }
                else
                {
                    cout << "  ";
                }
            }
        }
        cct_gotoxy(9, 30);
        cout << "=========================";
        cct_gotoxy(11, 31);
        cout << "A         B         C";
        for (int i = 0; qszz[i] > 0; i++)
        {
            cct_gotoxy((*qsz - 64) * 10, 29 - i);
            cout << setw(2) << qszz[i];
        }
        cct_gotoxy(20, 35);
        cct_setcursor(3);
    }
    if (xuan_xiang == 6|| xuan_xiang == 7)
    {
        cout << "�� " << *qsz << " �ƶ��� " << *mbz << ", �� " << *n << " ��";
    }
}
void you_xi_mo_shi(int n,char x,char y,char z)
{
    char arr[20] = { 0 };
    cct_gotoxy(20, 36);
    cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) ��";
    while (1)
    {
        cct_gotoxy(80, 36);
        for (int i = 0; i < 20; i++)
        {
            arr[i]=_getche();
            if (int(arr[i])==13)
            {
                if (i == 2)
                {
                    arr[2] = '\0';
                }
                else if (i == 1)
                {
                    if (arr[0] == 'q' || arr[0] == 'Q')
                    {
                        arr[1] = '\0';
                    }
                }
                break;
            }
        }
        if (arr[2] != '\0'||arr[1]=='\0')
        {
            if (arr[0] == 'q' || arr[0] == 'Q')
            {
                cct_gotoxy(0, 37);
                cout << "��Ϸ��ֹ!!!!!" << endl;
                break;
            }
            else
            {
                cct_showch(80, 36, ' ', 0, 7, 20);
                cct_gotoxy(80, 36);
            }
        }
        else
        {
            if (arr[0] >= 'a' && arr[0] <= 'z')
            {
                arr[0] = arr[0] - 32;
            }
            if (arr[1] >= 'a' && arr[1] <= 'z')
            {
                arr[1] = arr[1] - 32;
            }
            if (arr[0] == 'A' && arr[1] == 'B' || arr[0] == 'B' && arr[1] == 'A' || arr[0] == 'A' && arr[1] == 'C' || arr[0] == 'C' && arr[1] == 'A' || arr[0] == 'C' && arr[1] == 'B' || arr[0] == 'B' && arr[1] == 'C')
            {
                if (arr[0] == x && qszzz == 0||arr[0]==y&&zjzzz==0||arr[0]==z&&mbzzz==0)
                {
                    cout << endl << "Դ��Ϊ��!";
                    Sleep(2000);
                    cct_showch(0, 37, ' ', 0, 7, 9);
                    cct_showch(80, 36, ' ', 0, 7, 20);
                }
                else if (arr[0] == x && arr[1] == y && qszz[qszzz-1] > zjzz[zjzzz-1]&&zjzzz!=0|| arr[0] == x && arr[1] == z && qszz[qszzz-1] > mbzz[mbzzz-1] && mbzzz != 0|| arr[0] == y && arr[1] == x && zjzz[zjzzz-1] > qszz[qszzz-1] && qszzz != 0 || arr[0] == y && arr[1] == z && zjzz[zjzzz-1] > mbzz[mbzzz-1] && mbzzz != 0 || arr[0] == z && arr[1] == x && mbzz[mbzzz-1] > qszz[qszzz-1] && qszzz != 0|| arr[0] == z && arr[1] == y && mbzz[mbzzz -1] > zjzz[zjzzz-1] && zjzzz != 0 )
                {
                    cout << endl << "����ѹС�̣��Ƿ��ƶ���";
                    Sleep(2000);
                    cct_showch(0, 37, ' ', 0, 7, 22);
                    cct_showch(80, 36, ' ', 0, 7, 20);
                }
                else
                {
                    arr[2] = 'A' + 'B' + 'C' - arr[0] - arr[1];
                    cct_showch(80, 36, ' ', 0, 7, 20);
                    cct_gotoxy(80, 36);
                    yuan_pan_yi_dong(arr[0], arr[2], arr[1], x, y, z, 9);
                    da_yin_bu_zhou(arr[0], arr[2], arr[1], n, 9, x, y, z);
                    if (mbzz[n - 1] == 1)
                    {
                        cout << endl << "��Ϸ����!!!!!";
                        break;
                    }
                }
            }
            else
            {
                cct_showch(80, 36, ' ', 0, 7, 20);
                cct_gotoxy(80, 36);
            }
        }
    }
}