/* 信07 2253209 刘佳朋 */
#pragma once

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */
//菜单函数
int menu();
//输入参数的函数
void shu_ru_can_shu(char* qsz, char* zjz, char* mbz, int* n, int xuan_xiang);
//递归函数
void di_gui(char qsz, char zjz, char mbz, int n, int xuan_xiang,char x,char y,char z);
//5，6，7，8，9画三个柱子
void hua_zhu_zi();
//起始柱上画n个盘子
void hua_yuan_pan(char qsz, int n);
//9题的游戏模式
void you_xi_mo_shi(int n,char x,char y,char z);
//移动圆盘
void yuan_pan_yi_dong(char qsz, char zjz, char mbz, char x, char y, char z, int xuan_xiang);
//每次需要将全局变量回到原始值
void gui_ling();