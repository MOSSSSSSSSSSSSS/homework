// 2253209 ��07 ������
#include<iostream>
#include<conio.h>
#include<iomanip> 
using namespace std;

int geshu(const char arr[],const char ch)
{
	int n = 0;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] == ch)
			n++;
	}

	return n;
}
int main() {
	struct KFC {
		char choice;
		char name[25];
		double price;
	};
	struct SPECIAL {
		char choice[15];
		char name[25];
		double price;
	};
	const struct KFC list[] = {
	{'A', "�㱴����",			19.5},
	{'B', "�ͱ�",			19.5},
	{'C', "��÷����֭",		20.0},
	{'D', "������",			18.5},
	{'E', "��ɽ",	18.0},
	{'F', "÷�ͽ���",	18.0},
	{'G', "�㱴����",		12.5},
	{'H', "�㾫����",			13.5},
	{'I', "����̷�",		13.5},
	{'J', "����������",			12.0},
	{'K', "��Ϻ����",			12.5},
	{'L', "��������",		12.5},
	{'M', "��˷��ʼ�(һ��)",	55.0},
	{'N', "������",				9.0},
	{'O', "��֦",				12.5},
	{'P', "��Ϻͷ",				14.5},
	{'Q', "����̦÷",			9.0},
	{'R', "�˲ι���",			6.0},
	{'S', "��֦",			7.5},
	{'T', "����",				12.5},
	{'U', "��ȼ��ɰ",				8.0},
	{'V', "��¶��(С)",			8.5},
	{'W', "��¶��(��)",			10.0},
	{'X', "��¶��(��)",			12.0},
	{'Y', "÷�ƻ�",				13.0},
	{'Z', "��ë��",				14.5},
	{'\0', NULL,				0}
	};
	const struct SPECIAL special[] = {
		{"AOW", "С����������(�㱴����)",		31}, //�������Ҫ���ſ����ע�͵���һ�еġ�COW���Żݣ��۲��Żݲ˵��Ƿ����˱仯
		//	{"CDN", "С����������(��÷����֭)",	33.5}, //�������Ҫ���ſ����ע�͵���һ�еġ�AOW���Żݣ��۲��Żݲ˵��Ƿ����˱仯
			{"HHHHHKKKS", "����ȫ��Ͱ(�㾫����)",	101},
			{"BPUY", "����rap�����ļ���",		44},
			{"MM","����ԭζ��(2��)",			21},
			{NULL, NULL, 0}
	};
	system("mode con cols=130 lines=45");
	while (1)
	{
		int n = 1;
		system("cls");
		cout << "=========================================================================" << endl
			<< "                             �������� 2023�����˵�                       " << endl
			<< "=========================================================================" << endl;
		for (int i = 0; list[i].price != 0; i++)
		{
			cout << setiosflags(ios::left) << ' ' << list[i].choice << ' ' << setw(27) << list[i].name << setw(6) << list[i].price;
			if ((i + 1) % 2 == 0)
				cout << endl;
			else
				cout << "| ";
		}
		cout << endl << "���Ż���Ϣ����" << endl;
		for (int i = 0; special[i].price != 0; i++)
		{
			cout << special[i].name << '=';
			for (int j = 1; special[i].choice[j - 1]!='\0'; j++)
			{
				if (special[i].choice[j] == special[i].choice[j - 1])
				{
					n++;
				}
				else
				{
					for (int k = 0; k < 26; k++)
					{
						if (special[i].choice[j - 1] == list[k].choice)
						{
							cout << list[k].name;
							if (n != 1)
							{
								cout << '*' << n;
								n = 1;
							}
							if (special[i].choice[j] != '\0')
								cout << '+';
							else
								cout << '=' << special[i].price << endl;
						}
					}
				}
			}
		}
		cout << endl
			<< "���������˵������" << endl;
		for (int i = 0; special[2].choice[i]!='\0'; i++)
		{
			cout << special[2].choice[i];
		}
		cout << '=';
		for (int j = 1; special[2].choice[j - 1] != '\0'; j++)
		{
			if (special[2].choice[j] == special[2].choice[j - 1])
			{
				n++;
			}
			else
			{
				for (int k = 0; k < 26; k++)
				{
					if (special[2].choice[j - 1] == list[k].choice)
					{
						cout << list[k].name;
						if (n != 1)
						{
							cout << '*' << n;
							n = 1;
						}
						if (special[2].choice[j] != '\0')
							cout << '+';
					}
				}
			}
		}
		cout <<" / ";
		for (int i = 0; special[3].choice[i] != '\0'; i++)
		{
			cout << char(special[3].choice[i]-'A'+'a');
		}
		cout << '=';
		for (int j = 1; special[3].choice[j - 1] != '\0'; j++)
		{
			if (special[3].choice[j] == special[3].choice[j - 1])
			{
				n++;
			}
			else
			{
				for (int k = 0; k < 26; k++)
				{
					if (special[3].choice[j - 1] == list[k].choice)
					{
						cout << list[k].name;
						if (n != 1)
						{
							cout << '*' << n;
							n = 1;
						}
						if (special[3].choice[j] != '\0')
							cout << '+';
					}
				}
			}
		}
		cout << endl;
		cout<< "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl
			<< endl
			<< "��㵥 : ";
		char arr[4095] = { 0 };
		fgets(arr, 4095, stdin);
		bool z = 1;
		for (int i = 0; arr[i] != 10; i++)
		{
			if (!(arr[i] >= 'a' && arr[i] <= 'z' || arr[i] >= 'A' && arr[i] <= 'Z'))
			{
				if (arr[0] == '0' && arr[1] == 10)
				{
					return 0;
				}
				else
				{
					cout << "������󣬰����������." << endl;
					z = 0;
					_getch();
					break;
				}
			}
		}
		if (!z||arr[0]==10)
			continue;
		int num[26] = { 0 };
		for (int i = 0;arr[i]!=10; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (arr[i] == list[j].choice||arr[i]== list[j].choice-'A'+'a')
				{
					num[j]++;
					break;
				}
			}
		}
		cout << "���ĵ��=";
		bool x;
		for (int i = 0;i<26; i++)
		{
			if (num[i] != 0)
			{
				cout << list[i].name;
				if (num[i] != 1)
					cout << '*' << num[i];
				for (int j = i + 1; j < 26; j++)
				{
					if (num[j] != 0)
					{
						x = 1;
						break;
					}
					else
					{
						x = 0;
					}
				}
				if (x)
					cout << '+';
			}
		}
		bool y;
		double price2 = 0;
		for (int i = 0;special[i].price!=0; i++)
		{
			for (int j = 0;special[i].choice[j]!='\0'; j++)
			{
				if (num[special[i].choice[j] - 'A'] <geshu(special[i].choice,special[i].choice[j]))
				{
					y = 0;
					break;
				}
				else
				{
					y = 1;
				}
			}
			if (y)
			{
				price2 += special[i].price;
				for (int j = 0; special[i].choice[j] != '\0'; j++)
				{
					num[special[i].choice[j] - 'A']--;
				}
				i--;
			}
		}
		for (int i = 0; i < 26; i++)
			price2 += (num[i] * list[i].price);
		cout << endl << "���ƣ�" << price2 << endl;
		cout << "�㵥��ɣ������������." << endl;
		_getch();
	}

	return 0;
}
