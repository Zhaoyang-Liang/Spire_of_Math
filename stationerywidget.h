#ifndef STATIONERYWIDGET_H
#define STATIONERYWIDGET_H

#include <QWidget>
#include "player.h"
#include <QLabel>

class StationeryWidget : public QWidget
{
    Q_OBJECT
public:

    StationeryWidget(Player * p) ;

    void paintEvent(QPaintEvent *) ;
    Player * m_p ;

signals:
};

#endif // STATIONERYWIDGET_H
