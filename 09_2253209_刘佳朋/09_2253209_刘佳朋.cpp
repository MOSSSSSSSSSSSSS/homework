#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<climits>

// 节点
typedef struct BinarySearchTreeNode
{
	// 构造函数
	BinarySearchTreeNode(double v = 0.0) :data(v) { leftChild = NULL, rightChild = NULL; };

	double data;         // 数据 
	BinarySearchTreeNode* leftChild;  // 左孩子
	BinarySearchTreeNode* rightChild; // 右孩子
} BSTNode;

// 重载输出运算符
std::ostream& operator<<(std::ostream& os, const BSTNode& x)
{
	// 输出节点信息
	os << x.data << "->";
	return os;
}

// 二叉排序树
typedef class BinarySearchTree
{
public:
	// 构造函数
	BinarySearchTree() { root = NULL; }

	// 析构函数释放空间
	~BinarySearchTree() { MakeEmpty(root); }

	// 插入操作
	bool Insert(double key)
	{

		// 若为空树，先建立根节点
		if (root == NULL)
		{
			// 建立根节点
			BuildRoot(key);
			// 插入成功
			return true;
		}



		// 先在二叉排序树中查找要插入的值是否已经存在
		// 如果查找失败，则插入；此时p指向遍历的最后一个节点
		if (Search(root, key) == NULL)
		{
			Insert(root, key);
			return true;
		}
		else
		{
			std::cout << std::endl << "节点" << key << "已经存在于二叉排序树中" << std::endl;
			return false;
		}
	}

	// 搜索二叉树中是否存在值为key的节点
	BSTNode* Search(BSTNode* bst, double key)  //查找成功时，p指向值为key的节点。如果查找失败，则p指向遍历的最后一个节点
	{
		// 当前节点为空，回溯
		if (bst == NULL)
			return NULL;

		// 查找成功，返回当前节点位置
		if (bst->data == key)
			return bst;

		// 若当前节点的值小于查找的值，搜索其右子树
		else if (bst->data < key) 	return Search(bst->rightChild, key);

		// 若当前节点的值大于查找的值，搜索其左子树
		return Search(bst->leftChild, key);
	}

	// 中序遍历
	void inOrder(BSTNode* current)
	{
		if (current == NULL) return;
		inOrder(current->leftChild);
		std::cout << *current;
		inOrder(current->rightChild);
	}

	// 寻找根节点地址
	BSTNode* Root() { return root; }

	// 重置操作
	void MakeEmpty(BSTNode* current)
	{
		if (current == NULL) return;
		MakeEmpty(current->leftChild);
		MakeEmpty(current->rightChild);
		delete current;
	}

private:
	BSTNode* root; // 根节点

	// 初始化根节点
	void BuildRoot(double data)
	{
		// 为根节点分配空间
		root = new BSTNode(data);

		// 若失败则给出提示，保证健壮性
		if (root == NULL)
		{
			std::cerr << "内存分配错误！" << std::endl;
			system("pause");
			exit(1);
		}
	}

	// 插入
	void Insert(BSTNode* bst, double key)
	{
		// 若插入值小于当前节点的值，应搜索其左子树
		if (key < bst->data)
		{
			// 若当前节点已经有左子树，则向下搜索
			if (bst->leftChild != NULL) Insert(bst->leftChild, key);

			// 若无左子树，则当前的值作为其左儿子
			else
			{
				BSTNode* newNode = new BSTNode(key);

				// 若失败则给出提示，保证健壮性
				if (newNode == NULL)
				{
					std::cerr << "内存分配错误！" << std::endl;
					system("pause");
					exit(1);
				}
				// 建立父子关系
				bst->leftChild = newNode;
			}
		}
		// 若插入值大于当前节点的值，应搜索其右子树
		if (key > bst->data)
		{
			// 若当前节点已经有左子树，则向下搜索
			if (bst->rightChild != NULL) Insert(bst->rightChild, key);

			// 若无右子树，则当前的值作为其右儿子
			else
			{
				BSTNode* newNode = new BSTNode(key);

				// 若失败则给出提示，保证健壮性
				if (newNode == NULL)
				{
					std::cerr << "内存分配错误！" << std::endl;
					system("pause");
					exit(1);
				}
				// 建立父子关系
				bst->rightChild = newNode;
			}
		}
	}

	// 前序遍历
	void preOrder(BSTNode* current)
	{
		if (current == NULL) return;
		std::cout << *current;
		preOrder(current->leftChild);
		preOrder(current->rightChild);
	}

	// 后序遍历
	void postOrder(BSTNode* current)
	{
		if (current == NULL) return;
		postOrder(current->leftChild);
		postOrder(current->rightChild);
		std::cout << *current;
	}
}BST;

// 得到1-4的字符，进行了错误输入处理
char Choice()
{
	std::cout << std::endl << "请选择操作：";
	char ret = '\0';

	// 如果输入的字符不在1-4，要求用户继续输入
	while (1)
	{
		std::cin >> ret;
		if (std::cin.fail() || ret < '1' || ret > '4') // 若输入变量类型不同或数字不在要求范围内
		{
			std::cin.clear();
			std::cin.ignore(1024, '\n');                           // 清除缓存区
			std::cout << "输入错误，请重新输入：";                                // 给出错误输入的提示
			continue;
		}
		break;
	}

	return ret;
}

int main()
{

	std::cout << "**        二叉排序树      **" << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << "**    1 -- 建立二叉排序树 **" << std::endl;
	std::cout << "**    2 -- 插入元素       **" << std::endl;
	std::cout << "**    3 -- 查询元素       **" << std::endl;
	std::cout << "**    4 -- 退出程序       **" << std::endl;
	std::cout << "============================" << std::endl;

	BST bst;
	while (1)
	{
		char ch = Choice();
		switch (ch)
		{
		case'1':
			// 将原来的重置
			bst.MakeEmpty(bst.Root());

			// 得到数据
			std::cout << "请输入二叉排序树元素的值，以0结尾：" << std::endl;
			double key;
			while (1)
			{
				while (1)
				{
					std::cin >> key;
					if (std::cin.fail()) // 若输入变量类型不同
					{
						std::cin.clear();
						std::cin.ignore(1024, '\n');                           // 清除缓存区
						std::cout << "输入错误，请重新输入：" << std::endl;         // 给出错误输入的提示
						continue;
					}
					break;
				}
				// 遇到0则结束插入
				if (key == 0.0)  break;
				else bst.Insert(key);
			}
			std::cout << std::endl << "二叉排序树元素有：" << std::endl;
			bst.inOrder(bst.Root());
			std::cout << std::endl;
			break;


		case '2':
			// 若未建树，需先建树
			if (bst.Root() == NULL)	std::cout << "请先建立二叉搜索树！" << std::endl;
			else
			{
				std::cout << "请输入要插入的元素：" << std::endl;
				while (1)
				{
					std::cin >> key;
					if (std::cin.fail()) // 若输入变量类型不同
					{
						std::cin.clear();
						std::cin.ignore(1024, '\n');                           // 清除缓存区
						std::cout << "输入错误，请重新输入：" << std::endl;         // 给出错误输入的提示
						continue;
					}
					break;
				}
				bst.Insert(key);
				std::cout << std::endl << "二叉排序树元素有：" << std::endl;
				bst.inOrder(bst.Root());
				std::cout << std::endl;
			}
			break;

		case '3':
			// 若未建树，需先建树
			if (bst.Root() == NULL)	std::cout << "请先建立二叉搜索树！" << std::endl;
			else
			{
				std::cout << "请输入要查询的元素：" << std::endl;
				while (1)
				{
					std::cin >> key;
					if (std::cin.fail()) // 若输入变量类型不同
					{
						std::cin.clear();
						std::cin.ignore(1024, '\n');                           // 清除缓存区
						std::cout << "输入错误，请重新输入：" << std::endl;         // 给出错误输入的提示
						continue;
					}
					break;
				}
				if (bst.Search(bst.Root(), key))
					std::cout << std::endl << key << "存在于二叉搜索树中！" << std::endl;
				else
					std::cout << std::endl << key << "不存在于二叉搜索树中！" << std::endl;
			}
			break;

		case '4':
			system("pause");
			return 0;
		}

	}
	return 0;
}