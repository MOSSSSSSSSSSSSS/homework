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

// ���ú����ֵܱ�ʾ����ÿһ�����Ͻڵ��������ָ���򣬷ֱ�ָ���һ�����Ӻ���һ���ֵ�
// �������ڵ�
struct TreeNode
{
	// ���캯���������������ݳ�ʼ������
	TreeNode(std::string s = "", TreeNode* fc = NULL, TreeNode* ns = NULL) :name(s), firstChild(fc), nextSibling(ns) { father = NULL; };

	TreeNode* firstChild;  // ָ���һ������
	TreeNode* nextSibling; // ָ����һ���ֵ�
	TreeNode* father;      // ָ�򸸽ڵ�
	std::string name;           // ����
};

// ������
class Tree
{
public:
	// ���캯��
	Tree() { root = NULL; }

	// �����������ͷſռ�
	~Tree() { DeleteTree(root); }

	// �������ڵ㣬�����������
	void BuildRoot()
	{
		// �õ���������
		std::cout << "���Ƚ���һ�����ף�" << std::endl;
		std::cout << "���������ȵ�������";
		std::string name;
		std::cin >> name;

		// Ϊroot����ռ�
		root = new TreeNode(name);

		// ��ʧ���������ʾ����֤��׳��
		if (root == NULL)
		{
			std::cerr << "�ڴ�������" << std::endl;
			system("pause");
			exit(1);
		}

		// �����������
		std::cout << "�˼��׵������ǣ�" << root->name << std::endl;
	}

	// ����ĳ������
	void BuildTree()
	{
		// �õ�����������
		std::cout << "������Ҫ������ͥ���˵�������";
		std::string name;
		std::cin >> name;

		// ��parent��Search�ҵ������ߵ�λ��
		TreeNode* parent = Search(name);

		// �������봦��
		if (parent == NULL)
		{
			std::cout << "�������ڲ����ڸü�ͥ��Ա��" << std::endl;
			return;
		}

		// ����ǰ���Ѿ����˺��ӣ�˵���Ѿ���������ͥ�������ٴν�����ͥ��������ʾ
		if (parent->firstChild != NULL)
		{
			std:: cout<< "�ó�Ա�Ѿ���������ͥ��" << std::endl;
			return;
		}

		// ����getint�����õ���Ů��������֤��׳��
		std::cout << "������" << name << "�Ķ�Ů������";
		int childNum = getint(0, INT_MAX, "��Ů��������Ϊ�����������������룡");

		// Ϊparent���뺢��
		std::cout << "����������" << name << "�Ķ�Ů������:";

		// Ϊparent����firstChild
		while (1)
		{
			std::cin >> name;

			// ������δ��ʹ�ã����Բ���
			if (Search(name) == NULL)
			{
				// ���¶���
				parent->firstChild = new TreeNode(name);

				// ���ڴ������д�������֤��׳��
				if (parent->firstChild == NULL)
				{
					std::cerr << "�ڴ�������" << std::endl;
					system("pause");
					exit(1);
				}

				// ���¶��ӽڵ�ĸ���Ϊparent
				parent->firstChild->father = parent;
				break;
			}

			// �������Ѿ�ʹ�ù��ˣ���Ҫ��������
			else
			{
				std::cout << "����Ϊ" << name << "�ĳ�Ա�Ѵ��ڣ����������룡" << std::endl;
				std::cin.clear();

				// �������������������������������Ч��
				std::cin.ignore(1024, '\n');
			}
		}


		// ����������Ů��Ϣ
		for (int i = 1; i < childNum; i++)
		{
			while (1)
			{
				std::cin >> name;

				// ������δ��ʹ�ã����Բ���
				if (Search(name) == NULL)
				{
					TreeNode* p = parent->firstChild;

					// ��pָ���Ƶ�parent�����һ�����Ӵ�
					while (p->nextSibling != NULL)
						p = p->nextSibling;

					// Ϊ���һ�����Ӹ����ֵ�
					p->nextSibling = new TreeNode(name);

					// ���ڴ������д�������֤��׳��
					if (p->nextSibling == NULL)
					{
						std::cerr << "�ڴ�������" << std::endl;
						system("pause");
						exit(1);
					}

					// �����һ�����ӵ�father����Ϊparent
					p->nextSibling->father = parent;
					break;
				}

				// �������Ѿ�ʹ�ù��ˣ���Ҫ��������
				else
				{
					std::cout << "����Ϊ" << name << "�ĳ�Ա�Ѵ��ڣ����������룡" << std::endl;
					std::cin.clear();

					// �������������������������������Ч��
					std::cin.ignore(1024, '\n');
				}
			}
		}

		// չʾparent�ڵ�ĺ���
		ShowTree(parent->name);
	}

	// ���ĳ���ڵ�
	void AddTreeNode()
	{
		// �õ����������
		std::cout << "������Ҫ��Ӷ��ӣ���Ů�������˵�������";
		std::string name;
		std::cin >> name;

		// ��parent��¼����ߵ�λ��
		TreeNode* parent = Search(name);

		// �������봦��
		if (parent == NULL)
		{
			std::cout << "�������ڲ����ڸü�ͥ��Ա��" << std::endl;
			return;
		}

		// �õ�����ӵĽڵ������
		std::cout << "������" << name << "����Ӷ��ӣ���Ů������������";

		// ����firstChild
		if (parent->firstChild == NULL)
		{
			while (1)
			{
				std::cin >> name;

				// ������δ��ʹ�ã����Բ���
				if (Search(name) == NULL)
				{
					// ����firstChild
					parent->firstChild = new TreeNode(name);

					// ���ڴ���д�����֤��׳��
					if (parent->firstChild == NULL)
					{
						std::cerr << "�ڴ�������" << std::endl;
						system("pause");
						exit(1);
					}

					// ��firstChild��father����Ϊparent
					parent->firstChild->father = parent;
					break;
				}

				// �������Ѿ�ʹ�ù��ˣ���Ҫ��������
				else
				{
					std::cout << "����Ϊ" << name << "�ĳ�Ա�Ѵ��ڣ����������룡" << std::endl;
					std::cin.clear();

					// �������������������������������Ч��
					std::cin.ignore(1024, '\n');
				}
			}
		}

		// ���º��ӽڵ��nextSibling
		else
		{
			while (1)
			{
				std::cin >> name;

				// ������δ��ʹ�ã����Բ���
				if (Search(name) == NULL)
				{
					TreeNode* p = parent->firstChild;

					// ��pָ���Ƶ�parent�����һ�����Ӵ�
					while (p->nextSibling != NULL)
						p = p->nextSibling;

					// �����ֵ�
					p->nextSibling = new TreeNode(name);

					// ���ڴ���д�����֤��׳��
					if (p->nextSibling == NULL)
					{
						std::cerr << "�ڴ�������" << std::endl;
						system("pause");
						exit(1);
					}

					// ���õ�ǰ���һ�����ӵ�fatherΪparent
					p->nextSibling->father = parent;
					break;
				}

				// �������Ѿ�ʹ�ù��ˣ���Ҫ��������
				else
				{
					std::cout << "����Ϊ" << name << "�ĳ�Ա�Ѵ��ڣ����������룡" << std::endl;
					std::cin.clear();

					// �������������������������������Ч��
					std::cin.ignore(1024, '\n');
				}
			}
		}
		// չʾparent�ڵ�ĺ���
		ShowTree(parent->name);
	}

	// ɾ��ĳ������
	void DeleteTree()
	{
		// �õ���ɢ�ߵ�����
		std::cout << "������Ҫ��ɢ��ͥ���˵�����:";
		std::string name;
		std::cin >> name;

		// ����parent�õ���ɢ�ߵ�λ��
		TreeNode* parent = Search(name);
		if (parent == NULL)
		{
			std::cout << "�������ڲ����ڸü�ͥ��Ա��" << std::endl;
			return;
		}
		std::cout << "Ҫ��ɢ��ͥ������:" << name << std::endl;

		// �ڽ�ɢǰ����չʾ��ǰ��ɢ�ߵĺ���
		ShowTree(parent->name);

		// ����ɢ�߲��Ǹ��ڵ㣬��Ҫ�������²�������parentΪ���ڵ�����������ά����������Ȼ����
		if (parent != root)
		{
			// �����ɢ�����丸�ڵ�ĵ�һ�����ӣ����丸�ڵ��firstChildָ����Ҫָ���ɢ�ߵ���һ���ֵ�
			if (parent->father->firstChild == parent) parent->father->firstChild = parent->nextSibling;

			// �����ɢ�߲����丸�ڵ�ĵ�һ�����ӣ���������һ���ֵܽڵ��nextSiblingָ����Ҫָ���ɢ�ߵ���һ���ֵ�
			else
			{
				// ��p��Ѱ�ҽ�ɢ�ߵ���һ���ֵܽڵ�
				TreeNode* p = parent->father->firstChild;
				while (1)
				{
					if (p->nextSibling == parent) break;
					p = p->nextSibling;
				}

				//��һ���ֵܽڵ��nextSiblingָ����Ҫָ���ɢ�ߵ���һ���ֵ�
				p->nextSibling = parent->nextSibling;
			}

			// ����parentΪ����������������ͷ��ڴ�
			DeleteTree(parent);
		}
		else
			// ����ɢ��ǡΪ���ڵ㣬����Ҫ���룬ֱ���ͷ��ڴ漴��
			DeleteTree(parent);
	}

	// ����ĳ���ڵ���Ϣ
	void ResetTreeNode()
	{
		// �õ������˵���Ϣ
		std::cout << "������Ҫ�����������˵�Ŀǰ����:";
		std::string name;
		std::cin >> name;

		// ��current��¼�����ߵ�λ��
		TreeNode* current = Search(name);

		// ���ڴ������д�������֤��׳��
		if (current == NULL)
		{
			std::cout << "�������ڲ����ڸü�ͥ��Ա��" << std::endl;
			return;
		}

		// �õ����ĺ������
		std::cout << "��������ĺ��������";
		while (1)
		{
			std::cin >> name;

			// �����ĺ������û�г��ֹ������Ը���
			if (Search(name) == NULL)
			{
				std::cout << current->name << "�Ѹ���Ϊ" << name << std::endl;
				current->name = name;
				break;
			}

			// �������Ѿ�ʹ�ù��ˣ���Ҫ��������
			else
			{
				std::cout << "����Ϊ" << name << "�ĳ�Ա�Ѵ��ڣ����������룡" << std::endl;
				std::cin.clear();

				// �������������������������������Ч��
				std::cin.ignore(1024, '\n');
			}
		}

	}

	// չʾĳ���ڵ���Ů
	void ShowTree(const std::string& name)
	{
		// ��current��λname�����˵�λ��
		TreeNode* current = Search(name);
		if (current == NULL)
		{
			std::cout << std::endl;
			return;
		}

		// û����Ů����
		current = current->firstChild;
		if (current == NULL)
		{
			std::cout << name << "û����Ů" << std::endl;
			return;
		}

		// ����Ů����
		else
		{
			// ���������Ů����
			std::cout << name << "�ĵ�һ����Ů�У�";
			std::cout << current->name << " ";
			while (current->nextSibling != NULL)
			{
				current = current->nextSibling;
				std::cout << current->name << ' ';
			}
			std::cout << std::endl;
		}
	}

	// ���������Ƿ�������Ϊname�ļ����Ա�����ҳɹ����ض�Ӧ��ַ��ֵ��ʧ���򷵻�NULL
	TreeNode* Search(const std::string& name)const
	{
		if (root == NULL)
			return NULL;
		else
			return Search(root, name);
	}

private:
	TreeNode* root;   // ���������ڵ�

	// �鿴��ǰ����Ƿ�Ϊ����Ҫ���ҵļ����Ա�����ҳɹ����ض�Ӧ��ַ��ֵ��ʧ���򷵻�NULL
	TreeNode* Search(TreeNode* current, const std::string& name)const
	{
		// �����ǰ�ڵ����
		if (current->name == name)
			return current;

		// ������ǰ�ڵ�Ķ��ӽڵ���еݹ�����
		TreeNode* findResult = NULL;
		for (TreeNode* p = current->firstChild; p != NULL; p = p->nextSibling)
		{
			findResult = Search(p, name);

			// ���ӽڵ������ɹ�
			if (findResult != NULL)
				return findResult;
		}

		// ���ӽڵ�����ʧ��
		return NULL;
	}

	// ɾ���Ե�ǰ���Ϊ����������
	void DeleteTree(TreeNode* current)
	{
		// �����սڵ����
		if (current == NULL) return;

		// ��ǰ�ڵ�����Ů�����µݹ�
		if (current->firstChild != NULL)
		{
			// ��ɾ����һ������
			DeleteTree(current->firstChild);
			TreeNode* p = current->firstChild;

			// ������ɾ�����ֵ�
			while (p->nextSibling != NULL)
			{
				DeleteTree(p->nextSibling);
				p = p->nextSibling;
			}

			// �ͷ��ڴ�
			delete current;
		}
	}
};

// �õ�A-E���ַ��������˴������봦��
char Choice()
{
	std::cout << std::endl << "��ѡ��Ҫִ�еĲ�����";
	char ret = '\0';

	// ���������ַ�����A-E��Ҫ���û���������
	for (;;)
	{
		std::cin >> ret;
		if (std::cin.fail() || ret < 'A' || ret > 'E')                          // ������������Ͳ�ͬ�����ֲ���Ҫ��Χ��
		{
			std::cin.clear();
			std::cin.ignore(1024, '\n');                                        // ���������
			std::cout << "����������������룺";                                // ���������������ʾ
			continue;
		}
		break;
	}

	return ret;
}

int main()
{
	std::cout << "**           ���׹���ϵͳ            **" << std::endl;
	std::cout << "=======================================" << std::endl;
	std::cout << "**        ��ѡ��Ҫִ�е�ѡ��:        **" << std::endl;
	std::cout << "**           A --- ���Ƽ���          **" << std::endl;
	std::cout << "**           B --- ��Ӽ�ͥ��Ա      **" << std::endl;
	std::cout << "**           C --- ��ɢ�ֲ���ͥ      **" << std::endl;
	std::cout << "**           D --- ���ļ�ͥ��Ա����  **" << std::endl;
	std::cout << "**           E --- �˳�����          **" << std::endl;
	std::cout << "***************************************" << std::endl;
	Tree tree;
	tree.BuildRoot();
	for (;;)
	{
		char ch = Choice();
		if (ch == 'A')
		{
			// ���Ѿ����ڵĽڵ�Ϊ������һ����
			tree.BuildTree();
		}
		else if (ch == 'B')
		{
			// Ϊ�Ѿ����ڵĽڵ����һ������
			tree.AddTreeNode();
		}
		else if (ch == 'C')
		{
			// ɾ���Ѿ����ڵĽڵ�Ϊ����һ����
			tree.DeleteTree();
		}
		else if (ch == 'D')
		{
			// Ϊ�Ѿ����ڵĽڵ������Ϣ
			tree.ResetTreeNode();
		}
		else if (ch == 'E')
		{
			// �˳�����
			std::cout << std::endl;
			system("pause");
			return 0;
		}
	}
}