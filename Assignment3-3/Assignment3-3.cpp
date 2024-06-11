//2253209 刘佳朋
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int length = 0, indexDiff, valueDiff;
	vector<int> nums;
	bool flag = false; // 判断是否符合题意
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
		else if (length < 2 || length>100000)
		{
			cout << "请输入[2,100000]之间的数" << endl;
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
		cout << "输入indexDiff：";
		cin >> indexDiff;
		if (!cin.good())
		{
			cout << "请输入数字" << endl;
			cin.clear();
			cin.ignore(32768, '\n');
			continue;
		}
		else if (indexDiff < 1 || indexDiff >length)
		{
			cout << "请输入[1,length]之间的数" << endl;
			continue;
		}
		break;
	}
	while (1)
	{
		cout << "输入valueDiff：";
		cin >> valueDiff;
		if (!cin.good())
		{
			cout << "请输入数字" << endl;
			cin.clear();
			cin.ignore(32768, '\n');
			continue;
		}
		else if (valueDiff < 0 || valueDiff >1e9)
		{
			cout << "请输入[0,1e9]之间的数" << endl;
			continue;
		}
		break;
	}
	for (unsigned i = 0; i < nums.size(); i++) // 遍历每一个数
	{
		for (int j = i - indexDiff; j <= i + indexDiff; j++) // 在indexdiff范围中遍历每一个数
		{
			if (j!=i&&j >= 0 && j < nums.size()&& abs(nums[j] - nums[i]) <= valueDiff) // 如果有符合题意的
			{
				flag = true; // 有
				break; // 直接退出
			}
		}
		if (flag)break;
	}
	cout << "是否有距离小于等于indexdiff且大小的差的绝对值小于等于valuediff元素：" << (flag ? "true" : "false");
}