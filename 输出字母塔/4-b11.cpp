/* 2253209 信07 刘佳朋 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数（包括递归函数），但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
				 2、除print_tower之外的其他函数中不允许定义静态局部变量
   ----------------------------------------------------------------------------------- */
char print_equal_sigh(int a)
{
	if (a == 0)
	{
		;
	}
	else
	{
		cout << '=';
		print_equal_sigh(a - 1);
	}

	return '=';
}
void print_line(int a,int order)
{
	if (a==order)
	{
		print_line(a, order + 1);
	}
	else if(a>order)
	{
		cout << char(65 + order);
		print_line(a, order + 1);
	}
	else if (a < order)
	{
		if (2 * a + 64 - order>=65)
		{
			cout << char(2 * a + 64 - order);
			if (2 * a + 64 - order != 65)
			{
				print_line(a, order + 1);
			}
		}
	}
}
   /***************************************************************************
	 函数名称：
	 功    能：打印字母塔
	 输入参数：
	 返 回 值：
	 说    明：形参按需设置
			   提示：有一个参数order，指定正序/倒序
   ***************************************************************************/
void print_tower(int a,int order,int c)
{
	/* 允许按需定义最多一个静态局部变量（也可以不定义） */

	/* 按需实现，函数中不允许任何形式的循环，函数允许调用其它函数 */
	if (order == -1)
	{
		static int b;
		b++;
		if (a!=0)
		{
			cout << setw(b) << 'A';
		}
		if (b == c)
		{
			b = 1;
		}
		print_line(a, 1);
		cout << endl;
		if (a > 1)
		{
			print_tower(a - 1, order,c);
		}
	}
	else
	{
		if (a == 0)
		{
			;
		}
		else
		{
			cout << setw(a) << 'A';
			print_line(order, 1);
			cout << endl;
			print_tower(a - 1, order + 1,c);
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效，为避免循环出现，不处理输入错误) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(两边为A) */
	cout << print_equal_sigh(2 * (int(end_ch) - 65)) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔(A->" << end_ch << ")" << endl;
	cout << print_equal_sigh(2 * (int(end_ch) - 65)) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(int(end_ch) - 64, 1, int(end_ch) - 64); //正序打印 A~结束字符 
	cout << endl;
	
	/* 倒三角字母塔(两边为A) */
	cout << print_equal_sigh(2 * (int(end_ch) - 65)) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔(A->" << end_ch << ")" << endl;
	cout << print_equal_sigh(2 * (int(end_ch) - 65)) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(int(end_ch) - 64, -1, int(end_ch) - 64); //逆序打印 A~结束字符 
	cout << endl;

	/* 合起来就是漂亮的菱形（外侧为A） */
	cout << print_equal_sigh(2 * (int(end_ch) - 65)) << endl;/* 按字母塔最大宽度输出= */
	cout << "菱形(A->" << end_ch << ")" << endl;
	cout << print_equal_sigh(2 * (int(end_ch) - 65)) << endl;/* 按字母塔最大宽度输出= */
	print_tower(int(end_ch) - 64, 1, int(end_ch) - 64);   //打印 A~结束字符的正三角 
	print_tower(int(end_ch) - 65, -1, int(end_ch) - 64);   //打印 A~结束字符-1的倒三角 
	cout << endl;

	return 0;
}