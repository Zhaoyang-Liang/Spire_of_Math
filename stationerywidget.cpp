#include "stationerywidget.h"
#include <QPainter>
StationeryWidget::StationeryWidget(Player * p)
{
    setFixedSize(70,70);
    m_p = p ;
}
void StationeryWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap  pix = m_p->m_stationery ;

    pix = pix.scaled(this->width(), this->height()  , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(0,0,pix);
}
