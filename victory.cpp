#include "victory.h"
#include <QPainter>

Victory::Victory(QWidget *parent): QWidget{parent}
{
    setFixedSize(480,290);
}

void Victory::paintEvent(QPaintEvent *)//也就是我需要保证每个图片的大小完全一样
{
    QPainter painter(this);


    QPixmap  pix;
    pix.load(":/MainWindowScene/gameWindow/Victory.png") ;
    pix = pix.scaled(this->width() *1.1, this->height()*1.1 , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(0,0,pix);



}
