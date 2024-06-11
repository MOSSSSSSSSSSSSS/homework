// 2253209 信07 刘佳朋
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int i,j,n=0,score[1000];
	for (i = 0; i < 1000; i++)
	{
		score[i] = -1;
	}
	printf("请输入成绩（最多1000个），负数结束输入\n");
	for (i = 0; i < 1000; i++)
	{
		scanf("%d", &score[i]);
		if (score[0] < 0)
		{
			printf("无有效输入\n");
			break;
		}
		if (score[i] < 0)
		{
			break;
		}
	}
	printf("输入的数组为:\n");
	for (i = 0; i < 1000; i++)
	{
		if (score[i] >= 0)
		{
			printf("%d ", score[i]);
			n++;
			if (n % 10 == 0)
			{
				printf("\n");
			}
		}
	}
	if (n % 10 != 0)
	{
		printf("\n");
	}
	printf("分数与人数的对应关系为:\n");
	for (i = 0; i < 1000-1; i++)
	{
		for (j = 0; j < 1000 - i - 1; j++)
		{
			if (score[j] <= score[j + 1])
			{
				int temp = score[j];
				score[j] = score[j + 1];
				score[j + 1] = temp;
			}
		}
	}
	n = 1;
	for (i = 0; i < 1000; i++)
	{
		if (score[i] >= 0)
		{
			if (score[i] == score[i + 1])
			{
				n++;
			}
			else
			{
				printf("%d %d\n", score[i], n);
				n = 1;
			}
		}
		else
		{
			break;
		}
	}

	return 0;
}