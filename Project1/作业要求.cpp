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
		cout << "ĞÕÃû£º" << heroarray[i].name << " ÄêÁä£º" << heroarray[i].age << " ĞÔ±ğ£º" << heroarray[i].sex << endl;
	}
}
int main()
{
	struct hero heroarray[5] =
	{
		{"Áõ±¸",23,"ÄĞ"},
		{"ÕÅ·É",22,"ÄĞ"},
		{"¹ØÓğ",21,"ÄĞ"},
		{"ÕÔÔÆ",20,"ÄĞ"},
		{"õõ²õ",19,"Å®"},
	};
	int len = sizeof(heroarray) / sizeof(heroarray[0]);
	bubblesort(heroarray, len);
	printhero(heroarray, len);
	return 0;

	
}
