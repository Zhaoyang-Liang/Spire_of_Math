#include "ink.h"
#include <QPainter>
#include <QPixmap>
#include <QFont>

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


void Ink::reFreshImg(int cur)
{
    this->current = cur ;
    QFont font = l->font() ;
    font.setBold(true); // 设置字体加粗
    font.setPointSize(24);
    l->setFont(font);
    l->move(30,22);
    l->setStyleSheet("color:blue");
    l->setText( QString::number(current) ) ;
}




void Ink::cl()
{
    l->clear();
}













