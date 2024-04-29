#ifndef TOPWIDEGT_H
#define TOPWIDEGT_H

#include <QWidget>
#include "heart.h"
#include "money.h"

class TopWidegt : public QWidget
{
    Q_OBJECT
public:
    explicit TopWidegt(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);

signals:
};

#endif // TOPWIDEGT_H
