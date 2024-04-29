#ifndef SCROLL_H
#define SCROLL_H

#include <QScrollArea>
#include <QWidget>

class Scroll : public QWidget
{
    Q_OBJECT
public:
    explicit Scroll(QWidget *parent = nullptr);

signals:
};

#endif // SCROLL_H
