#include<iostream>
#include<string>
#include<iomanip>
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
			std::cin.ignore(65536, '\n');                           // ���������
			std::cout << errorTips;                                // ���������������ʾ
			continue;
		}
		break;
	}
	return retNum;
}

// �õ�һ�����Ȳ����� lengthMax ���ַ����������������������֤��׳��
std::string getstring(const unsigned int lengthMax = INT_MAX, const std::string inputTips = "")
{
	std::string retString;
	while (1)
	{
		std::cin >> retString;
		if (retString.size() > lengthMax) // ���ַ������ȳ���Ҫ��
		{
			std::cin.clear();
			std::cin.ignore(65536, '\n');        // ���������
			std::cout << inputTips;             // �Ӵ˴���ʼ�����������ʾ
			continue;
		}
		break;
	}
	return retString;
}

// �ڵ㣬һ���ڵ��ʾһ����������Ϣ
struct LinkedListNode
{
	int testNum;                      // ����
	std::string name;                 // ����
	std::string sex;                  // �Ա� 0Ϊ�У�1ΪŮ
	int age;                          // ���� 
	std::string testMajor;            // ����ְҵ
	LinkedListNode* next;             // ָ����һ���ڵ�

	// ���캯�������ÿ�����ʼ��Ϣ
	LinkedListNode(const int num1 = 0, const std::string str1 = "", const std::string str2 = "", int const num2 = 0, const std::string str3 = "", LinkedListNode* num3 = NULL)
	{
		testNum = num1, name = str1, sex = str2, age = num2, testMajor = str3, next = num3;
		next = NULL;
	}
	// ���������Ϣ
	void Display()
	{
		std::cout << std::setw(14) << std::setiosflags(std::ios::left) << testNum;
		std::cout << std::setw(14) << std::setiosflags(std::ios::left) << name;
		std::cout << std::setw(8) << std::setiosflags(std::ios::left) << sex;
		std::cout << std::setw(8) << std::setiosflags(std::ios::left) << age;
		std::cout << testMajor << std::endl;
	}
}student;

// ������
class LinkedList
{
public:

	// ���캯�������ó�ʼ��Ϣ
	LinkedList()
	{
		// Ϊͷָ�����ռ�
		head = new LinkedListNode;
		// ��ʧ���������ʾ����֤��׳��
		if (head == NULL)
		{
			std::cerr << "�ڴ�������" << std::endl;
			system("pause");
			exit(1);
		}
		std::cout << "�����뽨��������Ϣϵͳ��" << std::endl << "�����뿼��������";
		int stuNum = getint(1, INT_MAX, "�����������������Ӵ˴���ʼ�������룺");
		std::cout << "���������뿼���Ŀ���(Ӧ����0)������(���Ȳ�����10���޿ո�)���Ա�(��/Ů)������(0,100)���������(���Ȳ�����10���޿ո�)��" << std::endl;
		// ���ó�ʼ��������Ϣ����֤�˽�׳�ԣ�ͬʱ��ֹ�˿����ظ�
		for (int i = 0; i < stuNum; i++)
		{
			LinkedListNode current;
			current.testNum = getint(0, INT_MAX, "�������������Ӵ˴���ʼ�������룺");

			// �Կ����ظ����д���
			if (Search(current.testNum) != -1)
			{
				std::cout << "�Ѿ��иÿ��ſ������ڣ���Ӵ˴���ʼ�������룺" << std::endl;
				i--;
				std::cin.clear();
				std::cin.ignore(1024, '\n');                           // ���������
				continue;
			}

			current.name = getstring(10, "�������������Ӵ˴���ʼ�������룺");
			while (current.sex != "��" && current.sex != "Ů")
				current.sex = getstring(2, "�Ա����������Ӵ˴���ʼ�������룺");
			current.age = getint(1, 99, "�������������Ӵ˴���ʼ�������룺");
			current.testMajor = getstring(10, "����������������Ӵ˴���ʼ�������룺");
			Insert(i, current);
		}
	}

	// �����������ͷſռ�
	~LinkedList()
	{
		LinkedListNode* current = head->next;
		while (head->next != NULL)
		{
			current = head->next;
			head->next = current->next;
			delete current;
		}
		delete head;
	}

	// ���������ͷ���ĵ�����ĳ���
	int Length()
	{
		// retNumΪ����
		int retNum = 0; LinkedListNode* current = head->next;
		// ѭ��ɨ�裬Ѱ����β
		while (current != NULL)
		{
			current = current->next; retNum++;
		}
		return retNum;
	}

	// Ѱ���������Ƿ���x���ſ����������ɹ����ظýڵ�λ�ã����򷵻�-1
	int Search(int x)
	{
		int retNum = 1;
		LinkedListNode* current = head->next;
		while (current != NULL)
		{
			// �����ɹ�������ѭ��
			if (current->testNum == x) return retNum;
			// ��ǰ�ڵ�����ʧ�ܣ�������һ���ڵ�
			else current = current->next; retNum++;
		}
		//δ������
		return -1;
	}

	// ��λ���������ر��е�i��Ԫ�صĵ�ַ
	LinkedListNode* Locate(int i)
	{
		// i����������NULL��֤��׳��
		if (i < 0)return NULL;
		LinkedListNode* current = head; int k = 0;
		while (current != NULL && k < i)
			current = current->next, k++;
		// ���ص�i���ڵ��ַ��������NULL,�����iֵ̫��
		return current;
	}

	// ɾ����i��Ԫ��,x���ظ�Ԫ�ص�ֵ
	bool Remove(int i, LinkedListNode& x)
	{
		LinkedListNode* current = Locate(i - 1);

		// ɾ��ʧ��
		if (current == NULL || current->next == NULL) return false;

		// ��������������ɾ�ڵ������ժ��
		LinkedListNode* del = current->next;
		current->next = del->next;

		// ��¼ɾ���ڵ����Ϣ
		x.name = del->name;
		x.age = del->age;
		x.sex = del->sex;
		x.testNum = del->testNum;
		x.testMajor = del->testMajor;
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
		std::cout << std::endl << "����          ����          �Ա�    ����    �������" << std::endl;
		while (current != NULL)
		{
			std::cout << std::setw(14) << std::setiosflags(std::ios::left) << current->testNum;
			std::cout << std::setw(14) << std::setiosflags(std::ios::left) << current->name;
			std::cout << std::setw(8) << std::setiosflags(std::ios::left) << current->sex;
			std::cout << std::setw(8) << std::setiosflags(std::ios::left) << current->age;
			std::cout << current->testMajor << std::endl;
			current = current->next;
		}
	}

private:
	LinkedListNode* head;           // ����ͷָ�� 
};

int main()
{
	LinkedList testSignSystem;
	testSignSystem.Display();
	std::cout << "��������Ҫ���еĲ�����1Ϊ���룬2Ϊɾ����3Ϊ�޸ģ�4Ϊ���ң�5Ϊͳ�ƣ�0Ϊ�˳�������" << std::endl;
	for (;;)
	{
		// �õ�Ҫ���еĲ������ͣ���֤�˽�׳��
		int optionNum;
		std::cout << "��������Ҫ���еĲ�����";
		optionNum = getint(0, 5, "���������Ӵ˴���ʼ����������Ҫ���еĲ�����");

		// �˳�����
		if (!optionNum)
		{
			std::cout << "���Խ��������˳�����" << std::endl;
			break;
		}

		// �������
		else if (optionNum == 1)
		{
			int locate = -1;
			std::cout << "��������Ҫ����Ŀ���λ�ã�";
			locate = getint() - 1;
			std::cout << "���������뿼���Ŀ���(Ӧ����0)������(���Ȳ�����10���޿ո�)���Ա�(��/Ů)������(0,100)���������(���Ȳ�����10���޿ո�)��" << std::endl;
			int testNum = getint(0, INT_MAX, "�������������Ӵ˴���ʼ�������룺");
			std::string name = getstring(10, "�������������Ӵ˴���ʼ�������룺");
			std::string sex = "";
			while (sex != "��" && sex != "Ů")
				sex = getstring(2, "�Ա����������Ӵ˴���ʼ�������룺");
			int age = getint(0, 100, "�������������Ӵ˴���ʼ�������룺");
			std::string testMajor = getstring(10, "����������������Ӵ˴���ʼ�������룺");

			LinkedListNode current(testNum, name, sex, age, testMajor);

			// �Բ���ʧ�����˽�׳�Դ���
			if (!testSignSystem.Insert(locate, current))std::cout << "����λ�ò��Ϸ�������ʧ�ܣ�" << std::endl;
			testSignSystem.Display();
		}

		// ɾ������
		else if (optionNum == 2)
		{
			int locate = -1;
			std::cout << "��������Ҫɾ���Ŀ������ţ�";
			locate = getint();
			locate = testSignSystem.Search(locate);

			// ��ɾ��ʧ�����˽�׳�Դ���
			LinkedListNode del;
			if (!testSignSystem.Remove(locate, del))std::cout << "ɾ�����Ϸ�������ʧ�ܣ�" << std::endl;
			else
			{
				std::cout << "ɾ��������Ϣ��";
				del.Display();
			}
			testSignSystem.Display();
		}

		// �޸Ĳ�������֤�˲�����ѧ�Ų��ظ�
		else if (optionNum == 3)
		{
			int locate = -1;
			std::cout << "��������Ҫ�޸ĵĿ������ţ�";
			locate = getint();
			locate = testSignSystem.Search(locate);
			if (locate == -1)std::cout << "�޸Ĳ��Ϸ�������ʧ�ܣ�" << std::endl;
			else
			{
				LinkedListNode del;
				testSignSystem.Remove(locate, del);
				std::cout << "�޸Ŀ�����Ϣ��";
				del.Display();
				std::cout << "�����������޸ĺ����Ŀ���(Ӧ����0)������(���Ȳ�����10���޿ո�)���Ա�(��/Ů)������(0,100)���������(���Ȳ�����10���޿ո�)��" << std::endl;
				int testNum = getint(0, INT_MAX, "�������������Ӵ˴���ʼ�������룺");
				// �Կ����ظ����д���
				if (testSignSystem.Search(testNum) != -1)
				{
					std::cout << "�Ѿ��иÿ��ſ������ڣ���Ӵ˴���ʼ�������룺" << std::endl;
					std::cin.clear();
					std::cin.ignore(1024, '\n');                           // ���������
					continue;
				}

				std::string name = getstring(10, "�������������Ӵ˴���ʼ�������룺");
				std::string sex = "";
				while (sex != "��" && sex != "Ů")
					sex = getstring(2, "�Ա����������Ӵ˴���ʼ�������룺");
				int age = getint(0, 100, "�������������Ӵ˴���ʼ�������룺");
				std::string testMajor = getstring(10, "����������������Ӵ˴���ʼ�������룺");

				LinkedListNode current(testNum, name, sex, age, testMajor);
				testSignSystem.Insert(locate - 1, current);
			}
			testSignSystem.Display();
		}
		// ���Ҳ���
		else if (optionNum == 4)
		{
			int locate = -1;
			std::cout << "��������Ҫ���ҵĿ������ţ�";
			locate = getint();
			locate = testSignSystem.Search(locate);
			// �Բ���ʧ�ܽ����˽�׳�Դ���
			if (locate == -1)std::cout << "���Ҳ��Ϸ�������ʧ�ܣ�" << std::endl;
			else
			{
				std::cout << "���ҿ�����Ϣ��";
				(*testSignSystem.Locate(locate)).Display();
			}
			testSignSystem.Display();
		}
		// ͳ�Ʋ���
		else if (optionNum == 5)
		{
			std::cout << "��ǰϵͳ�洢����������" << testSignSystem.Length() << std::endl;
			testSignSystem.Display();
		}
	}
	system("pause");
	return 0;
}