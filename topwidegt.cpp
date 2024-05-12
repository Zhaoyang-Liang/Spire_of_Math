#include "topwidegt.h"
#include <QPainter>


TopWidegt::TopWidegt(Player * p , Heart * h)
{

    //fixsize
    setFixedSize(1080,150);
    this->m_heart = h ;
    m_player = p ;

    //血条的位置：
    h->setParent(this);
    h->move(220,10);


}



void TopWidegt::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap  pix;
    pix.load(":/MainWindowScene/tops/top.png") ;
    pix = pix.scaled(this->width(),this->height()  , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(0,0,pix);

}
