#include "seestawindow.h"
#include "mypushbtn.h"
#include <QPainter>
SeeStaWindow::SeeStaWindow(QWidget *parent): QMainWindow{parent}
{
    this->setFixedSize(1080,720);
    this->setWindowTitle("平衡性装备调整");

    //返回按钮
    MyPushBtn * backBtn = new MyPushBtn(":/MainWindowScene/res/backBtn.png",":/MainWindowScene/res/pressedBackBtn.png",200,50);
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width() , this->height() - backBtn->height());

    connect(backBtn, &MyPushBtn::clicked , this , [=](){
        emit this->seeStaSceneBack();// 发送
    });


}

void SeeStaWindow::paintEvent(QPaintEvent *)//也就是我需要保证每个图片的大小完全一样
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing) ;
    QPixmap  pix;
    pix.load(":/MainWindowScene/res/inroBack.png") ;
    pix = pix.scaled(pix.width() , pix.height() , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(0,0,pix);


}
