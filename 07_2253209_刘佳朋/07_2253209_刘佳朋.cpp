
#include<iostream>
#include<iomanip>
#include<string>

// ��¼�ڵ��¼�������ֻ��������
enum { isNumber, isOperation };

// ÿ���ڵ����Ϣ
struct info
{
	info()
	{
		value = 0.0;
		operation = '\0';
		infoType = 0;
	}
	double value;                                    // ���ֵ�ֵ 
	char operation;                                  // �����
	bool infoType;                                   // ��¼�ڵ���Ϣ
};

// �������ڵ�
struct BinaryTreeNode
{
	// ���캯����Ϊ���Ҷ��Ӹ�ֵ
	BinaryTreeNode(BinaryTreeNode* lc = NULL, BinaryTreeNode* rc = NULL) :leftChild(lc), rightChild(rc) {};

	// double to BinaryTreeNode ��ʽת��
	BinaryTreeNode(double v) { data.value = v; data.infoType = isNumber; }

	// char to BinaryTreeNode ��ʽת��
	BinaryTreeNode(char o) { data.operation = o; data.infoType = isOperation; }

	BinaryTreeNode* leftChild = NULL, * rightChild = NULL;// ���Ҷ���
	info data;                                            // �ڵ�洢��Ϣ
};
// ������������
std::ostream& operator<<(std::ostream& os, const BinaryTreeNode& x)
{
	// ���ݸýڵ�洢���������ͽ������
	if (x.data.infoType == isOperation) os << x.data.operation;
	if (x.data.infoType == isNumber) os << x.data.value;
	return os;
}

// ������
class BinaryTree
{
public:
	// ���캯��������������ַ������ʽs�������ʽ��
	// ˼·���Ƚ�ԭ���ʽת��Ϊ�沨��ʽ���ٽ��沨��ʽת��Ϊ���ʽ��
	BinaryTree(std::string& s)
	{
		/*����׺���ʽת��Ϊ�沨�����ʽ*/

		char stack1[1024];                // ����������ջ 
		int top1 = 0;                     // ջ��
		int lengthRPN = 0;                // �沨�����ʽ����
		BinaryTreeNode RPN[1024];         // ����沨�����ʽ
		// temp������ȡexpression�еĸ�λ���ֺ�С��

		std::string temp = "";

		// �����ʽ������������
		s += ')';
		stack1[top1++] = '(';

		// �������ʽ
		for (int i = 0; i < s.length(); i++)
		{
			// ���ʽ��λ��Ϊһ�����֣���¼��temp
			if (isdigit(s[i]))
				temp += s[i];

			// С����ֱ�Ӽ���temp
			else if (s[i] == '.')
				temp += s[i];

			// ���ʽ��λ��Ϊ�����
			else
			{
				// ��temp��Ϊ�գ���Ҫ�Ƚ����ڵ�tempת��Ϊ���ֽڵ������沨��ʽ������temp����
				if (temp != "")
				{
					// ����atof������c_str ʵ�� char* to double �� string to char*
					RPN[lengthRPN++] = BinaryTreeNode(atof(temp.c_str()));
					temp = "";
				}

				// ����������ֱ����ջ
				if (s[i] == '(') stack1[top1++] = s[i];

				// �����������򵯳�ջ����������������㣬ֱ������������Ϊֹ
				else if (s[i] == ')')
				{
					// ջΪ�գ���ֱ�ӽ�����һ��ѭ�������ؽ���������ƥ��
					if (!top1) continue;

					// ����ջ�������ֱ��ƥ�䵽������
					while (stack1[top1 - 1] != '(')
						// ��ջ�������ת��Ϊ�ڵ������沨��ʽ��ͬʱ����ջ��Ԫ��
						RPN[lengthRPN++] = BinaryTreeNode(stack1[--top1]);

					top1--; // �����ų�ջ
				}

				else if (CompareOperator(stack1[top1 - 1], s[i]) == 0) stack1[top1++] = s[i];// ջ��Ԫ�����ȼ�С�ڵ�ǰԪ�أ���ǰԪ����ջ
				else if (CompareOperator(stack1[top1 - 1], s[i]) == 1)                       // ջ��Ԫ�����ȼ����ڵ�ǰԪ�أ���ջ
				{
					RPN[lengthRPN++] = BinaryTreeNode(stack1[--top1]);                       // ��ջ�������ת��Ϊ�ڵ������沨��ʽ��ͬʱ����ջ��Ԫ��
					i--;                                                                     // i--�����¶Դ�������ظ�����������ֱ���������ָ������ȼ���Ԫ��(����ջΪ��)Ϊֹ
				}
			}
		}





		/*���沨��ʽת��Ϊ���ʽ��*/

		BinaryTreeNode stack2[1024];     // ��Žڵ��ջ
		int top2 = 0;                    // ջ�� 

		// �����沨��ʽ
		for (int i = 0; i < lengthRPN; i++)
		{
			// �������֣�ֱ����ջ
			if (RPN[i].data.infoType == isNumber) stack2[top2++] = RPN[i];

			// ���������
			if (RPN[i].data.infoType == isOperation)
			{
				BinaryTreeNode* rc = new BinaryTreeNode(stack2[--top2]);  // ȡջ��Ԫ��ΪrightChild
				BinaryTreeNode* lc = new BinaryTreeNode(stack2[--top2]);  // ȡ�ζ�Ԫ��ΪleftChild
				BinaryTreeNode* parent = new BinaryTreeNode(RPN[i]);      // ��¼���ڵ�Ϊ��ǰ������ڵ�
				MergeTree(*lc, *rc, *parent);                             // �������ӹ�ϵ
				stack2[top2++] = *parent;                                 // parent��ջ
				root = parent;                                            // ���¸��ڵ�
			}
		}
	}

	// �ϲ�bt1 bt2���ڵ���parent�ڵ�
	void MergeTree(BinaryTreeNode& bt1, BinaryTreeNode& bt2, BinaryTreeNode& parent)
	{
		// ��������λ������
		parent.leftChild = &bt1, parent.rightChild = &bt2;
	}

	// ����Ϊ���ֱ�������ķ�ʽ��Ϊ��֤�������Էֱ�С������λ������ÿ��Ԫ��֮��������һ���ո��Էָ�
	// ǰ�����
	void preOrder(BinaryTreeNode* current)
	{
		if (current == NULL) return;
		std::cout << *current << ' ';
		preOrder(current->leftChild);
		preOrder(current->rightChild);
	}
	// �������
	void inOrder(BinaryTreeNode* current)
	{
		if (current == NULL) return;
		inOrder(current->leftChild);
		std::cout << *current << ' ';
		inOrder(current->rightChild);
	}
	// �������
	void postOrder(BinaryTreeNode* current)
	{
		if (current == NULL) return;
		postOrder(current->leftChild);
		postOrder(current->rightChild);
		std::cout << *current << ' ';
	}

	BinaryTreeNode* Root() { return root; }
private:
	BinaryTreeNode* root;

	// ��������ȼ��Ƚ�
	bool CompareOperator(const char a, const char b)
	{
		if (a == '*' || a == '/')
		{
			if (b == '(') return 0;
			else return 1;
		}
		else if (a == '+' || a == '-')
		{
			if (b == '+' || b == '-' || b == ')') return 1;
			else return 0;
		}
		else if (a == '(')  return 0;
	}
};

int main()
{
	std::cout << "������֧������С������λ������Ϊ����ֱ����֣������ʱ����Ԫ��֮���пո�" << std::endl;
	std::cout << "��������ʽ(��ʹ��Ӣ������)�� ";
	std::string expression;
	std::cin >> expression;
	BinaryTree expressionTree(expression);

	std::cout << "�������ʽ�� ";
	expressionTree.preOrder(expressionTree.Root());
	std::cout << std::endl << "��׺���ʽ�� ";
	expressionTree.inOrder(expressionTree.Root());
	std::cout << std::endl << "�沨�����ʽ��";
	expressionTree.postOrder(expressionTree.Root());
	std::cout << std::endl << std::endl;
	system("pause");
	return 0;
}