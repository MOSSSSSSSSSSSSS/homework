#ifndef CHESSAI_H
#define CHESSAI_H

#include <QDebug>
#include <QPoint>
#include <QMap>

#define C_NONE 0//���ӣ�����,����,����
#define C_BLACK 1
#define C_WHITE 2

#define RIGHT 0//�������ҡ����ϡ����ϡ�����
#define UP 1
#define UPRIGHT 2
#define UPLEFT 3

//�������͵Ĵ��� /Ȩ��
#define OTHER 0//��������
#define WIN 1//1000000,��Ӯ
#define LOSE 2//-10000000
#define FLEX4 3//50000,�׻�4
#define flex4 4//-100000
#define BLOCK4 5//400
#define block4 6//-100000
#define FLEX3 7//400
#define flex3 8//-8000
#define BLOCK3 9//20
#define block3 10//-40
#define FLEX2 11//20
#define flex2 12//-40
#define BLOCK2 13//1
#define block2 14//-2
#define FLEX1 15//1
#define flex1 16//-2

enum gameMode { PLAYER, AI };
enum gameStatus { UNDERWAY, FINISH };
enum gameTurn { T_BLACK, T_WHITE };//�ֵ�˭��
enum gameResult { R_BLACK, R_WHITE, R_DRAW };//����Ӯ������Ӯ������

struct EVALUATION {
    int score;
    gameResult result;
    int STAT[8];//���沿�����εĸ���,�±�WIN=1Ϊ����5,LOSE=2Ϊ����5,FLEX4=3Ϊ�׻�4,BLOCK4=5Ϊ�׳�4,FLEX3=7Ϊ�׻�3
};
struct POINTS {//�������λ��,[0]�������,[19]�������
    QPoint pos[20];
    int score[20];//�˴����ӵľ��Ʒ���
};
struct DECISION {
    QPoint pos;//λ��
    int eval;//�Է���������
};

class chessAi
{
public:
    int chesses[15][15];//����
    DECISION decision;//���漫��С�����õ���Ҫ�ߵ�λ��

    int nodeNum = 0;

private:
    int tuple6type[4][4][4][4][4][4];//���ͱ�ʶ����,0����,1����,2����,3�߽�
    POINTS points;//�������λ��

public://̰���㷨����
    chessAi();
    int calcOnePosGreedy(int board[15][15], int row, int col, int C_ME);//����ĳһ��λ�ö���me�ķ���(̰��)
    int tupleScoreGreedy(int black, int white, int C_ME);//����ڰ��Ӹ�������Ԫ�����me�ķ���(̰���㷨)
    QPoint getXY(int row, int col, int dir, int rel);//���ڸ����㡢�����ƫ�������õ�ʵ������
    bool checkBound(int x, int y);//���߽�
    QPoint findBestMoveGreedy(int C_ME);//̰���㷨ֻ��һ��,Ч��������,����Ŀ���ǳ

public://��������������
    void init_tuple6type();//�������ж����鸳��ֵ
    POINTS seekPoints(int board[15][15]);//���ɶ��ڰ��ӵ����20������λ�ü�����
    void copyBoard(int A[15][15], int B[15][15]);//��A���̸��Ƶ�B����
    void reverseBoard(int A[15][15], int B[15][15]);//��A���̺ڰ��ӵߵ��������B����
    EVALUATION evaluate(int board[15][15], bool needPrint = false);//�����board�ĺ��ӵľ��ƹ�ֵ����,�������ж���Ӯ
    int analyse(int board[15][15], int depth, int alpha, int beta);//����������С������ab��֦

    bool analyse_kill(int board[15][15], int depth);//����ɱ��,���ҵ�ɱ���򷵻�true
    QList<QPoint> seek_kill_points(int board[15][15]);//�Ұ������5,��4,��4,��3��ɱ��λ��

};

#endif // CHESSAI_H
