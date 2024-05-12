#include "heart.h"
#include <QBrush>
#include <QPainter>
#include <QLabel>
#include <QFont>
#include <QDebug>
Heart::Heart(Player * p)
{
    setFixedSize(200,40);
    m_p = p ;
    l = new QLabel(this) ;

    rate = ( 1.0*m_p->m_currentLife/ m_p->m_life)*140.0 ;

    l->clear();
    reFreshImg(m_p->m_currentLife,m_p->m_life);

    l->move(100,12);



}


void Heart::paintEvent(QPaintEvent *)//也就是我需要保证每个图片的大小完全一样
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing) ;
    QPixmap  pix;
    pix.load(":/MainWindowScene/tops/health.png") ;
    pix = pix.scaled(40, 40 , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(0,0,pix);

    //到时候接受扣血信号：：
    QBrush brush;
    brush.setStyle(Qt::NoBrush);
    QPainter painter1(this)  ;
    painter1.setBrush(brush);
    painter1.drawRect(50,10,140,20);

    QPainter painter2(this) ;
    QBrush brush2 ;
    brush2.setColor(QColor(Qt::red));
    brush2.setStyle(Qt::SolidPattern);
    painter2.setBrush(brush2);
    painter2.drawRect(50,10,int(rate),20);





}


void Heart::cl()
{
    l->clear();
}

void Heart::reFreshImg(int c,int a)
{


    m_p->m_currentLife = c ;
    m_p->m_life = a ;


    QString cur = QString::number(m_p->m_currentLife) ;
    QString all = QString::number(m_p->m_life );


    rate = ( 1.0*m_p->m_currentLife/ m_p->m_life)*140.0 ;
    update();
    l->setText( cur + "/" + all );

}










