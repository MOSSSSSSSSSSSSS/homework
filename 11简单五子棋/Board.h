#pragma once

#ifndef  _BOARD
#define  _BOARD
typedef unsigned long long U64;
const int win = 7;              // 连五
const int flex4 = 6;            // 活四
const int block4 = 5;           // 冲四
const int flex3 = 4;            // 活三
const int block3 = 3;           // 眠三
const int flex2 = 2;            // 活二
const int block2 = 1;           // 眠二
const int Ntype = 8;            // 棋型个数
const int MaxSize = 20;         // 棋盘最大尺寸
const int MaxMoves = 40;        // 每层最大分支数
const int hashSize = 1 << 22;   // 普通置换表尺寸
const int pvsSize = 1 << 20;    // pvs置换表尺寸
const int MaxDepth = 20;        // 最大搜索深度
const int MinDepth = 2;			// 最小搜索深度

// hash表相关
const int hash_exact = 0;
const int hash_alpha = 1;
const int hash_beta = 2;
const int unknown = -20000;

// 点的状态
enum Pieces { White = 0, Black = 1, Empty = 2, Outside = 3 };
// 方向向量
const int dx[4] = { 1, 0, 1, 1 };
const int dy[4] = { 0, 1, 1, -1 };
// 坐标
struct Pos
{
	int x;
	int y;
};

// 带评价的点
struct Point
{
	Pos p;
	int val;
};

// 棋盘单点结构
struct Cell
{
	int piece;			//棋子颜色
	int IsCand;			//两格内棋子数量
	int pattern[2][4];	//黑白双方四个方向的棋型数据
};

// 哈希表结构
struct Hashe
{
	U64 key;
	int depth;
	int hashf;
	int val;
};
struct Pv
{
	U64 key;
	Pos best;
};

// 走法路线
struct Line
{
	int n;
	Pos moves[MaxDepth];
};

struct MoveList
{
	int phase, n, index;
	bool first;
	Pos hashMove;
	Pos moves[64];
};

class Board
{
public:
	int step = 0;                                 // 棋盘落子数
	int size = 15;                                // 棋盘当前尺寸
	int b_start, b_end;                           // 棋盘坐标最小值和最大值
	U64 zobristKey = 0;                           // 表示当前局面的zobristKey
	U64 zobrist[2][MaxSize + 4][MaxSize + 4];     // zobrist键值表
	Hashe hashTable[hashSize];                    // 哈希表
	Pv pvsTable[pvsSize];                         // pvs置换表
	int typeTable[10][6][6][3];                   // 棋型判断辅助表
	int patternTable[65536][2];                   // 棋型表
	int pval[8][8][8][8];                         // 走法评价表
	Cell cell[MaxSize + 8][MaxSize + 8];          // 棋盘
	Pos remMove[MaxSize * MaxSize];               // 走法列表
	Point cand[256];                              // 临时存储走法
	bool IsLose[MaxSize + 4][MaxSize + 4];        // 记录根节点的必败点
	int who = Black;                              // 下子方
	int opp = White;                              // 另一方
	Point rootMove[64];                           // 根节点走法
	int rootCount;                                // 根节点走法个数
	int ply = 0;                                  // 当前搜索的层数

	Board();
	~Board();
	void InitZobrist();
	//初始化棋型表
	void InitChessType();
	void SetSize(int _size);
	void MakeMove(Pos next);
	void DelMove();
	void Undo();
	void ReStart();
	//更新棋型
	void UpdateType(int x, int y);
	U64 Rand64();
	//获取该位置的key编码
	//x,y:棋盘位置的坐标
	//i:四个方向
	int GetKey(int x, int y, int i);
	//获取走法的价值
	//a,b,c,d：四个方向的棋型
	int GetPval(int a, int b, int c, int d);
	//获取棋型
	//key:共16位,每两位存储该位置的状态：黑、白、空、棋盘外
	//role:表示要判断哪一方的棋型：黑或白
	int LineType(int role, int key);
	int ShortLine(int* line);
	//判断是活三还是眠三
	int CheckFlex3(int* line);
	//判断是活四还是眠四
	int CheckFlex4(int* line);
	//生成棋型辅助表
	int GenerateAssist(int len, int len2, int count, int block);

	/* 可内联成员函数 */

	// 返回第step步棋的颜色，先手黑棋，后手白棋
	int color(int step)
	{
		return step & 1;
	}
	// 检查坐标x,y是否越界
	bool CheckXy(int x, int y)
	{
		return cell[x][y].piece != Outside;
	}
	// 返回上一步棋的Cell指针
	Cell* LastMove()
	{
		return &cell[remMove[step - 1].x][remMove[step - 1].y];
	}
	// role:黑棋=1 白棋=0 type:统计棋形个数的数组 c:棋盘该位置的Cell指针
	void TypeCount(Cell* c, int role, int* type)
	{
		++type[c->pattern[role][0]];
		++type[c->pattern[role][1]];
		++type[c->pattern[role][2]];
		++type[c->pattern[role][3]];
	}
	// role:黑棋=1 白棋=0 type:要判断的棋形 c:棋盘该位置的Cell指针
	// 返回cell是否存在棋形type
	bool IsType(Cell* c, int role, int type)
	{
		return c->pattern[role][0] == type || c->pattern[role][1] == type || c->pattern[role][2] == type || c->pattern[role][3] == type;
	}
	// 检查上一步棋是否成连五
	bool CheckWin()
	{
		Cell* c = LastMove();

		return c->pattern[opp][0] == win || c->pattern[opp][1] == win || c->pattern[opp][2] == win || c->pattern[opp][3] == win;
	}

};
#endif