#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define BOARD_SIZE 12
typedef int BOOL;
#define TRUE 1
#define FALSE 0
#define START "START"
#define PLACE "PLACE"
#define TURN "TURN"
#define END "END"
enum Color{EMPTY,BLACK,WHITE,OUTSIDE};
enum Shape{NONE,BLOCK1,FLEX1,BLOCK2,FLEX2,BLOCK3,FLEX3,BLOCK4,FLEX4,FIVE};
enum HashFlag { HASH_EXACT, HASH_ALPHA, HASH_BETA };
enum FourShape{N = 1,M,L,K,J,I,H,G,F,E,D,C,B,A};
const int FourDirectionOne[4] = { 1,11,12,13 };
const int EightDirectionTwo[16] = { -26,-24,-22,-13,-12,-11,-2,-1,1,2,11,12,13,22,24,26 };
const int Alpha = -100000;
const int Beta = 100000;
const int MINDEP = 1;
const int MAXDEP = 50;
const int NUM_OF_HASHVAL = 1260;
const int HASHSIZE = 1 << 23;

struct Command
{
    int x;
    int y;
};


struct HashItem
{
    unsigned long long hashkey;
    int dep;
    int value;
    int flag;
    int bestVer;
};
HashItem nowItem;
unsigned long long hashKey;
unsigned long long hashVal[NUM_OF_HASHVAL];
HashItem hashTable[HASHSIZE];
void InitHashVal()                                                              //  初始化  hashval
{
    srand(time(NULL));
    for (int i = 0; i < 2048; i++)
    {
        hashVal[i] = Rand64();                                                  //  hashval是一个2048大小的数组，填充满随机数，随机数的质量比较重要
    }
}
unsigned long long Rand64() { return rand() ^ ((unsigned long long)rand() << 15) ^ ((unsigned long long)rand() << 30) ^ ((unsigned long long)rand() << 45) ^ ((unsigned long long)rand() << 60); }
class HashTable
{
public:
    HashTable()
    {
        initHashVal();
    }
    void initHashVal()                                                              //  初始化  hashval
    {
        srand(time(NULL));
        for (int i = 0; i < 2048; i++)
        {
            hashVal[i] = Rand64();                                                  //  hashval是一个2048大小的数组，填充满随机数，随机数的质量比较重要
        }
    }
    int queryRecord(int depth, int alpha, int beta)
    {
        //如果是pvs节点,不做置换表截断
        if (beta == alpha + 1) return InvalidVal;
        if (currentItem->key == hashKey)
        {
            if (currentItem->flag == HASH_EXACT && (currentItem->value == WinScore || currentItem->value == LoseScore))
            {
                return currentItem->value;
            }
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
        return InvalidVal;
    }
    //记录局面信息到置换表
    void   update(int _value, int _depth, int _flag, Point _best)
    {
        HashItem* c = currentItem;
        c->value = _value;
        c->depth = _depth;
        c->best = _best;
        c->flag = _flag;
        c->key = hashKey;
    }
    //更新当前局面的hashKey以及currentItem
    void move(Point p, Piece who)
    {
        hashKey ^= hashVal[p + (who << 10)];                                              //   这个局面的哈希值就是hashkey
        currentItem = &table[hashKey % HashSize];                                         //   currentitem就是hashkey对应的局面
    }

    bool present() { return currentItem->key == hashKey; }
    short   value() { return currentItem->value; }
    short   depth() { return currentItem->depth; }
    Point best() { return currentItem->best; }
    U64 Rand64() { return rand() ^ ((U64)rand() << 15) ^ ((U64)rand() << 30) ^ ((U64)rand() << 45) ^ ((U64)rand() << 60); }
    static const int HashSize = 1 << 23;
    static const int InvalidVal = -20000;

    struct HashItem
    {
        U64   key;
        int depth;
        int value;
        int flag;
        Point best;
    };

    HashItem* currentItem;																//  currentitem是一个指向hashitem类型的指针

    HashItem table[HashSize];

    U64   hashKey;
    U64 hashVal[2048];
};


int myFlag;
int enemyFlag;
char shapeTable[256][256];
short shapePrior[256][256];	//棋型等级表
short shapeRank[256][256];	//棋型估值表
char fourShapeTable[10][10][10][10];//组合棋形表
const int fourShapeScore[16];	//组合棋型分值表
void InitShape()
{
    for (int i = 9; i > 0; i--)
    {
        for (int p1 = 0; p1 < 256; p1++)
        {
            for (int p2 = 0; p2 < 256; p2++)                                           
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
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            shapePrior[i][j] = GetShapePrior(i, j);
            shapeRank[i][j] = GetShapeRank(i, j);
        }
    }
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)
                for (int l = 0; l < 10; l++)
                    fourShapeTable[i][j][k][l] = GetFourShape(i, j, k, l);

}
int CheckFive(unsigned char p1, unsigned char p2)                                                        //  就是通过 位运算，节省空间，提高效率
{
    int cnt = 0;
    for (unsigned char mask = 16; mask != 0 && IsMyStone(p1, p2, mask); mask <<= 1)
    {
        cnt++;
    }
    for (unsigned char mask = 8; mask != 0 && IsMyStone(p1, p2, mask); mask >>= 1)
    {
        cnt++;
    }
    return cnt >= 4 ? FIVE : NONE;
}
bool IsEmpty(unsigned char p1, unsigned char p2, unsigned char mask) { return (p1 & mask) == 0 && (p2 & mask) == 0; }
int CheckShape(unsigned char p1, unsigned char p2, int nextShape)
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
bool IsMyStone(unsigned char p1, unsigned char p2, unsigned char mask) { return (p1 & mask) > 0 && (p2 & mask) == 0; }
void PutStone(unsigned char& p1, unsigned char& p2, unsigned char mask) { p1 |= mask; p2 &= ~mask; }
int GetFourShape(int s1, int s2, int s3, int s4)
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
int LowBit(unsigned char p)
{
    int cnt = 0;
    while (p)
    {
        p -= (p & (-p));
        cnt++;
    }
    return cnt;
}
short GetShapePrior(unsigned char p1, unsigned char p2)
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
short GetShapeRank(unsigned char p1, unsigned char p2)
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
short CalPrior(unsigned char pattern[4][2], int now)
{
    short v1 = shapePrior[pattern[0][1]][pattern[0][0]] + shapePrior[pattern[1][1]][pattern[1][0]] + shapePrior[pattern[2][1]][pattern[2][0]] + shapePrior[pattern[3][1]][pattern[3][0]];
    short v0 = shapePrior[pattern[0][0]][pattern[0][1]] + shapePrior[pattern[1][0]][pattern[1][1]] + shapePrior[pattern[2][0]][pattern[2][1]] + shapePrior[pattern[3][0]][pattern[3][1]];
    return now == 0 ? (v0 << 1) + v1 : (v1 << 1) + v0;
}
inline int GetX(int ver){return (ver>>5);}
inline int GetY(int ver){return (ver&31);}
inline int GetVer(int x, int y) { return ((x + 4) << 5) + y + 4; }//630


void debug(const char* str)
{
    printf("DEBUG %s\n", str);
    fflush(stdout);
}
BOOL isInBound(int x, int y)
{
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}
void place(struct Command cmd)
{
    board[cmd.x][cmd.y] = enemyFlag;
}
void initAI(int me)
{
    enemyFlag = 3 - me;
}
void start(int flag)
{
    InitShape();
    InitHashVal();
    int middlePlace = BOARD_SIZE / 2;
    board[middlePlace - 1][middlePlace - 1] = BLACK;
    board[middlePlace][middlePlace] = BLACK;
    board[middlePlace - 1][middlePlace] = WHITE;
    board[middlePlace][middlePlace - 1] = WHITE;
    initAI(flag);
}
void turn()
{
    /*for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == EMPTY)
            {
                printf("%d %d", i, j);
                printf("\n");
                fflush(stdout);
                board[i][j] = myFlag;
                return;
            }
        }
    }*/
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
            start(myFlag);
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