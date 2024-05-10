#ifndef SEESTAWINDOW_H
#define SEESTAWINDOW_H

#include <QMainWindow>

class SeeStaWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit SeeStaWindow(QWidget *parent = nullptr);


    void paintEvent(QPaintEvent *) ;






signals:
    void seeStaSceneBack();
};

#endif // SEESTAWINDOW_H
