#include "gamewindow.h"
#include <QPainter>
#include <QMenuBar>
#include <QMenu>
#include "heart.h"
#include "topwidegt.h"
#include "shopscene.h"




// GameWindow::GameWindow(QWidget *parent): QMainWindow{parent}
// {

// }
GameWindow::GameWindow(Player * p,TopWidegt * tp,StationeryWidget * st)
{

    m_stiWidget = st ;
    m_player = p ;
    m_topWidget = tp ;
    this->setFixedSize(1080,720);
    this->setWindowTitle("打架");

    m_stiWidget->setParent(this);
    m_stiWidget->move(0,75);

    m_topWidget->setParent(this);
    m_topWidget->move(0,0);

    m_done = new MyPushBtn(":/MainWindowScene/gameWindow/done.png",":/MainWindowScene/gameWindow/pressedDone.png",210,90) ;
    m_done->setParent(this);
    m_done->move(760,400);

    money.setParent(this);

    money.move(500,10);

    m_ink->move(980,360) ;

    m_ink->reFreshImg(3);
   // m_ink->cl();

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
    backBtn->move(this->width() - backBtn->width() , 0);

    connect(backBtn, &MyPushBtn::clicked , this , [=](){
        emit this->gameWindowBack(); // 发送
    });



    this->m_player2 = initPlayer( p->getPlayer() ) ;
    Heart * h2 = new Heart(m_player2) ;
    h2->setParent(this);
    h2->move(775,90);


    m_shop = new MyPushBtn(":/MainWindowScene/gameWindow/shop.png",":/MainWindowScene/gameWindow/pressedShop.png",50,50);
    m_shop->setParent(this);
    m_shop->move(790,0);

    //创建SHopScene
    m_shopScene = new ShopScene(this->m_player,this->m_topWidget,money);
    connect(m_shop,&MyPushBtn::clicked,this,[=](){
        this->hide();
        m_topWidget->setParent(m_shopScene);
        money.setParent(m_shopScene);
        m_shopScene->setGeometry(this->geometry() );
        m_shopScene->show();
    });

    connect(m_shopScene,&ShopScene::ShopSceneBack,this,[=](){
        m_shopScene->hide();
        //设置相同位置
        backBtn->move(this->width() - backBtn->width() , 0);

        m_topWidget->setParent(this);
        m_shop->raise(); // 重新置于顶层上方
        backBtn->raise();
        money.setParent(this);
        this->setGeometry(m_shopScene->geometry());
        this->show();
    });








}


void GameWindow::paintEvent(QPaintEvent *)//也就是我需要保证每个图片的大小完全一样
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing) ;
    QPixmap  pix;
    pix.load(":/MainWindowScene/gameWindow/gameWindowBack.png") ;
    pix = pix.scaled(pix.width() , pix.height() , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(0,0,pix);

    pix = m_player->m_playerImg;
    pix = pix.scaled(pix.width() * 0.9 , pix.height() * 0.9 , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(80,140,pix);

    pix = m_player2->m_playerImg;
    pix = pix.scaled(pix.width() * 0.66 , pix.height() * 0.66 , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(790,130,pix);

}



Player* GameWindow::initPlayer(int x)
{
    if(x == 1 )
    {
        return new Player(":/MainWindowScene/res/testp1.png",":/MainWindowScene/Info/huochaiInfo.png",":/MainWindowScene/res/pencile.png",50,1) ;
    }
    else if(x == 2)
    {
        return new Player(":/MainWindowScene/res/hanyongji.png",":/MainWindowScene/Info/HInfo.png" , ":/MainWindowScene/res/gua.png",50,10) ;
    }
    else if(x == 3)
    {
        return new Player(":/MainWindowScene/res/shao.png",":/MainWindowScene/Info/shaoInfo.png",":/MainWindowScene/res/Ink.png",250,0) ;
    }
    else if(x == 4)
    {
        return new Player(":/MainWindowScene/res/zang.png",":/MainWindowScene/Info/zangInfo.png",":/MainWindowScene/res/pencileCompass.png",10,100) ;
    }
}












