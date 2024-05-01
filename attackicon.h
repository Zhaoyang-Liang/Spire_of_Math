#ifndef ATTACKICON_H
#define ATTACKICON_H

#include <QWidget>
#include "player.h"
#include "QLabel"
class AttackIcon : public QWidget
{
    Q_OBJECT
public:
    AttackIcon(Player * p);

    Player * m_p ;

    int m_cur ;
    QLabel * l ;

    void paintEvent(QPaintEvent *) ;
    void reFreshImg(int cur) ;
    void cl();
signals:
};

#endif // ATTACKICON_H
