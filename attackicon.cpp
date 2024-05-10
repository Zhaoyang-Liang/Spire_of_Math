#include "attackicon.h"
#include "player.h"
#include <QPainter>
#include <QLabel>
#include <QFont>

AttackIcon::AttackIcon(Player * p)
{
    setFixedSize(100,40);
    m_p = p ;
    reFreshImg(p->m_attack);
}

void AttackIcon::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap  pix;
    pix.load(":/MainWindowScene/gameWindow/attackValue.png") ;
    pix = pix.scaled( 40 , 40  , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(0,0,pix);
}

void AttackIcon::reFreshImg(int cur)
{
    m_cur = cur ;

    l = new QLabel(this) ;
    QFont font = l->font() ;
    font.setBold(true);
    l->setStyleSheet("color:black");
    l->move(40,10);
    l->setText( QString::number( cur) );
}

void AttackIcon::cl()
{
    l->clear();
}
