/* 2253209 ��07 ������ */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������ݹ麯�����������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
				 2����print_tower֮������������в������徲̬�ֲ�����
   ----------------------------------------------------------------------------------- */
char print_equal_sigh(int a)
{
	if (a == 0)
	{
		;
	}
	else
	{
		cout << '=';
		print_equal_sigh(a - 1);
	}

	return '=';
}
void print_line(int a,int order)
{
	if (a==order)
	{
		print_line(a, order + 1);
	}
	else if(a>order)
	{
		cout << char(65 + order);
		print_line(a, order + 1);
	}
	else if (a < order)
	{
		if (2 * a + 64 - order>=65)
		{
			cout << char(2 * a + 64 - order);
			if (2 * a + 64 - order != 65)
			{
				print_line(a, order + 1);
			}
		}
	}
}
   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡ��ĸ��
	 ���������
	 �� �� ֵ��
	 ˵    �����βΰ�������
			   ��ʾ����һ������order��ָ������/����
   ***************************************************************************/
void print_tower(int a,int order,int c)
{
	/* �����趨�����һ����̬�ֲ�������Ҳ���Բ����壩 */

	/* ����ʵ�֣������в������κ���ʽ��ѭ����������������������� */
	if (order == -1)
	{
		static int b;
		b++;
		if (a!=0)
		{
			cout << setw(b) << 'A';
		}
		if (b == c)
		{
			b = 1;
		}
		print_line(a, 1);
		cout << endl;
		if (a > 1)
		{
			print_tower(a - 1, order,c);
		}
	}
	else
	{
		if (a == 0)
		{
			;
		}
		else
		{
			cout << setw(a) << 'A';
			print_line(order, 1);
			cout << endl;
			print_tower(a - 1, order + 1,c);
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч��Ϊ����ѭ�����֣��������������) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}

	/* ��������ĸ��(����ΪA) */
	cout << print_equal_sigh(2 * (int(end_ch) - 65)) << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(A->" << end_ch << ")" << endl;
	cout << print_equal_sigh(2 * (int(end_ch) - 65)) << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(int(end_ch) - 64, 1, int(end_ch) - 64); //�����ӡ A~�����ַ� 
	cout << endl;
	
	/* ��������ĸ��(����ΪA) */
	cout << print_equal_sigh(2 * (int(end_ch) - 65)) << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(A->" << end_ch << ")" << endl;
	cout << print_equal_sigh(2 * (int(end_ch) - 65)) << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(int(end_ch) - 64, -1, int(end_ch) - 64); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ����������Ư�������Σ����ΪA�� */
	cout << print_equal_sigh(2 * (int(end_ch) - 65)) << endl;/* ����ĸ����������= */
	cout << "����(A->" << end_ch << ")" << endl;
	cout << print_equal_sigh(2 * (int(end_ch) - 65)) << endl;/* ����ĸ����������= */
	print_tower(int(end_ch) - 64, 1, int(end_ch) - 64);   //��ӡ A~�����ַ��������� 
	print_tower(int(end_ch) - 65, -1, int(end_ch) - 64);   //��ӡ A~�����ַ�-1�ĵ����� 
	cout << endl;

	return 0;
}