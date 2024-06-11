/* 信07 2253209 刘佳朋 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
//可按需增加需要的头文件

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void daxie(char arr[],int x)
{
	sprintf(arr, "%c%c", chnstr[2*x], chnstr[2*x+1]);
	strcat(result, arr);
}
int main()
{
    /* --允许添加需要的内容 --*/
    printf("请输入[0-100亿)之间的数字:\n");
    double num;
    int a, b, c, d, e, f, g, h, i, j, k, l;
	char arr[3] = { 0,0,0 };
    scanf("%lf", &num);
    num += 0.001;
	a = (int)(num / 1e9) % 10;
	b = (int)(num / 1e8) % 10;
	c = (int)(num / 1e7) % 10;
	d = (int)(num / 1e6) % 10;
	e = (int)(num / 1e5) % 10;
	f = (int)(num / 1e4) % 10;
	g = (int)(num / 1e3) % 10;
	h = (int)(num / 1e2) % 10;
	i = (int)(num / 10) % 10;
	j = (int)(num - a * 1e9) % 10;
	k = (int)(num * 10 - a * 1e10 - b * 1e9) % 10;
	l = (int)(num * 100 - a * 1e11 - b * 1e10 - c * 1e9) % 10;
	printf("大写结果是:\n");
	if (num == 0.001)
	{
		daxie(arr, 0);
		strcat(result, "圆整");
	}
	else
	{
		if (a == 0)
		{
			;
		}
		else
		{
			daxie(arr, a);
			strcat(result, "拾");
		}
		if (b == 0)
		{
			;
		}
		else
		{
			daxie(arr,b);
		}
		if (a + b != 0)
		{
			strcat(result, "亿");
		}
		if (c == 0)
		{
			if (a + b != 0 && d != 0)
			{
				daxie(arr,c);
			}
			else
			{
				;
			}
		}
		else
		{
			daxie(arr, c);
			strcat(result, "仟");
		}
		if (d == 0)
		{
			if (a + b + c != 0 && e != 0)
			{
				daxie(arr,d);
			}
			else
			{
				;
			}
		}
		else
		{
			daxie(arr,d);
			strcat(result, "佰");
		}
		if (e == 0)
		{
			if (a + b + c + d != 0 && f != 0)
			{
				daxie(arr,e);
			}
			else
			{
				;
			}
		}
		else
		{
			daxie(arr,e);
			strcat(result, "拾");
		}
		if (f == 0)
		{
			;
		}
		else
		{
			daxie(arr,f);
		}
		if (c + d + e + f != 0)
		{
			strcat(result, "万");
		}
		if (g == 0)
		{
			if (a + b + c + d + e + f != 0 && h != 0)
			{
				daxie(arr,g);
			}
			else
			{
				;
			}
		}
		else
		{
			daxie(arr,g);
			strcat(result, "仟");
		}
		if (h == 0)
		{
			if (a + b + c + d + e + f + g != 0 && i != 0)
			{
				daxie(arr,h);
			}
			else
			{
				;
			}
		}
		else
		{
			daxie(arr,h);
			strcat(result, "佰");
		}
		if (i == 0)
		{
			if (a + b + c + d + e + f + g + h != 0 && j != 0)
			{
				daxie(arr,i);
			}
			else
			{
				;
			}
		}
		else
		{
			daxie(arr,i);
			strcat(result, "拾");
		}
		if (j == 0)
		{
			;
		}
		else
		{
			daxie(arr,j);
		}
		if (a + b + c + d + e + f + g + h + i + j != 0)
		{
			strcat(result, "圆");
		}
		if (k == 0)
		{
			if (a + b + c + d + e + f + g + h + i + j != 0 && l != 0)
			{
				daxie(arr,k);
			}
			else
			{
				;
			}
		}
		else
		{
			daxie(arr,k);
			strcat(result, "角");
		}
		if (l == 0)
		{
			strcat(result, "整");
		}
		else
		{
			daxie(arr,l);
			strcat(result, "分");
		}
	}
    printf("%s\n", result);  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}
