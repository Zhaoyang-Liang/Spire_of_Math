#ifndef CHOOSECHARACTERSCENE_H
#define CHOOSECHARACTERSCENE_H

#include <QMainWindow>

class ChooseCharacterScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseCharacterScene(QWidget *parent = nullptr);

    //重写绘图事件
    void paintEvent(QPaintEvent *) ;








    void shili() ;

signals:
    //写一个自定义的信号，告诉主场景要返回
    void chooseSceneBack();
};

#endif // CHOOSECHARACTERSCENE_H
