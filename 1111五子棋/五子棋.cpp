#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;
#define BOARD_SIZE 12
#define TRUE 1
#define FALSE 0
#define START "START"
#define PLACE "PLACE"
#define TURN "TURN"
#define END "END"
enum Color { EMPTY = 2, WHITE = 0, BLACK = 1, OUTSIDE = 3 };//һ��λ�ã������к���1������0����2���߽�3�����������color
enum Shape { NONE, BLOCK1, FLEX1, BLOCK2, FLEX2, BLOCK3, FLEX3, BLOCK4, FLEX4, FIVE };//��������
enum HashFlag { HASH_EXACT, HASH_ALPHA, HASH_BETA };
enum FourShape { A = 14, B = 13, C = 12, D = 11, E = 10, F = 9, G = 8, H = 7, I = 6, J = 5, K = 4, L = 3, M = 2, N = 1 };
typedef int Ver;
typedef int BOOL;
const int BASE_FOUR[4] = { 1,31,32,33 };//�ĸ�����
const int FOUR[8] = { -33,-32,-31,-1,1,31,32,33 };//�ĸ����򣬸�����һ�����ӣ���8��
const int BETA = 100000;
const int ALPHA = -100000;
const int HASHSIZE = 1 << 23;
const int UNKNOWN = -20000;
const int MaxDepth = 7;// 6���е㳬
const int MaxNode = 100;//256̫��ᱬջ�������ᳬ��350mb
struct Node//���棬���µ������ģ������Ƕ���
{
    Node(int ver = 0, int v = 0) :ver(ver), value(v) {}
    Ver ver;
    int value;
};
struct Command
{
    int x;
    int y;
};
int GetX(int ver) { return ver >> 5; }
int GetY(int ver) { return ver & 31; }
int GetVer(int x, int y) { return (x << 5) + y; }
class HashTable//zobrist��ϣ
{
public:
    struct HashItem
    {
        unsigned long long key;
        int depth;
        int value;
        int flag;
        Ver best;
    };
    HashItem* currentItem;
    HashItem table[HASHSIZE];
    unsigned long long hashKey;
    unsigned long long randomVal[2][BOARD_SIZE][BOARD_SIZE];
    HashTable() { InitRandomVal(); }
    unsigned long long Random64() { return (rand() | ((unsigned long long)rand() << 15) | ((unsigned long long)rand() << 30) | ((unsigned long long)rand() << 45) | ((unsigned long long)rand() << 60)); }//32767
    //  ��ʼ��  hashval
    void InitRandomVal()
    {
        srand((unsigned int)time(NULL));
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                randomVal[0][i][j] = Random64();
                randomVal[1][i][j] = Random64();
            }
        }
    }
    int QueryRecord(int depth, int alpha, int beta)
    {
        if (currentItem->key == hashKey)
        {
            if (currentItem->depth >= depth)
            {
                if (currentItem->flag == HASH_EXACT)
                {
                    return currentItem->value;
                }
                else if (currentItem->flag == HASH_ALPHA && currentItem->value <= alpha)
                {
                    return alpha;
                }
                else if (currentItem->flag == HASH_BETA && currentItem->value >= beta)
                {
                    return beta;
                }
            }
        }
        return UNKNOWN;
    }
    //��¼������Ϣ���û���
    void Update(int value, int depth, int flag, Ver best)
    {
        HashItem* c = currentItem;
        c->value = value;
        c->depth = depth;
        c->best = best;
        c->flag = flag;
        c->key = hashKey;
    }
    //���µ�ǰ�����hashKey�Լ�currentItem
    void Move(Ver p, Color now)
    {
        hashKey ^= randomVal[now][GetX(p) - 4][GetY(p) - 4]; //   �������Ĺ�ϣֵ����hashkey
        currentItem = &table[hashKey % HASHSIZE];            //   currentitem����hashkey��Ӧ�ľ���
    }
    bool Present() { return currentItem->key == hashKey; }
    int Value() { return currentItem->value; }
    int Depth() { return currentItem->depth; }
    Ver Best() { return currentItem->best; }
};
class ChessShape
{
public:
    static char shapeTable[256][256];	       //���ͱ�
    static short shapePrior[256][256];	       //���͵ȼ���
    static short shapeRank[256][256];	       //���͹�ֵ��
    static char fourShapeTable[10][10][10][10];//������α�
    static const int fourShapeScore[16];	   //������ͷ�ֵ��
    static void InitShape()
    {
        for (int i = 9; i > 0; i--)
        {
            for (int p1 = 0; p1 < 256; p1++)
            {
                for (int p2 = 0; p2 < 256; p2++)                                                                   //  ����ͨ�� λ���㣬��ʡ�ռ䣬���Ч��
                {
                    if (shapeTable[p1][p2] == 0)
                    {
                        switch (i)
                        {
                        case 9:
                            shapeTable[p1][p2] = CheckFive(p1, p2);
                            break;
                        case 8:
                        case 7:
                            shapeTable[p1][p2] = CheckShape(p1, p2, FIVE);
                            break;
                        default:
                            shapeTable[p1][p2] = CheckShape(p1, p2, i + 2);
                            break;
                        }
                    }
                }
            }
        }
        /*for (int p1 = 0; p1 < 256; p1++)
         {
              for (int p2 = 0; p2 < 256; p2++)                                                                   //  ����ͨ�� λ���㣬��ʡ�ռ䣬���Ч��
              {
                   cout << "p1��ֵ��" << bitset<8>(p1) << "  p2��ֵ��" << bitset<8>(p2) << "  shapeTable[p1][p2]��ֵ��" << (int)shapeTable[p1][p2] << endl;
              }
         }

    system("pause");
    */
        for (int i = 0; i < 256; i++)
            for (int j = 0; j < 256; j++)
            {
                shapePrior[i][j] = GetShapePrior(i, j);
                shapeRank[i][j] = GetShapeRank(i, j);
            }
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                for (int k = 0; k < 10; k++)
                    for (int l = 0; l < 10; l++)
                        fourShapeTable[i][j][k][l] = GetFourShape(i, j, k, l);
        /*
    for (int i = 0; i < 256; i++)
        for (int j = 0; j < 256; j++)
        {
            cout <<"shapePrior[i][j]: " << "�ҷ� " << bitset<8>(i) << "  �з�  " << bitset<8>(j) << "shapePrior[i][j]: " << shapePrior[i][j] << endl;
            cout << "shapeRank[i][j]: " << "�ҷ� " << bitset<8>(i) << "  �з�  " << bitset<8>(j) << "shapeRank[i][j]: " << shapeRank[i][j] << endl;
        }
    system("pause");
    */
    /*for (int p1 = 0; p1 < 256; p1++)
    {
        for (int p2 = 0; p2 < 256; p2++)
        {
            cout << "p1��ֵ��" << bitset<8>(p1) << "  p2��ֵ��" << bitset<8>(p2) << "  shapePrior[i][j]��ֵ��" << (int)shapePrior[p1][p2] << endl;
        }
    }*/


    }
    static short CalPrior(unsigned char pattern[4][2], int now)
    {
        short v1 = shapePrior[pattern[0][1]][pattern[0][0]] + shapePrior[pattern[1][1]][pattern[1][0]] + shapePrior[pattern[2][1]][pattern[2][0]] + shapePrior[pattern[3][1]][pattern[3][0]];
        short v0 = shapePrior[pattern[0][0]][pattern[0][1]] + shapePrior[pattern[1][0]][pattern[1][1]] + shapePrior[pattern[2][0]][pattern[2][1]] + shapePrior[pattern[3][0]][pattern[3][1]];
        return now == 0 ? (v0 << 1) + v1 : (v1 << 1) + v0;
    }
    static int GetFourShape(int s1, int s2, int s3, int s4)
    {
        int n[10] = { 0 };
        n[s1]++; n[s2]++; n[s3]++; n[s4]++;

        if (n[FIVE] >= 1) return A;							// OOOO_
        if (n[FLEX4] >= 1) return B;						// OOO_
        if (n[BLOCK4] >= 2) return B;						// XOOO_ * _OOOX
        if (n[BLOCK4] >= 1 && n[FLEX3] >= 1) return C;		// XOOO_ * _OO
        if (n[BLOCK4] >= 1 && n[BLOCK3] >= 1) return D;		// XOOO_ * _OOX
        if (n[BLOCK4] >= 1 && n[FLEX2] >= 1) return D;		// XOOO_ * _O
        if (n[BLOCK4] >= 1 && n[BLOCK2] >= 1) return E;		// XOOO_ * _OX
        if (n[BLOCK4] >= 1) return F;						// XOOO_
        if (n[FLEX3] >= 2) return G;						// OO_ * _OO
        if (n[FLEX3] >= 1 && n[BLOCK3] >= 1) return H;		// OO_ * _OOX
        if (n[FLEX3] >= 1 && n[FLEX2] >= 1) return H;		// OO_ * _O
        if (n[FLEX3] >= 1 && n[BLOCK2] >= 1) return I;		// OO_ * _OX
        if (n[FLEX3] >= 1) return J;						// OO_
        if (n[BLOCK3] + n[FLEX2] >= 2) return K;			// O_ * _OOX
        if (n[BLOCK3] >= 1) return L;						// _OOX
        if (n[FLEX2] >= 1) return M;						// _O
        if (n[BLOCK2] >= 1) return N;						// _OX

        return 0;
    }
    static int CheckFive(unsigned char p1, unsigned char p2)
    {
        int count = 0;
        for (unsigned char mask = 16; mask != 0 && IsMyStone(p1, p2, mask); mask <<= 1)
        {
            count++;
        }
        for (unsigned char mask = 8; mask != 0 && IsMyStone(p1, p2, mask); mask >>= 1)
        {
            count++;
        }
        return count >= 4 ? FIVE : NONE;
    }
    static int CheckShape(unsigned char p1, unsigned char p2, int nextShape)
    {
        unsigned char temp1 = p1, temp2 = p2;
        int count = 0;
        for (unsigned char mask = 1; mask != 0; mask <<= 1)
        {
            if (IsEmpty(temp1, temp2, mask))
            {
                PutStone(temp1, temp2, mask);
                if (shapeTable[temp1][temp2] == nextShape) count++;
                temp1 = p1, temp2 = p2;
            }
        }
        if (count > 0)
        {
            if (nextShape == FIVE)
            {
                return count >= 2 ? FLEX4 : BLOCK4;
            }
            else
            {
                return nextShape - 2;
            }
        }
        return NONE;
    }
    static bool IsEmpty(unsigned char p1, unsigned char p2, unsigned char mask) { return (p1 & mask) == 0 && (p2 & mask) == 0; }
    static bool IsMyStone(unsigned char p1, unsigned char p2, unsigned char mask) { return (p1 & mask) > 0 && (p2 & mask) == 0; }
    static void PutStone(unsigned char& p1, unsigned char& p2, unsigned char mask) { p1 |= mask; p2 &= ~mask; }
    static short GetShapePrior(unsigned char p1, unsigned char p2)
    {
        int score = 0;
        int val[5] = { 1,4,9,16,25 };
        unsigned char shapeMask[5] = { 0xF0,0x78,0x3C,0x1E,0x0F };
        for (int i = 0; i < 5; i++)
        {
            if ((p2 & shapeMask[i]) == 0)
            {
                int cnt = LowBit(p1 & shapeMask[i]);
                score += val[cnt];
            }
        }
        return score;
    }
    static short GetShapeRank(unsigned char p1, unsigned char p2)
    {
        int score = 0;
        int val[5] = { 3,7,11,15,19 };
        unsigned char shapeMask[5] = { 0xF0,0x78,0x3C,0x1E,0x0F };
        for (int i = 0; i < 5; i++)
        {
            if ((p2 & shapeMask[i]) == 0)
            {
                int cnt = LowBit(p1 & shapeMask[i]);
                score += val[cnt];
            }
        }
        return score;
    }
    static int LowBit(unsigned char p)
    {
        int res = 0;
        while (p)
        {
            p -= (p & (-p));
            res++;
        }
        return res;
    }
};
class Chess
{
public:
    char color;
    char neighbor;		//8��������һ���ڵ�������
    unsigned char pattern[4][2];//4����4������2�Ƿֱ��¼�����͵з�����
    unsigned char shape[4][2];//4�����򼺷��͵з�������
    unsigned char shape4[2];
    void Update1(int k)
    {
        shape[k][0] = ChessShape::shapeTable[pattern[k][0]][pattern[k][1]];
        shape[k][1] = ChessShape::shapeTable[pattern[k][1]][pattern[k][0]];
    }
    void Update4()
    {
        shape4[0] = ChessShape::fourShapeTable[shape[0][0]][shape[1][0]][shape[2][0]][shape[3][0]];
        shape4[1] = ChessShape::fourShapeTable[shape[0][1]][shape[1][1]][shape[2][1]][shape[3][1]];
    }
    void UpdateShape()
    {
        Update1(0); Update1(1); Update1(2); Update1(3);
    }
    short Getprior(int now)
    {
        return ChessShape::CalPrior(pattern, now);
    }
    bool IsNode() { return neighbor > 0 && color == EMPTY; }
};
class Board
{
public:
    Chess board[1024];						//��������,��¼ÿ��λ�õ������Ϣ
    Ver remVer[1024];					    //��¼ÿ�����λ��
    Chess* remChess[1024];					//��¼ÿ�����chessָ��
    Ver remULNode[1024];					//��¼���Ͻ�
    Ver remLRNode[1024];					//��¼���½�
    int chessCount;							//������
    Color now, opp;							//��ǰ���ӷ����Լ���һ��
    int nShape[2][16];						//˫����һ���ܳɵ�����ͳ��
    Ver upperLeft;						    //���Ͻ�
    Ver lowerRight;						    //���½�
    HashTable* hashTable;
    Board(HashTable* _hashTable)
    {
        hashTable = _hashTable;
        InitBoard();
    }
    void InitBoard()
    {
        for (int i = 0; i < 1024; i++)
        {
            if (GetX(i) >= 4 && GetX(i) < BOARD_SIZE + 4 && GetY(i) >= 4 && GetY(i) < BOARD_SIZE + 4)
            {
                board[i].color = EMPTY;
            }
            else
            {
                board[i].color = OUTSIDE;
            }
        }
        for (int i = 0; i < 1024; i++)
        {
            if (IsInBoard(i))
            {
                for (int k = 0; k < 4; k++)
                {
                    int ii = i - BASE_FOUR[k];
                    for (unsigned char p = 8; p != 0; p >>= 1)
                    {
                        if (board[ii].color == OUTSIDE) board[i].pattern[k][0] |= p;
                        if (board[ii].color == OUTSIDE) board[i].pattern[k][1] |= p;
                        ii -= BASE_FOUR[k];
                    }
                    ii = i + BASE_FOUR[k];
                    for (unsigned char p = 16; p != 0; p <<= 1)
                    {
                        if (board[ii].color == OUTSIDE) board[i].pattern[k][0] |= p;
                        if (board[ii].color == OUTSIDE) board[i].pattern[k][1] |= p;
                        ii += BASE_FOUR[k];
                    }
                }
            }
        }
        for (int i = 0; i < 1024; i++)
        {
            if (IsInBoard(i))
            {
                board[i].Update1(0);
                board[i].Update1(1);
                board[i].Update1(2);
                board[i].Update1(3);
                board[i].Update4();
            }
        }
        chessCount = 0;
        now = BLACK;
        opp = WHITE;
        upperLeft = GetVer(BOARD_SIZE + 3, BOARD_SIZE + 3);
        lowerRight = GetVer(4, 4);
        memset(nShape, 0, sizeof nShape);
    }
    void Move(Ver p)
    {
        nShape[0][board[p].shape4[0]]--;
        nShape[1][board[p].shape4[1]]--;

        hashTable->Move(p, now);

        board[p].color = now;
        remChess[chessCount] = &board[p];
        remVer[chessCount] = p;
        remULNode[chessCount] = upperLeft;
        remLRNode[chessCount] = lowerRight;
        chessCount++;

        int x1 = GetX(upperLeft), y1 = GetY(upperLeft);
        int x2 = GetX(lowerRight), y2 = GetY(lowerRight);

        if (GetX(p) - 2 < x1) x1 = max(GetX(p) - 2, 4);
        if (GetY(p) - 2 < y1) y1 = max(GetY(p) - 2, 4);
        if (GetX(p) + 2 > x2) x2 = min(GetX(p) + 2, BOARD_SIZE + 3);
        if (GetY(p) + 2 > y2) y2 = min(GetY(p) + 2, BOARD_SIZE + 3);
        upperLeft = GetVer(x1, y1);                                                        //    ԭ���ֱ������̵����Ͻǣ����½�
        lowerRight = GetVer(x2, y2);

        //����λ�����Լ�������Ϣ
        for (int k = 0; k < 4; k++)
        {
            Ver move_p = p;
            //p��move_p���ұߣ���λ����
            for (unsigned char m = 16; m != 0; m <<= 1)
            {
                move_p -= BASE_FOUR[k];
                int x = GetX(move_p) - 4;
                int y = GetY(move_p) - 4;
                board[move_p].pattern[k][now] |= m;
                if (board[move_p].color == EMPTY)
                {
                    unsigned char& s0 = board[move_p].shape4[0];
                    unsigned char& s1 = board[move_p].shape4[1];
                    board[move_p].Update1(k);
                    nShape[0][s0]--; nShape[1][s1]--;
                    board[move_p].Update4();
                    nShape[0][s0]++; nShape[1][s1]++;
                }
            }
            move_p = p;
            //p��move_p����ߣ���λ����
            for (unsigned char m = 8; m != 0; m >>= 1)
            {
                move_p += BASE_FOUR[k];
                board[move_p].pattern[k][now] |= m;
                if (board[move_p].color == EMPTY)
                {
                    unsigned char& s0 = board[move_p].shape4[0];
                    unsigned char& s1 = board[move_p].shape4[1];
                    board[move_p].Update1(k);
                    nShape[0][s0]--; nShape[1][s1]--;
                    board[move_p].Update4();
                    nShape[0][s0]++; nShape[1][s1]++;
                }
            }
        }
        //����8�������������ڵ�������
        for (int r : FOUR)
        {
            board[p + r].neighbor++;
        }
        swap(now, opp);
    }
    void Undo()
    {
        chessCount--;
        Ver p = remVer[chessCount];
        upperLeft = remULNode[chessCount];
        lowerRight = remLRNode[chessCount];

        Chess* chess = remChess[chessCount];
        chess->Update1(0);
        chess->Update1(1);
        chess->Update1(2);
        chess->Update1(3);
        chess->Update4();

        nShape[0][chess->shape4[0]]++;
        nShape[1][chess->shape4[1]]++;
        chess->color = EMPTY;

        swap(now, opp);

        hashTable->Move(p, now);

        //����λ�����Լ�������Ϣ
        for (int k = 0; k < 4; k++)
        {
            Ver move_p = p;
            //p��move_p���ұߣ�����move_p�ĸ�λ
            for (unsigned char m = 16; m != 0; m <<= 1)
            {
                move_p -= BASE_FOUR[k];
                board[move_p].pattern[k][now] ^= m;
                if (board[move_p].color == EMPTY)
                {
                    unsigned char& s0 = board[move_p].shape4[0];
                    unsigned char& s1 = board[move_p].shape4[1];
                    board[move_p].Update1(k);
                    nShape[0][s0]--; nShape[1][s1]--;
                    board[move_p].Update4();
                    nShape[0][s0]++; nShape[1][s1]++;
                }
            }
            move_p = p;
            //p��move_p�ĵ���ߣ�����move_p�ĵ�λ
            for (unsigned char m = 8; m != 0; m >>= 1)
            {
                move_p += BASE_FOUR[k];
                board[move_p].pattern[k][now] ^= m;
                if (board[move_p].color == EMPTY)
                {
                    unsigned char& s0 = board[move_p].shape4[0];
                    unsigned char& s1 = board[move_p].shape4[1];
                    board[move_p].Update1(k);
                    nShape[0][s0]--; nShape[1][s1]--;
                    board[move_p].Update4();
                    nShape[0][s0]++; nShape[1][s1]++;
                }
            }
        }
        //����8�������������ڵ�������
        for (int r : FOUR)
        {
            board[p + r].neighbor--;
        }
    }
    void GenerateNode(Node node[], int& nNode)
    {
        nNode = 0;
        if (nShape[now][A] > 0)
        {
            for (int i = upperLeft; i <= lowerRight; i++)
            {
                if (board[i].IsNode() && board[i].shape4[now] == A)
                {
                    nNode = 1;
                    node[0].ver = i;
                    return;
                }
            }
        }

        if (nShape[opp][A] > 0)
        {
            for (int i = upperLeft; i <= lowerRight; i++)
            {
                if (board[i].IsNode() && board[i].shape4[opp] == A)
                {
                    nNode = 1;
                    node[0].ver = i;
                    return;
                }
            }
        }
        if (nShape[now][B] > 0)
        {
            for (int i = upperLeft; i <= lowerRight; i++)
            {
                if (board[i].IsNode() && board[i].shape4[now] == B)
                {
                    nNode = 1;
                    node[0].ver = i;
                    return;
                }
            }
        }
        //��ѯ��ϣ���е���ѵ�
        Ver hashMove = 0;
        if (hashTable->Present() && hashTable->Depth() >= 0 && hashTable->Best() != 0)
        {
            hashMove = hashTable->Best();
            node[0].ver = hashMove;
            node[0].value = BETA;
            nNode = 1;
        }
        if (nShape[opp][B] > 0)
        {
            for (int i = upperLeft; i <= lowerRight; i++)
            {
                if (board[i].IsNode() && i != hashMove)
                {
                    if (board[i].shape4[now] >= F || board[i].shape4[opp] >= F)
                    {
                        node[nNode].value = board[i].Getprior(now);
                        node[nNode++].ver = i;
                    }
                }
            }
            return;
        }

        for (int i = upperLeft; i <= lowerRight; i++)
        {
            if (board[i].IsNode() && i != hashMove)
            {
                node[nNode].value = board[i].Getprior(now);
                node[nNode].ver = i;
                if (node[nNode].value > 1) nNode++;
                if (nNode >= MaxNode)break;
            }
        }
    }
    void SortNode(Node node[], int nNode)
    {
        Node key;
        int i, j;
        for (i = 1; i < nNode; i++)
        {
            key = node[i];
            for (j = i; j > 0 && node[j - 1].value < key.value; j--)
            {
                node[j] = node[j - 1];
            }
            node[j] = key;
        }
    }
    int Evaluate()
    {
        int p;
        int eval[2] = { 0 };
        Chess* c;
        for (int i = 0; i < chessCount; i++)
        {
            c = remChess[i];
            p = c->color;
            for (int k = 0; k < 4; k++)
            {
                eval[p] += ChessShape::shapeRank[c->pattern[k][p]][c->pattern[k][1 - p]];
            }
        }
        return eval[now] - eval[opp] + 70;
    }
    //   �����ϵ�ÿ������  x����y���꣬�и���x�����y�õ���ver���и������Ӹ�����Ӧ�ı��		
    //   chesscount �� ��������һ��������µ�һ���ӵı�� �� chesscount - 1
    int GetColor(int x, int y) { return board[GetVer(x, y)].color; }
    bool IsInBoard(int ver) { return board[ver].color != OUTSIDE; }
};
class Ai
{
public:
    Node rootNode[MaxNode];					    //���ڵ��֧
    int nRootNode = 0;							//���ڵ��֧��
    Board* board;
    HashTable* hashTable;
    Ai()
    {
        hashTable = new HashTable();
        board = new Board(hashTable);
        ChessShape::InitShape();
    }
    ~Ai()
    {
        delete hashTable;
        delete board;
    }
    void Move(int x, int y)
    {
        int ver = GetVer(x + 4, y + 4);
        board->Move(ver);
    }
    void CutLoseNode()
    {
        for (int i = nRootNode - 1; i >= 0; i--)
        {
            if (rootNode[i].value == ALPHA)
            {
                for (int j = i + 1; j < nRootNode; j++)
                {
                    rootNode[j - 1] = rootNode[j];
                }
                nRootNode--;
            }
        }
    }
    void FindBest(int& x, int& y)
    {                                                                                                   //   �Է�������ֵ�ai�¡�
        Node best;                                                                                      //   node��ʾһ����֧�����������֧�� �µ��λ��ver�������֧��value
        board->GenerateNode(rootNode, nRootNode);													    //   rootnode��һ�����飬�����и��ڵ�ķ�֧��n rootnode�Ƿ�֧����
        board->SortNode(rootNode, nRootNode);
        /*for (int i = 0; i < nRootNode; i++)
        {
            cout << "node��" << GetX(rootNode[i].ver) - 4 << ' ' << GetY(rootNode[i].ver) - 4 << endl;
        }*/
        for (int i = 1; i <= MaxDepth; i++)                                                             //   ��ൽmaxdep���Ϊֹ
        {
            int depth = i;
            best = RootSearch(depth, ALPHA, BETA);
            /*for (int j = 0; j < nRootNode; j++)
            {
                cout << "node 6 ��" << GetX(rootNode[j].ver) - 4 << ' ' << GetY(rootNode[j].ver) - 4 << endl;
                cout << rootNode[j].value << endl;
                cout << nRootNode << endl;
            }
            */
            if (best.value == ALPHA || best.value == BETA || nRootNode == 1)
            {
                break;
            }

            board->SortNode(rootNode, nRootNode);
            CutLoseNode();
            /*for (int j = 0; j < nRootNode; j++)
            {
                cout << "node��" << GetX(rootNode[j].ver) - 4 << ' ' << GetY(rootNode[j].ver) - 4 << endl;
                cout << rootNode[j].value << endl;
                cout << nRootNode << endl;
            }*/
            if (nRootNode == 1)
            {
                best = rootNode[0];
                break;
            }
        }

        x = GetX(best.ver) - 4;
        y = GetY(best.ver) - 4;
        Move(x, y);
    }
    Node RootSearch(int depth, int alpha, int beta)
    {
        Node best = Node(0, alpha - 1);
        int value;
        for (int i = 0; i < nRootNode; i++)
        {
            board->Move(rootNode[i].ver);
            do
            {
                if (i > 0 && alpha + 1 < beta)
                {
                    value = -Search(depth - 1, -alpha - 1, -alpha);
                    if (value <= alpha || value >= beta)
                    {
                        break;
                    }
                }
                value = -Search(depth - 1, -beta, -alpha);
            } while (0);
            board->Undo();
            rootNode[i].value = value;
            if (value > best.value)
            {
                best = rootNode[i];
                alpha = value;
                if (value == BETA) return best;
            }
        }
        return best;
    }
    int Search(int depth, int alpha, int beta)
    {
        int q;
        //����Ҷ�ڵ�
        if (depth <= 0)
        {
            return board->Evaluate();
        }
        if ((q = hashTable->QueryRecord(depth, alpha, beta)) != UNKNOWN) return q;

        int hash_flag = HASH_ALPHA;
        Node node[MaxNode];
        int nNode = 0;
        board->GenerateNode(node, nNode);
        board->SortNode(node, nNode);
        /*for (int i = 0; i < nNode; i++)
        {
            cout << "node 2 ��" << GetX(node[i].ver) - 4 << ' ' << GetY(node[i].ver) - 4 << endl;
        }*/
        int value;
        Ver best = node[0].ver;
        for (int i = 0; i < nNode; i++)
        {
            board->Move(node[i].ver);
            do
            {
                if (i > 0 && alpha + 1 < beta)
                {
                    value = -Search(depth - 1, -alpha - 1, -alpha);
                    if (value <= alpha || value >= beta)
                    {
                        break;
                    }
                }
                value = -Search(depth - 1, -beta, -alpha);
            } while (0);
            board->Undo();

            if (value >= beta)
            {
                if (beta != alpha + 1) hashTable->Update(beta, depth, HASH_BETA, node[i].ver);
                return beta;
            }
            if (value > alpha)
            {
                hash_flag = HASH_EXACT;
                best = node[i].ver;
                alpha = value;
            }
        }
        if (beta != alpha + 1)
        {
            hashTable->Update(alpha, depth, hash_flag, best);
        }
        return alpha;
    }
};





Ai* ai = new Ai();
char ChessShape::shapeTable[256][256] = { 0 };
short ChessShape::shapePrior[256][256] = { 0 };
short ChessShape::shapeRank[256][256] = { 0 };
char ChessShape::fourShapeTable[10][10][10][10] = { 0 };
int myFlag;
int enemyFlag;
void debug(const char* str)
{
    printf("DEBUG %s\n", str);
    fflush(stdout);
}
BOOL isValidPos(int x, int y) { return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && ai->board->GetColor(x + 4, y + 4) == EMPTY; }
void place(struct Command cmd) { ai->Move(cmd.x, cmd.y); }
void start()
{
    int middlePlace = BOARD_SIZE / 2;
    ai->Move(middlePlace - 1, middlePlace);
    ai->Move(middlePlace - 1, middlePlace - 1);
    ai->Move(middlePlace, middlePlace - 1);
    ai->Move(middlePlace, middlePlace);
}
void turn()
{
    //for (int i = 0; i < ai->board->chessCount; i++)
    //{
    //    Chess* c = ai->board->remChess[i];
    //    char p = c->color;
    //    for (int k = 0; k < 4; k++)
    //    {
    //        cout << "shape: " << int(c->shape[k][p])/* << ' ' << int(c->shape[k][1 - p])*/ << endl;
    //        cout << "����" << ai->board->chessCount << ' ' << "%%% k = " << k << ' ' << "p= " << int(p) << ' ' << GetX(ai->board->remVer[i]) - 4 << ' ' << GetY(ai->board->remVer[i]) - 4 << ' ' << bitset<8>(c->pattern[k][p]) << ' ' << bitset<8>(c->pattern[k][1 - p]) << endl;
    //    }
    //}
    int newX, newY;
    ai->FindBest(newX, newY);
    printf("%d %d", newX, newY);
    printf("\n");
    fflush(stdout);
}
void end(int x)
{
    exit(0);
}
void loop()
{
    char tag[10] = { 0 };
    struct Command command =
    {
        command.x = 0,
        command.y = 0,
    };
    int status;
    while (TRUE)
    {
        memset(tag, 0, sizeof(tag));
        scanf("%s", tag);
        if (strcmp(tag, START) == 0)
        {
            scanf("%d", &myFlag);
            start();
            printf("OK\n");
            fflush(stdout);
        }
        else if (strcmp(tag, PLACE) == 0)
        {
            scanf("%d %d", &command.x, &command.y);
            place(command);
        }
        else if (strcmp(tag, TURN) == 0)
        {
            turn();
        }
        else if (strcmp(tag, END) == 0)
        {
            scanf("%d", &status);
            end(status);
        }
    }
}
int main(int argc, char* argv[])
{
    loop();
    return 0;
}