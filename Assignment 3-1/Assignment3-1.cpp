//2253209 ������
#include<iostream>
#include<map> 
#include<vector>
using namespace std;

int main()
{
	int length = 0;
	vector<int> nums;
	bool flag = false;
	map<int, int> m;// ��map��ɢ��
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
	for (unsigned int i = 1; i <= length; i++)
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
	for (unsigned int i = 0; i < nums.size(); i++)
	{
		if (m[nums[i]]) // �������ͬ����
		{
			flag = true;
			break;
		}
		else
			m[nums[i]] = 1; // ���û�У����ھ�����
	}
	cout << "�Ƿ����ظ�Ԫ�أ�" << (flag ? "true" : "false");
}