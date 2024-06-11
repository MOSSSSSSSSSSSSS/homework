// 2253209 ������
#include<iostream>
#include<algorithm> // sort��Ҫ��ͷ�ļ�
#include<utility> // pair��Ҫ��ͷ�ļ�
using namespace std;

const int N = 1e4;

template<class T> class movies {
private:
	int num_of_movie = 0;
	pair<T, T>* ptr = new pair<T, T>[N]; // ÿ����Ӱ�Ŀ�ʼ�ͽ���ʱ��
	pair<T, T>* ans = new pair<T, T>[N]; // ������
public:
	void init();
	void get_new_time(); // �õ��𰸵ĺ���
	~movies();
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
template<class T> void movies<T> ::get_new_time()
{
	int idx = 0;
	sort(ptr, ptr + num_of_movie);
	ans[idx].first = ptr[0].first; // �Ȱѵ�һ����Ӱ�Ž�ȥ
	ans[idx].second = ptr[0].second; // �Ȱѵ�һ����Ӱ�Ž�ȥ
	for (int i = 1; i < num_of_movie; i++)
	{
		if(ans[idx].second < ptr[i].first) // �������ʱ��С����һ���Ŀ�ʼʱ��
		{
			idx++; // ��������Ԫ�ؼ�һ��
			ans[idx].first = ptr[i].first; 
		}
		ans[idx].second = ptr[i].second;
	}
	cout << "�ϲ����ʱ�䣺[";
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