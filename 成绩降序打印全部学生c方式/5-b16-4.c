// 2253209 刘佳朋 信07
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void shu_ru(int cheng_ji[], char xing_ming[][9], char xue_hao[][8])
{
	for (int i = 0; i < 10; i++)
	{
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s %s %d", xue_hao[i], xing_ming[i], &cheng_ji[i]);
	}
}
void pai_xu(int cheng_ji[], char xing_ming[][9], char xue_hao[][8])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10 - i - 1; j++)
		{
			if (cheng_ji[j]<cheng_ji[j+1])
			{
				char temp[9];
				int temp2;
				for (int k = 0; k < 8; k++)
				{
					temp[k] = xue_hao[j][k];
					xue_hao[j][k] = xue_hao[j + 1][k];
					xue_hao[j + 1][k] = temp[k];
				}
				for (int k = 0; k < 9; k++)
				{
					temp[k] = xing_ming[j][k];
					xing_ming[j][k] = xing_ming[j + 1][k];
					xing_ming[j + 1][k] = temp[k];
				}
				temp2 = cheng_ji[j];
				cheng_ji[j] = cheng_ji[j + 1];
				cheng_ji[j + 1] = temp2;
			}
		}
	}
}
void shu_chu(int cheng_ji[], char xing_ming[][9], char xue_hao[][8])
{
	printf("\n全部学生(成绩降序):\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%s %s %d\n", xing_ming[i], xue_hao[i], cheng_ji[i]);
	}
}
int main()
{
	int cheng_ji[10];
	char xing_ming[10][9], xue_hao[10][8];
	shu_ru(cheng_ji, xing_ming, xue_hao);
	pai_xu(cheng_ji, xing_ming, xue_hao);
	shu_chu(cheng_ji, xing_ming, xue_hao);

	return 0;
}