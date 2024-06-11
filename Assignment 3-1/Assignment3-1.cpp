//2253209 刘佳朋
#include<iostream>
#include<map> 
#include<vector>
using namespace std;

int main()
{
	int length = 0;
	vector<int> nums;
	bool flag = false;
	map<int, int> m;// 用map离散化
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
	for (unsigned int i = 1; i <= length; i++)
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
	for (unsigned int i = 0; i < nums.size(); i++)
	{
		if (m[nums[i]]) // 如果有相同的数
		{
			flag = true;
			break;
		}
		else
			m[nums[i]] = 1; // 如果没有，现在就有了
	}
	cout << "是否有重复元素：" << (flag ? "true" : "false");
}