#include<iostream>
#include<cstdlib>
#include<cstdio>
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

// ������
class ChessBoard
{
	friend void SetQueue(ChessBoard& queueProblem, const int currentLine);
public:

	// ���캯�����������ݳ�Ա��Ϣ
	ChessBoard(const int n = 0)
	{
		size = counter = 0;
		line = NULL;
		col = leftDiagonal = rightDiagonal = NULL;

		// ��������ռ�
		// �к��д�1-n ��ţ��ʿռ������һ��
		line = new int[n + 1], col = new bool[n + 1];
		// ��Խ��ߺ��ҶԽ���ͬ�����ݴ�С����ռ�
		leftDiagonal = new bool[2 * n + 1], rightDiagonal = new bool[2 * n + 1];

		if (line == NULL || col == NULL || leftDiagonal == NULL || rightDiagonal == NULL)
		{
			std::cerr << "�ڴ�������" << std::endl;
			system("pause");
			exit(1);
		}

		// ��ʼ��������Ϣ
		for (int i = 0; i < n + 1; i++)
			line[i] = col[i] = 0;

		for (int i = 0; i < 2 * n + 1; i++)
			leftDiagonal[i] = rightDiagonal[i] = 0;

		// ���̴�С��ʼ��
		size = n;
	}

	// �����������ͷ�����Ŀռ�
	~ChessBoard() { delete[]line, delete[]col, delete[]leftDiagonal, delete[]rightDiagonal; }

	// �����ǰ������Ϣ
	void Display()
	{
		for (int i = 1; i < size + 1; i++)
		{
			for (int j = 1; j < size + 1; j++)
			{
				if (j == line[i])	std::cout << 'X' << " ";
				else std::cout << 0 << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	// �õ��𰸼�������ֵ
	int GetCounter()const { return counter; }

private:
	int size;           // ��¼���̴�С
	int* line;          // ��
	bool* col;          // ��
	bool* leftDiagonal; // ��Խ���
	bool* rightDiagonal;// �ҶԽ���
	int counter;        // ��¼������
};

// �ݹ���ûʺ���
void SetQueue(ChessBoard& queueProblem, const int currentLine)  // ��ǰ��currentLine��
{
	// �����ǰ���Ѿ��������̣�˵�����������Ѿ�������ɣ��ҵ�һ���
	if (currentLine > queueProblem.size)
	{
		// ����������
		queueProblem.Display();
		// ����������
		queueProblem.counter++;
		return;
	}

	for (int i = 1; i < queueProblem.size + 1; i++) // ��ǰ��i��
	{
		// �Ե�currentLine�е�i�н��з���������ǰ�С����ҶԽ����Ͼ�δ�������ӣ�����Է��ûʺ�
		if (*(queueProblem.col + i) == 0 && *(queueProblem.rightDiagonal + currentLine + i) == 0 && *(queueProblem.leftDiagonal + currentLine - i + queueProblem.size) == 0)
		{
			// ��currentLine�б�ռ��
			*(queueProblem.line + currentLine) = i;
			// ��col�б�ռ��
			*(queueProblem.col + i) = true;
			// ��currentLine+i���ҶԽ��߱�ռ��
			*(queueProblem.rightDiagonal + currentLine + i) = true;
			// ��currentLine-i+n����Խ��߱�ռ��
			*(queueProblem.leftDiagonal + currentLine - i + queueProblem.size) = true;
			// ������һ�е����Ӱڷ�λ��
			SetQueue(queueProblem, currentLine + 1);
			// �����������������Ϊ�ڵ�ǰ�������½��з��ã���Ҫ����ǰλ�õ�״̬������Ϊ������
			*(queueProblem.col + i) = false;
			*(queueProblem.rightDiagonal + currentLine + i) = false;
			*(queueProblem.leftDiagonal + currentLine - i + queueProblem.size) = false;
		}
	}
}

int main()
{
	// ����������ʾ
	std::cout << "����N��N�����̣�����N���ʺ�Ҫ�����лʺ���ͬһ�С��С��Խ����ϣ�" << std::endl << std::endl;
	std::cout << "������ʺ�ĸ�����6-15����";

	// ����getint�����õ����̴�С����֤��׳�ԣ���n>15�������Ч���޷���֤
	int n = getint(6, 15, "�ʺ��������������������룺");

	// ����ChessBoard�������Ϸ
	ChessBoard queueProblem(n);
	std::cout << std::endl << "�ʺ�ڷ�" << std::endl;

	// ����������
	SetQueue(queueProblem, 1);

	// ����ⷨ����
	std::cout << "����" << queueProblem.GetCounter() << "�ֽⷨ��" << std::endl;

	system("pause");

	return 0;
}