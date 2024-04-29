#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mypushbtn.h"
#include <QAction>
#include <QPaintEvent>
#include "choosecharacterscene.h"
#include <QPainter>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    MyPushBtn * startBtn ;

    void paintEvent(QPaintEvent *);

    ChooseCharacterScene * chooseCharacterScene;


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
