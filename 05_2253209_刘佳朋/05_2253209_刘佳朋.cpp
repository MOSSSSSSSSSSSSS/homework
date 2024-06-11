#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<ctype.h>
#include<climits>

// �ֵ����ڵ�
struct TrieNode
{
    TrieNode()
    {
        wordNum = 0;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
    int wordNum;                  // ����Ƶ������Ϊ0˵����ǰλ�ò��ڴ�β
    TrieNode* next[26];           // ָ��26�����ܵĺ�̽ڵ㣨26����ĸ��
};

// �ֵ��� Trie��
class Trie {

public:

    // ���캯����Ϊ���ڵ�����ռ�
    Trie()
    {
        root = NULL;

        root = new TrieNode;

        // ���ռ������󣬽��д�����ʾ
        if (root == NULL)
        {
            std::cerr << "�ڴ�������" << std::endl;
            system("pause");
            exit(1);
        }
    }

    // ���ֵ������뵥��word
    void insert(std::string word)
    {
        TrieNode* current = root;

        // ����word���ַ����Ӹ��ڵ㿪ʼ��һֱ������
        for (int i = 0; i < word.length(); i++)
        {
            char c = word[i];
            // �������NULL����new���½ڵ�
            if (current->next[c - 'a'] == nullptr)
            {
                current->next[c - 'a'] = new TrieNode;

                // ���ռ������󣬽��д�����ʾ
                if (current->next[c - 'a'] == NULL)
                {
                    std::cerr << "�ڴ�������" << std::endl;
                    system("pause");
                    exit(1);
                }
            }
            // ����ڵ��Ѿ����ڣ�current˳�������߾Ϳ���
            current = current->next[c - 'a'];
        }
        // ��Ƶ����
        current->wordNum++;
    }

    // ����word���ֵĴ�Ƶ
    int search(std::string word)
    {
        TrieNode* current = root;
        // current�Ӹ��ڵ㿪ʼ������word���ַ�һֱ����������
        for (int i = 0; i < word.length(); i++)
        {
            char c = word[i];
            // ����ߵ���NULL��˵�����word����ǰ׺�����κ�һ��·��������0
            if (current->next[c - 'a'] == nullptr)  return 0;
            current = current->next[c - 'a'];
        }
        //  �������word˳�������꣬��Ҫ�жϴ�ʱcurrent�Ƿ�Ϊ����β�ˣ�����ǣ�����wordNum��������ǣ�˵��word������һ��ǰ׺���������������ص����м�ڵ�ļ�¼ֵ0
        return current->wordNum;
    }

private:
    TrieNode* root;      // ���ڵ�
};

int main()
{
    std::cout << "�ļ�����ϵͳ" << std::endl;

    // �õ��ļ�����
    FILE* fp;
    char fileName[1024];
    std::cout << "�������ļ�����";
    std::cin.getline(fileName, 1024);

    // ���ļ�
    fp = fopen(fileName, "w");

    // ���ļ�����֤��׳��
    if (fp == NULL)
    {
        std::cout << "�ļ���ʧ��" << std::endl;
        system("pause");
        exit(-1);
    }

    // �õ��ļ�����
    std::cout << "������һ��Ӣ�ģ�" << std::endl;
    char fileContent[1024];
    std::cin.getline(fileContent, 1024);

    // ���ļ�����д���ļ�
    fputs(fileContent, fp);

    std::cout << "�����ı��Ѿ��������ı��ļ���" << fileName << "���С�";

    // �ر��ļ�
    fclose(fp);

    // �����������
    std::string keyWord;
    std::cout << "������Ҫ�����Ĺؼ��֣�";
    std::cin >> keyWord;

    // չʾ�ļ�����
    std::cout << std::endl << "��ʾԴ�ļ���" << fileName << "����" << std::endl;
    fp = fopen(fileName, "r");
    fgets(fileContent, 1024, fp);
    std::cout << fileContent;

    // ���ı��еĵ���ȫ����Сд������ʽ�����ֵ�����ͬʱͳ�ƴ�Ƶ
    Trie trie;
    int i = 0;
    std::cout << std::endl;
    while (fileContent[i] != '\0')
    {
        // ����ǰλ�ò�����ĸ�������Ѱ��
        if (!isalpha(fileContent[i]))
        {
            i++;
            continue;
        }
        // current������¼��ǰ����
        std::string current = "";
        while (isalpha(fileContent[i]))
        {
            // ��֤currrnt����Ķ�ΪСд��ĸ
            current += tolower(fileContent[i]);
            i++;
        }
        // ��current��Ϊ�գ������ֵ���
        if (current != " ")  trie.insert(current);
    }

    // ��_keyWord��¼ȫΪСд�Ĺؼ���
    std::string _keyWord = keyWord;

    // ����transform����ת��
    transform(keyWord.begin(), keyWord.end(), _keyWord.begin(), ::tolower);

    // ����Trie�õ��ؼ��ʴ�Ƶ
    std::cout << std::endl << "��Դ�ļ��й������� ��" << trie.search(_keyWord) << "���ؼ��֡�" << keyWord << "��" << std::endl;
    system("pause");
    return 0;

}