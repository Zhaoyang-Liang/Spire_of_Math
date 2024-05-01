#ifndef VICTORY_H
#define VICTORY_H

#include <QWidget>

class Victory : public QWidget
{
    Q_OBJECT
public:
    explicit Victory(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

signals:
};

#endif // VICTORY_H
