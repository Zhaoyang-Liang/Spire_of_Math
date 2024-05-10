#ifndef CARD_H
#define CARD_H

#include <QWidget>
#include "mypushbtn.h"

class Card : public QWidget
{
    Q_OBJECT
public:


    explicit Card(int bianHao,QString type);
    bool isClick = false ;
    bool isSelected = false ;
    void setClick(bool b);
    void paintEvent(QPaintEvent *event);
    void setSelected(bool b) ;



    bool flag  ;
    QString m_type ;
    int m_rarity;
    void mousePressEvent(QMouseEvent *);
    int inkPrice;
    int m_bianHao ;

signals:
    void chuPai();
    void xinxi();

};

#endif // CARD_H
