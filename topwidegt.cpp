#include "topwidegt.h"
#include <QPainter>


//

TopWidegt::TopWidegt(QWidget *parent): QWidget{parent}
{
    setFixedSize(70,720);






}





void TopWidegt::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap  pix;
    pix.load(":/MainWindowScene/tops/top.png") ;
    pix = pix.scaled(this->width(),this->height()  , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(0,0,pix);

}
