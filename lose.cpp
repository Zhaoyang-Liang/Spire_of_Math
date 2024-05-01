#include "lose.h"
#include <QPainter>

Lose::Lose(QWidget *parent): QWidget{parent}
{
    setFixedSize(500,200);
}

void Lose::paintEvent(QPaintEvent *)//也就是我需要保证每个图片的大小完全一样
{
    QPainter painter(this);


    QPixmap  pix;
    pix.load(":/MainWindowScene/gameWindow/Defeat.png") ;
    pix = pix.scaled(this->width() , this->height() , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(0,0,pix);



}
