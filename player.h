#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include "money.h"



class Player : public QWidget
{
    Q_OBJECT
public:
    // explicit Player(QWidget *parent = nullptr);

    Player(QString playerImg , QString Info ,QString stationery = "" , int life = 100 , int attack = 100 ,QString playerAttackImg= "" , QString playerBeAttackedImg = "" ) ;

    //卡牌 ：

    int m_life ; // 血量，攻击力
    int m_currentLife ;
    int num;
    int m_attack ;
    int m_curMoney ;
    QPixmap m_playerImg;
    QPixmap m_playerAttackImg;
    QPixmap m_playerBeAttackedImg;
    QPixmap m_Info;
    QPixmap m_stationery;
    int flag1 = 0 ;
    void paintEvent(QPaintEvent *);
    int getPlayer();



signals:
    void checkSignal() ;
};

#endif // PLAYER_H
