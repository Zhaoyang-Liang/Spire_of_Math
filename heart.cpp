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
    QLabel * l = new QLabel(this) ;

    l->move(100,12);
    int x = m_p->m_currentLife ;
    int y = m_p->m_life ;
    rate = ( 1.0*x / y)*140.0 ;
    //qDebug()<<x<<y<<rate ;
    QString cur = QString::number(m_p->m_currentLife) ;
    QString all = QString::number(m_p->m_life );

    l->setText( cur + "/" + all );

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
    // brush.setColor(QColor(Qt::black));
    brush.setStyle(Qt::NoBrush);
    QPainter painter1(this)  ;
    // painter1.setPen(Qt::black);
    painter1.setBrush(brush);
    painter1.drawRect(50,10,140,20);



    QPainter painter2(this) ;
    QBrush brush2 ;
    brush2.setColor(QColor(Qt::red));
    brush2.setStyle(Qt::SolidPattern);
    painter2.setBrush(brush2);
    painter2.drawRect(50,10,int(rate),20);


    update();




    // QBrush red_brush( QColor("#F20900") );//把刷子设置为红色
    // painter.setBrush(red_brush);//应用刷子
    // float rate = 1.0*enemys[i].now_hp/enemys[i].sum_hp;//计算比例
    // painter.drawRect(enemys[i].m_x,enemys[i].m_y,rate*enemys[i].img_enemy.width(),enemys[i].img_enemy.height()*0.2);//绘制矩形





}
