#ifndef HEART_H
#define HEART_H

#include <QWidget>
#include "player.h"
class Heart : public QWidget
{
    Q_OBJECT
public:
    Heart(Player * p) ;
    void paintEvent(QPaintEvent *);

    Player * m_p ;
    QLabel * l;
    double rate ;

    void cl() ;

    void reFreshImg(int c,int a) ;




signals:
};

#endif // HEART_H
