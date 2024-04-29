#ifndef MONEY_H
#define MONEY_H

#include <QWidget>

class Money : public QWidget
{
    Q_OBJECT
public:
    Money(int cur = 100 ,QString Img = ":/MainWindowScene/tops/money.png");
    int currentMoney ;
    QPixmap m ;
    void paintEvent(QPaintEvent *) ;

signals:
};

#endif // MONEY_H
