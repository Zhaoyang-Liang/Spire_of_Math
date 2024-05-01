#ifndef CHOOSECHARACTERWINDOW2_H
#define CHOOSECHARACTERWINDOW2_H

#include <QMainWindow>

class ChooseCharacterWindow2 : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseCharacterWindow2(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *) ;
    void shili() ;
signals:
    void back();
};

#endif // CHOOSECHARACTERWINDOW2_H
