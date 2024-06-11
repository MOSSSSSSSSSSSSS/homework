// 2253209 ������
#include<iostream>
#include<algorithm> // sort��Ҫ��ͷ�ļ�
#include<utility>  // pair��Ҫ��ͷ�ļ�
using namespace std;

const int N = 1e4;

template<class T> class movies {
private:
	int num_of_movie = 0; // ��Ӱ������
	pair<T, T>* ptr = new pair<T, T>[N]; // ÿ����Ӱ�Ŀ�ʼ����ʱ��
public:
	void init(); // ��ʼ������
	bool judge(); // �ж��ܲ��ܿ���ȫ���ĺ���
	~movies(); // ��������delete���еĿռ�
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
			cin.ignore(32768,'\n');
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
				cout << "�������"<<i+1<<"����Ӱ��ʼ�ͽ�����ʱ���ǣ�";
				cin >> ptr[i].first >> ptr[i].second;
				if (!cin.good())
				{
					cout << "����������" << endl;
					cin.clear();
					cin.ignore(32768, '\n');
					i--;
					continue;
				}
				else if (ptr[i].first<0|| ptr[i].first>1000000|| ptr[i].second<0|| ptr[i].second>1000000)
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
template<class T> bool movies<T>::judge()
{
	sort(ptr, ptr + num_of_movie); // ������ pair Ĭ�϶�first���򣬵�first��ͬʱ��second����
	for (int i = 0; i < num_of_movie-1; i++)
		if (ptr[i].second > ptr[i + 1].first)
			return false; // �����һ����Ӱ�Ŀ�ʼʱ�����һ����Ӱ�Ľ���ʱ���غϾͲ�����
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
	cout << "�ܷ���ȫ����";
	if (m1.judge())cout << "true" << endl;
	else cout << "false" << endl;

	return 0;
}