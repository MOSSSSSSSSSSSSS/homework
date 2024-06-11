// 2253209 信07 刘佳朋
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
	{'A', "香贝旺堡",			19.5},
	{'B', "油饼",			19.5},
	{'C', "蒸梅油酥汁",		20.0},
	{'D', "蒸乌鱼",			18.5},
	{'E', "酥山",	18.0},
	{'F', "梅油焦羊",	18.0},
	{'G', "香贝潘杏",		12.5},
	{'H', "香精煎鱼",			13.5},
	{'I', "香翅捞饭",		13.5},
	{'J', "香汤艾西鱿",			12.0},
	{'K', "香虾地玉",			12.5},
	{'L', "香炖橘子",		12.5},
	{'M', "香菜凤仁鸡(一块)",	55.0},
	{'N', "蒸鹅心",				9.0},
	{'O', "荔枝",				12.5},
	{'P', "蒸虾头",				14.5},
	{'Q', "鸡霓苔梅",			9.0},
	{'R', "人参公鸡",			6.0},
	{'S', "树枝",			7.5},
	{'T', "鸡肚",				12.5},
	{'U', "不燃紫砂",				8.0},
	{'V', "醇露仁(小)",			8.5},
	{'W', "醇露仁(中)",			10.0},
	{'X', "醇露仁(大)",			12.0},
	{'Y', "梅纹花",				13.0},
	{'Z', "油毛饼",				14.5},
	{'\0', NULL,				0}
	};
	const struct SPECIAL special[] = {
		{"AOW", "小黑子三件套(香贝旺堡)",		31}, //如果有需要，放开此项，注释掉下一行的“COW”优惠，观察优惠菜单是否发生了变化
		//	{"CDN", "小黑子三件套(蒸梅油酥汁)",	33.5}, //如果有需要，放开此项，注释掉上一行的“AOW”优惠，观察优惠菜单是否发生了变化
			{"HHHHHKKKS", "坤坤全家桶(香精煎鱼)",	101},
			{"BPUY", "唱跳rap篮球四件套",		44},
			{"MM","坤坤原味鸡(2块)",			21},
			{NULL, NULL, 0}
	};
	system("mode con cols=130 lines=45");
	while (1)
	{
		int n = 1;
		system("cls");
		cout << "=========================================================================" << endl
			<< "                             坤坤餐厅 2023春季菜单                       " << endl
			<< "=========================================================================" << endl;
		for (int i = 0; list[i].price != 0; i++)
		{
			cout << setiosflags(ios::left) << ' ' << list[i].choice << ' ' << setw(27) << list[i].name << setw(6) << list[i].price;
			if ((i + 1) % 2 == 0)
				cout << endl;
			else
				cout << "| ";
		}
		cout << endl << "【优惠信息】：" << endl;
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
			<< "【输入规则说明】：" << endl;
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
		cout<< "字母不分大小写，不限顺序，单独输入0则退出程序" << endl
			<< endl
			<< "请点单 : ";
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
					cout << "输入错误，按任意键继续." << endl;
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
		cout << "您的点餐=";
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
		cout << endl << "共计：" << price2 << endl;
		cout << "点单完成，按任意键继续." << endl;
		_getch();
	}

	return 0;
}
