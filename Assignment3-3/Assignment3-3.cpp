//2253209 ������
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int length = 0, indexDiff, valueDiff;
	vector<int> nums;
	bool flag = false; // �ж��Ƿ��������
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
		else if (length < 2 || length>100000)
		{
			cout << "������[2,100000]֮�����" << endl;
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
		cout << "����indexDiff��";
		cin >> indexDiff;
		if (!cin.good())
		{
			cout << "����������" << endl;
			cin.clear();
			cin.ignore(32768, '\n');
			continue;
		}
		else if (indexDiff < 1 || indexDiff >length)
		{
			cout << "������[1,length]֮�����" << endl;
			continue;
		}
		break;
	}
	while (1)
	{
		cout << "����valueDiff��";
		cin >> valueDiff;
		if (!cin.good())
		{
			cout << "����������" << endl;
			cin.clear();
			cin.ignore(32768, '\n');
			continue;
		}
		else if (valueDiff < 0 || valueDiff >1e9)
		{
			cout << "������[0,1e9]֮�����" << endl;
			continue;
		}
		break;
	}
	for (unsigned i = 0; i < nums.size(); i++) // ����ÿһ����
	{
		for (int j = i - indexDiff; j <= i + indexDiff; j++) // ��indexdiff��Χ�б���ÿһ����
		{
			if (j!=i&&j >= 0 && j < nums.size()&& abs(nums[j] - nums[i]) <= valueDiff) // ����з��������
			{
				flag = true; // ��
				break; // ֱ���˳�
			}
		}
		if (flag)break;
	}
	cout << "�Ƿ��о���С�ڵ���indexdiff�Ҵ�С�Ĳ�ľ���ֵС�ڵ���valuediffԪ�أ�" << (flag ? "true" : "false");
}