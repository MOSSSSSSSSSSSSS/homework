#include <iostream>
#include<climits>

// �õ�һ��[ minNum��maxNum ]�����֣������������������֤��׳��
int getint(const int minNum = INT_MIN, const int maxNum = INT_MAX, const std::string errorTips = "")
{
	int retNum = INT_MIN;
	while (1)
	{
		std::cin >> retNum;
		if (std::cin.fail() || retNum < minNum || retNum > maxNum) // ������������Ͳ�ͬ�����ֲ���Ҫ��Χ��
		{
			std::cin.clear();
			std::cin.ignore(1024, '\n');                           // ���������
			std::cout << errorTips;                                // ���������������ʾ
			continue;
		}
		break;
	}
	return retNum;
}


// ��
struct Edge
{
	Edge()
	{
		src = dst = -1;
		value = 0;
	}
	int src;          // ��ʼ����  
	int dst;          // Ŀ������
	double value;     // �߳���Ȩ��
	bool operator<(const Edge& other) { return value < other.value; };// ����С�ڱȽ������
	bool operator>(const Edge& other) { return value > other.value; };// ���ش��ڱȽ������
};

// ��
struct Vertex
{
	Vertex()
	{
		name = "";
		ancestor = -1;
	}
	std::string name;
	int ancestor;          // ��¼�ڲ��鼯�е�����
};

// ��ģ��ʵ���Ż���Ŀ���������������Ϊ[l,r]
template<typename T>
void QuickSort(T a[], int l, int r)
{
	if (l > r)
		return;
	T mid = a[(l + r) / 2];      // ȡ�м�Ԫ��
	int i = l, j = r;
	while (i < j)
	{
		while (a[i] < mid) i++;  // ������벿�ֱ��м��������
		while (a[j] > mid) j--;  // �����Ұ벿�ֱ��м���С����
		if (i <= j)              // �����һ�鲻����������������С�Ҵ󣩵���
		{
			std::swap(a[i], a[j]);    // ����
			i++;
			j--;
		}
	}
	if (l < j) QuickSort(a, l, j);// �ݹ�������벿��
	if (i < r) QuickSort(a, i, r);// �ݹ������Ұ벿��
}

class Graph
{
	template<typename T>
	friend void QuickSort(T a[], int l, int r);
public:
	// ���캯��
	Graph(int n = 0, int m = 0) :vertexNumber(n), edgeNumber(m)
	{
		vertexs = NULL, edges = NULL;
		MST = NULL;
		vertexs = new Vertex[n]; edges = new Edge[m];
	}

	// ��������
	~Graph()
	{
		// �ֱ��ͷ���С��������������Ͷ��������ڴ棬�����ڴ�й¶
		delete[]edges;
		delete[]vertexs;
		delete MST;
	}

	// Kruskal�㷨�����С������������Ϣ�洢��MST
	bool Kruskal()
	{
		// ������������[0,edgeNumber - 1]
		QuickSort(edges, 0, edgeNumber - 1);

		// ɾ��ԭ����MST��Ϣ
		delete MST;
		MST = NULL;

		// ΪMST����ռ�
		MST = new Graph(vertexNumber, vertexNumber - 1);

		// cnt��¼��ѡ������
		int cnt = 0;
		for (int i = 0; i < edgeNumber; i++)
		{
			int f1 = FindAncestor(edges[i].src); // f1Ϊ����������
			int f2 = FindAncestor(edges[i].dst); // f2Ϊ���յ������

			// ���������Ȳ�ͬ���������ͬ����ͨ��֧����Ҫ�ϲ������˱߼�����С������
			if (f1 != f2)
			{
				cnt++;                     // ��ѡ����+1
				vertexs[f1].ancestor = f2; // f1����������Ϊf2����������ͬһ����ͨ��֧
				MST->edges[cnt - 1] = edges[i];
			}
			if (cnt == vertexNumber - 1)   // ����С����������ѡ����=������-1ʱ����С�������������
			{
				std::cout << std::endl;
				return true;
			}
		}
		// ��δ��ѡ��vertexNumber-1���ߣ����ܹ�����С������
		delete MST;
		MST = NULL;
		std::cout << std::endl;
		return false;

	}

	// ��ʼ��������Ϣ
	void InitVertex()
	{
		// ��ͼ����
		MakeEmpty();

		// ��ʼ����������
		std::cout << "�����붥��ĸ�����";
		vertexNumber = getint(1, 1024, "���������1-1024�����֣����������룺");
		vertexs = new Vertex[vertexNumber];

		// ���ö�������
		std::cout << "�������������������ƣ�" << std::endl;
		for (int i = 0; i < vertexNumber; ++i)
		{
			std::string vertexName;
			std::cin >> vertexName;
			// �ж������Ƿ��Ѵ���
			if (SearchVertex(vertexName) != -1)
			{
				// ���Ѿ����ڣ�����������
				std::cout << "����" << vertexName << "�Ѵ��ڣ����������룺";
				i--;
			}
			// ��ʼ�����鼯����Ϊ�Լ�
			else
			{
				vertexs[i].name = vertexName;
				vertexs[i].ancestor = i;
			}
		}
	}

	// ��ʼ������Ϣ
	void InitEdge()
	{
		// ɾ��ԭ���ı߼���Ϣ
		delete[]edges;

		std::cin.clear();
		std::cin.ignore(1024, '\n');                           // ���������

		// ������Ŀ��Ϣ��������� n*(n-1)/2 ��
		std::cout << "������ߵ���Ŀ��";
		edgeNumber = getint(1, vertexNumber * (vertexNumber - 1) / 2, "������Ŀ��Ϣ��������� n*(n-1)/2 �������������룺");
		edges = new Edge[edgeNumber];

		// ����߼���Ϣ��ͨ��getint���������˴������룬��֤�˽�׳��
		std::cout << "����������" << edgeNumber << "���ߵ���㡢�յ㡢Ȩ�أ�" << std::endl;

		for (int i = 0; i < edgeNumber; i++)
		{
			// ��������յ�
			std::cout << "�������" << i + 1 << "���ߵ���Ϣ��";
			std::string src, dst;
			double value;
			std::cin >> src >> dst;
			edges[i].src = SearchVertex(src);
			edges[i].dst = SearchVertex(dst);
			// ��Ϣ�쳣����
			if (edges[i].src == -1 || edges[i].dst == -1)
			{
				std::cout << "����Ϣ����������������룺" << std::endl;
				std::cin.clear();
				std::cin.ignore(1024, '\n');                           // ���������
				i--;
				continue;
			}

			// ���ñ�Ȩ
			std::cin >> value;
			// ��Ϣ�쳣����
			if (std::cin.fail() || value <= 0)
			{
				std::cout << "����Ϣ����������������룺" << std::endl;
				std::cin.clear();
				std::cin.ignore(1024, '\n');                           // ���������
				i--;
				continue;
			}
			edges[i].value = value;
		}
	}

	// ��ӡ��С������
	void printMST()
	{
		// δ���ɳɹ�
		if (MST == NULL)
		{
			std::cout << "δ������С���������������ɣ�" << std::endl << std::endl;
			return;
		}


		// ���ɳɹ�
		std::cout << "��С��������Ϣ���£�" << std::endl;
		// ���MST�е���Ϣ
		for (int i = 0; i < MST->edgeNumber; i++)
			std::cout << "ѡ����Ϣ�����<" << vertexs[MST->edges[i].src].name << ">  �յ�<" << vertexs[MST->edges[i].dst].name << ">  Ȩֵ��" << MST->edges[i].value << std::endl;

		std::cout << std::endl;

	}


private:
	// ��ͼ����
	void MakeEmpty()
	{
		vertexNumber = 0, edgeNumber = 0;
		if (edges != NULL)	delete[]edges;
		if (vertexs != NULL)delete[]vertexs;
		edges = NULL, vertexs = NULL;
	}

	// Ѱ����ͼ���Ƿ�������Ϊs�Ķ���
	int SearchVertex(const std::string& s)
	{
		for (int i = 0; i < vertexNumber; i++)
		{
			// ����У������±�
			if (vertexs[i].name == s)
				return i;
		}
		// ���û�У�����-1
		return -1;
	}

	// ���鼯Ѱ���ڵ㣬���ü��仯����������·��ѹ���Ż�
	int FindAncestor(int i)
	{
		if (i == vertexs[i].ancestor) return i;
		return vertexs[i].ancestor = FindAncestor(vertexs[i].ancestor);
	}

	Graph* MST;					  // ��С������
	int vertexNumber, edgeNumber; // ��¼������������
	Edge* edges;                  // ��������
	Vertex* vertexs;              // ������
};

// �õ�A-E���ַ��������˴������봦��
char Choice()
{
	std::cout << std::endl << "��ѡ�������";
	char ret = '\0';

	while (1)
	{
		std::cin >> ret;
		if (std::cin.fail() || ret < 'A' || ret > 'E') // ������������Ͳ�ͬ�����ֲ���Ҫ��Χ��
		{
			std::cin.clear();
			std::cin.ignore(1024, '\n');                           // ���������
			std::cout << "����������������룺";                                // ���������������ʾ
			continue;
		}
		break;
	}
	return ret;
}

int main()
{
	std::cout << "**    �������ģ��ϵͳ    **" << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << "**    A---������������    **" << std::endl;
	std::cout << "**    B---��ӵ����ı�    **" << std::endl;
	std::cout << "**    C---������С������  **" << std::endl;
	std::cout << "**    D---��ʾ��С������  **" << std::endl;
	std::cout << "**    E---�˳�    ����    **" << std::endl;
	std::cout << "============================" << std::endl;

	Graph graph;
	while (1)
	{
		char ch = Choice();
		switch (ch)
		{
		case 'A':
			graph.InitVertex();
			break;
		case 'B':
			graph.InitEdge();
			break;
		case 'C':
			if (graph.Kruskal()) std::cout << "Kruskal��С������������ϣ�" << std::endl;
			else std::cout << "�޷�������С��������";
			break;
		case 'D':
			graph.printMST();
			break;
		case 'E':
			system("pause");
			return 0;
		}
	}
}