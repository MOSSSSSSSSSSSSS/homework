/* 2253209 刘佳朋 信07 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、仅允许hanoi中定义一个静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */

   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
               3、允许定义一个静态局部变量
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static int a = 1;
    if (n == 1)
    {
        cout <<setw(5)<<a<<':' << setw(3) << 1 << '#' << ' ' << src << "-->" << dst << endl;
        a++;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        cout << setw(5) << a << ':' << setw(3) << n << '#' << ' ' << src << "-->" << dst << endl;
        a++;
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
    int n;
    char a, b, c;//a是起始柱，c是目标柱，b是中间柱
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-16)" << endl;
        cin >> n;
        cin.ignore(65536, '\n');
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
        }
        else if (1 <= n && n <= 16)
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
        cout << "请输入起始柱(A-C)" << endl;
        cin >> a;
        cin.ignore(65536, '\n');
        if (a == 'A' || a == 'a' || a == 'b' || a == 'c' || a == 'B' || a == 'C')
        {
            if (int(a) >= 97)
            {
                a = int(a) - 32;
            }
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
        cin >> c;
        cin.ignore(65536, '\n');
        if ((c == 'A' || c == 'a' || c == 'b' || c == 'c' || c == 'B' || c == 'C') && c != a)
        {
            if (int(c) >= 97)
            {
                c = int(c) - 32;
            }
            break;
        }
        else
        {
            ;
        }
    }
    if (a == 'A' && c == 'B' || a == 'B' && c == 'A')
    {
        b = 'C';
    }
    else if (a == 'C' && c == 'B' || a == 'B' && c == 'C')
    {
        b = 'A';
    }
    else
    {
        b = 'B';
    }
    cout << "移动步骤为:" << endl;
    hanoi(n, a, b, c);

    return 0;
}