// 2253209 ��07 ������
#include<iostream>
#include"cmd_console_tools.h"
#include"popstar.h"
#include<conio.h>
#include<Windows.h>
#define HANG 3
#define LIE 6
using namespace std;

char meau()
{
	char option;
	cout << "--------------------------------------------" << endl;
	cout << "A.�������ҳ����������ʶ" << endl;
	cout << "B.���������һ���������ֲ�����ʾ��" << endl;
	cout << "C.���������һ�أ��ֲ�����ʾ��" << endl;
	cout << "D.αͼ�ν����������ѡ��һ��ɫ�飨�޷ָ��ߣ�" << endl;
	cout << "E.αͼ�ν����������ѡ��һ��ɫ�飨�зָ��ߣ�" << endl;
	cout << "F.αͼ�ν������һ���������ֲ��裩" << endl;
	cout << "G.αͼ�ν���������" << endl;
	cout << "Q.�˳�" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "[��ѡ��:] ";
	while (1)
	{
		option = _getch();
		if (option >= 'a' && option <= 'g' || option >= 'A' && option <= 'G' || option == 'q' || option == 'Q')
		{
			cout << option;
			Sleep(300);
			break;
		}
	}
	if (option >= 'a' && option <= 'g')
		option -= 32;
	return option;
}

int main()
{
	srand((unsigned int)(time(0)));
	cct_setconsoleborder(55, 32, -1, -1);
	while (1)
	{
		char option, xy[3] = { 0 };
		int line, column, temp, num = 0, star[10][10] = { 0 }, star2[10][10] = { 0 };
		cct_cls();
		option = meau();
		if (option == 'q' || option == 'Q')
			return 0;
		cct_cls();
		while (1)
		{
			cout << "����������(8-10)��" << endl;
			cin >> line;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(65536, '\n');
			}
			else if (line <= 10 && line >= 8)
			{
				break;
			}
		}
		while (1)
		{
			cout << "����������(8-10)��" << endl;
			cin >> column;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(65536, '\n');
			}
			else if (column <= 10 && column >= 8)
			{
				break;
			}
		}
		if (option == 'A' || option == 'B' || option == 'C')
		{
			shu_zu(line, column, star, 0, 0, star2);
			while (1)
			{
				temp = shu_ru(star, line, column, xy, num);
				shu_zu(line, column, star, 1, temp, star2);
				shu_zu(line, column, star, 2, temp, star2);
				if (option == 'B' || option == 'C')
				{
					int a = YNQ(xy);
					if (a == 1)
					{
						shu_zu(line, column, star, 3, temp, star2);
						score(num);
						yi_dong(star, line, column, star2);
						hui_che(1);
						shu_zu(line, column, star, 4, temp, star2);
						if (option == 'C')
							hui_che(2);
					}
					else
					{
						if (option == 'C'&&a == 0)
							break;
						else if (option == 'C' && a == 2)
						{
							for (int i = 0; i < line; i++)
							{
								for (int j = 0; j < column; j++)
								{
									if (star[i][j] == 0 && star2[i][j] == 0)
									{
										star[i][j] = temp;
									}
								}
							}
							shu_zu(line, column, star, 5, 0, star2);
							continue;
						}
					}
					if (option == 'C')
					{
						shu_zu(line, column, star, 5, 0, star2);
						int num;
						if (num = pan_duan_tong_guan(star, line, column))
						{
							cct_setcolor(14, 0);
							cout << "ʣ��" << num - 1 << "��������������ؽ���!";
							cct_setcolor(0, 7);
							cout << endl;
							break;
						}
					}
				}
				if (option == 'B' || option == 'A')
					break;
			}
			score(0, 0);
			zan_ting();
			continue;
		}
		else if (option == 'D' || option == 'F' || option == 'E' || option == 'G')
		{
			cct_enable_mouse();
			cct_setcursor(3);
			while (1)
			{
				int mx = 4, my = 3, maction = 0, keycode1, keycode2, x, y, pan_duan = 0, pan_duan2 = 0, tong_guan = 0, star[10][10] = { 0 }, star2[10][10] = { 0 };//pan��duan������ȷ�������ǴӷǷ�������뷽���У�����һֱ��ͬһ�������У���ֹ��һ�������е���˸�ʹӷǷ�������뷽�򲻷���;panduan2�������Ƿ�ֹ�ӺϷ������ȥ���ڷǷ������ƶ�ʱɫ�鲻ͣ����
				wai_kuang_jia(line, column, HANG, LIE, (option == 'E' || option == 'G' ? 2 : 1));
				chu_shi_zhuang_tai_lan(line, column, HANG, LIE, (option == 'E' || option == 'G' ? 2 : 1));
				for (int i = 0; i < line; i++)
				{
					for (int j = 0; j < column; j++)
						yi_ge_se_kuai(HANG + (option == 'E' || option == 'G' ? 1 : 0), LIE + (option == 'E' || option == 'G' ? 2 : 0), star, i, j, 0, 0);
				}
				yi_ge_se_kuai(HANG + (option == 'E' || option == 'G' ? 1 : 0), LIE + (option == 'E' || option == 'G' ? 2 : 0), star, (my - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG), (mx - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE), 1, 0);//һ��ʼ ��һ���ǰ׵�
				while (1)
				{
					if (pan_duan_he_fa(mx, my, line, column, option, star, 0))
					{
						x = mx;
						y = my;
					}//x��y����һ���ƶ��յ㣬��Ϊ�������ƶ�����㣬��������mx��my���ƶ����յ㡣ֻ��mx��my�Ϸ���x��y�Ÿ�Ϊ���ǵ�ֵ
					if (!cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2))//�������Ϊ���.ֻ����궯�˻��߼���������Ż�����������
					{
						if (maction == 0x0001)//�������ƶ�
						{
							if (pan_duan_he_fa(mx, my, line, column, option, star, 0))//�����ǰλ�úϷ���״̬����ӡ��ǰλ��
							{
								cct_gotoxy(0, (option == 'E' || option == 'G' ? (HANG + 1) : HANG) * line + 4);
								cout << "[��ǰ���] " << char((my - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG) + 'A') << "��" << (mx - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE) << "��                                                                                                                    ";
								if (((y - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG) != (my - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG) || (x - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE) != (mx - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE)) && pan_duan_he_fa(x, y, line, column, option, star, 0))
								{//���ԭʼλ�úϷ�����ǰλ�ú�ԭʼλ�����ڷ���ͬ��ԭʼ��ڵ�ǰ��ף����ԭʼλ�úϷ�����ǰλ�ú�ԭʼλ�����ڷ�����ͬ������
									yi_ge_se_kuai((option == 'E' || option == 'G' ? (HANG + 1) : HANG), (option == 'E' || option == 'G' ? (LIE + 2) : LIE), star, (y - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG), (x - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE), 2, 0);
									yi_ge_se_kuai((option == 'E' || option == 'G' ? (HANG + 1) : HANG), (option == 'E' || option == 'G' ? (LIE + 2) : LIE), star, (my - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG), (mx - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE), 1, 0);
								}
								else if (pan_duan_he_fa(x, y, line, column, option, star) && (y - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG) == (my - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG) && (x - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE) == (mx - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE))
								{
									if (pan_duan)
									{
										yi_ge_se_kuai((option == 'E' || option == 'G' ? (HANG + 1) : HANG), (option == 'E' || option == 'G' ? (LIE + 2) : LIE), star, (my - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG), (mx - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE), 1, 0);
										pan_duan = 0;
									}
								}
								else//���ԭʼλ�ò��Ϸ�����ǰλ�ñ�ף�1��
									yi_ge_se_kuai((option == 'E' || option == 'G' ? (HANG + 1) : HANG), (option == 'E' || option == 'G' ? (LIE + 2) : LIE), star, (my - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG), (mx - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE), 1, 0);
								pan_duan2 = 1;
							}
							else//�����ǰλ�÷Ƿ���ԭʼλ�÷Ƿ����򲻱䣻�����ǰλ�÷Ƿ���ԭʼλ�úϷ�����ԭʼ�����ڣ�2��
							{
								cct_gotoxy(0, (option == 'E' || option == 'G' ? (HANG + 1) : HANG) * line + 4);
								cout << "[��ǰ���] λ�÷Ƿ�                                  ";
								if (pan_duan_he_fa(x, y, line, column, option, star, 0))
								{
									if (pan_duan2)
									{
										yi_ge_se_kuai((option == 'E' || option == 'G' ? (HANG + 1) : HANG), (option == 'E' || option == 'G' ? (LIE + 2) : LIE), star, (y - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG), (x - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE), 2, 0);
										pan_duan2 = 0;
									}
									pan_duan = 1;
								}
							}
						}
						else if (maction == 0x0002 && pan_duan_he_fa(mx, my, line, column, option, star, 0))//����������������ҵ�ǰλ�úϷ�
						{
							x = mx;
							y = my;//�����һ���Ǽ��̲�����x��mx��y��myֵ����ͬ��Ҫ��������ͬ�����������ж��Ƿ�ȡ��ѡ���д����������ͬһ��ɫ�����ƶ�Ҳ����Ϊ��ȡ��ѡ��
							yi_ge_se_kuai((option == 'E' || option == 'G' ? (HANG + 1) : HANG), (option == 'E' || option == 'G' ? (LIE + 2) : LIE), star, (my - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG), (mx - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE), 1, 0);
							if (option == 'D' || option == 'E')
							{
								cct_gotoxy(0, (option == 'E' ? (HANG + 1) : HANG) * line + 4);
								cout << "ѡ����" << char((my - 3) / (option == 'E' ? (HANG + 1) : HANG) + 'A') << "��" << (mx - 4) / (option == 'E' ? (LIE + 2) : LIE) << "��                             ";
								break;
							}
							else if (option == 'F' || option == 'G')
							{
								cct_gotoxy(0, (option == 'G' ? (HANG + 1) : HANG) * line + 4);
								cout << "[��ǰ���] " << char((my - 3) / (option == 'G' ? (HANG + 1) : HANG) + 'A') << "��" << (mx - 4) / (option == 'G' ? (LIE + 2) : LIE) << "��                                                                                                                  ";
								int temp = star[(my - 3) / (option == 'G' ? (HANG + 1) : HANG)][(mx - 4) / (option == 'G' ? (LIE + 2) : LIE)];
								if (!cha_zhao(star, (my - 3) / (option == 'G' ? (HANG + 1) : HANG), (mx - 4) / (option == 'G' ? (LIE + 2) : LIE), line, column, star[(my - 3) / (option == 'G' ? (HANG + 1) : HANG)][(mx - 4) / (option == 'G' ? (LIE + 2) : LIE)], 1))
								{
									cct_gotoxy(0, (option == 'G' ? (HANG + 1) : HANG) * line + 4);
									cout << "��Χ����ֵͬ ��ͷ��/�����ƶ���Q/�����Ҽ�����";
									while (1)
									{
										cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2);
										jian_pan(keycode2, mx, my, (option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), line, column);
										if ((y - 3) / (option == 'G' ? (HANG + 1) : HANG) != (my - 3) / (option == 'G' ? (HANG + 1) : HANG) || (x - 4) / (option == 'G' ? (LIE + 2) : LIE) != (mx - 4) / (option == 'G' ? (LIE + 2) : LIE))
										{
											yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, (y - 3) / (option == 'G' ? (HANG + 1) : HANG), (x - 4) / (option == 'G' ? (LIE + 2) : LIE), 4, temp);
											if (pan_duan_he_fa(mx, my, line, column, option, star, 0))
												yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, (my - 3) / (option == 'G' ? (HANG + 1) : HANG), (mx - 4) / (option == 'G' ? (LIE + 2) : LIE), 1, 0);
											cct_gotoxy(0, (option == 'G' ? (HANG + 1) : HANG) * line + 4);
											cout << "[��ǰ����] " << char((my - 3) / (option == 'G' ? (HANG + 1) : HANG) + 'A') << "��" << (mx - 4) / (option == 'G' ? (LIE + 2) : LIE) << "��                                                 ";
											maction = 0;
											break;
										}
										continue;
									}
									continue;
								}
								for (int i = 0; i < line; i++)
								{
									for (int j = 0; j < column; j++)
									{
										if (star[i][j] == 0 && (i != (my - 3) / (option == 'G' ? (HANG + 1) : HANG) || j != (mx - 4) / (option == 'G' ? (LIE + 2) : LIE)) && star2[i][j] == 0)
										{
											yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, i, j, 3, temp);
										}
									}
								}
								yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, (my - 3) / (option == 'G' ? (HANG + 1) : HANG), (mx - 4) / (option == 'G' ? (LIE + 2) : LIE), 6, temp);
								cct_gotoxy(0, (option == 'G' ? (HANG + 1) : HANG) * line + 5);
								cout << "��ͷ��/����ƶ�ȡ����ǰѡ�񣬻س���/��������ϳ�";
								while (1)
								{
									if (!cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2))//�������Ϊ���
									{
										if (maction == 0x0001)//�������ƶ�
										{
											if (!pan_duan_he_fa(mx, my, line, column, option, star) || ((my - 3) / (option == 'G' ? (HANG + 1) : HANG) != (y - 3) / (option == 'G' ? (HANG + 1) : HANG) || (mx - 4) / (option == 'G' ? (LIE + 2) : LIE) != (x - 4) / (option == 'G' ? (LIE + 2) : LIE)))//���ȡ��ѡ��
											{
												for (int i = 0; i < line; i++)
												{
													for (int j = 0; j < column; j++)
													{
														if (star[i][j] == 0 && star2[i][j] == 0)
														{
															star[i][j] = temp;
															yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, i, j, 2, 0);
														}
													}
												}
												Sleep(50);
												if (pan_duan_he_fa(mx, my, line, column, option, star))
													yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, (my - 3) / (option == 'G' ? (HANG + 1) : HANG), (mx - 4) / (option == 'G' ? (LIE + 2) : LIE), 1, 0);
												else
													pan_duan = 1;
												break;//Ӧ���˵���һ��ѭ��������������һ��break���˳�����ѭ������ì��
											}
											continue;//û��ȡ��ѡ��ֻ����ѡ��ķ������ƶ�
										}
										else if (maction == 0x0002)//�����굥���������ʾ�ϳ�
										{
											int num = 0;
											for (int i = 0; i < line; i++)
											{
												for (int j = 0; j < column; j++)
												{
													if (star[i][j] == 0 && star2[i][j] == 0)
													{
														star2[i][j] = 1;
														num++;//�ڲ�������0
														yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, i, j, 5, 0);
													}
												}
											}
											cct_gotoxy(0, 0);
											score(num);
											//���ε÷�
											if (option == 'F')
											{
												cct_gotoxy(0, HANG * line + 4);
												cout << "�ϳ���ɣ��س���/�����������";
												//maction = 0;//������㰴һ�������Ϳ��Լ���???Ϊʲômaction�����1����
												while (1)
												{
													cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2);//ֻ����궯�˻��߼���������Ż�����������
													if (maction == 0x0002 || keycode1 == 13)
													{
														cout << maction;
														se_kuai_yi_dong(star, line, column, option, star2);
														break;
													}
													else
														continue;
												}
												cct_gotoxy(0, HANG * line + 4);
												cout << "���κϳɽ�������c/�������������һ�εĺϳ�";
												while (1)
												{
													cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2);//ֻ����궯�˻��߼���������Ż�����������
													if (maction == 0x0002 || keycode1 == 'c' || keycode1 == 'C')
														break;
													else
														continue;
												}
												score(0, 0);
												maction = 0;
											}
											else
											{
												se_kuai_yi_dong(star, line, column, option, star2);
												int num = pan_duan_tong_guan(star, line, column);
												if (num)
												{
													tong_guan = 1;
													cct_gotoxy(0, (HANG + 1) * line + 4);
													cout << "ʣ��" << num - 1 << "�����ǣ��޿���������ؽ������س�������һ��";
													cct_gotoxy(0, 0);
													score(num - 1, 2);
													while (_getch() != 13)
													{
													}
													break;
												}
												else
												{
													if (pan_duan_he_fa(mx, my, line, column, option, star, 0))
														yi_ge_se_kuai(HANG + 1, LIE + 2, star, (my - 3) / (HANG + 1), (mx - 4) / (LIE + 2), 1, 0);
												}
											}
											break;
										}
										else if (maction == 0x0008)
											break;
									}
									else
									{
										if (keycode1 == 'q' || keycode1 == 'Q')
											break;
										jian_pan(keycode2, mx, my, (option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), line, column);
										if ((my - 3) / (option == 'G' ? (HANG + 1) : HANG) != (y - 3) / (option == 'G' ? (HANG + 1) : HANG) || (mx - 4) / (option == 'G' ? (LIE + 2) : LIE) != (x - 4) / (option == 'G' ? (LIE + 2) : LIE))//���ȡ��ѡ��
										{
											for (int i = 0; i < line; i++)
											{
												for (int j = 0; j < column; j++)
												{
													if (star[i][j] == 0)
													{
														star[i][j] = temp;
														yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, i, j, 2, 0);
													}
												}
											}
											Sleep(50);
											yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, (my - 3) / (option == 'G' ? (HANG + 1) : HANG), (mx - 4) / (option == 'G' ? (LIE + 2) : LIE), 1, 0);
											cct_gotoxy(0, (option == 'G' ? (HANG + 1) : HANG) * line + 4);
											cout << "[��ǰ����] " << char((my - 3) / (option == 'G' ? (HANG + 1) : HANG) + 'A') << "��" << (mx - 4) / (option == 'G' ? (LIE + 2) : LIE) << "��                                ";
											break;
										}
										else
										{
											if (keycode1 == 13)
											{
												int num = 0;
												for (int i = 0; i < line; i++)
												{
													for (int j = 0; j < column; j++)
													{
														if (star[i][j] == 0 && star2[i][j] == 0)
														{
															star2[i][j] = 1;
															num++;//�ڲ�������0
															yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, i, j, 5, 0);
														}
													}
												}
												cct_gotoxy(0, 0);
												score(num);
												if (option == 'F')
												{
													cct_gotoxy(0, HANG * line + 4);
													cout << "�ϳ���ɣ��س���/�����������";
													while (1)
													{
														cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2);//ֻ����궯�˻��߼���������Ż�����������
														if (maction == 0x0002 || keycode1 == 13)
														{
															cout << maction;
															se_kuai_yi_dong(star, line, column, option, star2);
															break;
														}
														else
															continue;
													}
													cct_gotoxy(0, HANG * line + 4);
													cout << "���κϳɽ�������c/�������������һ�εĺϳ�";
													while (1)
													{
														cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2);//ֻ����궯�˻��߼���������Ż�����������
														if (maction == 0x0002 || keycode1 == 'c' || keycode1 == 'C')
															break;
														else
															continue;
													}
													score(0, 0);
													maction = 0;
												}
												else
												{
													se_kuai_yi_dong(star, line, column, option, star2);
													int num = pan_duan_tong_guan(star, line, column);
													if (num)
													{
														tong_guan = 1;
														cct_gotoxy(0, (HANG + 1) * line + 4);
														cout << "ʣ��" << num - 1 << "�����ǣ��޿���������ؽ������س�������һ��";
														cct_gotoxy(0, 0);
														score(num - 1, 2);
														while (_getch() != 13)
														{
														}
														break;
													}
													else
													{
														if (pan_duan_he_fa(mx, my, line, column, option, star, 0))
															yi_ge_se_kuai(HANG + 1, LIE + 2, star, (my - 3) / (HANG + 1), (mx - 4) / (LIE + 2), 1, 0);
													}
												}
												break;
											}
											else
												continue;
										}
									}
								}
								if (maction == 1 || option == 'G' && !tong_guan)//ȡ��ѡ�����¿�ʼѡ�񣻻�g��������ٴο�ʼ�µ�ѡ��
								{
									//pan_duan = 1;
									continue;
								}
								break;
							}
							break;
						}
						else if (maction == 0x0008)
						{
							cct_gotoxy(0, (option == 'G' || option == 'E' ? (HANG + 1) : HANG)* line + 4);
							break;
						}
					}
					else//�������Ϊ����
					{
						if (keycode1 == 0xE0)
						{
							if (!pan_duan_he_fa(mx, my, line, column, option, star))
							{
								mx = x;
								my = y;
							}
							do {
								jian_pan(keycode2, mx, my, (option == 'E' || option == 'G' ? (HANG + 1) : HANG), (option == 'E' || option == 'G' ? (LIE + 2) : LIE), line, column);
							} while (!pan_duan_he_fa(mx, my, line, column, option, star, 0));
							cct_gotoxy(0, (option == 'E' || option == 'G' ? (HANG + 1) : HANG) * line + 4);
							cout << "[��ǰ����] " << char((my - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG) + 'A') << "��" << (mx - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE) << "��                                    ";
							yi_ge_se_kuai((option == 'E' || option == 'G' ? (HANG + 1) : HANG), (option == 'E' || option == 'G' ? (LIE + 2) : LIE), star, (y - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG), (x - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE), 2, 0);
							yi_ge_se_kuai((option == 'E' || option == 'G' ? (HANG + 1) : HANG), (option == 'E' || option == 'G' ? (LIE + 2) : LIE), star, (my - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG), (mx - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE), 1, 0);
						}
						else if (keycode1 == 13)
						{
							if (option == 'D' || option == 'E')
							{
								cct_gotoxy(0, (option == 'E' ? (HANG + 1) : HANG) * line + 4);
								cout << "ѡ����" << char((my - 3) / (option == 'E' ? (HANG + 1) : HANG) + 'A') << "��" << (mx - 4) / (option == 'E' ? (LIE + 2) : LIE) << "��                                         ";
								break;
							}
							else if (option == 'F' || option == 'G')
							{
								cct_gotoxy(0, (option == 'G' ? (HANG + 1) : HANG) * line + 4);
								cout << "[��ǰ����] " << char((my - 3) / (option == 'G' ? (HANG + 1) : HANG) + 'A') << "��" << (mx - 4) / (option == 'G' ? (LIE + 2) : LIE) << "��                                        ";
								int temp = star[(my - 3) / (option == 'G' ? (HANG + 1) : HANG)][(mx - 4) / (option == 'G' ? (LIE + 2) : LIE)];
								if (!cha_zhao(star, (my - 3) / (option == 'G' ? (HANG + 1) : HANG), (mx - 4) / (option == 'G' ? (LIE + 2) : LIE), line, column, star[(my - 3) / (option == 'G' ? (HANG + 1) : HANG)][(mx - 4) / (option == 'G' ? (LIE + 2) : LIE)], 1))
								{
									cct_gotoxy(0, (option == 'G' ? (HANG + 1) : HANG) * line + 4);
									cout << "��Χ����ֵͬ ��ͷ��/�����ƶ���Q/�����Ҽ�����";
									continue;
								}
								for (int i = 0; i < line; i++)
								{
									for (int j = 0; j < column; j++)
									{
										if (star[i][j] == 0 && (i != (my - 3) / (option == 'G' ? (HANG + 1) : HANG) || j != (mx - 4) / (option == 'G' ? (LIE + 2) : LIE)) && star2[i][j] == 0)
										{
											yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, i, j, 3, temp);
										}
									}
								}
								yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, (my - 3) / (option == 'G' ? (HANG + 1) : HANG), (mx - 4) / (option == 'G' ? (LIE + 2) : LIE), 6, temp);
								cct_gotoxy(0, (option == 'G' ? (HANG + 1) : HANG) * line + 5);
								cout << "��ͷ��/����ƶ�ȡ����ǰѡ�񣬻س���/��������ϳ�";
								while (1)
								{
									if (!cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2))//�������Ϊ���
									{
										if (maction == 0x0001)//�������ƶ�
										{
											if (!pan_duan_he_fa(mx, my, line, column, option, star) || ((my - 3) / (option == 'G' ? (HANG + 1) : HANG) != (y - 3) / (option == 'G' ? (HANG + 1) : HANG) || (mx - 4) / (option == 'G' ? (LIE + 2) : LIE) != (x - 4) / (option == 'G' ? (LIE + 2) : LIE)))//���ȡ��ѡ��
											{
												for (int i = 0; i < line; i++)
												{
													for (int j = 0; j < column; j++)
													{
														if (star[i][j] == 0 && star2[i][j] == 0)
														{
															star[i][j] = temp;
															yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, i, j, 2, 0);
														}
													}
												}
												Sleep(50);
												if (pan_duan_he_fa(mx, my, line, column, option, star))
													yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, (my - 3) / (option == 'G' ? (HANG + 1) : HANG), (mx - 4) / (option == 'G' ? (LIE + 2) : LIE), 1, 0);
												else
													pan_duan = 1;
												break;//Ӧ���˵���һ��ѭ��������������һ��break���˳�����ѭ������ì��
											}
											continue;//û��ȡ��ѡ��ֻ����ѡ��ķ������ƶ�
										}
										else if (maction == 0x0002)//�����굥���������ʾ�ϳ�
										{
											int num = 0;
											for (int i = 0; i < line; i++)
											{
												for (int j = 0; j < column; j++)
												{
													if (star[i][j] == 0 && star2[i][j] == 0)
													{
														star2[i][j] = 1;
														num++;//�ڲ�������0
														yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, i, j, 5, 0);
													}
												}
											}
											cct_gotoxy(0, 0);
											score(num);
											//���ε÷�
											if (option == 'F')
											{
												cct_gotoxy(0, HANG * line + 4);
												cout << "�ϳ���ɣ��س���/�����������";
												//maction = 0;//������㰴һ�������Ϳ��Լ���???Ϊʲômaction�����1����
												while (1)
												{
													cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2);//ֻ����궯�˻��߼���������Ż�����������
													if (maction == 0x0002 || keycode1 == 13)
													{
														cout << maction;
														se_kuai_yi_dong(star, line, column, option, star2);
														break;
													}
													else
														continue;
												}
												cct_gotoxy(0, HANG * line + 4);
												cout << "���κϳɽ�������c/�������������һ�εĺϳ�";
												while (1)
												{
													cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2);//ֻ����궯�˻��߼���������Ż�����������
													if (maction == 0x0002 || keycode1 == 'c' || keycode1 == 'C')
														break;
													else
														continue;
												}
												score(0, 0);
												maction = 0;
											}
											else
											{
												se_kuai_yi_dong(star, line, column, option, star2);
												int num = pan_duan_tong_guan(star, line, column);
												if (num)
												{
													tong_guan = 1;
													cct_gotoxy(0, (HANG + 1) * line + 4);
													cout << "ʣ��" << num - 1 << "�����ǣ��޿���������ؽ������س�������һ��";
													cct_gotoxy(0, 0);
													score(num - 1, 2);
													while (_getch() != 13)
													{
													}
													break;
												}
												else
												{
													if (pan_duan_he_fa(mx, my, line, column, option, star, 0))
														yi_ge_se_kuai(HANG + 1, LIE + 2, star, (my - 3) / (HANG + 1), (mx - 4) / (LIE + 2), 1, 0);
												}
											}
											break;
										}
										else if (maction == 0x0008)
											break;
									}
									else
									{
										if (keycode1 == 'q' || keycode1 == 'Q')
											break;
										jian_pan(keycode2, mx, my, (option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), line, column);
										if ((my - 3) / (option == 'G' ? (HANG + 1) : HANG) != (y - 3) / (option == 'G' ? (HANG + 1) : HANG) || (mx - 4) / (option == 'G' ? (LIE + 2) : LIE) != (x - 4) / (option == 'G' ? (LIE + 2) : LIE))//���ȡ��ѡ��
										{
											for (int i = 0; i < line; i++)
											{
												for (int j = 0; j < column; j++)
												{
													if (star[i][j] == 0)
													{
														star[i][j] = temp;
														yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, i, j, 2, 0);
													}
												}
											}
											Sleep(50);
											yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, (my - 3) / (option == 'G' ? (HANG + 1) : HANG), (mx - 4) / (option == 'G' ? (LIE + 2) : LIE), 1, 0);
											cct_gotoxy(0, (option == 'G' ? (HANG + 1) : HANG) * line + 4);
											cout << "[��ǰ����] " << char((my - 3) / (option == 'G' ? (HANG + 1) : HANG) + 'A') << "��" << (mx - 4) / (option == 'G' ? (LIE + 2) : LIE) << "��                                    ";
											break;
										}
										else
										{
											if (keycode1 == 13)
											{
												int num = 0;
												for (int i = 0; i < line; i++)
												{
													for (int j = 0; j < column; j++)
													{
														if (star[i][j] == 0 && star2[i][j] == 0)
														{
															star2[i][j] = 1;
															num++;//�ڲ�������0
															yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, i, j, 5, 0);
														}
													}
												}
												cct_gotoxy(0, 0);
												score(num);
												if (option == 'F')
												{
													cct_gotoxy(0, HANG * line + 4);
													cout << "�ϳ���ɣ��س���/�����������";
													while (1)
													{
														cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2);//ֻ����궯�˻��߼���������Ż�����������
														if (maction == 0x0002 || keycode1 == 13)
														{
															cout << maction;
															se_kuai_yi_dong(star, line, column, option, star2);
															break;
														}
														else
															continue;
													}
													cct_gotoxy(0, HANG * line + 4);
													cout << "���κϳɽ�������c/�������������һ�εĺϳ�";
													while (1)
													{
														cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2);//ֻ����궯�˻��߼���������Ż�����������
														if (maction == 0x0002 || keycode1 == 'c' || keycode1 == 'C')
															break;
														else
															continue;
													}
													score(0, 0);
													maction = 0;
												}
												else
												{
													se_kuai_yi_dong(star, line, column, option, star2);
													int num = pan_duan_tong_guan(star, line, column);
													if (num)
													{
														maction = 0;
														tong_guan = 1;
														cct_gotoxy(0, (HANG + 1) * line + 4);
														cout << "ʣ��" << num - 1 << "�����ǣ��޿���������ؽ������س�������һ��";
														cct_gotoxy(0, 0);
														score(num - 1, 2);
														while (_getch() != 13)
														{
														}
														break;
													}
													else
													{
														for (int i = 0; i < line; i++)
														{
															if (star[i][0] != 0)
															{
																my = i * (option == 'G' ? (HANG + 1) : HANG) + 3;
																mx = 4;
																break;
															}
															else
																continue;
														}
														yi_ge_se_kuai(HANG + 1, LIE + 2, star, (my - 3) / (HANG + 1), (mx - 4) / (LIE + 2), 1, 0);
													}
												}
												break;
											}
											else
												continue;
										}
									}
								}
								if (maction == 1 || option == 'G' && !tong_guan)//ȡ��ѡ�����¿�ʼѡ�񣻻�g��������ٴο�ʼ�µ�ѡ��
								{
									//pan_duan = 1;
									continue;
								}
								break;
							}
							break;
						}
						else if (keycode1 == 'q' || keycode1 == 'Q')
						{
							cct_gotoxy(0, (option == 'G'||option == 'E' ? (HANG + 1) : HANG)* line + 4);
							break;
						}
					}
				}
				if (tong_guan == 1)
					continue;
				zan_ting();
				score(0, 0);
				break;
			}
		}
	}


	return 0;
}