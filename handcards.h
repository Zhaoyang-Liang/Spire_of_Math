#ifndef HANDCARDS_H
#define HANDCARDS_H

#include <QWidget>
#include "card.h"

class HandCards : public QWidget
{
    Q_OBJECT
public:
    explicit HandCards(QWidget *parent = nullptr);



    int arr[100] ;

signals:
};

#endif // HANDCARDS_H
