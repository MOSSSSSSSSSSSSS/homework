#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;
#define BOARD_SIZE 12
typedef int BOOL;
#define TRUE 1
#define FALSE 0
#define START "START"
#define PLACE "PLACE"
#define TURN "TURN"
#define END "END"
typedef int Ver;                                                                                            //   ��ϰ���ã�û��
const int MOV[4] = { 1,31,32,33 };//�ĸ��������ã�����Ϊfour_direction
const int RANGE[16] = { -66,-64,-62,-33,-32,-31,-2,-1,1,2,31,32,33,62,64,66 };//�ĸ����򣬸������������ӣ���16��,four_direction_two
//ָ����  ver �仯�ĵ㣬����Ҳ��
//8�����Ե�
const int horse[8] = { -65,-63,-34,-30,30,34,63,65 };                                              //   ������ 
const int Range4[32] = { -1,-31,-32,-33,1,31,32,33,-2,-62,-64,-66,2,62,64,66,-3,-93,-96,-99,3,93,96,99,-65,-63,-34,-30,30,34,63,65 };						//4���ڵ����ַ�Χ
const int Range3[32] = { -1,-31 - 32,-33,1,31,32,33,-2,-62,-64,-66,2,62,64,66,-3,-93,-96,-99,3,93,96,99,-4,-124,-128,-132,4,124,128,132 };					//3���ڵ����ַ�Χ�Ͱ��Ե�
enum Piece { EMPTY = 2, WHITE = 0, BLACK = 1, OUTSIDE = 3 };//һ��λ�ã������к���1������0����2���߽�3�����������color
enum Shape { NONE, BLOCK1, FLEX1, BLOCK2, FLEX2, BLOCK3, FLEX3, BLOCK4, FLEX4, FIVE };//��������
enum HashFlag { HASH_EXACT, HASH_ALPHA, HASH_BETA };
enum FourShape { A = 14, B = 13, C = 12, D = 11, E = 10, F = 9, G = 8, H = 7, I = 6, J = 5, K = 4, L = 3, M = 2, N = 1 };
const int FOUR_SHAPE_COUNT = 16;
const int COLOR_COUNT = 2;
const int WIN_SCORE = 100000;
const int LOSE_SCORE = -100000;
const int HASHSIZE = 1 << 23;
const int UNKNOWN = -20000;
const int MaxDepth = 7;// 50  6������е㳬
const int MaxCand = 256;//256                ��̫��ᱬջ�������ᳬ��350mb

struct Cand//���棬���µ������ģ������Ƕ��٣�ju_mian
{
    Cand(int p = 0, int v = 0) : ver(p), value(v) {}
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
class HashTable
{

public:
    HashTable()
    {
        InitHashVal();
    }
    void InitHashVal()
    {
        srand((unsigned int)time(NULL));
        for (int i = 0; i < 2048; i++)
            hashVal[i] = Random();
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
    void   Update(int _value, int _depth, int _flag, Ver _best)
    {
        HashItem* c = currentItem;
        c->value = _value;
        c->depth = _depth;
        c->best = _best;
        c->flag = _flag;
        c->key = hashKey;
    }
    //���µ�ǰ�����hashKey�Լ�currentItem
    void Move(Ver p, Piece who)
    {
        hashKey ^= hashVal[p + (who << 10)];
        currentItem = &table[hashKey % HASHSIZE];
    }
    bool Present() { return currentItem->key == hashKey; }
    short Value() { return currentItem->value; }
    short Depth() { return currentItem->depth; }
    Ver Best() { return currentItem->best; }
    unsigned long long Random() { return (rand() | ((unsigned long long)rand() << 15) | ((unsigned long long)rand() << 30) | ((unsigned long long)rand() << 45) | ((unsigned long long)rand() << 60)); }//32767
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
    unsigned long long   hashKey;
    unsigned long long hashVal[2048];
};
class ChessShape
{
public:
    static void initShape()
    {
        memset(shapeTable, 0, sizeof(shapeTable));
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
                            shapeTable[p1][p2] = checkFive(p1, p2);
                            break;
                        case 8:
                        case 7:
                            shapeTable[p1][p2] = checkShape(p1, p2, FIVE);
                            break;
                        default:
                            shapeTable[p1][p2] = checkShape(p1, p2, i + 2);
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 256; i++)
            for (int j = 0; j < 256; j++)
            {
                shapePrior[i][j] = getShapePrior(i, j);
                shapeRank[i][j] = getShapeRank(i, j);
            }
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                for (int k = 0; k < 10; k++)
                    for (int l = 0; l < 10; l++)
                        fourShapeTable[i][j][k][l] = getFourShape(i, j, k, l);

    }
    static short calPrior(unsigned char pattern[4][2], int who)
    {
        short v1 = shapePrior[pattern[0][1]][pattern[0][0]] + shapePrior[pattern[1][1]][pattern[1][0]] + shapePrior[pattern[2][1]][pattern[2][0]] + shapePrior[pattern[3][1]][pattern[3][0]];
        short v0 = shapePrior[pattern[0][0]][pattern[0][1]] + shapePrior[pattern[1][0]][pattern[1][1]] + shapePrior[pattern[2][0]][pattern[2][1]] + shapePrior[pattern[3][0]][pattern[3][1]];
        return who == 0 ? (v0 << 1) + v1 : (v1 << 1) + v0;
    }
    static char shapeTable[256][256];	//���ͱ�
    static short shapePrior[256][256];	//���͵ȼ���
    static short shapeRank[256][256];	//���͹�ֵ��
    static char fourShapeTable[10][10][10][10];//������α�
    static const int fourShapeScore[16];	//������ͷ�ֵ��
    static int getFourShape(int s1, int s2, int s3, int s4)
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
    static int checkFive(unsigned char p1, unsigned char p2)
    {
        int count = 0;
        for (unsigned char mask = 16; mask != 0 && isMyStone(p1, p2, mask); mask <<= 1)
        {
            count++;
        }
        for (unsigned char mask = 8; mask != 0 && isMyStone(p1, p2, mask); mask >>= 1)
        {
            count++;
        }
        return count >= 4 ? FIVE : NONE;
    }
    static int checkShape(unsigned char p1, unsigned char p2, int nextShape)
    {
        unsigned char temp1 = p1, temp2 = p2;
        int count = 0;
        for (unsigned char mask = 1; mask != 0; mask <<= 1)
        {
            if (isEmpty(temp1, temp2, mask))
            {
                putStone(temp1, temp2, mask);
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
    static bool isEmpty(unsigned char p1, unsigned char p2, unsigned char mask) { return (p1 & mask) == 0 && (p2 & mask) == 0; }
    static bool isMyStone(unsigned char p1, unsigned char p2, unsigned char mask) { return (p1 & mask) > 0 && (p2 & mask) == 0; }
    static void putStone(unsigned char& p1, unsigned char& p2, unsigned char mask) { p1 |= mask; p2 &= ~mask; }
    static short getShapePrior(unsigned char p1, unsigned char p2)
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
    static short getShapeRank(unsigned char p1, unsigned char p2)
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
    void update1(int k)
    {
        shape[k][0] = ChessShape::shapeTable[pattern[k][0]][pattern[k][1]];
        shape[k][1] = ChessShape::shapeTable[pattern[k][1]][pattern[k][0]];
    }
    void update4()
    {
        shape4[0] = ChessShape::fourShapeTable[shape[0][0]][shape[1][0]][shape[2][0]][shape[3][0]];
        shape4[1] = ChessShape::fourShapeTable[shape[0][1]][shape[1][1]][shape[2][1]][shape[3][1]];
    }
    void updateShape()
    {
        update1(0); update1(1); update1(2); update1(3);
    }

    char piece;
    char neighbor;		//8�������������ڵ�������
    unsigned char pattern[4][2];
    unsigned char shape[4][2];
    unsigned char shape4[2];

    short prior(int who)
    {
        return ChessShape::calPrior(pattern, who);
    }
    bool isCand() { return neighbor > 0 && piece == EMPTY; }
};
class Board
{
public:
    int dep;								//��ǰ��������
    int maxdep;								//ʵ��������������

    int fiveVer[2];						//��¼�����
    Chess board[1024];						//��������,��¼ÿ��λ�õ������Ϣ
    Ver remVer[1024];					//��¼ÿ�����λ��
    Chess* remChess[1024];					//��¼ÿ�����chessָ��
    Ver remULCand[1024];					//��¼���Ͻ�
    Ver remLRCand[1024];					//��¼���½�
    int chessCount;							//������
    Piece who, opp;							//��ǰ���ӷ����Լ���һ��
    int nShape[2][16];						//˫����һ���ܳɵ�����ͳ��
    Ver upperLeft;						//���Ͻ�
    Ver lowerRight;						//���½�


    Board(HashTable* _hashTable)
    {
        hashTable = _hashTable;
        initBoard();
    }
    void initBoard()
    {
        memset(board, 0, sizeof(board));
        for (int i = 0; i < 1024; i++)
        {
            if (GetX(i) >= 4 && GetX(i) < BOARD_SIZE + 4 && GetY(i) >= 4 && GetY(i) < BOARD_SIZE + 4)
            {
                board[i].piece = EMPTY;
            }
            else
            {
                board[i].piece = OUTSIDE;
            }
        }
        for (int i = 0; i < 1024; i++)
        {
            if (inBoard(i))
            {
                for (int k = 0; k < 4; k++)
                {
                    int ii = i - MOV[k];
                    for (unsigned char p = 8; p != 0; p >>= 1)
                    {
                        if (board[ii].piece == OUTSIDE) board[i].pattern[k][0] |= p;
                        if (board[ii].piece == OUTSIDE) board[i].pattern[k][1] |= p;
                        ii -= MOV[k];
                    }
                    ii = i + MOV[k];
                    for (unsigned char p = 16; p != 0; p <<= 1)
                    {
                        if (board[ii].piece == OUTSIDE) board[i].pattern[k][0] |= p;
                        if (board[ii].piece == OUTSIDE) board[i].pattern[k][1] |= p;
                        ii += MOV[k];
                    }
                }
            }
        }
        for (int i = 0; i < 1024; i++)
        {
            if (inBoard(i))
            {
                board[i].update1(0);
                board[i].update1(1);
                board[i].update1(2);
                board[i].update1(3);
                board[i].update4();
            }
        }
        chessCount = 0;
        who = BLACK;
        opp = WHITE;
        upperLeft = GetVer(BOARD_SIZE + 3, BOARD_SIZE + 3);
        lowerRight = GetVer(4, 4);
        memset(nShape, 0, sizeof(nShape));
    }
    void move(Ver p)
    {
        dep++;
        if (dep > maxdep) maxdep = dep;
        nShape[0][board[p].shape4[0]]--;
        nShape[1][board[p].shape4[1]]--;

        hashTable->Move(p, who);

        board[p].piece = who;
        remChess[chessCount] = &board[p];
        remVer[chessCount] = p;
        remULCand[chessCount] = upperLeft;
        remLRCand[chessCount] = lowerRight;
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
                move_p -= MOV[k];
                int x = GetX(move_p) - 4;
                int y = GetY(move_p) - 4;
                board[move_p].pattern[k][who] |= m;
                if (board[move_p].piece == EMPTY)
                {
                    unsigned char& s0 = board[move_p].shape4[0];
                    unsigned char& s1 = board[move_p].shape4[1];
                    board[move_p].update1(k);
                    nShape[0][s0]--; nShape[1][s1]--;
                    board[move_p].update4();
                    nShape[0][s0]++; nShape[1][s1]++;
                    if (s0 == A) fiveVer[0] = move_p;
                    if (s1 == A) fiveVer[1] = move_p;
                }
            }
            move_p = p;
            //p��move_p����ߣ���λ����
            for (unsigned char m = 8; m != 0; m >>= 1)
            {
                move_p += MOV[k];
                board[move_p].pattern[k][who] |= m;
                if (board[move_p].piece == EMPTY)
                {
                    unsigned char& s0 = board[move_p].shape4[0];
                    unsigned char& s1 = board[move_p].shape4[1];
                    board[move_p].update1(k);
                    nShape[0][s0]--; nShape[1][s1]--;
                    board[move_p].update4();
                    nShape[0][s0]++; nShape[1][s1]++;
                    if (s0 == A) fiveVer[0] = move_p;
                    if (s1 == A) fiveVer[1] = move_p;
                }
            }
        }
        //����8�������������ڵ�������
        for (int r : RANGE)
        {
            board[p + r].neighbor++;
        }
        swap(who, opp);
    }
    void undo()
    {
        dep--;
        chessCount--;
        Ver p = remVer[chessCount];
        upperLeft = remULCand[chessCount];
        lowerRight = remLRCand[chessCount];

        Chess* chess = remChess[chessCount];
        chess->update1(0);
        chess->update1(1);
        chess->update1(2);
        chess->update1(3);
        chess->update4();

        nShape[0][chess->shape4[0]]++;
        nShape[1][chess->shape4[1]]++;
        if (chess->shape4[0] == A) fiveVer[0] = p;
        if (chess->shape4[1] == A) fiveVer[1] = p;
        chess->piece = EMPTY;

        swap(who, opp);

        hashTable->Move(p, who);

        //����λ�����Լ�������Ϣ
        for (int k = 0; k < 4; k++)
        {
            Ver move_p = p;
            //p��move_p���ұߣ�����move_p�ĸ�λ
            for (unsigned char m = 16; m != 0; m <<= 1)
            {
                move_p -= MOV[k];
                board[move_p].pattern[k][who] ^= m;
                if (board[move_p].piece == EMPTY)
                {
                    unsigned char& s0 = board[move_p].shape4[0];
                    unsigned char& s1 = board[move_p].shape4[1];
                    board[move_p].update1(k);
                    nShape[0][s0]--; nShape[1][s1]--;
                    board[move_p].update4();
                    nShape[0][s0]++; nShape[1][s1]++;
                    if (s0 == A) fiveVer[0] = move_p;
                    if (s1 == A) fiveVer[1] = move_p;
                }
            }
            move_p = p;
            //p��move_p�ĵ���ߣ�����move_p�ĵ�λ
            for (unsigned char m = 8; m != 0; m >>= 1)
            {
                move_p += MOV[k];
                board[move_p].pattern[k][who] ^= m;
                if (board[move_p].piece == EMPTY)
                {
                    unsigned char& s0 = board[move_p].shape4[0];
                    unsigned char& s1 = board[move_p].shape4[1];
                    board[move_p].update1(k);
                    nShape[0][s0]--; nShape[1][s1]--;
                    board[move_p].update4();
                    nShape[0][s0]++; nShape[1][s1]++;
                    if (s0 == A) fiveVer[0] = move_p;
                    if (s1 == A) fiveVer[1] = move_p;
                }
            }
        }
        //����8�������������ڵ�������
        for (int r : RANGE)
        {
            board[p + r].neighbor--;
        }
    }
    bool check()
    {
        int n[COLOR_COUNT][FOUR_SHAPE_COUNT] = { 0 };
        for (int m = 0; m < 1024; m++)
        {
            if (board[m].piece == EMPTY)
            {
                n[0][board[m].shape4[0]]++;
                n[1][board[m].shape4[1]]++;
            }
        }
        for (int i = 0; i < COLOR_COUNT; i++)
            for (int j = 1; j < FOUR_SHAPE_COUNT; j++)
                if (n[i][j] != nShape[i][j])
                {
                    return false;
                }
        return true;
    }
    void generateCand(Cand cand[], int& nCand)
    {
        nCand = 0;
        if (nShape[who][A] > 0)
        {
            for (int i = upperLeft; i <= lowerRight; i++)
            {
                if (board[i].isCand() && board[i].shape4[who] == A)
                {
                    nCand = 1;
                    cand[0].ver = i;
                    return;
                }
            }
        }

        if (nShape[opp][A] > 0)
        {
            nCand = 1;
            cand[0].ver = fiveVer[opp];
            return;
        }
        if (nShape[who][B] > 0)
        {
            for (int i = upperLeft; i <= lowerRight; i++)
            {
                if (board[i].isCand() && board[i].shape4[who] == B)
                {
                    nCand = 1;
                    cand[0].ver = i;
                    return;
                }
            }
        }
        //��ѯ��ϣ���е���ѵ�
        Ver hashMove = 0;
        if (hashTable->Present() && hashTable->Depth() >= 0 && hashTable->Best() != 0)
        {
            hashMove = hashTable->Best();
            cand[0].ver = hashMove;
            cand[0].value = WIN_SCORE;
            nCand = 1;
        }
        if (nShape[opp][B] > 0)
        {
            for (int i = upperLeft; i <= lowerRight; i++)
            {
                if (board[i].isCand() && i != hashMove)
                {
                    if (board[i].shape4[who] >= F || board[i].shape4[opp] >= F)
                    {
                        cand[nCand].value = board[i].prior(who);
                        cand[nCand++].ver = i;
                    }
                }
            }
            return;
        }

        for (int i = upperLeft; i <= lowerRight; i++)
        {
            if (board[i].isCand() && i != hashMove)
            {
                cand[nCand].value = board[i].prior(who);
                cand[nCand].ver = i;
                if (cand[nCand].value > 1) nCand++;
            }
        }
    }
    void sortCand(Cand cand[], int nCand)
    {
        Cand key;
        int i, j;
        for (i = 1; i < nCand; i++)
        {
            key = cand[i];
            for (j = i; j > 0 && cand[j - 1].value < key.value; j--)
            {
                cand[j] = cand[j - 1];
            }
            cand[j] = key;
        }
    }
    void getEmptyCand(Cand cand[], int& nCand)
    {
        for (int m = upperLeft; m < lowerRight; m++)
        {
            if (board[m].piece == EMPTY)
            {
                cand[nCand++] = { m,0 };
            }
        }
    }
    int evaluate()
    {
        int p;
        int eval[2] = { 0 };
        Chess* c;
        for (int i = 0; i < chessCount; i++)
        {
            c = remChess[i];
            p = c->piece;
            for (int k = 0; k < 4; k++)
            {
                eval[p] += ChessShape::shapeRank[c->pattern[k][p]][c->pattern[k][1 - p]];
            }
        }
        return eval[who] - eval[opp] + 70;
    }
    int quickWinSearch()
    {
        int q;
        if (nShape[who][A] >= 1) return 1;
        if (nShape[opp][A] >= 2) return -2;
        if (nShape[opp][A] == 1)
        {
            move(fiveVer[opp]);
            q = -quickWinSearch();
            undo();
            if (q < 0) q--; else if (q > 0) q++;
            return q;

        }
        if (nShape[who][B] >= 1) return 3;
        if (nShape[who][C] >= 1)             // XOOO_ * _OO
        {
            if (nShape[opp][B] == 0 && nShape[opp][C] == 0 && nShape[opp][D] == 0 && nShape[opp][E] == 0 && nShape[opp][F] == 0) return 5;
            for (int m = upperLeft; m < lowerRight; m++)
            {
                if (board[m].isCand() && board[m].shape4[who] == C)
                {

                    move(m);
                    q = -quickWinSearch();
                    undo();
                    if (q > 0)
                    {
                        return q + 1;
                    }

                }
            }
        }
        if (nShape[who][G] >= 1)
        {
            if (nShape[opp][B] == 0 && nShape[opp][C] == 0 && nShape[opp][D] == 0 && nShape[opp][E] == 0 && nShape[opp][F] == 0)
            {
                return 5;
            }
        }
        return 0;
    }
    Ver findVer(Piece piece, FourShape shape)
    {
        for (int m = upperLeft; m < lowerRight; m++)
        {
            if (board[m].isCand() && board[m].shape4[piece] == shape)
            {
                return m;
            }
        }
        return -1;
    }
    Ver findVCFStartVer()
    {
        for (int i = chessCount - 2; i >= 0; i -= 2)                             //   �����ϵ�ÿ������  x����y���꣬�и���x�����y�õ���ver���и������Ӹ�����Ӧ�ı��
        {																		 //   chesscount �� ��������һ��������µ�һ���ӵı�� �� chesscount - 1
            Chess* c = remChess[i];
            c->updateShape();
            if (c->shape[0][who] >= BLOCK3 || c->shape[1][who] >= BLOCK3 || c->shape[2][who] >= BLOCK3 || c->shape[3][who] >= BLOCK3)
            {
                return remVer[i];
            }
        }
        return -1;
    }
    Ver findVCTStartVer()
    {
        for (int i = chessCount - 2; i >= 0; i -= 2)
        {
            Chess* c = remChess[i];
            c->updateShape();
            if (c->shape[0][who] >= FLEX2 || c->shape[1][who] >= FLEX2 || c->shape[2][who] >= FLEX2 || c->shape[3][who] >= FLEX2)
            {
                return remVer[i];
            }
        }
        return -1;
    }

    int verPiece(int x, int y) { return board[GetVer(x, y)].piece; }
    bool inBoard(int ver) { return board[ver].piece != OUTSIDE; }

    HashTable* hashTable;
};
class AI
{
public:
    AI()
    {
        hashTable = new HashTable();
        board = new Board(hashTable);
        ChessShape::initShape();
    }
    ~AI()
    {
        delete hashTable;
        delete board;
    }
    void Undo()
    {
        board->undo();
    }
    void Move(int x, int y)
    {
        int ver = GetVer(x + 4, y + 4);
        board->move(ver);
    }
    void FindBest(int& x, int& y)
    {                                                                                                   //   �Է�������ֵ�ai�¡�
        Cand best;                                                                                      //   cand��ʾһ����֧�����������֧�� �µ��λ��ver�������֧��value
        stopAi = false;																			//   ���������ı�־��һ��ʼ��false
        board->generateCand(rootCand, nRootCand);													//   rootcand��һ�����飬�����и��ڵ�ķ�֧��n rootcand�Ƿ�֧����
        board->sortCand(rootCand, nRootCand);
        board->dep = 0, board->maxdep = 0;
        for (int i = 1; i <= MaxDepth; i++)                                        //   ��mindep��ȿ�ʼ����ൽmaxdep���Ϊֹ
        {
            int depth = i;
            best = rootSearch(depth, LOSE_SCORE, WIN_SCORE);
            if (/*rootBest.value == WIN_SCORE || rootBest.value == LOSE_SCORE || nRootCand == 1 || */ stopAi) break;
        }

        x = GetX(best.ver) - 4;
        y = GetY(best.ver) - 4;
        Move(x, y);
    }
    Cand rootSearch(int depth, int alpha, int beta)
    {
        Cand best = Cand(0, alpha - 1);
        int value;
        for (int i = 0; i < nRootCand; i++)
        {
            board->move(rootCand[i].ver);
            do
            {
                if (i > 0 && alpha + 1 < beta)
                {
                    value = -search(depth - 1, -alpha - 1, -alpha);
                    if (value <= alpha || value >= beta)
                    {
                        break;
                    }
                }
                value = -search(depth - 1, -beta, -alpha);
            } while (0);
            board->undo();
            if (stopAi) break;

            rootCand[i].value = value;
            if (value > best.value)
            {
                best = rootCand[i];
                alpha = value;
                if (value == WIN_SCORE) return best;
            }

        }
        return best;

    }
    int search(int depth, int alpha, int beta)
    {
        static int cnt;
        if (--cnt < 0)
        {
            cnt = 1000;
        }
        //��ʤ
        int q = board->quickWinSearch();
        if (q != 0) return q > 0 ? WIN_SCORE : LOSE_SCORE;
        //����Ҷ�ڵ�
        if (depth <= 0)
        {
            return board->evaluate();
        }
        if ((q = hashTable->QueryRecord(depth, alpha, beta)) != UNKNOWN) return q;          // �����pvs�ڵ�

        int hash_flag = HASH_ALPHA;
        Cand cand[MaxCand];
        int nCand = 0;
        board->generateCand(cand, nCand);

        if (nCand == 0)
        {
            board->getEmptyCand(cand, nCand);
        }
        else if (nCand > 1)
        {
            board->sortCand(cand, nCand);
        }
        int value;
        Ver best = cand[0].ver;
        for (int i = 0; i < nCand; i++)
        {
            board->move(cand[i].ver);
            do
            {
                if (i > 0 && alpha + 1 < beta)
                {
                    value = -search(depth - 1, -alpha - 1, -alpha);
                    if (value <= alpha || value >= beta)
                    {
                        break;
                    }
                }
                value = -search(depth - 1, -beta, -alpha);
            } while (0);
            board->undo();

            if (value >= beta)
            {
                if (!stopAi && beta != alpha + 1) hashTable->Update(beta, depth, HASH_BETA, cand[i].ver);
                return beta;
            }
            if (value > alpha)
            {
                hash_flag = HASH_EXACT;
                best = cand[i].ver;
                alpha = value;
            }
            if (stopAi) break;
        }
        if (!stopAi && beta != alpha + 1)
        {
            hashTable->Update(alpha, depth, hash_flag, best);
        }
        return alpha;
    }

    Cand rootBest;							//���ڵ㷵�ص���ѵ�
    Cand rootCand[MaxCand];					//���ڵ��֧
    int nRootCand;							//���ڵ��֧��
    bool stopAi;						//ֹͣ������־
    Board* board;
    HashTable* hashTable;
};

AI* ai = new AI();
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
BOOL isValidPos(int x, int y) { return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && ai->board->verPiece(x + 4, y + 4) == EMPTY; }
void place(struct Command cmd) { ai->Move(cmd.x, cmd.y); }
void start()
{
    int middlePlace = BOARD_SIZE / 2;
    ai->Move(middlePlace - 1, middlePlace - 1);
    ai->Move(middlePlace, middlePlace - 1);
    ai->Move(middlePlace, middlePlace);
    ai->Move(middlePlace - 1, middlePlace);
}
void turn()
{
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