#pragma once
typedef unsigned char  UCHAR;                                                                                 //   ��ϰ���ã�û��
typedef unsigned long long  U64;                                                                              //   ��ϰ���ã�û��
typedef int Point;                                                                                            //   ��ϰ���ã�û��
const int MOV[4] = { 1,31,32,33 };//�ĸ��������ã�����Ϊfour_direction
const int RANGE[16] = { -66,-64,-62,-33,-32,-31,-2,-1,1,2,31,32,33,62,64,66 };//�ĸ����򣬸������������ӣ���16��,four_direction_two
enum Piece { EMPTY = 2, WHITE = 0, BLACK = 1, OUTSIDE = 3 };//һ��λ�ã������к���1������0����2���߽�3�����������color

enum Shape { NONE, BLOCK1, FLEX1, BLOCK2, FLEX2, BLOCK3, FLEX3, BLOCK4, FLEX4, FIVE };//��������

enum HashFlag { HASH_EXACT, HASH_ALPHA, HASH_BETA };
enum FourShape { A = 14, B = 13, C = 12, D = 11, E = 10, F = 9, G = 8, H = 7, I = 6, J = 5, K = 4, L = 3, M = 2, N = 1, FORBID = 15 };
const int FOUR_SHAPE_COUNT = 16;
const int COLOR_COUNT = 2;
static const int WinScore = 100000;
static const int LoseScore = -WinScore;
struct Cand//���棬���µ������ģ������Ƕ��٣�ju_mian
{
	Cand(int p = 0, int v = 0) : point(p), value(v) {}
	Point point;
	int value;
};




//Piece liu = EMPTY;   ��
//Piece ljp = 2;       ��