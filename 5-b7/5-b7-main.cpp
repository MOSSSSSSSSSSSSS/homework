// 2253209 ������ ��07
#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<conio.h>
#include"5-b7.h"
using namespace std;

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
static int yanshi, show;
int qszzz, zjzzz, mbzzz, qszz[10], zjzz[10], mbzz[10], a = 1;
void hanoi(int n, char qsz, char zjz, char mbz)
{
    int temp;
    static char x = qsz, y = zjz, z = mbz;
    if (n == 1)
    {
        cct_gotoxy(20, 25);
        cout << "                                                                                                                                                                               ";
        cct_gotoxy(20, 25);
        cout << "��" << setw(4) << a << "��(" << n << "#: " << qsz << "-->" << mbz<<')';
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
        if (show)
        {
            cout << ' ';
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
            if (yanshi == 0)
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
                Sleep((6 - yanshi) * 100);
            }
        }
        if (qsz == x && mbz == z)
        {
            cct_gotoxy((qsz - 64) * 10, 19 - qszzz);
            cout << "  ";
            cct_gotoxy((mbz - 64) * 10, 20 - mbzzz);
            cout << setw(2) << temp;
        }
        else if (qsz == x && mbz == y)
        {
            cct_gotoxy((qsz - 64) * 10, 19 - qszzz);
            cout << "  ";
            cct_gotoxy((mbz - 64) * 10, 20 - zjzzz);
            cout << setw(2) << temp;
        }
        else if (qsz == y && mbz == x)
        {
            cct_gotoxy((qsz - 64) * 10, 19 - zjzzz);
            cout << "  ";
            cct_gotoxy((mbz - 64) * 10, 20 - qszzz);
            cout << setw(2) << temp;
        }
        else if (qsz == y && mbz == z)
        {
            cct_gotoxy((qsz - 64) * 10, 19 - zjzzz);
            cout << "  ";
            cct_gotoxy((mbz - 64) * 10, 20 - mbzzz);
            cout << setw(2) << temp;
        }
        else if (qsz == z && mbz == x)
        {
            cct_gotoxy((qsz - 64) * 10, 19 - mbzzz);
            cout << "  ";
            cct_gotoxy((mbz - 64) * 10, 20 - qszzz);
            cout << setw(2) << temp;
        }
        else
        {
            cct_gotoxy((qsz - 64) * 10, 19 - mbzzz);
            cout << "  ";
            cct_gotoxy((mbz - 64) * 10, 20 - zjzzz);
            cout << setw(2) << temp;
        }
        if (yanshi == 0)
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
            Sleep((6 - yanshi) * 100);
        }
        a++;
    }
    else
    {
        hanoi(n - 1, qsz, mbz, zjz);
        cct_gotoxy(20, 25);
        cout << "                                                                                                                                                                               ";
        cct_gotoxy(20, 25);
        cout << "��" << setw(4) << a << "��(" << n << "#: " << qsz << "-->" << mbz << ')';
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
        if (show)
        {
            cout << ' ';
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
            if (yanshi == 0)
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
                Sleep((6 - yanshi) * 100);
            }
        }
        if (qsz == x && mbz == z)
        {
            cct_gotoxy((qsz - 64) * 10, 19 - qszzz);
            cout << "  ";
            cct_gotoxy((mbz - 64) * 10, 20 - mbzzz);
            cout << setw(2) << temp;
        }
        else if (qsz == x && mbz == y)
        {
            cct_gotoxy((qsz - 64) * 10, 19 - qszzz);
            cout << "  ";
            cct_gotoxy((mbz - 64) * 10, 20 - zjzzz);
            cout << setw(2) << temp;
        }
        else if (qsz == y && mbz == x)
        {
            cct_gotoxy((qsz - 64) * 10, 19 - zjzzz);
            cout << "  ";
            cct_gotoxy((mbz - 64) * 10, 20 - qszzz);
            cout << setw(2) << temp;
        }
        else if (qsz == y && mbz == z)
        {
            cct_gotoxy((qsz - 64) * 10, 19 - zjzzz);
            cout << "  ";
            cct_gotoxy((mbz - 64) * 10, 20 - mbzzz);
            cout << setw(2) << temp;
        }
        else if (qsz == z && mbz == x)
        {
            cct_gotoxy((qsz - 64) * 10, 19 - mbzzz);
            cout << "  ";
            cct_gotoxy((mbz - 64) * 10, 20 - qszzz);
            cout << setw(2) << temp;
        }
        else
        {
            cct_gotoxy((qsz - 64) * 10, 19 - mbzzz);
            cout << "  ";
            cct_gotoxy((mbz - 64) * 10, 20 - zjzzz);
            cout << setw(2) << temp;
        }
        if (yanshi == 0)
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
            Sleep((6 - yanshi) * 100);
        }
        a++;
        hanoi(n - 1, zjz, qsz, mbz);
    }
}
int main()
{
    int n;
    char qsz, zjz, mbz;
    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> n;
        cin.ignore(65536, '\n');
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
        }
        else
        {
            if (n < 1 || n>10)
            {
                ;
            }
            else
            {
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        qszz[i] = n - i;
    }
    qszzz = n;
    while (1)
    {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> qsz;
        cin.ignore(65536, '\n');
        if (qsz == 'a' || qsz == 'b' || qsz == 'c')
        {
            qsz = qsz - 32;
            break;
        }
        else if (qsz == 'A' || qsz == 'B' || qsz == 'C')
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
        cin >> mbz;
        cin.ignore(65536, '\n');
        if (mbz == 'a' || mbz == 'b' || mbz == 'c')
        {
            mbz = mbz - 32;
        }
        if (mbz != 'A' && mbz != 'B' && mbz != 'C' || mbz == qsz)
        {
            ;
        }
        else
        {
            break;
        }
    }
    zjz = 'A' + 'B' + 'C' - qsz - mbz;
    while (1)
    {
        cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
        cin >> yanshi;
        cin.ignore(65536, '\n');
        if (cin.fail())
        {
            cin.clear();
        }
        else if (yanshi > 5 || yanshi < 0)
        {
           ;
        }
        else
        {
            break;
        }
    }
    while (1)
    {
        cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
        cin >> show;
        cin.ignore(65536, '\n');
        if (cin.fail())
        {
            cin.clear();
        }
        else if (show != 0 && show != 1)
        {
            ;
        }
        else
        {
            break;
        }
    }
    cct_cls();
    cout << "�� " << qsz << " �ƶ��� " << mbz <<"��" << "�� " << n << " �㣬��ʱ����Ϊ " << yanshi << "��" << (show ? "��ʾ�ڲ�����ֵ" : "����ʾ�ڲ�����ֵ") << endl;
    if (show)
    {
        cct_gotoxy(20, 25);
        cout << "��ʼ:                A:";
        if (qsz == 'A')
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
        else if (qsz == 'B')
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
        if (yanshi == 0)
        {
            while (1)
            {
                if (_getch()==13)
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
            Sleep((6 - yanshi) * 100);
        }
        cct_gotoxy(9, 20);
        cout << "=========================";
        cct_gotoxy(11, 21);
        cout << "A         B         C";
        for (int i = 0; qszz[i] > 0; i++)
        {
            cct_gotoxy((qsz - 64) * 10, 19 - i);
            cout << setw(2) << qszz[i];
        }
        if (yanshi == 0)
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
            Sleep((6 - yanshi) * 100);
        }
        hanoi(n, qsz, zjz, mbz);
    }
    else
    {
        cct_gotoxy(9, 20);
        cout << "=========================";
        cct_gotoxy(11, 21);
        cout << "A         B         C";
        for (int i = 0; qszz[i]>0; i++)
        {
            cct_gotoxy((qsz-64)*10, 19-i);
            cout << setw(2) << qszz[i];
        }
        if (yanshi == 0)
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
            Sleep((6 - yanshi) * 100);
        }
        hanoi(n, qsz, zjz, mbz);
    }

    cct_gotoxy(20, 35);
	system("pause"); //���������ʾ��ͣ��ע�⣺ֻ�ʺ����ض��������ر������ĳ���Ӵ˾���÷�Ϊ0��
	return 0;
}
