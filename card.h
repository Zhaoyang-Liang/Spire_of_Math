#ifndef CARD_H
#define CARD_H

#include <QWidget>

class Card : public QWidget
{
    Q_OBJECT
public:


    enum Rarity
    {
        Commen  =  1 ,
        Uncommen = 2,
        Rare = 5
    };



    explicit Card(int Rarity,QString type );

    bool isClick = false ;
    bool isSelected = false ;
    void setClick(bool b);

    void paintEvent(QPaintEvent *event);
    void setSelected(bool b) ;

    int m_rarity ; // 1 ， 2 ， 5 ；！！！
    QString m_type ;



signals:
};

#endif // CARD_H
