#ifndef HANDCARDSSHOWSCENE_H
#define HANDCARDSSHOWSCENE_H

#include <QMainWindow>
#include <QVector>
#include "card.h"





class HandCardsShowScene : public QMainWindow
{
    Q_OBJECT
public:
    HandCardsShowScene(QVector<Card*> & v);
    int num ;

    // QVector<Card*>  haveCards ;

    void paintEvent(QPaintEvent *) ;

signals:
    void HandSceneBack();
};

#endif // HANDCARDSSHOWSCENE_H
