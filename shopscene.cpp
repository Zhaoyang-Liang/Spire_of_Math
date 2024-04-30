#include "shopscene.h"
#include "mypushbtn.h"
#include <QPainter>







ShopScene::ShopScene(Player * p , TopWidegt * tp , Money & m)
{

    this->setFixedSize(1080,720);
    this->setWindowTitle("商店界面");

    //到时候按下购买按钮触发类似指令即可
    m.currentMoney -= 5 ;
    m.cl();
    m.reFreshImg(m.currentMoney);


    m_p = p  ;
    m_top = tp  ;

    //返回按钮
    MyPushBtn * backBtn = new MyPushBtn(":/MainWindowScene/res/backBtn.png",":/MainWindowScene/res/pressedBackBtn.png",200,50);
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width() , this->height() - backBtn->height());
    connect(backBtn, &MyPushBtn::clicked , this , [=](){
        emit this->ShopSceneBack(); // 发送
    });

}


void ShopScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap  pix;
    pix.load(":/MainWindowScene/res/BackGround.png") ;
    pix = pix.scaled(pix.width() , pix.height()  , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(0,0,pix);


}
