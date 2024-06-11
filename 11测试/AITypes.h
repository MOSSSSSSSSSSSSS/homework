#pragma once
typedef unsigned char  UCHAR;                                                                                 //   不习惯用，没用
typedef unsigned long long  U64;                                                                              //   不习惯用，没用
typedef int Point;                                                                                            //   不习惯用，没用
const int MOV[4] = { 1,31,32,33 };//四个方向，有用，改名为four_direction
const int RANGE[16] = { -66,-64,-62,-33,-32,-31,-2,-1,1,2,31,32,33,62,64,66 };//四个方向，各延申两个棋子，共16个,four_direction_two
enum Piece { EMPTY = 2, WHITE = 0, BLACK = 1, OUTSIDE = 3 };//一个位置，可能有黑棋1，白棋0，空2，边界3，四种情况，color

enum Shape { NONE, BLOCK1, FLEX1, BLOCK2, FLEX2, BLOCK3, FLEX3, BLOCK4, FLEX4, FIVE };//各种棋形

enum HashFlag { HASH_EXACT, HASH_ALPHA, HASH_BETA };
enum FourShape { A = 14, B = 13, C = 12, D = 11, E = 10, F = 9, G = 8, H = 7, I = 6, J = 5, K = 4, L = 3, M = 2, N = 1, FORBID = 15 };
const int FOUR_SHAPE_COUNT = 16;
const int COLOR_COUNT = 2;
static const int WinScore = 100000;
static const int LoseScore = -WinScore;
struct Cand//局面，新下的棋在哪，评分是多少，ju_mian
{
	Cand(int p = 0, int v = 0) : point(p), value(v) {}
	Point point;
	int value;
};




//Piece liu = EMPTY;   对
//Piece ljp = 2;       错