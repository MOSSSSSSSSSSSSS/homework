#include<iostream>
#include<iomanip>
#include<climits>

// ��ͼ����������ꡢ�����꣬�������޸�
const int c_xMAX = 6;
const int c_yMAX = 6;

// ������������仯���ֱ�������ҡ��ϡ���
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };

// ��ͼ�ĳ�ʼ״̬��#�����ϰ���0��������ߣ��������޸ģ�ע����c_xMAX��c_yMAXƥ��
char c_map[c_xMAX + 1][c_yMAX + 1] = {
'#', '#', '#', '#', '#', '#', '#',
'#', '0', '#', '0', '0', '0', '#',
'#', '0', '#', '0', '#', '#', '#',
'#', '0', '0', '0', '#', '0', '#',
'#', '0', '#', '0', '0', '0', '#',
'#', '0', '#', '0', '#', '0', '#',
'#', '#', '#', '#', '#', '#', '#' };

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
	// ���캯������ʼ������
	LinkedListNode(int xx = 0, int yy = 0) :x(xx), y(yy) { next = NULL; flag = 0; };
	// չʾ�ýڵ�����
	void Display() { std::cout << '<' << x << ',' << y << '>'; }

	// ��¼�����ꡢ������
	int x, y;
	// ��¼����ʱ�Ƿ��Լ�������
	bool flag;
	// ��¼����ʱ����һ����
	LinkedListNode* next;
};

class Game;

// ������
class LinkedList
{
	friend Game;

public:
	// ���캯����Ϊheadָ������ʼ�ռ�
	LinkedList()
	{
		head = NULL;
		// Ϊͷָ�����ռ�
		head = new LinkedListNode;
		// ��ʧ���������ʾ����֤��׳��
		if (head == NULL)
		{
			std::cerr << "�ڴ�������" << std::endl;
			system("pause");
			exit(1);
		}
		head->next = NULL;
	};

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

	// ���������Ϣ
	void Display()
	{
		LinkedListNode* now = head->next;
		while (now != NULL)
		{
			now->Display();
			now = now->next;
			if (now != NULL)
				std::cout << " --> ";
		}
	}

private:
	LinkedListNode* head;           // ����ͷָ�� 
};

// ��Ϸ������
class Game
{
public:

	// ���캯������ʼ��������Ϣ
	Game()
	{
		for (int i = 0; i < c_xMAX + 1; i++)
			for (int j = 0; j < c_yMAX + 1; j++)
				node[i][j].x = i, node[i][j].y = j;
	}

	// �������������Ѱ·�����ɴﷵ��true����¼·�������ɴﷵ��false
	bool FindPath(int nowX, int nowY, int dstX, int dstY)
	{
		// ��ǰλ��Խ������ϰ�����ɴ�
		if (nowX<0 || nowX>c_xMAX || nowY<0 || nowY>c_yMAX || node[nowX][nowY].flag || c_map[nowX][nowY] == '#')
			return false;

		// ��ǵ�ǰλ���Ѿ�������
		node[nowX][nowY].flag = true;

		// �����ǰλ��Ϊ�յ�
		if (nowX == dstX && nowY == dstY)
		{
			// �ڵ�ͼ�ϱ�Ǵ˵㱻����
			c_map[nowX][nowY] = 'x';
			// ���˵���뵽��ʾ·����������
			path.Insert(path.Length(), node[nowX][nowY]);
			return true;
		}

		// ����������
		for (int i = 0; i < 4; i++)
		{
			// ��������ĵ�ɴ�
			if (FindPath(nowX + dx[i], nowY + dy[i], dstX, dstY))
			{
				// ����ǰ���ڵ�ͼ�ϼ�¼Ϊ��·����
				c_map[nowX][nowY] = 'x';
				// ����ǰ�ĵ���뵽��ʾ·����������
				path.Insert(path.Length(), node[nowX][nowY]);
				return true;
			}
		}
		return false;
	}

	// ����Թ�·��
	void Display()
	{
		std::cout << std::endl << "�Թ�·��" << std::endl << std::endl;
		path.Display();
	}

	bool GetNodeFlag(int x, int y) { return node[x][y].flag; }

private:
	LinkedListNode node[c_xMAX + 1][c_yMAX + 1];
	LinkedList path;
};

int main()
{
	// �����ͼ��ʼ��Ϣ
	std::cout << "��ʼ��ͼ" << std::endl << std::endl;
	std::cout << "        ";
	for (int i = 0; i < c_yMAX + 1; i++)
		std::cout << i << "��        ";
	std::cout << std::endl;

	for (int i = 0; i < c_xMAX + 1; i++)
	{
		std::cout << i << "��     ";
		for (int j = 0; j < c_yMAX + 1; j++)
			std::cout << c_map[i][j] << "          ";
		std::cout << std::endl;
	}

	// ����getint�����õ���㡢�յ���Ϣ��ͬʱ��֤��׳��
	std::cout << "���������x���꣺";
	int srcX = getint(0, c_xMAX, "���x��������������������룺");
	std::cout << "���������y���꣺";
	int srcY = getint(0, c_yMAX, "���y��������������������룺");
	std::cout << "�������յ�x���꣺";
	int dstX = getint(0, c_xMAX, "�յ�x��������������������룺");
	std::cout << "�������յ�y���꣺";
	int dstY = getint(0, c_yMAX, "�յ�y��������������������룺");

	// ��ʼ�����
	if (c_map[srcX][srcY] == '#' || c_map[dstX][dstY] == '#')
	{
		std::cout << "�޷�����" << std::endl;
		return 0;
	}

	Game game;

	// ������޷������յ�
	if (!game.FindPath(dstX, dstY, srcX, srcY))
	{
		std::cout << "�޷�����" << std::endl;
		system("pause");
		return 0;
	}

	// �ܹ�������·����ͼ
	std::cout << std::endl << "·����ͼ" << std::endl << std::endl;

	// ����չʾ��ͼ·��
	for (int i = 0; i < c_yMAX + 1; i++)
		std::cout << i << "��        ";
	std::cout << std::endl;

	for (int i = 0; i < c_xMAX + 1; i++)
	{
		std::cout << i << "��     ";
		for (int j = 0; j < c_yMAX + 1; j++)
			std::cout << c_map[i][j] << "          ";
		std::cout << std::endl;
	}
	// ����չʾ��ͼ·��
	game.Display();
	std::cout << std::endl;
	system("pause");
	return 0;
}