//2253209 刘佳朋
#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
	int length = 0,k;
	vector<int> nums;
	bool flag = false; // 判断是否有符合题意的
	map<int, int> m; // 用map离散化
	while (1)
	{
		cout << "输入数组长度：";
		cin >> length;
		if (!cin.good())
		{
			cout << "请输入数字" << endl;
			cin.clear();
			cin.ignore(32768, '\n');
			continue;
		}
		else if (length < 1 || length>100000)
		{
			cout << "请输入[1,100000]之间的数" << endl;
			continue;
		}
		break;
	}
	for (int i = 1; i <= length; i++)
	{
		int num;
		while (1)
		{
			cout << "输入第" << i << "个数：";
			cin >> num;
			if (!cin.good())
			{
				cout << "请输入数字" << endl;
				cin.clear();
				cin.ignore(32768, '\n');
				continue;
			}
			else if (num < -1e9 || num >1e9)
			{
				cout << "请输入[-1e9,1e9]之间的数" << endl;
				continue;
			}
			break;
		}
		nums.push_back(num);
	}
	while (1)
	{
		cout << "输入k：";
		cin >> k;
		if (!cin.good())
		{
			cout << "请输入数字" << endl;
			cin.clear();
			cin.ignore(32768, '\n');
			continue;
		}
		else if (k < 0 || k >100000)
		{
			cout << "请输入[0,100000]之间的数" << endl;
			continue;
		}
		break;
	}
	for (unsigned int i = 0; i < nums.size(); i++) 
	{
		if (m[nums[i]]&&(i + 1 - m[nums[i]] <= k) ) // 如果在合法范围里已经有相同的数
		{
			m[nums[i]] = i + 1; // 更新新的下标
			flag = true;
			break;
		}
		m[nums[i]] = i + 1; // 如果原来没有这个数或者有但不在合法范围里，也要更新新的下标
	}
	cout << "是否有距离小于等于k的重复元素：" << (flag ? "true" : "false");
}