#include<iostream>
#include<string>
using namespace std;

struct hero
{
	string name;
	int age;
	string sex;
};
void bubblesort(struct hero heroarray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (heroarray[j].age >heroarray[j + 1].age)
			{
				struct hero temp = heroarray[j];
				heroarray[j] = heroarray[j + 1];
				heroarray[j + 1] = temp;
			}
		}
	}
}
void printhero(struct hero heroarray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "������" << heroarray[i].name << " ���䣺" << heroarray[i].age << " �Ա�" << heroarray[i].sex << endl;
	}
}
int main()
{
	struct hero heroarray[5] =
	{
		{"����",23,"��"},
		{"�ŷ�",22,"��"},
		{"����",21,"��"},
		{"����",20,"��"},
		{"����",19,"Ů"},
	};
	int len = sizeof(heroarray) / sizeof(heroarray[0]);
	bubblesort(heroarray, len);
	printhero(heroarray, len);
	return 0;

	
}
