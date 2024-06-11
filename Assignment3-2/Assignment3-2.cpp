//2253209 ������
#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
	int length = 0,k;
	vector<int> nums;
	bool flag = false; // �ж��Ƿ��з��������
	map<int, int> m; // ��map��ɢ��
	while (1)
	{
		cout << "�������鳤�ȣ�";
		cin >> length;
		if (!cin.good())
		{
			cout << "����������" << endl;
			cin.clear();
			cin.ignore(32768, '\n');
			continue;
		}
		else if (length < 1 || length>100000)
		{
			cout << "������[1,100000]֮�����" << endl;
			continue;
		}
		break;
	}
	for (int i = 1; i <= length; i++)
	{
		int num;
		while (1)
		{
			cout << "�����" << i << "������";
			cin >> num;
			if (!cin.good())
			{
				cout << "����������" << endl;
				cin.clear();
				cin.ignore(32768, '\n');
				continue;
			}
			else if (num < -1e9 || num >1e9)
			{
				cout << "������[-1e9,1e9]֮�����" << endl;
				continue;
			}
			break;
		}
		nums.push_back(num);
	}
	while (1)
	{
		cout << "����k��";
		cin >> k;
		if (!cin.good())
		{
			cout << "����������" << endl;
			cin.clear();
			cin.ignore(32768, '\n');
			continue;
		}
		else if (k < 0 || k >100000)
		{
			cout << "������[0,100000]֮�����" << endl;
			continue;
		}
		break;
	}
	for (unsigned int i = 0; i < nums.size(); i++) 
	{
		if (m[nums[i]]&&(i + 1 - m[nums[i]] <= k) ) // ����ںϷ���Χ���Ѿ�����ͬ����
		{
			m[nums[i]] = i + 1; // �����µ��±�
			flag = true;
			break;
		}
		m[nums[i]] = i + 1; // ���ԭ��û������������е����ںϷ���Χ�ҲҪ�����µ��±�
	}
	cout << "�Ƿ��о���С�ڵ���k���ظ�Ԫ�أ�" << (flag ? "true" : "false");
}