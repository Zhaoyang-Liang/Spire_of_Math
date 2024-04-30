#ifndef SHOPSCENE_H
#define SHOPSCENE_H

#include <QMainWindow>
#include "topwidegt.h"
#include "player.h"
#include "money.h"
#include <QVector>
#include "shopscene.h"
#include "card.h"


class ShopScene : public QMainWindow
{
    Q_OBJECT
public:


    ShopScene(Player * p , TopWidegt * tp ,Money & m);
    void paintEvent(QPaintEvent *) ;
    TopWidegt * m_top ;
    Player * m_p ;

    Money * m_m ;

    QVector<Card *> allCards;
    QVector<Card *> haveCards ; //买下来的


    Card* cardInk;
    Card* cardRecover ;
    Card* cardPlus1 ;
    Card* cardplus4 ;
    Card* cardLaser ;
    Card* cardDerive ;


    MyPushBtn* buy1 ;
    MyPushBtn* buy2 ;

    void showCard1(int x);
    void showCard2(int x);
    void shili() ;
    int randomGetCard () ;


signals:
    void ShopSceneBack();
};

#endif // SHOPSCENE_H
