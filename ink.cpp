#include "ink.h"
#include <QPainter>
Ink::Ink(QWidget *parent): QWidget{parent}
{
    setFixedSize(80,80);

}

void Ink::paintEvent(QPaintEvent *)
{

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing) ;
    QPixmap  pix;
    pix.load(":/MainWindowScene/gameWindow/INK.png") ;
    pix = pix.scaled(this->width() ,this->height() , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(0,0,pix);
    // pix.load("");
    // pix = pix.scaled(pix.width() *0.2 , pix.height() *0.2 ) ;
    // painter.drawPixmap(10,10,pix);

}
