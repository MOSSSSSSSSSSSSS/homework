#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<climits>

// �ڵ�
typedef struct BinarySearchTreeNode
{
	// ���캯��
	BinarySearchTreeNode(double v = 0.0) :data(v) { leftChild = NULL, rightChild = NULL; };

	double data;         // ���� 
	BinarySearchTreeNode* leftChild;  // ����
	BinarySearchTreeNode* rightChild; // �Һ���
} BSTNode;

// ������������
std::ostream& operator<<(std::ostream& os, const BSTNode& x)
{
	// ����ڵ���Ϣ
	os << x.data << "->";
	return os;
}

// ����������
typedef class BinarySearchTree
{
public:
	// ���캯��
	BinarySearchTree() { root = NULL; }

	// ���������ͷſռ�
	~BinarySearchTree() { MakeEmpty(root); }

	// �������
	bool Insert(double key)
	{

		// ��Ϊ�������Ƚ������ڵ�
		if (root == NULL)
		{
			// �������ڵ�
			BuildRoot(key);
			// ����ɹ�
			return true;
		}



		// ���ڶ����������в���Ҫ�����ֵ�Ƿ��Ѿ�����
		// �������ʧ�ܣ�����룻��ʱpָ����������һ���ڵ�
		if (Search(root, key) == NULL)
		{
			Insert(root, key);
			return true;
		}
		else
		{
			std::cout << std::endl << "�ڵ�" << key << "�Ѿ������ڶ�����������" << std::endl;
			return false;
		}
	}

	// �������������Ƿ����ֵΪkey�Ľڵ�
	BSTNode* Search(BSTNode* bst, double key)  //���ҳɹ�ʱ��pָ��ֵΪkey�Ľڵ㡣�������ʧ�ܣ���pָ����������һ���ڵ�
	{
		// ��ǰ�ڵ�Ϊ�գ�����
		if (bst == NULL)
			return NULL;

		// ���ҳɹ������ص�ǰ�ڵ�λ��
		if (bst->data == key)
			return bst;

		// ����ǰ�ڵ��ֵС�ڲ��ҵ�ֵ��������������
		else if (bst->data < key) 	return Search(bst->rightChild, key);

		// ����ǰ�ڵ��ֵ���ڲ��ҵ�ֵ��������������
		return Search(bst->leftChild, key);
	}

	// �������
	void inOrder(BSTNode* current)
	{
		if (current == NULL) return;
		inOrder(current->leftChild);
		std::cout << *current;
		inOrder(current->rightChild);
	}

	// Ѱ�Ҹ��ڵ��ַ
	BSTNode* Root() { return root; }

	// ���ò���
	void MakeEmpty(BSTNode* current)
	{
		if (current == NULL) return;
		MakeEmpty(current->leftChild);
		MakeEmpty(current->rightChild);
		delete current;
	}

private:
	BSTNode* root; // ���ڵ�

	// ��ʼ�����ڵ�
	void BuildRoot(double data)
	{
		// Ϊ���ڵ����ռ�
		root = new BSTNode(data);

		// ��ʧ���������ʾ����֤��׳��
		if (root == NULL)
		{
			std::cerr << "�ڴ�������" << std::endl;
			system("pause");
			exit(1);
		}
	}

	// ����
	void Insert(BSTNode* bst, double key)
	{
		// ������ֵС�ڵ�ǰ�ڵ��ֵ��Ӧ������������
		if (key < bst->data)
		{
			// ����ǰ�ڵ��Ѿ���������������������
			if (bst->leftChild != NULL) Insert(bst->leftChild, key);

			// ��������������ǰ��ֵ��Ϊ�������
			else
			{
				BSTNode* newNode = new BSTNode(key);

				// ��ʧ���������ʾ����֤��׳��
				if (newNode == NULL)
				{
					std::cerr << "�ڴ�������" << std::endl;
					system("pause");
					exit(1);
				}
				// �������ӹ�ϵ
				bst->leftChild = newNode;
			}
		}
		// ������ֵ���ڵ�ǰ�ڵ��ֵ��Ӧ������������
		if (key > bst->data)
		{
			// ����ǰ�ڵ��Ѿ���������������������
			if (bst->rightChild != NULL) Insert(bst->rightChild, key);

			// ��������������ǰ��ֵ��Ϊ���Ҷ���
			else
			{
				BSTNode* newNode = new BSTNode(key);

				// ��ʧ���������ʾ����֤��׳��
				if (newNode == NULL)
				{
					std::cerr << "�ڴ�������" << std::endl;
					system("pause");
					exit(1);
				}
				// �������ӹ�ϵ
				bst->rightChild = newNode;
			}
		}
	}

	// ǰ�����
	void preOrder(BSTNode* current)
	{
		if (current == NULL) return;
		std::cout << *current;
		preOrder(current->leftChild);
		preOrder(current->rightChild);
	}

	// �������
	void postOrder(BSTNode* current)
	{
		if (current == NULL) return;
		postOrder(current->leftChild);
		postOrder(current->rightChild);
		std::cout << *current;
	}
}BST;

// �õ�1-4���ַ��������˴������봦��
char Choice()
{
	std::cout << std::endl << "��ѡ�������";
	char ret = '\0';

	// ���������ַ�����1-4��Ҫ���û���������
	while (1)
	{
		std::cin >> ret;
		if (std::cin.fail() || ret < '1' || ret > '4') // ������������Ͳ�ͬ�����ֲ���Ҫ��Χ��
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

	std::cout << "**        ����������      **" << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << "**    1 -- �������������� **" << std::endl;
	std::cout << "**    2 -- ����Ԫ��       **" << std::endl;
	std::cout << "**    3 -- ��ѯԪ��       **" << std::endl;
	std::cout << "**    4 -- �˳�����       **" << std::endl;
	std::cout << "============================" << std::endl;

	BST bst;
	while (1)
	{
		char ch = Choice();
		switch (ch)
		{
		case'1':
			// ��ԭ��������
			bst.MakeEmpty(bst.Root());

			// �õ�����
			std::cout << "���������������Ԫ�ص�ֵ����0��β��" << std::endl;
			double key;
			while (1)
			{
				while (1)
				{
					std::cin >> key;
					if (std::cin.fail()) // ������������Ͳ�ͬ
					{
						std::cin.clear();
						std::cin.ignore(1024, '\n');                           // ���������
						std::cout << "����������������룺" << std::endl;         // ���������������ʾ
						continue;
					}
					break;
				}
				// ����0���������
				if (key == 0.0)  break;
				else bst.Insert(key);
			}
			std::cout << std::endl << "����������Ԫ���У�" << std::endl;
			bst.inOrder(bst.Root());
			std::cout << std::endl;
			break;


		case '2':
			// ��δ���������Ƚ���
			if (bst.Root() == NULL)	std::cout << "���Ƚ���������������" << std::endl;
			else
			{
				std::cout << "������Ҫ�����Ԫ�أ�" << std::endl;
				while (1)
				{
					std::cin >> key;
					if (std::cin.fail()) // ������������Ͳ�ͬ
					{
						std::cin.clear();
						std::cin.ignore(1024, '\n');                           // ���������
						std::cout << "����������������룺" << std::endl;         // ���������������ʾ
						continue;
					}
					break;
				}
				bst.Insert(key);
				std::cout << std::endl << "����������Ԫ���У�" << std::endl;
				bst.inOrder(bst.Root());
				std::cout << std::endl;
			}
			break;

		case '3':
			// ��δ���������Ƚ���
			if (bst.Root() == NULL)	std::cout << "���Ƚ���������������" << std::endl;
			else
			{
				std::cout << "������Ҫ��ѯ��Ԫ�أ�" << std::endl;
				while (1)
				{
					std::cin >> key;
					if (std::cin.fail()) // ������������Ͳ�ͬ
					{
						std::cin.clear();
						std::cin.ignore(1024, '\n');                           // ���������
						std::cout << "����������������룺" << std::endl;         // ���������������ʾ
						continue;
					}
					break;
				}
				if (bst.Search(bst.Root(), key))
					std::cout << std::endl << key << "�����ڶ����������У�" << std::endl;
				else
					std::cout << std::endl << key << "�������ڶ����������У�" << std::endl;
			}
			break;

		case '4':
			system("pause");
			return 0;
		}

	}
	return 0;
}