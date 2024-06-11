// 2253209 ĞÅ07 Áõ¼ÑÅó
#pragma once
void shu_zu(int line, int column,int star[][10],int n,int temp, int star2[][10]);
int shu_ru(int star[][10], int line, int column,char xy[],int &num);
void zan_ting();
int YNQ(char xy[]);
void hui_che(int x);
void yi_dong(int star[][10], int line, int column,int star2[][10]);
int pan_duan_tong_guan(int star[][10], int line, int column);
void score(int num, int n = 1);
void wai_kuang_jia(int line, int column,int hang,int lie,int n);
void sui_ji(int star[][10], int i, int j);
void yi_ge_se_kuai(int hang, int lie, int star[][10], int i, int j, int n, int temp, int d = 0,int d2 = 0);
void chu_shi_zhuang_tai_lan(int line, int column, int hang, int lie,int n);
void jian_pan(int keycode2, int &x, int &y, int hang, int lie, int line, int column);
int cha_zhao(int star[][10], int x, int y, int line, int column, int temp, int n);
int pan_duan_he_fa(int x, int y, int line, int column, char option, int star[][10], int n = 1);
void se_kuai_yi_dong(int star[][10], int line, int column, char option, int star2[][10]);