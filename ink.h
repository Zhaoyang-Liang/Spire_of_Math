#ifndef INK_H
#define INK_H

#include <QWidget>

class Ink : public QWidget
{
    Q_OBJECT
public:
    explicit Ink(QWidget *parent = nullptr);

    const int all = 3 ;
    int current ;

    void paintEvent(QPaintEvent *) ;

signals:
};

#endif // INK_H
