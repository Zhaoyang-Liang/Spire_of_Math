#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>


class Player : public QWidget
{
    Q_OBJECT
public:
    // explicit Player(QWidget *parent = nullptr);

    Player(QString playerImg , QString Info ,QString playerAttackImg= "" , QString playerBeAttackedImg = "" ,int life = 0 , int attack = 0 ) ;



    //卡牌 ：

    int m_life ;
    int m_attack ;
    QPixmap m_playerImg;
    QPixmap m_playerAttackImg;
    QPixmap m_playerBeAttackedImg;
    QPixmap m_Info;
    int flag1 = 0 ;
    void paintEvent(QPaintEvent *);


signals:
    void checkSignal() ;
};

#endif // PLAYER_H
