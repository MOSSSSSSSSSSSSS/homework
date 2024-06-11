// 2253209 刘佳朋
#include<iostream>
#include<algorithm> // sort需要的头文件
#include<utility> // pair需要的头文件
using namespace std;

const int N = 1e4;

template<class T> class movies {
private:
	int num_of_movie = 0;
	pair<T, T>* ptr = new pair<T, T>[N]; // 每部电影的开始和结束时间
	pair<T, T>* ans = new pair<T, T>[N]; // 答案数组
public:
	void init();
	void get_new_time(); // 得到答案的函数
	~movies();
};
template<class T> void movies<T>::init()
{
	while (1)
	{
		cout << "请输入电影部数（整数）：";
		cin >> num_of_movie;
		if (!cin.good())
		{
			cout << "请输入数字" << endl;
			cin.clear();
			cin.ignore(32768, '\n');
			continue;
		}
		else if (num_of_movie < 0 || num_of_movie>10000)
		{
			cout << "请输入[0,10000]之间的数" << endl;
			continue;
		}
		else
		{
			for (int i = 0; i < num_of_movie; i++)
			{
				cout << "请输入第" << i + 1 << "部电影开始和结束的时间标记：";
				cin >> ptr[i].first >> ptr[i].second;
				if (!cin.good())
				{
					cout << "请输入数字" << endl;
					cin.clear();
					cin.ignore(32768, '\n');
					i--;
					continue;
				}
				else if (ptr[i].first < 0 || ptr[i].first>1000000 || ptr[i].second < 0 || ptr[i].second>1000000)
				{
					cout << "请输入[0,1000000]之间的数" << endl;
					i--;
					continue;
				}
				else if (ptr[i].first >= ptr[i].second)
				{
					cout << "开始时间应该小于结束时间" << endl;
					i--;
					continue;
				}
			}
			break;
		}
	}
} 
template<class T> void movies<T> ::get_new_time()
{
	int idx = 0;
	sort(ptr, ptr + num_of_movie);
	ans[idx].first = ptr[0].first; // 先把第一部电影放进去
	ans[idx].second = ptr[0].second; // 先把第一部电影放进去
	for (int i = 1; i < num_of_movie; i++)
	{
		if(ans[idx].second < ptr[i].first) // 如果结束时间小于下一部的开始时间
		{
			idx++; // 答案数组中元素加一个
			ans[idx].first = ptr[i].first; 
		}
		ans[idx].second = ptr[i].second;
	}
	cout << "合并后的时间：[";
	for (int i = 0; i <= idx; i++)
		cout << '[' << ans[i].first << ',' << ans[i].second << ']';
	cout << ']' << endl;
}
template<class T> movies<T>::~movies()
{
	delete[]ptr;
	delete[]ans;
}

int main()
{
	movies<int> m1;
	m1.init();
	m1.get_new_time();

	return 0;
}