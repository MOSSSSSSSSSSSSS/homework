/* 2253209 ������ ��07 */
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], *p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	is_num = 0;
	cout << "�����������������������ֵ��ַ���" << endl;
	gets_s(str);
	p = str;
	pa = a;
	for (pa = a; *p != '\0'; p++)
	{
		if ('0' <= *p && *p <= '9')
		{
			if ('1' <= *p && *p <= '9')
			{
				*pa = *pa * 10 + *p-'0';
				is_num = 1;
			}
			else
			{
				if (is_num)
				{
					*pa = *pa * 10 ;
					is_num = 1;
				}
				else
				{
					is_num = 0;
				}
			}
		}
		else
		{
			if ('0' <= *(p-1) && *(p-1) <= '9')
			{
				if (pa - a == 9)
				{
					break;
				}
				pa++;
				is_num = 0;
			}
		}
	}
	cout << "����" << ((*--p >= '0' && *p <= '9') ? (++pa - a) : (pa - a)) << "������" << endl;
	pnum = pa;
	for (pa = a;pa<pnum; pa++)
	{
		cout << *pa << ' ';
	}
	cout << endl; 
	return 0;
}
