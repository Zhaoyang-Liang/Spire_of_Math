#ifndef TOPWIDEGT_H
#define TOPWIDEGT_H

#include <QWidget>
#include "heart.h"
#include "money.h"
#include "player.h"
#include "mypushbtn.h"


class TopWidegt : public QWidget
{
    Q_OBJECT
public:

    TopWidegt(Player * p, Heart * h) ;


    void paintEvent(QPaintEvent *);

    Heart * m_heart ;
    Player * m_player ;
    MyPushBtn * m_shop ;


signals:
};

#endif // TOPWIDEGT_H
