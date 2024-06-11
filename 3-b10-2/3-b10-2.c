/* 信07 2253209 刘佳朋*/
#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int n = 0;
	for (int a = 1; a <= 5; a++)
	{
		for (int b = 1; b <= 9; b++)
		{
			for (int c = 1; c <= 9; c++)
			{
				for (int d = 5; d <= 8; d++)
				{
					for (int g = 7; g <= 9; g++)
					{
						for (int e = 1; e <= 9; e++)
						{
							for (int h = 1; h <= 9; h++)
							{
								for (int f = 1; f <= 9; f++)
								{
									for (int i = 1; i <= 9; i++)
									{
										if (a != b && a != c && a != d && a != e && a != f && a != g && a != h && a != i && b != c && b != d && b != e && b != f && b != g && b != h && b != i && c != d && c != e && c != f && c != g && c != h && c != i && d != e && d != f && d != g && d != h && d != i && e != f && e != g && e != h && e != i && f != g && f != h && f != i && g != h && g != i && h != i && a * 100 + b * 10 + c + d * 100 + e * 10 + f + g * 100 + h * 10 + i == 1953 && d < g)
										{
											n++;
											printf("No.%3d : %d%d%d+%d%d%d+%d%d%d=1953\n", n, a, b, c, d, e, f, g, h, i);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("total=%d\n", n);

	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}