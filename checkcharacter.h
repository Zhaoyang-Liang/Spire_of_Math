#ifndef CHECKCHARACTER_H
#define CHECKCHARACTER_H

#include <QMainWindow>
#include "player.h"
#include "mypushbtn.h"
#include "gamewindow.h"
#include "topwidegt.h"
#include "stationerywidget.h"
class CheckCharacter : public QMainWindow
{
    Q_OBJECT
public:
    CheckCharacter(Player  * p ) ;

    void paintEvent(QPaintEvent *) ;

    QPixmap m_playerImg;
    QPixmap m_Info ;

    GameWindow * gameWindow;
    Heart * heart ;
    TopWidegt * tp ;
    StationeryWidget * st ;
signals:
    void checkSceneBack();

};

#endif // CHECKCHARACTER_H
