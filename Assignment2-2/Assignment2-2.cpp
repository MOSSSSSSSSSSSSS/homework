// 2253209 刘佳朋
#include<iostream>
#include<algorithm> // sort需要的头文件
#include<queue> // queue需要的头文件
#include<utility> // pair需要的头文件
#include<vector> // vector头文件
using namespace std;

const int N = 1e4;

template<class T> class movies {
private:
	int num_of_movie = 0; // 电影部数
	pair<T, T>* ptr = new pair<T, T>[N]; // 每部电影的开始和结束时间
public:
	void init(); // 初始化函数
	int get_num_of_videohall(); // 返回需要多少放映厅
	~movies(); // 析构函数
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
template<class T> int movies<T>::get_num_of_videohall()
{
	sort(ptr, ptr + num_of_movie); // 排序， pair 默认对first升序，当first相同时对second升序
	int ans = 1;
	priority_queue<int, vector<int>, greater<int>> heap; // 小根堆，最小的数在最前面
	heap.push(ptr[0].second); // 先把第一步电影放进去
	for (int i = 1; i < num_of_movie; i++)
	{
		if (ptr[i].first < heap.top())ans++; // 如果比当前结束时间最小的都要小，就要新增加放映厅
		else heap.pop(); // 在当前结束时间最小的电影后面安排这部电影
		heap.push(ptr[i].second);
	}

	return ans;
}
template<class T> movies<T>::~movies()
{
	delete[]ptr;
}

int main()
{
	movies<int> m1;
	m1.init();
	cout << "最少放映厅数量：" << m1.get_num_of_videohall() << endl;
	
	return 0;
}