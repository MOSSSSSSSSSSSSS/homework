/* ��07 2253209 ������ */
#pragma once

/* ------------------------------------------------------------------------------------------------------

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */
//�˵�����
int menu();
//��������ĺ���
void shu_ru_can_shu(char* qsz, char* zjz, char* mbz, int* n, int xuan_xiang);
//�ݹ麯��
void di_gui(char qsz, char zjz, char mbz, int n, int xuan_xiang,char x,char y,char z);
//5��6��7��8��9����������
void hua_zhu_zi();
//��ʼ���ϻ�n������
void hua_yuan_pan(char qsz, int n);
//9�����Ϸģʽ
void you_xi_mo_shi(int n,char x,char y,char z);
//�ƶ�Բ��
void yuan_pan_yi_dong(char qsz, char zjz, char mbz, char x, char y, char z, int xuan_xiang);
//ÿ����Ҫ��ȫ�ֱ����ص�ԭʼֵ
void gui_ling();