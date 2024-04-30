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



class GameWindow : public QMainWindow
{
    Q_OBJECT
public:
    // explicit GameWindow(QWidget *parent = nullptr);

    GameWindow(Player * p ,TopWidegt * tp,StationeryWidget * st );

    void paintEvent(QPaintEvent *) ;

    Player * m_player ;


    TopWidegt * m_topWidget ;
    StationeryWidget * m_stiWidget;
    MyPushBtn * m_done      ;
    Money money ;
    Ink * m_ink = new Ink(this) ;
    int p2                  ;
    Player * m_player2      ;
    Player* initPlayer(int x) ;
    MyPushBtn * m_shop        ;
    ShopScene * m_shopScene   ;




signals:
    void gameWindowBack();
};

#endif // GAMEWINDOW_H
