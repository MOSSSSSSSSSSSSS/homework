#include<iostream>
#include<string>
#include<iomanip>
#include<climits>

// 得到一个[ minNum，maxNum ]的数字，进行了输入错误处理，保证健壮性
int getint(const int minNum = INT_MIN, const int maxNum = INT_MAX, const std::string errorTips = "")
{
	int retNum = INT_MIN;
	while (1)
	{
		std::cin >> retNum;
		if (std::cin.fail() || retNum < minNum || retNum > maxNum) // 若输入变量类型不同或数字不在要求范围内
		{
			std::cin.clear();
			std::cin.ignore(65536, '\n');                           // 清除缓存区
			std::cout << errorTips;                                // 给出错误输入的提示
			continue;
		}
		break;
	}
	return retNum;
}

// 得到一个长度不超过 lengthMax 的字符串，进行了输入错误处理，保证健壮性
std::string getstring(const unsigned int lengthMax = INT_MAX, const std::string inputTips = "")
{
	std::string retString;
	while (1)
	{
		std::cin >> retString;
		if (retString.size() > lengthMax) // 若字符串长度超过要求
		{
			std::cin.clear();
			std::cin.ignore(65536, '\n');        // 清除缓存区
			std::cout << inputTips;             // 从此处开始重新输入的提示
			continue;
		}
		break;
	}
	return retString;
}

// 节点，一个节点表示一个考生的信息
struct LinkedListNode
{
	int testNum;                      // 考号
	std::string name;                 // 姓名
	std::string sex;                  // 性别 0为男，1为女
	int age;                          // 年龄 
	std::string testMajor;            // 报考职业
	LinkedListNode* next;             // 指向下一个节点

	// 构造函数，设置考生初始信息
	LinkedListNode(const int num1 = 0, const std::string str1 = "", const std::string str2 = "", int const num2 = 0, const std::string str3 = "", LinkedListNode* num3 = NULL)
	{
		testNum = num1, name = str1, sex = str2, age = num2, testMajor = str3, next = num3;
		next = NULL;
	}
	// 输出考生信息
	void Display()
	{
		std::cout << std::setw(14) << std::setiosflags(std::ios::left) << testNum;
		std::cout << std::setw(14) << std::setiosflags(std::ios::left) << name;
		std::cout << std::setw(8) << std::setiosflags(std::ios::left) << sex;
		std::cout << std::setw(8) << std::setiosflags(std::ios::left) << age;
		std::cout << testMajor << std::endl;
	}
}student;

// 链表类
class LinkedList
{
public:

	// 构造函数，设置初始信息
	LinkedList()
	{
		// 为头指针分配空间
		head = new LinkedListNode;
		// 若失败则给出提示，保证健壮性
		if (head == NULL)
		{
			std::cerr << "内存分配错误！" << std::endl;
			system("pause");
			exit(1);
		}
		std::cout << "首先请建立考生信息系统！" << std::endl << "请输入考生人数：";
		int stuNum = getint(1, INT_MAX, "考生人数输入错误，请从此处开始重新输入：");
		std::cout << "请依次输入考生的考号(应大于0)，姓名(长度不超过10且无空格)，性别(男/女)，年龄(0,100)及报考类别(长度不超过10且无空格)！" << std::endl;
		// 设置初始考生的信息，保证了健壮性，同时防止了考号重复
		for (int i = 0; i < stuNum; i++)
		{
			LinkedListNode current;
			current.testNum = getint(0, INT_MAX, "考号输入错误，请从此处开始重新输入：");

			// 对考号重复进行处理
			if (Search(current.testNum) != -1)
			{
				std::cout << "已经有该考号考生存在，请从此处开始重新输入：" << std::endl;
				i--;
				std::cin.clear();
				std::cin.ignore(1024, '\n');                           // 清除缓存区
				continue;
			}

			current.name = getstring(10, "姓名输入错误，请从此处开始重新输入：");
			while (current.sex != "男" && current.sex != "女")
				current.sex = getstring(2, "性别输入错误，请从此处开始重新输入：");
			current.age = getint(1, 99, "年龄输入错误，请从此处开始重新输入：");
			current.testMajor = getstring(10, "报考类别输入错误，请从此处开始重新输入：");
			Insert(i, current);
		}
	}

	// 析构函数，释放空间
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

	// 计算带附加头结点的单链表的长度
	int Length()
	{
		// retNum为长度
		int retNum = 0; LinkedListNode* current = head->next;
		// 循链扫描，寻找链尾
		while (current != NULL)
		{
			current = current->next; retNum++;
		}
		return retNum;
	}

	// 寻找链表中是否含有x考号考生，搜索成功返回该节点位置，否则返回-1
	int Search(int x)
	{
		int retNum = 1;
		LinkedListNode* current = head->next;
		while (current != NULL)
		{
			// 搜索成功，跳出循环
			if (current->testNum == x) return retNum;
			// 当前节点搜索失败，搜索下一个节点
			else current = current->next; retNum++;
		}
		//未搜索到
		return -1;
	}

	// 定位函数，返回表中第i个元素的地址
	LinkedListNode* Locate(int i)
	{
		// i不合理，返回NULL保证健壮性
		if (i < 0)return NULL;
		LinkedListNode* current = head; int k = 0;
		while (current != NULL && k < i)
			current = current->next, k++;
		// 返回第i个节点地址，若返回NULL,则代表i值太大
		return current;
	}

	// 删除第i个元素,x返回该元素的值
	bool Remove(int i, LinkedListNode& x)
	{
		LinkedListNode* current = Locate(i - 1);

		// 删除失败
		if (current == NULL || current->next == NULL) return false;

		// 重新拉链，将被删节点从链中摘下
		LinkedListNode* del = current->next;
		current->next = del->next;

		// 记录删除节点的信息
		x.name = del->name;
		x.age = del->age;
		x.sex = del->sex;
		x.testNum = del->testNum;
		x.testMajor = del->testMajor;
		x.next = del->next;

		delete del;
		return true;
	}

	// 将新元素x插入到第i个节点后
	bool Insert(int i, LinkedListNode& x)
	{
		LinkedListNode* current = Locate(i);

		// 插入不成功
		if (current == NULL)return false;

		LinkedListNode* newNode = new LinkedListNode(x);
		// 空间申请异常
		if (newNode == NULL)
		{
			std::cerr << "内存分配错误！" << std::endl;
			system("pause");
			exit(1);
		}

		// 链接在current之后
		newNode->next = current->next;
		current->next = newNode;

		// 插入成功
		return true;
	}

	// 将链表中信息依次输出
	void Display()
	{
		LinkedListNode* current = head->next;
		std::cout << std::endl << "考号          姓名          性别    年龄    报考类别" << std::endl;
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
	LinkedListNode* head;           // 链表头指针 
};

int main()
{
	LinkedList testSignSystem;
	testSignSystem.Display();
	std::cout << "请输入您要进行的操作（1为插入，2为删除，3为修改，4为查找，5为统计，0为退出操作）" << std::endl;
	for (;;)
	{
		// 得到要进行的操作类型，保证了健壮性
		int optionNum;
		std::cout << "请输入您要进行的操作：";
		optionNum = getint(0, 5, "输入错误！请从此处开始重新输入您要进行的操作：");

		// 退出程序
		if (!optionNum)
		{
			std::cout << "测试结束，请退出程序！" << std::endl;
			break;
		}

		// 插入操作
		else if (optionNum == 1)
		{
			int locate = -1;
			std::cout << "请输入你要插入的考生位置：";
			locate = getint() - 1;
			std::cout << "请依次输入考生的考号(应大于0)，姓名(长度不超过10且无空格)，性别(男/女)，年龄(0,100)及报考类别(长度不超过10且无空格)！" << std::endl;
			int testNum = getint(0, INT_MAX, "考号输入错误，请从此处开始重新输入：");
			std::string name = getstring(10, "姓名输入错误，请从此处开始重新输入：");
			std::string sex = "";
			while (sex != "男" && sex != "女")
				sex = getstring(2, "性别输入错误，请从此处开始重新输入：");
			int age = getint(0, 100, "年龄输入错误，请从此处开始重新输入：");
			std::string testMajor = getstring(10, "报考类别输入错误，请从此处开始重新输入：");

			LinkedListNode current(testNum, name, sex, age, testMajor);

			// 对插入失败做了健壮性处理
			if (!testSignSystem.Insert(locate, current))std::cout << "插入位置不合法，操作失败！" << std::endl;
			testSignSystem.Display();
		}

		// 删除操作
		else if (optionNum == 2)
		{
			int locate = -1;
			std::cout << "请输入你要删除的考生考号：";
			locate = getint();
			locate = testSignSystem.Search(locate);

			// 对删除失败做了健壮性处理
			LinkedListNode del;
			if (!testSignSystem.Remove(locate, del))std::cout << "删除不合法，操作失败！" << std::endl;
			else
			{
				std::cout << "删除考生信息：";
				del.Display();
			}
			testSignSystem.Display();
		}

		// 修改操作，保证了插入者学号不重复
		else if (optionNum == 3)
		{
			int locate = -1;
			std::cout << "请输入你要修改的考生考号：";
			locate = getint();
			locate = testSignSystem.Search(locate);
			if (locate == -1)std::cout << "修改不合法，操作失败！" << std::endl;
			else
			{
				LinkedListNode del;
				testSignSystem.Remove(locate, del);
				std::cout << "修改考生信息：";
				del.Display();
				std::cout << "请依次输入修改后考生的考号(应大于0)，姓名(长度不超过10且无空格)，性别(男/女)，年龄(0,100)及报考类别(长度不超过10且无空格)！" << std::endl;
				int testNum = getint(0, INT_MAX, "考号输入错误，请从此处开始重新输入：");
				// 对考号重复进行处理
				if (testSignSystem.Search(testNum) != -1)
				{
					std::cout << "已经有该考号考生存在，请从此处开始重新输入：" << std::endl;
					std::cin.clear();
					std::cin.ignore(1024, '\n');                           // 清除缓存区
					continue;
				}

				std::string name = getstring(10, "姓名输入错误，请从此处开始重新输入：");
				std::string sex = "";
				while (sex != "男" && sex != "女")
					sex = getstring(2, "性别输入错误，请从此处开始重新输入：");
				int age = getint(0, 100, "年龄输入错误，请从此处开始重新输入：");
				std::string testMajor = getstring(10, "报考类别输入错误，请从此处开始重新输入：");

				LinkedListNode current(testNum, name, sex, age, testMajor);
				testSignSystem.Insert(locate - 1, current);
			}
			testSignSystem.Display();
		}
		// 查找操作
		else if (optionNum == 4)
		{
			int locate = -1;
			std::cout << "请输入你要查找的考生考号：";
			locate = getint();
			locate = testSignSystem.Search(locate);
			// 对查找失败进行了健壮性处理
			if (locate == -1)std::cout << "查找不合法，操作失败！" << std::endl;
			else
			{
				std::cout << "查找考生信息：";
				(*testSignSystem.Locate(locate)).Display();
			}
			testSignSystem.Display();
		}
		// 统计操作
		else if (optionNum == 5)
		{
			std::cout << "当前系统存储考生数量：" << testSignSystem.Length() << std::endl;
			testSignSystem.Display();
		}
	}
	system("pause");
	return 0;
}