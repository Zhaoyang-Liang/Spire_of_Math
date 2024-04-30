#ifndef SHOPSCENE_H
#define SHOPSCENE_H

#include <QMainWindow>
#include "topwidegt.h"
#include "player.h"
#include "money.h"



class ShopScene : public QMainWindow
{
    Q_OBJECT
public:


    ShopScene(Player * p , TopWidegt * tp ,Money & m);
    void paintEvent(QPaintEvent *) ;
    TopWidegt * m_top ;
    Player * m_p ;





signals:
    void ShopSceneBack();
};

#endif // SHOPSCENE_H
