#include "shopscene.h"
#include "mypushbtn.h"
#include <QPainter>
ShopScene::ShopScene(Player * p , TopWidegt * tp )
{

    this->setFixedSize(1080,720);
    this->setWindowTitle("商店界面");

    // m_p = p     ;
    // m_top = tp  ;


    //tp->setParent(this);

    // money->currentMoney -= 5 ;
    // money->update();
    // money->setParent(this);







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
