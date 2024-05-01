#ifndef LOSE_H
#define LOSE_H

#include <QWidget>

class Lose : public QWidget
{
    Q_OBJECT
public:
    explicit Lose(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);
signals:
};

#endif // LOSE_H
