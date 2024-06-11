/* 2253209 ��07 ������ */

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include<iomanip>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//�����ļ�������󳤶�

/* stu_metge ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_merge {
private:
	int  stu_no;					//ѧ��
	char stu_name[MAX_NAME_LEN];  //����
	friend class stu_list;
	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */

public:
	//���಻�������κεĹ������ݳ�Ա����Ա����
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//��һ��ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_1;						//��һ��ѡ�ε�ѧ������

	student list_round_2[MAX_STU_NUM];	//�ڶ���ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_2;						//�ڶ���ѡ�ε�ѧ������

	stu_merge list_merge[MAX_STU_NUM];	//�ϲ����ѧ��������ȥ�أ����������У�
	int list_merge_num;					//�ϲ����ѧ��������Ŀǰ����ӡ�����������ڲ������������Ҫ��Ҳ��Ҫɾ����

	/* ���������private���ݳ�Ա�ͳ�Ա����
	   ע�⣬���������array / set / map / vector��STL���� */

public:
	stu_list();										//���캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
	int read(const char* filename, const int round);	//���ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
	int print(const char* prompt = NULL);				//��ӡ���յ�ѡ������
	void he_bing();
	void qu_chong();
	void pai_xu();
	/* �������������public��Ա��������ʾ���ϲ���ȥ�ء�����ȣ�
	   �������幫�е����ݳ�Ա
	   �������ڳ�Ա������ʹ��array / set / map / vector��STL���� */

};

/* --- ������Ը���stu_merge/stu_list������ĳ�Ա����������ʵ�� --- */
void stu_list::pai_xu()
{
	for (int i = 0; i < list_merge_num - 1; i++)
	{
		for (int j = 0; j < list_merge_num - i - 1; j++)
		{
			if (list_merge[j].stu_no > list_merge[j + 1].stu_no)
			{
				stu_merge temp = list_merge[j ];
				list_merge[j ] = list_merge[j + 1];
				list_merge[j + 1 ] = temp;
			}
		}
	}
}
void stu_list::qu_chong()
{
	for (int i = 0; list_merge[i].stu_no >= 0; i++)
	{
		for (int j = i + 1; list_merge[j].stu_no >= 0&&list_merge[i].stu_no>0; j++)
		{
			if (list_merge[i].stu_no == list_merge[j].stu_no)
				list_merge[j].stu_no = 0;
			else
				continue;
		}
	}
	list_merge_num = 0;
	for (int i = 0; list_merge[i].stu_no >= 0;i++)
	{
		if (list_merge[i].stu_no >= 0)
			list_merge_num++;
		else
			continue;
	}
}
void stu_list::he_bing()
{
	int i;
	for (i = 0; list_round_1[i].no>0; i++)
	{
		list_merge[i].stu_no = list_round_1[i].no;
		strcpy(list_merge[i].stu_name, list_round_1[i].name);
	}
	for (int j = 0; list_round_2[j].no > 0; j++)
	{
		list_merge[i+j].stu_no = list_round_2[j].no;
		strcpy(list_merge[i+j].stu_name, list_round_2[j].name);
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
  ���������
  �� �� ֵ��
  ˵    �������캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
***************************************************************************/
stu_list::stu_list()
{
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��̬���ӿ��ʹ�ã��������е��þ�̬���ӿ��е�Ԥ�ú���
  ���������
  �� �� ֵ��
  ˵    ��������������Ҫ�޸� 
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* ��ȡ��1/2�ֵ�ѡ����������ӡ */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("��һ��ѡ��������", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("�ڶ���ѡ��������", this->list_round_2, this->list_num_2);
			else
				ret = -1;
			break;
		default:
			ret = -1;
			break;
	}

	return ret;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ������ӡ���յ�ѡ������
***************************************************************************/
int stu_list::print(const char* prompt)
{
	cout << "����ѡ������" << endl;
	cout << "============================================================" << endl;
	cout << "��� ѧ��     ����                            ��һ�� �ڶ��� " << endl;
	cout << "============================================================" << endl;
	int i;
	for (i = 0;; i++)
	{
		if (list_merge[i].stu_no > 0)
			break;
		else
			continue;
	}
	for (int j = i;list_merge[j].stu_no>0; j++)
	{
		int pan_duan = 0, pan_duan2 = 0;
		cout << setiosflags(ios::left) << setw(5) << j - i + 1 << setw(9) << list_merge[j].stu_no << setw(32) << list_merge[j].stu_name;
		for (int k = 0; list_round_1[k].no>0; k++)
		{
			if (list_round_1[k].no == list_merge[j].stu_no)
			{
				pan_duan = 1;
				break;
			}
			else
				continue;
		}
		if (pan_duan)
			cout << setw(7) << 'Y';
		else
			cout << setw(7) << '/';
		for (int k = 0; list_round_2[k].no > 0; k++)
		{
			if (list_round_2[k].no == list_merge[j].stu_no)
			{
				pan_duan2 = 1;
				break;
			}
			else
				continue;
		}
		if (pan_duan2&&pan_duan)
			cout << setw(7) << 'Y';
		else if(!pan_duan&&pan_duan2)
			cout << setw(7) << "��ѡ";
		else
			cout<< setw(7) << "�˿�";
		cout << endl;
	}
	cout << "============================================================" << endl;

	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	gets_s(file1); //cin���ܶ��пո���ļ�

	cout << "�������һ��ѡ�ε������ļ� : ";
	gets_s(file2);

	stu_list list;

	/* �������� */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* �������� */
	list.he_bing();
	list.qu_chong();
	list.pai_xu();
	/* ��ӡ */
	list.print("����ѡ������");

	return 0;
}

