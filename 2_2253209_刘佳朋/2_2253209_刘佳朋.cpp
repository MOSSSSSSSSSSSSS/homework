#include<iostream>
#include<iomanip>
#include<string>
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

// �ڵ�
struct LinkedListNode
{

	// ���캯������ʼ�����
	LinkedListNode(int i = 0) { num = i; next = NULL; }

	// ��������Ϣ
	void Display() { std::cout << num << std::endl; }

	int num;              // ���
	LinkedListNode* next; // ָ���¸�λ��
};

// ѭ��������
class CircleLinkedList
{
	friend void JosephusSolve(CircleLinkedList& circleJosephus, int n, int s, int m, int k);
public:
	// ���캯����Ϊͷ�������ռ䣬ͬʱ����ѭ������
	CircleLinkedList()
	{
		head = NULL;

		// Ϊͷ�ڵ�����ռ�
		head = new LinkedListNode;

		// ���ռ������쳣�����н�׳�Դ���
		if (head == NULL)
		{
			std::cerr << "�ڴ�������" << std::endl;
			system("pause");
			exit(1);
		}

		// ��ʼ״̬��ͷ����nextָ��ָ���Լ����Թ���ѭ������
		head->next = head;
	}

	// �����������ͷſռ�
	~CircleLinkedList()
	{
		LinkedListNode* current = head->next;
		while (head->next != head)
		{
			current = head->next;
			head->next = current->next;
			delete current;
		}
		delete head;
	}

	// ����ѭ��������
	int Length()
	{
		int retNum = 0;
		LinkedListNode* current = head->next;
		// �����±�����ͷ�ڵ�󣬱�־��ѭ������ı�������
		while (current != head)
		{
			current = current->next;
			retNum++;
		}
		return retNum;
	}

	// ��λ���������ر��е�i��Ԫ�صĵ�ַ
	LinkedListNode* Locate(int i)
	{
		// ��ͷ����������
		if (!i) return head;

		// i����������NULL��֤��׳��
		if (i < 0 || i>Length())return NULL;

		LinkedListNode* current = head->next; int k = 1;
		while (current != head && k < i)
			current = current->next, k++;

		// ���ص�i���ڵ��ַ
		return current;
	}

	// Ѱ���������Ƿ���x��ŵ��ˣ������ɹ����ظýڵ�λ�ã����򷵻�-1
	int Search(int x)
	{
		int retNum = 1;
		LinkedListNode* current = head->next;
		while (current != head)
		{
			// �����ɹ�������ѭ��
			if (current->num == x) return retNum;
			// ��ǰ�ڵ�����ʧ�ܣ�������һ���ڵ�
			else current = current->next; retNum++;
		}
		return -1;
	}

	// ɾ����i��Ԫ��,x���ظ�Ԫ�ص�ֵ
	bool Remove(int i, LinkedListNode& x)
	{
		LinkedListNode* current = Locate(i - 1);

		// ɾ��ʧ��
		if (current == NULL || current->next == head) return false;

		// ��������������ɾ�ڵ������ժ��
		LinkedListNode* del = current->next;
		current->next = del->next;

		// ��¼ɾ���ڵ����Ϣ
		x.num = del->num;
		x.next = del->next;

		delete del;
		return true;
	}

	// ����Ԫ��x���뵽��i���ڵ��
	bool Insert(int i, LinkedListNode& x)
	{
		LinkedListNode* current = Locate(i);

		// ���벻�ɹ�
		if (current == NULL)return false;

		LinkedListNode* newNode = new LinkedListNode(x);
		// �ռ������쳣
		if (newNode == NULL)
		{
			std::cerr << "�ڴ�������" << std::endl;
			system("pause");
			exit(1);
		}

		// ������current֮��
		newNode->next = current->next;
		current->next = newNode;

		// ����ɹ�
		return true;
	}

	// ����������Ϣ�������
	void Display()
	{
		LinkedListNode* current = head->next;
		while (current != head)
		{
			std::cout << std::setw(7) << std::setiosflags(std::ios::left) << current->num;
			current = current->next;
		}
	}

private:
	LinkedListNode* head;           // ����ͷָ�� 
};

void JosephusSolve(CircleLinkedList& circleJosephus, int n, int s, int m, int k)
{
	// ��¼��ʼ�ڵ���Ϣ
	LinkedListNode* begin = circleJosephus.Locate(s);
	LinkedListNode current = *begin;

	//��ɱ��n-k����
	for (int i = 0; i < n - k; i++)
	{
		// ÿ��m����ɱ��һ����
		for (int j = 1; j < m; j++)
		{
			// ��������ͷ���սڵ㣩����ָ���һ���ڵ�
			if (begin == circleJosephus.head)
				begin = begin->next;

			// ָ���¸�����
			begin = begin->next;

			// ��������ͷ���սڵ㣩����ָ���һ���ڵ�
			if (begin == circleJosephus.head)
				begin = begin->next;
		}

		// ���������Ϣ
		std::cout << "��" << i + 1 << "�����ߵ�λ���ǣ�" << begin->num << std::endl;
		int killed = begin->num;

		// ɱ������Ҫ��ָ��ָ��ɱ�ߵ���һ����
		begin = begin->next;

		// ɱ�����Ϊkilled���ˣ���current��¼����Ϣ
		circleJosephus.Remove(circleJosephus.Search(killed), current);
	}

	std::cout << "����ʣ�£�        " << k << "��" << std::endl;
	std::cout << "ʣ�������λ��Ϊ��";
	// ������ѭ���������������������Ϣ
	circleJosephus.Display();
}

int main()
{
	int n, s, m, k;
	std::cout << "����N��Χ��һȦ���ӵ�S���˿�ʼ���α�������M���˳��֣�������һ�˿�ʼ���������ѭ����ֱ��ʣ��K����Ϊֹ " << std::endl << std::endl;

	std::cout << "������������Ϸ��������N��";
	n = getint(1, INT_MAX, "�����������������������Ϸ��������N��");

	std::cout << "��������Ϸ��ʼ��λ��S��  ";
	s = getint(1, n, "�������������������Ϸ��ʼ��λ��S��");

	std::cout << "��������������M��        ";
	m = getint(1, n, "�������������������������M��");

	std::cout << "������ʣ�����������K��  ";
	k = getint(1, n - 1, "�����������������ʣ�����������K��");
	std::cout << std::endl;
	CircleLinkedList circleJosephus;

	// �������˲�������
	for (int i = 0; i < n; i++)
	{
		LinkedListNode current(i + 1);
		circleJosephus.Insert(i, current);
	}

	// ����Լɪ�򻷵����
	JosephusSolve(circleJosephus, n, s, m, k);

	system("pause");
	return 0;
}