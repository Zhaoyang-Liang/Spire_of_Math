#ifndef MONEY_H
#define MONEY_H

#include <QWidget>
#include <QLabel>



class Money : public QWidget
{
    Q_OBJECT
public:
    Money(int cur = 100 ,QString Img = ":/MainWindowScene/tops/money.png");
    int currentMoney ;
    QPixmap m ;
    void paintEvent(QPaintEvent *) ;

    QLabel * l = new QLabel(this) ;

    void cl();

    void reFreshImg(int cur) ;
signals:
};


#endif // MONEY_H
