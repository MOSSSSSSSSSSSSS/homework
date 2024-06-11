// 2253209 信07 刘佳朋
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
	cout << "A.命令行找出可消除项并标识" << endl;
	cout << "B.命令行完成一次消除（分步骤显示）" << endl;
	cout << "C.命令行完成一关（分步骤显示）" << endl;
	cout << "D.伪图形界面下用鼠标选择一个色块（无分隔线）" << endl;
	cout << "E.伪图形界面下用鼠标选择一个色块（有分隔线）" << endl;
	cout << "F.伪图形界面完成一次消除（分步骤）" << endl;
	cout << "G.伪图形界面完整版" << endl;
	cout << "Q.退出" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "[请选择:] ";
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
			cout << "请输入行数(8-10)：" << endl;
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
			cout << "请输入列数(8-10)：" << endl;
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
							cout << "剩余" << num - 1 << "个不可消除项，本关结束!";
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
				int mx = 4, my = 3, maction = 0, keycode1, keycode2, x, y, pan_duan = 0, pan_duan2 = 0, tong_guan = 0, star[10][10] = { 0 }, star2[10][10] = { 0 };//pan—duan是用来确定到底是从非法区域进入方框中，还是一直在同一个方框中，防止在一个方框中的闪烁和从非法区域进入方框不反显;panduan2的作用是防止从合法区域出去后，在非法区域移动时色块不停闪。
				wai_kuang_jia(line, column, HANG, LIE, (option == 'E' || option == 'G' ? 2 : 1));
				chu_shi_zhuang_tai_lan(line, column, HANG, LIE, (option == 'E' || option == 'G' ? 2 : 1));
				for (int i = 0; i < line; i++)
				{
					for (int j = 0; j < column; j++)
						yi_ge_se_kuai(HANG + (option == 'E' || option == 'G' ? 1 : 0), LIE + (option == 'E' || option == 'G' ? 2 : 0), star, i, j, 0, 0);
				}
				yi_ge_se_kuai(HANG + (option == 'E' || option == 'G' ? 1 : 0), LIE + (option == 'E' || option == 'G' ? 2 : 0), star, (my - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG), (mx - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE), 1, 0);//一开始 第一个是白的
				while (1)
				{
					if (pan_duan_he_fa(mx, my, line, column, option, star, 0))
					{
						x = mx;
						y = my;
					}//x，y是上一次移动终点，作为接下来移动的起点，接下来的mx，my是移动的终点。只有mx，my合法，x，y才赋为它们的值
					if (!cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2))//如果是因为鼠标.只有鼠标动了或者键盘有输入才会进行下面操作
					{
						if (maction == 0x0001)//如果鼠标移动
						{
							if (pan_duan_he_fa(mx, my, line, column, option, star, 0))//如果当前位置合法，状态栏打印当前位置
							{
								cct_gotoxy(0, (option == 'E' || option == 'G' ? (HANG + 1) : HANG) * line + 4);
								cout << "[当前鼠标] " << char((my - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG) + 'A') << "行" << (mx - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE) << "列                                                                                                                    ";
								if (((y - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG) != (my - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG) || (x - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE) != (mx - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE)) && pan_duan_he_fa(x, y, line, column, option, star, 0))
								{//如果原始位置合法，当前位置和原始位置所在方框不同，原始变黑当前变白；如果原始位置合法，当前位置和原始位置所在方框相同，不变
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
								else//如果原始位置不合法，当前位置变白（1）
									yi_ge_se_kuai((option == 'E' || option == 'G' ? (HANG + 1) : HANG), (option == 'E' || option == 'G' ? (LIE + 2) : LIE), star, (my - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG), (mx - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE), 1, 0);
								pan_duan2 = 1;
							}
							else//如果当前位置非法，原始位置非法，则不变；如果当前位置非法，原始位置合法，则原始方框变黑（2）
							{
								cct_gotoxy(0, (option == 'E' || option == 'G' ? (HANG + 1) : HANG) * line + 4);
								cout << "[当前鼠标] 位置非法                                  ";
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
						else if (maction == 0x0002 && pan_duan_he_fa(mx, my, line, column, option, star, 0))//如果单击鼠标左键，且当前位置合法
						{
							x = mx;
							y = my;//如果上一步是键盘操作，x与mx，y与my值不相同，要让他们相同，否则下面判断是否取消选择有错，错误：鼠标在同一个色块上移动也会认为是取消选择
							yi_ge_se_kuai((option == 'E' || option == 'G' ? (HANG + 1) : HANG), (option == 'E' || option == 'G' ? (LIE + 2) : LIE), star, (my - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG), (mx - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE), 1, 0);
							if (option == 'D' || option == 'E')
							{
								cct_gotoxy(0, (option == 'E' ? (HANG + 1) : HANG) * line + 4);
								cout << "选中了" << char((my - 3) / (option == 'E' ? (HANG + 1) : HANG) + 'A') << "行" << (mx - 4) / (option == 'E' ? (LIE + 2) : LIE) << "列                             ";
								break;
							}
							else if (option == 'F' || option == 'G')
							{
								cct_gotoxy(0, (option == 'G' ? (HANG + 1) : HANG) * line + 4);
								cout << "[当前鼠标] " << char((my - 3) / (option == 'G' ? (HANG + 1) : HANG) + 'A') << "行" << (mx - 4) / (option == 'G' ? (LIE + 2) : LIE) << "列                                                                                                                  ";
								int temp = star[(my - 3) / (option == 'G' ? (HANG + 1) : HANG)][(mx - 4) / (option == 'G' ? (LIE + 2) : LIE)];
								if (!cha_zhao(star, (my - 3) / (option == 'G' ? (HANG + 1) : HANG), (mx - 4) / (option == 'G' ? (LIE + 2) : LIE), line, column, star[(my - 3) / (option == 'G' ? (HANG + 1) : HANG)][(mx - 4) / (option == 'G' ? (LIE + 2) : LIE)], 1))
								{
									cct_gotoxy(0, (option == 'G' ? (HANG + 1) : HANG) * line + 4);
									cout << "周围无相同值 箭头键/鼠标键移动，Q/单击右键结束";
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
											cout << "[当前键盘] " << char((my - 3) / (option == 'G' ? (HANG + 1) : HANG) + 'A') << "行" << (mx - 4) / (option == 'G' ? (LIE + 2) : LIE) << "列                                                 ";
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
								cout << "箭头键/鼠标移动取消当前选择，回车键/单击左键合成";
								while (1)
								{
									if (!cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2))//如果是因为鼠标
									{
										if (maction == 0x0001)//如果鼠标移动
										{
											if (!pan_duan_he_fa(mx, my, line, column, option, star) || ((my - 3) / (option == 'G' ? (HANG + 1) : HANG) != (y - 3) / (option == 'G' ? (HANG + 1) : HANG) || (mx - 4) / (option == 'G' ? (LIE + 2) : LIE) != (x - 4) / (option == 'G' ? (LIE + 2) : LIE)))//如果取消选择
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
												break;//应该退到上一个循环，但是与下面一个break想退出所有循环，相矛盾
											}
											continue;//没有取消选择，只是在选择的方框上移动
										}
										else if (maction == 0x0002)//如果鼠标单击左键，表示合成
										{
											int num = 0;
											for (int i = 0; i < line; i++)
											{
												for (int j = 0; j < column; j++)
												{
													if (star[i][j] == 0 && star2[i][j] == 0)
													{
														star2[i][j] = 1;
														num++;//内部数组是0
														yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, i, j, 5, 0);
													}
												}
											}
											cct_gotoxy(0, 0);
											score(num);
											//本次得分
											if (option == 'F')
											{
												cct_gotoxy(0, HANG * line + 4);
												cout << "合成完成，回车键/单击左键下落";
												//maction = 0;//否则随便按一个按键就可以继续???为什么maction变成了1？？
												while (1)
												{
													cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2);//只有鼠标动了或者键盘有输入才会进行下面操作
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
												cout << "本次合成结束，按c/单击左键进行新一次的合成";
												while (1)
												{
													cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2);//只有鼠标动了或者键盘有输入才会进行下面操作
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
													cout << "剩余" << num - 1 << "个星星，无可消除项，本关结束！回车进行下一关";
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
										if ((my - 3) / (option == 'G' ? (HANG + 1) : HANG) != (y - 3) / (option == 'G' ? (HANG + 1) : HANG) || (mx - 4) / (option == 'G' ? (LIE + 2) : LIE) != (x - 4) / (option == 'G' ? (LIE + 2) : LIE))//如果取消选择
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
											cout << "[当前键盘] " << char((my - 3) / (option == 'G' ? (HANG + 1) : HANG) + 'A') << "行" << (mx - 4) / (option == 'G' ? (LIE + 2) : LIE) << "列                                ";
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
															num++;//内部数组是0
															yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, i, j, 5, 0);
														}
													}
												}
												cct_gotoxy(0, 0);
												score(num);
												if (option == 'F')
												{
													cct_gotoxy(0, HANG * line + 4);
													cout << "合成完成，回车键/单击左键下落";
													while (1)
													{
														cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2);//只有鼠标动了或者键盘有输入才会进行下面操作
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
													cout << "本次合成结束，按c/单击左键进行新一次的合成";
													while (1)
													{
														cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2);//只有鼠标动了或者键盘有输入才会进行下面操作
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
														cout << "剩余" << num - 1 << "个星星，无可消除项，本关结束！回车进行下一关";
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
								if (maction == 1 || option == 'G' && !tong_guan)//取消选择，重新开始选择；或g消除完后再次开始新的选择
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
					else//如果是因为键盘
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
							cout << "[当前键盘] " << char((my - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG) + 'A') << "行" << (mx - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE) << "列                                    ";
							yi_ge_se_kuai((option == 'E' || option == 'G' ? (HANG + 1) : HANG), (option == 'E' || option == 'G' ? (LIE + 2) : LIE), star, (y - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG), (x - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE), 2, 0);
							yi_ge_se_kuai((option == 'E' || option == 'G' ? (HANG + 1) : HANG), (option == 'E' || option == 'G' ? (LIE + 2) : LIE), star, (my - 3) / (option == 'E' || option == 'G' ? (HANG + 1) : HANG), (mx - 4) / (option == 'E' || option == 'G' ? (LIE + 2) : LIE), 1, 0);
						}
						else if (keycode1 == 13)
						{
							if (option == 'D' || option == 'E')
							{
								cct_gotoxy(0, (option == 'E' ? (HANG + 1) : HANG) * line + 4);
								cout << "选中了" << char((my - 3) / (option == 'E' ? (HANG + 1) : HANG) + 'A') << "行" << (mx - 4) / (option == 'E' ? (LIE + 2) : LIE) << "列                                         ";
								break;
							}
							else if (option == 'F' || option == 'G')
							{
								cct_gotoxy(0, (option == 'G' ? (HANG + 1) : HANG) * line + 4);
								cout << "[当前键盘] " << char((my - 3) / (option == 'G' ? (HANG + 1) : HANG) + 'A') << "行" << (mx - 4) / (option == 'G' ? (LIE + 2) : LIE) << "列                                        ";
								int temp = star[(my - 3) / (option == 'G' ? (HANG + 1) : HANG)][(mx - 4) / (option == 'G' ? (LIE + 2) : LIE)];
								if (!cha_zhao(star, (my - 3) / (option == 'G' ? (HANG + 1) : HANG), (mx - 4) / (option == 'G' ? (LIE + 2) : LIE), line, column, star[(my - 3) / (option == 'G' ? (HANG + 1) : HANG)][(mx - 4) / (option == 'G' ? (LIE + 2) : LIE)], 1))
								{
									cct_gotoxy(0, (option == 'G' ? (HANG + 1) : HANG) * line + 4);
									cout << "周围无相同值 箭头键/鼠标键移动，Q/单击右键结束";
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
								cout << "箭头键/鼠标移动取消当前选择，回车键/单击左键合成";
								while (1)
								{
									if (!cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2))//如果是因为鼠标
									{
										if (maction == 0x0001)//如果鼠标移动
										{
											if (!pan_duan_he_fa(mx, my, line, column, option, star) || ((my - 3) / (option == 'G' ? (HANG + 1) : HANG) != (y - 3) / (option == 'G' ? (HANG + 1) : HANG) || (mx - 4) / (option == 'G' ? (LIE + 2) : LIE) != (x - 4) / (option == 'G' ? (LIE + 2) : LIE)))//如果取消选择
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
												break;//应该退到上一个循环，但是与下面一个break想退出所有循环，相矛盾
											}
											continue;//没有取消选择，只是在选择的方框上移动
										}
										else if (maction == 0x0002)//如果鼠标单击左键，表示合成
										{
											int num = 0;
											for (int i = 0; i < line; i++)
											{
												for (int j = 0; j < column; j++)
												{
													if (star[i][j] == 0 && star2[i][j] == 0)
													{
														star2[i][j] = 1;
														num++;//内部数组是0
														yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, i, j, 5, 0);
													}
												}
											}
											cct_gotoxy(0, 0);
											score(num);
											//本次得分
											if (option == 'F')
											{
												cct_gotoxy(0, HANG * line + 4);
												cout << "合成完成，回车键/单击左键下落";
												//maction = 0;//否则随便按一个按键就可以继续???为什么maction变成了1？？
												while (1)
												{
													cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2);//只有鼠标动了或者键盘有输入才会进行下面操作
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
												cout << "本次合成结束，按c/单击左键进行新一次的合成";
												while (1)
												{
													cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2);//只有鼠标动了或者键盘有输入才会进行下面操作
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
													cout << "剩余" << num - 1 << "个星星，无可消除项，本关结束！回车进行下一关";
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
										if ((my - 3) / (option == 'G' ? (HANG + 1) : HANG) != (y - 3) / (option == 'G' ? (HANG + 1) : HANG) || (mx - 4) / (option == 'G' ? (LIE + 2) : LIE) != (x - 4) / (option == 'G' ? (LIE + 2) : LIE))//如果取消选择
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
											cout << "[当前键盘] " << char((my - 3) / (option == 'G' ? (HANG + 1) : HANG) + 'A') << "行" << (mx - 4) / (option == 'G' ? (LIE + 2) : LIE) << "列                                    ";
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
															num++;//内部数组是0
															yi_ge_se_kuai((option == 'G' ? (HANG + 1) : HANG), (option == 'G' ? (LIE + 2) : LIE), star, i, j, 5, 0);
														}
													}
												}
												cct_gotoxy(0, 0);
												score(num);
												if (option == 'F')
												{
													cct_gotoxy(0, HANG * line + 4);
													cout << "合成完成，回车键/单击左键下落";
													while (1)
													{
														cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2);//只有鼠标动了或者键盘有输入才会进行下面操作
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
													cout << "本次合成结束，按c/单击左键进行新一次的合成";
													while (1)
													{
														cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2);//只有鼠标动了或者键盘有输入才会进行下面操作
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
														cout << "剩余" << num - 1 << "个星星，无可消除项，本关结束！回车进行下一关";
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
								if (maction == 1 || option == 'G' && !tong_guan)//取消选择，重新开始选择；或g消除完后再次开始新的选择
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