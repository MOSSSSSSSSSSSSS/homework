/* 2253209 ������ ��07 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
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

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/
char menu()
{
	char a;
	cout << "1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" << endl;
	cout << "2.��I��J��K��L��������������(��Сд���ɣ��߽����)" << endl;
	cout << "3.�ü�ͷ�������������ң��߽�ֹͣ" << endl;
	cout << "4.�ü�ͷ�������������ң��߽����" << endl;
	cout << "5.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ,�����ͷ����׼�����ƶ�)" << endl;
	cout << "6.��I��J��K��L��������������(��Сд���ɣ��߽����,�����ͷ����׼�����ƶ�)" << endl;
	cout << "0.�˳�" << endl;
	cout << "[��ѡ��0-6] ";
	a = _getch();


	return a;
}
void move_by_ijkl(char b)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
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
				cout << "��Ϸ���������س������ز˵�.";
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
				cout << "��Ϸ���������س������ز˵�.";
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
					cout << "��Ϸ���������س������ز˵�.";
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
					cout << "��Ϸ���������س������ز˵�.";
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
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
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
				cout << "��Ϸ���������س������ز˵�.";
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
				cout << "��Ϸ���������س������ز˵�.";
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/

int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
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
//˼��1:_getch()���������������������ҵķ������F1~F9��Delete�ȹ��ܼ�����������Σ���������������ֵ���ڶ��η�����ʵ��ֵ�����պ����н��հ���ֵ��char�ͱ���aӦ���ǵڶ��η��ص���ʵ��ֵ
//�������ͷ���ڶ��η���75����K��asc������ͬ���ͻ�����Ͱ�Kͬ����Ч��
//˼��2:��һ�����п��ܲ���20����ĸ��rand����%69+1��x���꣬rand����%17+1��y���꣬��ĳһ��ѭ����rand���������������%69��%17������������ǰ����ѭ����ĳһ�ε���ͬ���ͻ�����ͬλ���ٴδ�ӡһ����ĸ��
//���ǵ�ԭ������ĸ��������С��20