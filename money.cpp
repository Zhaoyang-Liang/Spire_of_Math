#include "money.h"
#include <QPixmap>
#include <QPainter>
#include <QLabel>
#include <QFont>



Money::Money(int cur ,QString Img)
{
    setFixedSize(200,40);
    s = Img ;
    this->currentMoney = cur ;
    m.load(s) ;
    reFreshImg(currentMoney);


}
void Money::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap  pix;
    pix = m ;
    pix = pix.scaled( 40 , 40  , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(0,0,pix);
}


void Money::reFreshImg(int cur)
{
    currentMoney = cur ;
    QFont font = l->font() ;
    font.setBold(true); // 设置字体加粗
    l->setFont(font);
    l->move(60,10);
    l->setStyleSheet("color:gold");
    l->setText( QString::number(currentMoney) ) ;
}

void Money::cl()
{
    l->clear();
}




