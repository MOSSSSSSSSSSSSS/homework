#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
#include <QMap>
#include <QRandomGenerator>
#include <QTimer>
#include <QTime>
#include <sys/time.h>
#include <QDebug>
#include <iostream>
#include "chessai.h"
using namespace std;


namespace Ui {
    class gameWidget;
}

class gameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit gameWidget(QWidget* parent = nullptr);
    ~gameWidget()override;
    void initializeGame();
    void setGameMode(gameMode m) { mode = m; }
    bool chessOneByPlayer();
    void oneChessMove(int row, int col);//����Ҫ���ӵĵ�ַ����һ��
    bool isDeadGame();//�ж��Ƿ��ǽ���
    bool isLegalMove(int row, int col);//�ж�����λ���Ƿ�Ϸ�

protected:
    void paintEvent(QPaintEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;//ʵ������

signals:
    void returnSignal();

public slots:
    void returnPush();
    void chessOneByAi();

private:
    Ui::gameWidget* ui;
    QPoint chessboard[15][15];//��һ���±����У��ڶ�������
    chessAi ai;//���̷���ai����
    int cursorRow;//���λ��
    int cursorCol;

    gameMode mode;
    gameTurn turn;
    gameStatus status;

    int score_black;
    int score_write;

};

#endif // GAMEWIDGET_H