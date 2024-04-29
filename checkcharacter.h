#ifndef CHECKCHARACTER_H
#define CHECKCHARACTER_H

#include <QMainWindow>
#include "player.h"
#include "mypushbtn.h"

class CheckCharacter : public QMainWindow
{
    Q_OBJECT
public:
    CheckCharacter(Player  * p) ;

    void paintEvent(QPaintEvent *) ;

    QPixmap m_playerImg;
    QPixmap m_Info ;




signals:
    void checkSceneBack();

};

#endif // CHECKCHARACTER_H
