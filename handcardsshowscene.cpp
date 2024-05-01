#include "handcardsshowscene.h"
#include <QPainter>
#include "mypushbtn.h"
#include <QMenuBar>
#include <QLabel>
#include <QDebug>
HandCardsShowScene::HandCardsShowScene(QVector<Card*> & v )
{




    setWindowTitle("现有卡牌");

    QMenuBar * bar = menuBar() ;
    setMenuBar(bar);
    //创建开始菜单 添加startMenu
    QMenu * startMenu = bar->addMenu("开始") ;
    //添加quitAction
    QAction * quitAction = startMenu->addAction("退出") ;

    //connect退出
    connect(quitAction,&QAction::triggered,this,[=](){
        this->close();
    });

    //返回按钮
    MyPushBtn * backBtn = new MyPushBtn(":/MainWindowScene/res/backBtn.png",":/MainWindowScene/res/pressedBackBtn.png",200,50);
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width() , this->height() - backBtn->height());
    connect(backBtn, &MyPushBtn::clicked , this , [=](){
        emit this->HandSceneBack(); // 发送
    });

    num = v.count() ;


    for(int i = 0 ; i< num ; i++)
    {
        v[i]->setParent(this);
        v[i]->show();
        v[i]->move(200 + i*200 ,200 + (i/4) * 500 );
    }





}



void HandCardsShowScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap  pix;
    pix.load(":/MainWindowScene/res/BackGround.png") ;
    pix = pix.scaled(pix.width() , pix.height()  , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(0,0,pix);

}
