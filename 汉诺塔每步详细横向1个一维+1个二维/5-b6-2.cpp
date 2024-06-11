// 2253209 信07 刘佳朋
#include<iostream>
#include<iomanip>
using namespace std;

int arrzz[3], arrz[3][10], a = 1;
void hannuo(int n, char qsz, char zjz, char mbz, char x, char y, char z)
{
    if (n == 1)
    {
        cout << "第" << setw(4) << a << ' ' << "步" << '(' << setw(2) << n << ')' << ':' << ' ' << qsz << "-->" << mbz;
        if (qsz == x && mbz == z)
        {
            arrzz[0]--;
            int temp;
            temp = arrz[0][arrzz[0]];
            arrz[0][arrzz[0]] = 0;
            arrz[2][arrzz[2]] = temp;
            arrzz[2]++;
        }
        else if (qsz == x && mbz == y)
        {
            arrzz[0]--;
            int temp;
            temp = arrz[0][arrzz[0]];
            arrz[0][arrzz[0]] = 0;
            arrz[1][arrzz[1]] = temp;
            arrzz[1]++;
        }
        else if (qsz == y && mbz == x)
        {
            arrzz[1]--;
            int temp;
            temp = arrz[1][arrzz[1]];
            arrz[1][arrzz[1]] = 0;
            arrz[0][arrzz[0]] = temp;
            arrzz[0]++;
        }
        else if (qsz == y && mbz == z)
        {
            arrzz[1]--;
            int temp;
            temp = arrz[1][arrzz[1]];
            arrz[1][arrzz[1]] = 0;
            arrz[2][arrzz[2]] = temp;
            arrzz[2]++;
        }
        else if (qsz == z && mbz == x)
        {
            arrzz[2]--;
            int temp;
            temp = arrz[2][arrzz[2]];
            arrz[2][arrzz[2]] = 0;
            arrz[0][arrzz[0]] = temp;
            arrzz[0]++;
        }
        else
        {
            arrzz[2]--;
            int temp;
            temp = arrz[2][arrzz[2]];
            arrz[2][arrzz[2]] = 0;
            arrz[1][arrzz[1]] = temp;
            arrzz[1]++;
        }
        if (x == 'A' && y == 'B')
        {
            cout << " A:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[0][i] > 0)
                {
                    cout << setw(2) << arrz[0][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " B:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[1][i] > 0)
                {
                    cout << setw(2) << arrz[1][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " C:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[2][i] > 0)
                {
                    cout << setw(2) << arrz[2][i];
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
                if (arrz[0][i] > 0)
                {
                    cout << setw(2) << arrz[0][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " B:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[2][i] > 0)
                {
                    cout << setw(2) << arrz[2][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " C:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[1][i] > 0)
                {
                    cout << setw(2) << arrz[1][i];
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
                if (arrz[1][i] > 0)
                {
                    cout << setw(2) << arrz[1][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " B:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[0][i] > 0)
                {
                    cout << setw(2) << arrz[0][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " C:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[2][i] > 0)
                {
                    cout << setw(2) << arrz[2][i];
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
                if (arrz[2][i] > 0)
                {
                    cout << setw(2) << arrz[2][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " B:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[0][i] > 0)
                {
                    cout << setw(2) << arrz[0][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " C:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[1][i] > 0)
                {
                    cout << setw(2) << arrz[1][i];
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
                if (arrz[1][i] > 0)
                {
                    cout << setw(2) << arrz[1][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " B:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[2][i] > 0)
                {
                    cout << setw(2) << arrz[2][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " C:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[0][i] > 0)
                {
                    cout << setw(2) << arrz[0][i];
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
                if (arrz[2][i] > 0)
                {
                    cout << setw(2) << arrz[2][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " B:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[1][i] > 0)
                {
                    cout << setw(2) << arrz[1][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " C:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[0][i] > 0)
                {
                    cout << setw(2) << arrz[0][i];
                }
                else
                {
                    cout << "  ";
                }
            }
        }
        cout << endl;
        a++;
    }
    else
    {
        hannuo(n - 1, qsz, mbz, zjz, x, y, z);
        cout << "第" << setw(4) << a << ' ' << "步" << '(' << setw(2) << n << ')' << ':' << ' ' << qsz << "-->" << mbz;
        if (qsz == x && mbz == z)
        {
            arrzz[0]--;
            int temp;
            temp = arrz[0][arrzz[0]];
            arrz[0][arrzz[0]] = 0;
            arrz[2][arrzz[2]] = temp;
            arrzz[2]++;
        }
        else if (qsz == x && mbz == y)
        {
            arrzz[0]--;
            int temp;
            temp = arrz[0][arrzz[0]];
            arrz[0][arrzz[0]] = 0;
            arrz[1][arrzz[1]] = temp;
            arrzz[1]++;
        }
        else if (qsz == y && mbz == x)
        {
            arrzz[1]--;
            int temp;
            temp = arrz[1][arrzz[1]];
            arrz[1][arrzz[1]] = 0;
            arrz[0][arrzz[0]] = temp;
            arrzz[0]++;
        }
        else if (qsz == y && mbz == z)
        {
            arrzz[1]--;
            int temp;
            temp = arrz[1][arrzz[1]];
            arrz[1][arrzz[1]] = 0;
            arrz[2][arrzz[2]] = temp;
            arrzz[2]++;
        }
        else if (qsz == z && mbz == x)
        {
            arrzz[2]--;
            int temp;
            temp = arrz[2][arrzz[2]];
            arrz[2][arrzz[2]] = 0;
            arrz[0][arrzz[0]] = temp;
            arrzz[0]++;
        }
        else
        {
            arrzz[2]--;
            int temp;
            temp = arrz[2][arrzz[2]];
            arrz[2][arrzz[2]] = 0;
            arrz[1][arrzz[1]] = temp;
            arrzz[1]++;
        }
        if (x == 'A' && y == 'B')
        {
            cout << " A:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[0][i] > 0)
                {
                    cout << setw(2) << arrz[0][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " B:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[1][i] > 0)
                {
                    cout << setw(2) << arrz[1][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " C:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[2][i] > 0)
                {
                    cout << setw(2) << arrz[2][i];
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
                if (arrz[0][i] > 0)
                {
                    cout << setw(2) << arrz[0][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " B:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[2][i] > 0)
                {
                    cout << setw(2) << arrz[2][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " C:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[1][i] > 0)
                {
                    cout << setw(2) << arrz[1][i];
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
                if (arrz[1][i] > 0)
                {
                    cout << setw(2) << arrz[1][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " B:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[0][i] > 0)
                {
                    cout << setw(2) << arrz[0][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " C:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[2][i] > 0)
                {
                    cout << setw(2) << arrz[2][i];
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
                if (arrz[2][i] > 0)
                {
                    cout << setw(2) << arrz[2][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " B:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[0][i] > 0)
                {
                    cout << setw(2) << arrz[0][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " C:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[1][i] > 0)
                {
                    cout << setw(2) << arrz[1][i];
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
                if (arrz[1][i] > 0)
                {
                    cout << setw(2) << arrz[1][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " B:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[2][i] > 0)
                {
                    cout << setw(2) << arrz[2][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " C:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[0][i] > 0)
                {
                    cout << setw(2) << arrz[0][i];
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
                if (arrz[2][i] > 0)
                {
                    cout << setw(2) << arrz[2][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " B:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[1][i] > 0)
                {
                    cout << setw(2) << arrz[1][i];
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << " C:";
            for (int i = 0; i < 10; i++)
            {
                if (arrz[0][i] > 0)
                {
                    cout << setw(2) << arrz[0][i];
                }
                else
                {
                    cout << "  ";
                }
            }
        }
        cout << endl;
        a++;
        hannuo(n - 1, zjz, qsz, mbz, x, y, z);
    }

}
int main()
{
    int n;
    char qsz, zjz, mbz;
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        cin.ignore(65536, '\n');
        if (cin.fail())
        {
            cin.clear();
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
    while (1)
    {
        cout << "请输入起始柱(A-C)"<<endl;
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
        cout << "请输入目标柱(A-C)" << endl;
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
    if (qsz == 'B' && mbz == 'C' || qsz == 'C' && mbz == 'B')
    {
        zjz = 'A';
    }
    else if (qsz == 'A' && mbz == 'C' || qsz == 'C' && mbz == 'A')
    {
        zjz = 'B';
    }
    else
    {
        zjz = 'C';
    }
    for (int i = 0; i < n; i++)
    {
        arrz[0][i] = n - i;
    }
    arrzz[0] = n;
    char x = qsz, y = zjz, z = mbz;
    if (x == 'A')
    {
        cout << "初始:                A:";
        for (int i = 0; i < 10; i++)
        {
            if (arrz[0][i]>0)
            {
                cout << setw(2) << arrz[0][i];
            }
            else
            {
                cout << "  ";
            }
        }
        cout << " B:                    ";
        cout << " C:" << endl;
    }
    else if (x == 'B')
    {
        cout << "初始:                A:                    ";
        cout << " B:";
        for (int i = 0; i < 10; i++)
        {
            if (arrz[0][i] > 0)
            {
                cout << setw(2) << arrz[0][i];
            }
            else
            {
                cout << "  ";
            }
        }
        cout << " C:" << endl;
    }
    else
    {
        cout << "初始:                A:                    ";
        cout << " B:                    ";
        cout << " C:";
        for (int i = 0; i < 10; i++)
        {
            if (arrz[0][i] > 0)
            {
                cout << setw(2) << arrz[0][i];
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
    hannuo(n, qsz, zjz, mbz, x, y, z);

    return 0;
}