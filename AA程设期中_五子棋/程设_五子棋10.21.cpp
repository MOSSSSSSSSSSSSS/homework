#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<utility>
#define INF 1e8
#define BOARD_SIZE 12
#define EMPTY 0
#define BLACK 1
#define WHITE 2
#define TRUE 1
#define FALSE 0
#define START "START"
#define PLACE "PLACE"
#define TURN "TURN"
#define END "END"
#define OTHER 0//��������
#define WIN 1//�ҷ�Ӯ
#define LOSE 2//�з�Ӯ
#define FLEX4 3//�ҷ�����
#define flex4 4//�з�����
#define BLOCK4 5//�Դ����ƣ���д�ҷ���Сд�Է�
#define block4 6
#define FLEX3 7
#define flex3 8
#define BLOCK3 9
#define block3 10
#define FLEX2 11
#define flex2 12
#define BLOCK2 13
#define block2 14
#define FLEX1 15
#define flex1 16
#define DEPTH 3             //    �����Ϊ4����ʱ
using namespace std;
int all_types[4][4][4][4][4][4];                                                                     //  ���������������ϵ����λ��
int weight[17] = { 0,1000000,-10000000,50000,-100000,400,-100000,400,-8000,20,-50,20,-50,1,-3,1,-3 };//  ������Ȩֵ 

//bool trick = true;                                                                                   //  trick������ҷ����壬��һ������

typedef int BOOL;
typedef pair<int, int> PII;

struct Command
{
    int x;
    int y;
};
struct evaluation {
    int score = 0;
    bool flag = false;                                   //  �ܲ����ѵ�ĳһ��Ӯ�Ľ������Ӯ����ô����ڵ�֮��ȫΪӮ
};
char board[BOARD_SIZE][BOARD_SIZE] = { 0 };    // 0�� 11
int myFlag,enemyFlag;

//PII* find_best_15pos(char copy_board[BOARD_SIZE][BOARD_SIZE])                                        //  dfsʱ��ö�ٵ��Ƿ�����ߵ� 15 ���㣬����ö�����п��ܵĵ㣬����ʱ��Ϳռ����ģ���ȸ���
//{
  //  ;
//}
BOOL isInBound(int x, int y)
{
    return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE);
}
bool has_neighbor(char copy_board[BOARD_SIZE][BOARD_SIZE], int x, int y,bool is_me)
{
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            if (isInBound(x + i, y + j) &&!(i==0&&j==0)&& copy_board[x + i][y + j]==(is_me?myFlag:enemyFlag))
                return true;
    return false;
}
void init_all_types()
{
    //���壬Ӯ
    all_types[myFlag][myFlag][myFlag][myFlag][myFlag][myFlag] = WIN;
    all_types[myFlag][myFlag][myFlag][myFlag][myFlag][0] = WIN;
    all_types[0][myFlag][myFlag][myFlag][myFlag][myFlag] = WIN;
    all_types[myFlag][myFlag][myFlag][myFlag][myFlag][enemyFlag] = WIN;
    all_types[enemyFlag][myFlag][myFlag][myFlag][myFlag][myFlag] = WIN;
    all_types[3][myFlag][myFlag][myFlag][myFlag][myFlag] = WIN;//�߽翼��
    all_types[myFlag][myFlag][myFlag][myFlag][myFlag][3] = WIN;
    //��5,��
    all_types[enemyFlag][enemyFlag][enemyFlag][enemyFlag][enemyFlag][enemyFlag] = LOSE;
    all_types[enemyFlag][enemyFlag][enemyFlag][enemyFlag][enemyFlag][0] = LOSE;
    all_types[0][enemyFlag][enemyFlag][enemyFlag][enemyFlag][enemyFlag] = LOSE;
    all_types[enemyFlag][enemyFlag][enemyFlag][enemyFlag][enemyFlag][myFlag] = LOSE;
    all_types[myFlag][enemyFlag][enemyFlag][enemyFlag][enemyFlag][enemyFlag] = LOSE;
    all_types[3][enemyFlag][enemyFlag][enemyFlag][enemyFlag][enemyFlag] = LOSE;
    all_types[enemyFlag][enemyFlag][enemyFlag][enemyFlag][enemyFlag][3] = LOSE;
    //�ҷ���4
    all_types[0][myFlag][myFlag][myFlag][myFlag][0] = FLEX4;
    //�Է���4
    all_types[0][enemyFlag][enemyFlag][enemyFlag][enemyFlag][0] = flex4;
    //�ҷ���3
    all_types[0][myFlag][myFlag][myFlag][0][0] = FLEX3;
    all_types[0][0][myFlag][myFlag][myFlag][0] = FLEX3;
    all_types[0][myFlag][0][myFlag][myFlag][0] = FLEX3;
    all_types[0][myFlag][myFlag][0][myFlag][0] = FLEX3;
    //�Է���3
    all_types[0][enemyFlag][enemyFlag][enemyFlag][0][0] = flex3;
    all_types[0][0][enemyFlag][enemyFlag][enemyFlag][0] = flex3;
    all_types[0][enemyFlag][0][enemyFlag][enemyFlag][0] = flex3;
    all_types[0][enemyFlag][enemyFlag][0][enemyFlag][0] = flex3;
    //�ҷ���2
    all_types[0][myFlag][myFlag][0][0][0] = FLEX2;
    all_types[0][myFlag][0][myFlag][0][0] = FLEX2;
    all_types[0][myFlag][0][0][myFlag][0] = FLEX2;
    all_types[0][0][myFlag][myFlag][0][0] = FLEX2;
    all_types[0][0][myFlag][0][myFlag][0] = FLEX2;
    all_types[0][0][0][myFlag][myFlag][0] = FLEX2;
    //�Է���2
    all_types[0][enemyFlag][enemyFlag][0][0][0] = flex2;
    all_types[0][enemyFlag][0][enemyFlag][0][0] = flex2;
    all_types[0][enemyFlag][0][0][enemyFlag][0] = flex2;
    all_types[0][0][enemyFlag][enemyFlag][0][0] = flex2;
    all_types[0][0][enemyFlag][0][enemyFlag][0] = flex2;
    all_types[0][0][0][enemyFlag][enemyFlag][0] = flex2;
    //�ҷ���1
    all_types[0][myFlag][0][0][0][0] = FLEX1;
    all_types[0][0][myFlag][0][0][0] = FLEX1;
    all_types[0][0][0][myFlag][0][0] = FLEX1;
    all_types[0][0][0][0][myFlag][0] = FLEX1;
    //�Է���1
    all_types[0][enemyFlag][0][0][0][0] = flex1;
    all_types[0][0][enemyFlag][0][0][0] = flex1;
    all_types[0][0][0][enemyFlag][0][0] = flex1;
    all_types[0][0][0][0][enemyFlag][0] = flex1;

    int p1, p2, p3, p4, p5, p6, x, y, ix, iy;//x:��5�жԷ�����,y:��5���ҷ�����,ix:��5�жԷ�����,iy:��5���ҷ�����
    for (p1 = 0; p1 < 4; p1++) {
        for (p2 = 0; p2 < 3; p2++) {
            for (p3 = 0; p3 < 3; p3++) {
                for (p4 = 0; p4 < 3; p4++) {
                    for (p5 = 0; p5 < 3; p5++) {
                        for (p6 = 0; p6 < 4; p6++) {
                            x = y = ix = iy = 0;

                            if (p1 == enemyFlag)x++;
                            else if (p1 == myFlag)y++;

                            if (p2 == enemyFlag) { x++; ix++; }
                            else if (p2 == myFlag) { y++; iy++; }

                            if (p3 == enemyFlag) { x++; ix++; }
                            else if (p3 == myFlag) { y++; iy++; }

                            if (p4 == enemyFlag) { x++; ix++; }
                            else if (p4 == myFlag) { y++; iy++; }

                            if (p5 == enemyFlag) { x++; ix++; }
                            else if (p5 == myFlag) { y++; iy++; }

                            if (p6 == enemyFlag)ix++;
                            else if (p6 == myFlag)iy++;

                            if (p1 == 3 || p6 == 3) {//�б߽�
                                if (p1 == 3 && p6 != 3) {//��߽�
                                    //�׳�4
                                    if (ix == 0 && iy == 4) {//���ұ��п�λ�ǻ�4Ҳû��ϵ����Ϊ��4Ȩ��Զ���ڳ�4���ټ��ϳ�4Ȩ�ر仯���Բ���
                                        if (all_types[p1][p2][p3][p4][p5][p6] == 0)
                                            all_types[p1][p2][p3][p4][p5][p6] = BLOCK4;
                                    }
                                    //�ڳ�4
                                    if (ix == 4 && iy == 0) {
                                        if (all_types[p1][p2][p3][p4][p5][p6] == 0)
                                            all_types[p1][p2][p3][p4][p5][p6] = block4;
                                    }
                                    //����3
                                    if (ix == 0 && iy == 3) {
                                        if (all_types[p1][p2][p3][p4][p5][p6] == 0)
                                            all_types[p1][p2][p3][p4][p5][p6] = BLOCK3;
                                    }
                                    //����3
                                    if (ix == 3 && iy == 0) {
                                        if (all_types[p1][p2][p3][p4][p5][p6] == 0)
                                            all_types[p1][p2][p3][p4][p5][p6] = block3;
                                    }
                                    //����2
                                    if (ix == 0 && iy == 2) {
                                        if (all_types[p1][p2][p3][p4][p5][p6] == 0)
                                            all_types[p1][p2][p3][p4][p5][p6] = BLOCK2;
                                    }
                                    //����2
                                    if (ix == 2 && iy == 0) {
                                        if (all_types[p1][p2][p3][p4][p5][p6] == 0)
                                            all_types[p1][p2][p3][p4][p5][p6] = block2;
                                    }
                                }
                                else if (p6 == 3 && p1 != 3) {//�ұ߽�
                                    //�׳�4
                                    if (x == 0 && y == 4) {
                                        if (all_types[p1][p2][p3][p4][p5][p6] == 0)
                                            all_types[p1][p2][p3][p4][p5][p6] = BLOCK4;
                                    }
                                    //�ڳ�4
                                    if (x == 4 && y == 0) {
                                        if (all_types[p1][p2][p3][p4][p5][p6] == 0)
                                            all_types[p1][p2][p3][p4][p5][p6] = block4;
                                    }
                                    //����3
                                    if (x == 3 && y == 0) {
                                        if (all_types[p1][p2][p3][p4][p5][p6] == 0)
                                            all_types[p1][p2][p3][p4][p5][p6] = BLOCK3;
                                    }
                                    //����3
                                    if (x == 0 && y == 3) {
                                        if (all_types[p1][p2][p3][p4][p5][p6] == 0)
                                            all_types[p1][p2][p3][p4][p5][p6] = block3;
                                    }
                                    //����2
                                    if (x == 2 && y == 0) {
                                        if (all_types[p1][p2][p3][p4][p5][p6] == 0)
                                            all_types[p1][p2][p3][p4][p5][p6] = BLOCK2;
                                    }
                                    //����2
                                    if (x == 0 && y == 2) {
                                        if (all_types[p1][p2][p3][p4][p5][p6] == 0)
                                            all_types[p1][p2][p3][p4][p5][p6] = block2;
                                    }
                                }
                            }
                            else {//�ޱ߽�
                                //�׳�4
                                if ((x == 0 && y == 4) || (ix == 0 && iy == 4)) {
                                    if (all_types[p1][p2][p3][p4][p5][p6] == 0)
                                        all_types[p1][p2][p3][p4][p5][p6] = BLOCK4;
                                }
                                //�ڳ�4
                                if ((x == 4 && y == 0) || (ix == 4 && iy == 0)) {
                                    if (all_types[p1][p2][p3][p4][p5][p6] == 0)
                                        all_types[p1][p2][p3][p4][p5][p6] = block4;
                                }
                                //����3
                                if ((x == 0 && y == 3) || (ix == 0 && iy == 3)) {
                                    if (all_types[p1][p2][p3][p4][p5][p6] == 0)
                                        all_types[p1][p2][p3][p4][p5][p6] = BLOCK3;
                                }
                                //����3
                                if ((x == 3 && y == 0) || (ix == 3 && iy == 0)) {
                                    if (all_types[p1][p2][p3][p4][p5][p6] == 0)
                                        all_types[p1][p2][p3][p4][p5][p6] = block3;
                                }
                                //����2
                                if ((x == 0 && y == 2) || (ix == 0 && iy == 2)) {
                                    if (all_types[p1][p2][p3][p4][p5][p6] == 0)
                                        all_types[p1][p2][p3][p4][p5][p6] = BLOCK2;
                                }
                                //����2
                                if ((x == 2 && y == 0) || (ix == 2 && iy == 0)) {
                                    if (all_types[p1][p2][p3][p4][p5][p6] == 0)
                                        all_types[p1][p2][p3][p4][p5][p6] = block2;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
evaluation evaluate(char copy_board[BOARD_SIZE][BOARD_SIZE])
{
    evaluation e;                                        
    int state_of_board[4][17] = { 0 };                   //  ��ǰ״̬�������� �Լ� ��ǰ�������������μ���
    char v_board[BOARD_SIZE + 2][BOARD_SIZE + 2];        //  �����߽���������̣�3�Ǳ߽�
    for (int i = 0; i < BOARD_SIZE + 2; i++)v_board[i][0] = 3;
    for (int i = 0; i < BOARD_SIZE + 2; i++)v_board[0][i] = 3;
    for (int i = 0; i < BOARD_SIZE + 2; i++)v_board[i][BOARD_SIZE + 1] = 3;
    for (int i = 0; i < BOARD_SIZE + 2; i++)v_board[BOARD_SIZE + 1][i] = 3;
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            v_board[i+1][j+1] = copy_board[i][j];               //  ����ͬ��ǰ����
    //�жϺ�������
    for (int i = 1; i <= BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE - 3; j++)
            state_of_board[0][all_types[v_board[i][j]][v_board[i][j + 1]][v_board[i][j + 2]][v_board[i][j + 3]][v_board[i][j + 4]][v_board[i][j + 5]]]++;
    //�ж���������
    for (int i = 0; i < BOARD_SIZE - 3; i++)
        for (int j = 1; j <= BOARD_SIZE; j++)
            state_of_board[1][all_types[v_board[i][j]][v_board[i + 1][j]][v_board[i + 2][j]][v_board[i + 3][j]][v_board[i + 4][j]][v_board[i + 5][j]]]++;
    //�ж���������������
    for (int i = 0; i < BOARD_SIZE - 3; i++)
        for (int j = 0; j < BOARD_SIZE - 3; j++)
            state_of_board[2][all_types[v_board[i][j]][v_board[i + 1][j + 1]][v_board[i + 2][j + 2]][v_board[i + 3][j + 3]][v_board[i + 4][j + 4]][v_board[i + 5][j + 5]]]++;
    //�ж���������������
    for (int i = 0; i < BOARD_SIZE - 3; i++)
        for (int j = 5; j <= BOARD_SIZE + 1; j++)
            state_of_board[3][all_types[v_board[i][j]][v_board[i + 1][j - 1]][v_board[i + 2][j - 2]][v_board[i + 3][j - 3]][v_board[i + 4][j - 4]][v_board[i + 5][j - 5]]]++;
    for (int i = 1; i < 17; i++)
        e.score += (state_of_board[0][i] + state_of_board[1][i] + state_of_board[2][i] + state_of_board[3][i]) * weight[i];//�����Ʒ�
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            if (state_of_board[i][j])
            {
                e.flag = true;
                break;
            }
        }
    }
    return e;
}
int dfs(char copy_board[BOARD_SIZE][BOARD_SIZE], int dep, int alpha, int beta, bool is_me, int& new_x, int& new_y)
{
    evaluation e = evaluate(copy_board);
    if (!dep || e.flag)return e.score;
    if (is_me)
    {
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                if (!copy_board[i][j]&&has_neighbor(copy_board, i, j,is_me))
                {
                    //printf("^%d^^^%d^",i, j);
                    copy_board[i][j] = myFlag;
                    int value = dfs(copy_board, dep - 1, alpha, beta, !is_me, new_x, new_y);
                    copy_board[i][j] = 0;
                    if (value > alpha)
                    {
                        alpha = value;
                        if (dep == DEPTH)new_x = i, new_y = j;
                    }
                    if (alpha > beta)break;
                }
            }
        }
        return alpha;
    }
    else
    {
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                if (!copy_board[i][j]&&has_neighbor(copy_board, i, j,is_me))
                {
                    copy_board[i][j] = enemyFlag;
                    int value = dfs(copy_board, dep - 1, alpha, beta, !is_me, new_x, new_y);
                    copy_board[i][j] = 0;
                    if (value < beta)beta = value;
                    if (alpha > beta)break;
                }
            }
        }
        return beta;
    }
}
void turn()
{
    int new_x, new_y;
    //if ( trick&&myFlag==1)
    //{
      //  trick = false;
        //new_x = 5, new_y = 7;
    //}
    //else
    //{
        char copy_board[BOARD_SIZE][BOARD_SIZE];
        memcpy(copy_board, board, sizeof board);
        dfs(copy_board, DEPTH, -INF, INF, true, new_x, new_y);
    //}
    printf("%d %d", new_x, new_y);
    printf("\n");
    fflush(stdout);
    board[new_x][new_y] = myFlag;
    return;
}
void debug(const char* str)
{
    printf("DEBUG %s\n", str);
    fflush(stdout);
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
    memset(board, 0, sizeof(board));
    int middlePlace = BOARD_SIZE / 2;                     //6
    board[middlePlace - 1][middlePlace - 1] = BLACK;
    board[middlePlace][middlePlace] = BLACK;
    board[middlePlace - 1][middlePlace] = WHITE;
    board[middlePlace][middlePlace - 1] = WHITE;
    initAI(flag);
    init_all_types();
}
void end(int x)
{
    exit(0);
}
void loop()
{
    char tag[10] = { 0 };
    Command cmd({0,0});
    int status;
    while (TRUE)
    {
        memset(tag, 0, sizeof(tag));
        scanf("%s", tag);
        if (strcmp(tag, START) == 0)
        {
            scanf("%d", &myFlag);
            start(myFlag);           //  1 ִ���� 
            printf("OK\n");
            fflush(stdout);
        }
        else if (strcmp(tag, PLACE) == 0)
        {
            scanf("%d %d", &cmd.x, &cmd.y);
            place(cmd);
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