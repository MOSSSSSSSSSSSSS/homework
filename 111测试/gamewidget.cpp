#include "gamewidget.h"
#include "ui_gamewidget.h"

gameWidget::gameWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::gameWidget)
{
    ui->setupUi(this);

    for (int i = 0; i < 15; ++i) {//�������Ͻǵ�Ϊ(20,20),ÿ����Ϊ30
        for (int j = 0; j < 15; ++j) {
            chessboard[i][j].setX(20 + 30 * i);
            chessboard[i][j].setY(20 + 30 * j);
        }
    }
    connect(this->ui->btn_return, SIGNAL(clicked(bool)), this, SLOT(returnPush()));

    setMouseTracking(true);//���õ�����Ҳһֱ׷��
    initializeGame();

}
gameWidget::~gameWidget()
{
    delete ui;
}
void gameWidget::returnPush() {
    emit returnSignal();
    this->hide();
    initializeGame();
}

void gameWidget::initializeGame() {
    qDebug() << "��Ϸ���³�ʼ��";
    if (mode == PLAYER)qDebug() << "���ģʽ";
    else qDebug() << "�˻�ģʽ";

    for (int i = 0; i < 15; ++i)
        for (int j = 0; j < 15; ++j)
            ai.chesses[i][j] = C_NONE;

    status = UNDERWAY;
    turn = T_BLACK;
    cursorRow = -1;
    cursorCol = -1;
}

void gameWidget::paintEvent(QPaintEvent* event) {

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    //������
    painter.setPen(Qt::black);
    for (int i = 0; i < 15; ++i) {
        painter.drawLine(chessboard[0][i], chessboard[14][i]);
        painter.drawLine(chessboard[i][0], chessboard[i][14]);
    }
    if (turn == T_BLACK)painter.setBrush(Qt::black);
    else painter.setBrush(Qt::white);
    //�������
    if (cursorRow != -1 && cursorCol != -1) {
        //8Ϊ���߳�
        QRect rec(chessboard[cursorCol][cursorRow].x() - 8 / 2, chessboard[cursorCol][cursorRow].y() - 8 / 2, 8, 8);
        painter.drawRect(rec);
    }

    //������
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            if (ai.chesses[i][j] != C_NONE) {
                if (ai.chesses[i][j] == C_BLACK)painter.setBrush(Qt::black);
                else painter.setBrush(Qt::white);
                painter.drawEllipse(chessboard[j][i].x() - 20 / 2, chessboard[j][i].y() - 20 / 2, 20, 20);

            }
        }
    }
}

void gameWidget::mouseMoveEvent(QMouseEvent* event) {
    if (event->x() >= 5 && event->x() <= 455 && event->y() >= 5 && event->y() <= 455) {//5=20-15,455=20+14*30+15
        setCursor(Qt::BlankCursor);
        for (int i = 0; i < 15; ++i)
            for (int j = 0; j < 15; ++j) {
                float x = event->x(), y = event->y();
                //�ж����������һ���㸽��(�����η�Χ)
                if ((x >= (chessboard[i][j].x() - 15)) && (x < (chessboard[i][j].x() + 15)) &&
                    (y >= (chessboard[i][j].y() - 15)) && (y < (chessboard[i][j].y() + 15))) {
                    cursorRow = j;
                    cursorCol = i;
                    if (ai.chesses[cursorRow][cursorCol] != C_NONE)
                        setCursor(Qt::ForbiddenCursor);

                    //չʾͼ������
                    QString str = "����:";
                    str += QString::number(j);
                    str += ",";
                    str += QString::number(i);
                    if (turn == T_BLACK)ui->lb_black_position->setText(str);
                    else ui->lb_white_position->setText(str);
                    break;
                }
            }
    }
    else setCursor(Qt::ArrowCursor);
    update();
}

void gameWidget::mouseReleaseEvent(QMouseEvent* event) {
    if (mode == PLAYER) {
        if (chessOneByPlayer()) {
            if (status == FINISH)initializeGame();
        }
    }
    else {
        if (chessOneByPlayer()) {
            if (status == UNDERWAY) {
                chessOneByAi();
                if (status == FINISH)initializeGame();
            }
            else initializeGame();
        }
    }
}

bool gameWidget::chessOneByPlayer() {
    if (ai.chesses[cursorRow][cursorCol] == C_NONE) {
        qDebug() << "player chess";
        oneChessMove(cursorRow, cursorCol);

        // qDebug()<<"���Ƶ÷�:"<<ai.evaluate(ai.chesses).score;

        return true;
    }
    return false;
}

bool gameWidget::isDeadGame() {
    int chessNum = 0;
    for (int i = 0; i < 16; ++i)
        for (int j = 0; j < 16; ++j)
            if (ai.chesses[i][j] != C_NONE)chessNum++;
    if (chessNum == 16 * 16)return true;
    else return false;
}
bool gameWidget::isLegalMove(int row, int col) {
    if (ai.chesses[row][col] == C_NONE)return true;
    else return false;
}

void gameWidget::oneChessMove(int row, int col) {
    qDebug() << row << "," << col;

    if (turn == T_BLACK) {
        turn = T_WHITE;
        ai.chesses[row][col] = C_BLACK;
    }
    else {
        turn = T_BLACK;
        ai.chesses[row][col] = C_WHITE;
    }

    gameResult result = ai.evaluate(ai.chesses).result;

    QMessageBox msg;
    msg.setIcon(QMessageBox::Critical);
    msg.setStandardButtons(QMessageBox::Yes);
    if (result != R_DRAW) {
        status = FINISH;
        if (result == R_BLACK) {
            qDebug() << "����Ӯ";
            msg.setText("����Ӯ");
            score_black++;
        }
        else {
            qDebug() << "����Ӯ";
            msg.setText("����Ӯ");
            score_write++;
        }
        msg.exec();

        ui->lcd_black->display(score_black);
        ui->lcd_write->display(score_write);
    }
    else if (isDeadGame()) {
        status = FINISH;
        msg.setText("ƽ��");
        msg.exec();
    }
    update();
}

void gameWidget::chessOneByAi() {
    qDebug() << "ai chess";

    //QPoint p=ai.findBestMove(T_BLACK);

    struct timeval tpstart, tpend;
    float timeuse;//ai�����ʱ
    gettimeofday(&tpstart, NULL);

    //QPoint p=ai.findBestMoveGreedy(C_BLACK);
    ai.nodeNum = 0;

    if (!ai.analyse_kill(ai.chesses, 16)) {
        qDebug() << "û�ҵ�ɱ��";
        ai.analyse(ai.chesses, 6, -INT_MAX, INT_MAX);

    }
    else {
        qDebug() << "�ҵ���ɱ��";
    }

    QPoint p = ai.decision.pos;

    qDebug() << "ai����:" << p.x() << "," << p.y();

    if (isLegalMove(p.x(), p.y()))
        oneChessMove(p.x(), p.y());
    else qDebug() << "ai�±겻�Ϸ���";

    qDebug() << "ai������Ƶ÷�:" << ai.evaluate(ai.chesses).score;

    gettimeofday(&tpend, NULL);
    timeuse = (1000000 * (tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec) / 1000000.0;
    qDebug() << timeuse << "s";

    QString text = "ai�����ʱ:" + QString::number(timeuse) + "s";
    this->ui->lb_timeuse->setText(text);

    text = "aiҶ�����:" + QString::number(ai.nodeNum);
    this->ui->lb_nodeNum->setText(text);

    text = "ai�������:" + QString::number(ai.evaluate(ai.chesses).score);
    this->ui->lb_eval->setText(text);
}