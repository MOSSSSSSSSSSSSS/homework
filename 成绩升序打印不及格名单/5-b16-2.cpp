// 2253209 ������ ��07
#include<iostream>
#include<cstring>
using namespace std;

void shu_ru(int cheng_ji[],string xue_hao[], string xing_ming[])
{
	for (int i = 0; i < 10; i++)
	{
		cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�" << endl;
		cin >> xue_hao[i] >> xing_ming[i] >> cheng_ji[i];
	}
}
void pai_xu(int cheng_ji[], string xue_hao[], string xing_ming[])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10 - i - 1; j++)
		{
			if (cheng_ji[j] > cheng_ji[j + 1])
			{
				int temp2=cheng_ji[j];
				cheng_ji[j] = cheng_ji[j + 1];
				cheng_ji[j + 1] = temp2;
				string temp = xue_hao[j];
				xue_hao[j] = xue_hao[j + 1];
				xue_hao[j + 1] = temp;
				temp = xing_ming[j];
				xing_ming[j] = xing_ming[j + 1];
				xing_ming[j + 1] = temp;
			}
		}
	}
}
void shu_chu(int cheng_ji[], string xue_hao[], string xing_ming[])
{
	cout << endl << "����������(�ɼ�����):" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (cheng_ji[i] <= 59)
		{
			cout << xing_ming[i] << ' ' << xue_hao[i] << ' ' << cheng_ji[i] << endl;
		}
		else
		{
			continue;
		}
	}
}
int main()
{
	int cheng_ji[10];
	string xue_hao[10], xing_ming[10];
	shu_ru(cheng_ji, xue_hao, xing_ming);
	pai_xu(cheng_ji, xue_hao, xing_ming);
	shu_chu(cheng_ji, xue_hao, xing_ming);

	return 0;
}