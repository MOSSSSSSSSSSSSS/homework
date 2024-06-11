// 2253209 刘佳朋
#include<iostream>
#include<algorithm> // sort需要的头文件
#include<utility>  // pair需要的头文件
using namespace std;

const int N = 1e4;

template<class T> class movies {
private:
	int num_of_movie = 0; // 电影的数量
	pair<T, T>* ptr = new pair<T, T>[N]; // 每部电影的开始结束时间
public:
	void init(); // 初始化函数
	bool judge(); // 判断能不能看完全部的函数
	~movies(); // 析构函数delete堆中的空间
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
			cin.ignore(32768,'\n');
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
				cout << "请输入第"<<i+1<<"部电影开始和结束的时间标记：";
				cin >> ptr[i].first >> ptr[i].second;
				if (!cin.good())
				{
					cout << "请输入数字" << endl;
					cin.clear();
					cin.ignore(32768, '\n');
					i--;
					continue;
				}
				else if (ptr[i].first<0|| ptr[i].first>1000000|| ptr[i].second<0|| ptr[i].second>1000000)
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
template<class T> bool movies<T>::judge()
{
	sort(ptr, ptr + num_of_movie); // 先排序， pair 默认对first升序，当first相同时对second升序
	for (int i = 0; i < num_of_movie-1; i++)
		if (ptr[i].second > ptr[i + 1].first)
			return false; // 如果有一部电影的开始时间和上一部电影的结束时间重合就不可以
	return true;
}
template<class T> movies<T>::~movies()
{
	delete[]ptr;
}

int main()
{
	movies<int> m1;
	m1.init();
	cout << "能否看完全部：";
	if (m1.judge())cout << "true" << endl;
	else cout << "false" << endl;

	return 0;
}