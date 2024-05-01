#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "topwidegt.h"
#include "stationerywidget.h"
#include "player.h"
#include "mypushbtn.h"
#include "money.h"
#include "ink.h"
#include "shopscene.h"
#include <QVector>
#include "card.h"
#include "money.h"
#include "handcardsshowscene.h"
#include <QVector>
#include "handcardsshowscene.h"
#include "attackicon.h"
#include "victory.h"
#include "lose.h"

class GameWindow : public QMainWindow
{
    Q_OBJECT
public:
    // explicit GameWindow(QWidget *parent = nullptr);

    GameWindow(Player * p ,TopWidegt * tp,StationeryWidget * st );

    void paintEvent(QPaintEvent *) ;
    void reFreshHandsCardsShow() ;
    void chuPaiPanDuan(int type) ;
    void beAttackFuc(int x);
    void isWin(int x) ;
    void isLose(int x);
    int getRandomAction();
    Card* getPaiRandom(int x) ;

    Player * m_player ;
    HandCardsShowScene * m_handsCard ;
    int p2                  ;
    TopWidegt * m_topWidget ;
    StationeryWidget * m_stiWidget;
    MyPushBtn * m_done      ;
    Money money ;
    Ink * m_ink = new Ink(this) ;
    Player * m_player2      ;
    Player* initPlayer(int x) ;
    MyPushBtn * m_shop        ;
    ShopScene * m_shopScene   ;
    HandCardsShowScene * m_curCardsSHow ;
    MyPushBtn * m_curCardsBtn ;
    QVector<Card*> m_curHaveCards ;
    MyPushBtn * dealt         ;
    AttackIcon * m_ac         ;
    AttackIcon * m_ac2        ;
    Heart * h2                ;
    Victory *vi = new Victory(this) ;
    Lose * lo = new Lose(this) ;



signals:
    void gameWindowBack();
};

#endif // GAMEWINDOW_H
