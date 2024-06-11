// 2253209 ������
#include<iostream>
#include<algorithm> // sort��Ҫ��ͷ�ļ�
#include<queue> // queue��Ҫ��ͷ�ļ�
#include<utility> // pair��Ҫ��ͷ�ļ�
#include<vector> // vectorͷ�ļ�
using namespace std;

const int N = 1e4;

template<class T> class movies {
private:
	int num_of_movie = 0; // ��Ӱ����
	pair<T, T>* ptr = new pair<T, T>[N]; // ÿ����Ӱ�Ŀ�ʼ�ͽ���ʱ��
public:
	void init(); // ��ʼ������
	int get_num_of_videohall(); // ������Ҫ���ٷ�ӳ��
	~movies(); // ��������
};
template<class T> void movies<T>::init()
{
	while (1)
	{
		cout << "�������Ӱ��������������";
		cin >> num_of_movie;
		if (!cin.good())
		{
			cout << "����������" << endl;
			cin.clear();
			cin.ignore(32768, '\n');
			continue;
		}
		else if (num_of_movie < 0 || num_of_movie>10000)
		{
			cout << "������[0,10000]֮�����" << endl;
			continue;
		}
		else
		{
			for (int i = 0; i < num_of_movie; i++)
			{
				cout << "�������" << i + 1 << "����Ӱ��ʼ�ͽ�����ʱ���ǣ�";
				cin >> ptr[i].first >> ptr[i].second;
				if (!cin.good())
				{
					cout << "����������" << endl;
					cin.clear();
					cin.ignore(32768, '\n');
					i--;
					continue;
				}
				else if (ptr[i].first < 0 || ptr[i].first>1000000 || ptr[i].second < 0 || ptr[i].second>1000000)
				{
					cout << "������[0,1000000]֮�����" << endl;
					i--;
					continue;
				}
				else if (ptr[i].first >= ptr[i].second)
				{
					cout << "��ʼʱ��Ӧ��С�ڽ���ʱ��" << endl;
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
	sort(ptr, ptr + num_of_movie); // ���� pair Ĭ�϶�first���򣬵�first��ͬʱ��second����
	int ans = 1;
	priority_queue<int, vector<int>, greater<int>> heap; // С���ѣ���С��������ǰ��
	heap.push(ptr[0].second); // �Ȱѵ�һ����Ӱ�Ž�ȥ
	for (int i = 1; i < num_of_movie; i++)
	{
		if (ptr[i].first < heap.top())ans++; // ����ȵ�ǰ����ʱ����С�Ķ�ҪС����Ҫ�����ӷ�ӳ��
		else heap.pop(); // �ڵ�ǰ����ʱ����С�ĵ�Ӱ���氲���ⲿ��Ӱ
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
	cout << "���ٷ�ӳ��������" << m1.get_num_of_videohall() << endl;
	
	return 0;
}