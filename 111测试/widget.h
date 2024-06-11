#ifndef WIDGET_H
#define WIDGET_H

#include "gamewidget.h"

namespace Ui { class Widget; }

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr);
    ~Widget();

private slots:
    void playerButtonPush();
    void aiButtonPush();

private:
    Ui::Widget* ui;
    gameWidget* game;
};
#endif // WIDGET_H