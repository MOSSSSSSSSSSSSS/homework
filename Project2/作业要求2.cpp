#include<iostream>
#include<string>
using namespace std;

struct student
{
	string name;
	int score;
};
struct teacher
{
	string tname;
	struct student sarray[5];
};
void allocatespace(struct teacher tarray[],int len)
{
	string nameseed = "ABCDE";
	for (int i = 0; i < len; i++)
	{
		tarray[i].tname = "teacher_";
		tarray[i].tname += nameseed[i];
		for (int j = 0; j < 5; j++)
		{
			tarray[i].sarray[j].name = "student_";
			tarray[i].sarray[j].name += nameseed[j];
			tarray[i].sarray[j].score = 60;
		}
	}
}
void printinfo(struct teacher tarray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "老师姓名是：" << tarray[i].tname << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t学生姓名：" << tarray[i].sarray[j].name << "考试分数：" << tarray[i].sarray[j].score << endl;

		}

	}
}
int main()
{
	struct teacher tarray[3];
	int len = sizeof(tarray) / sizeof(tarray[0]);
	allocatespace(tarray, len);
	printinfo(tarray, len);



	return 0;
}