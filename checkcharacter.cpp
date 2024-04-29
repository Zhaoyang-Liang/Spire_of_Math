#include "checkcharacter.h"
#include "player.h"
#include "mypushbtn.h"
#include <QPainter>
//是一个QMianWindow

// CheckCharacter::CheckCharacter(QWidget *parent): QMainWindow{parent}
// {

// }


CheckCharacter::CheckCharacter(Player * p)
{
    setFixedSize(1080,720);


    //返回按钮
    MyPushBtn * backBtn = new MyPushBtn(":/MainWindowScene/res/backBtn.png",":/MainWindowScene/res/pressedBackBtn.png",200,50);
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width() , this->height() - backBtn->height());
    connect(backBtn, &MyPushBtn::clicked , this , [=](){
        emit this->checkSceneBack(); // 发送
    });


    m_playerImg = p->m_playerImg ;
    m_Info = p->m_Info ;

    MyPushBtn * yes = new MyPushBtn(":/MainWindowScene/Info/queren.png",":/MainWindowScene/Info/querenPressed.png",300,100) ;
    yes->setParent(this);
    yes->move(400,550);


}

void CheckCharacter::paintEvent(QPaintEvent *)//也就是我需要保证每个图片的大小完全一样
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing) ;
    QPixmap  pix;
    pix.load(":/MainWindowScene/res/BackGround.png") ;
    pix = pix.scaled(pix.width() , pix.height() , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(0,0,pix);


    painter.drawPixmap(200,150,m_playerImg);
    painter.drawPixmap(500,130,m_Info);


}
