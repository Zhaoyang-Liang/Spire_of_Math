#ifndef INK_H
#define INK_H

#include <QWidget>
#include <QLabel>
class Ink : public QWidget
{
    Q_OBJECT
public:
    explicit Ink(QWidget *parent = nullptr);

    const int all = 3 ;

    int current ;

    QLabel * l = new QLabel(this) ;

    void paintEvent(QPaintEvent *) ;

    void cl() ;

    void reFreshImg(int cur) ;


signals:
};

#endif // INK_H
