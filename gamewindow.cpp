#include "gamewindow.h"
#include <QPainter>
#include <QMenuBar>
#include <QMenu>
#include "heart.h"
#include "topwidegt.h"
#include "shopscene.h"
#include "money.h"
#include "QDebug"
#include <QTimer>
#include <QRandomGenerator>
#include <QRandomGenerator>

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


    vi->move(250,75);
    vi->hide();

    lo->move(250,120);
    lo->hide();

    this->m_player2 = initPlayer( p->getPlayer() ) ;
    h2 = new Heart(m_player2) ;
    h2->setParent(this);
    h2->move(775,70);

    m_stiWidget->setParent(this);
    m_stiWidget->move(0,75);

    m_topWidget->setParent(this);
    m_topWidget->move(0,0);

    m_done = new MyPushBtn(":/MainWindowScene/gameWindow/done.png",":/MainWindowScene/gameWindow/pressedDone.png",210,90) ;
    m_done->setParent(this);
    m_done->move(780,370);

    m_player->m_curMoney = 100 ;

    money.setParent(this);
    money.move(500,10);




    connect(m_done,&MyPushBtn::clicked,this,[=](){
        m_ink->current = 3 ;
        m_player->m_curMoney += 30 ;
        m_ink->reFreshImg(m_ink->current);
        money.cl();
        money.reFreshImg(m_player->m_curMoney);
        beAttackFuc( this->getRandomAction() );
        isLose(m_player->m_currentLife);


    }) ;



    m_ink->move(980,340) ;
    m_ink->reFreshImg(3);
   // m_ink->cl();

    m_ac = new AttackIcon(this->m_player);
    m_ac->setParent(this);
    m_ac->move(80,75);
    m_ac->reFreshImg(m_player->m_attack);

    m_ac2 = new AttackIcon(this->m_player2) ;
    m_ac2->setParent(this);
    m_ac2->move(980,70);
    m_ac2->reFreshImg(m_player2->m_attack);

    //出牌按钮
    dealt = new MyPushBtn(":/MainWindowScene/card/dealt.png",":/MainWindowScene/card/pressedDealt.png",100,70) ;
    dealt->setParent(this);
    dealt->move(970,270);
    dealt->raise();


    connect(dealt,&MyPushBtn::clicked,this,[=](){
        for(int i = 0 ; i < m_curHaveCards.count() ; i++)
        {
            if( m_curHaveCards[i]->flag == true && (m_ink->current >= m_curHaveCards[i]->inkPrice) )
            {
                m_curHaveCards[i]->move(400,115);
                QTimer::singleShot(500,this,[=](){ //执行的函数体
                    this->chuPaiPanDuan( m_curHaveCards[i]->m_bianHao );
                    m_curHaveCards[i]->close();
                    m_curHaveCards.remove(i);
                    reFreshHandsCardsShow();
                });
                break;

            }
        }
    });



    //返回按钮
    MyPushBtn * backBtn = new MyPushBtn(":/MainWindowScene/res/backBtn.png",":/MainWindowScene/res/pressedBackBtn.png",200,50);
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width() , 0);

    connect(backBtn, &MyPushBtn::clicked , this , [=](){
        emit this->gameWindowBack(); // 发送
    });

    m_shop = new MyPushBtn(":/MainWindowScene/gameWindow/shop.png",":/MainWindowScene/gameWindow/pressedShop.png",50,50);
    m_shop->setParent(this);
    m_shop->move(790,0);


    //创建SHopScene
    m_shopScene = new ShopScene( this->m_player, this->m_topWidget, this->money , this->m_curHaveCards );

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
        reFreshHandsCardsShow();
    });

    //手牌界面


    for(int i = 0  ; i < 5 ; i++)
    {
        m_curHaveCards.push_back(getPaiRandom( m_shopScene->randomGetCard() ));
        m_curHaveCards[i]->setParent(this);
        m_curHaveCards[i]->hide();
    }
    reFreshHandsCardsShow();




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
    painter.drawPixmap(70,120,pix);

    pix = m_player2->m_playerImg;
    pix = pix.scaled(pix.width() * 0.66 , pix.height() * 0.66 , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(800,110,pix);

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


void GameWindow::reFreshHandsCardsShow()
{

    int num = this->m_curHaveCards.count();

    for(int i = 0 ; i< num ; i++)
    {
        m_curHaveCards[i]->setParent(this);
        m_curHaveCards[i]->raise();
        m_curHaveCards[i]->show();
        m_curHaveCards[i]->move(50 + i*100 ,440);
    }
}



Card* GameWindow::getPaiRandom(int x)
{
    if( x>=1 && x <= 21)
    {
        return new Card(1,":/MainWindowScene/card/Ink.png") ;
    }
    else if( x>= 22 && x <=42)
    {
       return new Card(2,":/MainWindowScene/card/recover.png") ;
    }
    else if( x>= 43 && x <=63)
    {
        return new Card(3,":/MainWindowScene/card/plus1.png") ;
    }
    else if( x>= 64 && x <=76)
    {
        return new Card(4,":/MainWindowScene/card/plus4.png") ;
    }
    else if( x>= 77 && x <=93)
    {
        return  new Card(5,":/MainWindowScene/card/laser.png") ;
    }
    else if( x>= 94 && x <=100)
    {
        return new Card(6,":/MainWindowScene/card/derive.png") ;
    }
}

void GameWindow::chuPaiPanDuan(int type)
{
    if(type == 1)
    {
        this->m_ink->current += 1 ;
        this->m_ink->reFreshImg(m_ink->current);

    }
    else if( type == 2)
    {
        this->m_ink->current -= 1 ;
        this->m_ink->reFreshImg(m_ink->current);
        this->m_player->m_currentLife += 20 ;
        this->m_player->m_life += 20 ;
        this->m_topWidget->m_heart->reFreshImg(m_player->m_currentLife,m_player->m_life);

    }
    else if( type == 3)
    {
        this->m_ink->current -= 1 ;
        this->m_ink->reFreshImg(m_ink->current);
        this->m_player2->m_currentLife -= m_player->m_attack * 1 ;
        if(m_player2->m_currentLife <= 0) m_player2->m_currentLife = 0;
        this->h2->reFreshImg(m_player2->m_currentLife,m_player2->m_life);
        this->isWin(m_player2->m_currentLife);

    }
    else if( type == 4)
    {
        this->m_ink->current -= 2 ;
        this->m_ink->reFreshImg(m_ink->current);
        this->m_player2->m_currentLife -= m_player->m_attack * 4 ;
        if(m_player2->m_currentLife <= 0) m_player2->m_currentLife = 0;
        this->h2->reFreshImg(m_player2->m_currentLife,m_player2->m_life);
        this->isWin(m_player2->m_currentLife);

    }
    else if( type == 5)
    {
        this->m_ink->current -= 2 ;
        this->m_ink->reFreshImg(m_ink->current);
        this->m_player2->m_currentLife /= 2;
        if(m_player2->m_currentLife <= 0) m_player2->m_currentLife = 0;
        this->h2->reFreshImg(m_player2->m_currentLife,m_player2->m_life);
        this->isWin(m_player2->m_currentLife);

    }
    else if( type == 6)
    {
        this->m_ink->current -= 5 ;
        this->m_ink->reFreshImg(m_ink->current);
        this->m_player2->m_currentLife = 0;
        if(m_player2->m_currentLife <= 0) m_player2->m_currentLife = 0;
        this->h2->reFreshImg(m_player2->m_currentLife,m_player2->m_life);
        this->isWin(m_player2->m_currentLife);
    }

}

void GameWindow::isWin(int x)
{
    if(x == 0)
    {
        vi->show();
        // this->m_curCardsBtn->setEnabled(false);
        // this->m_shop->setEnabled(false);
        // this-> m_curCardsBtn->setEnabled(false);
        // this->m_done->setEnabled(false);
        // this->dealt->setEnabled(false);
    }
}
void GameWindow::isLose(int x)
{
    if(x == 0)
    {
        lo->show();
        // this->m_curCardsBtn->setEnabled(false);
        // this->m_shop->setEnabled(false);
        // this-> m_curCardsBtn->setEnabled(false);
        // this->m_done ->setEnabled(false);
        // this->dealt ->setEnabled(false);
    }

}



int GameWindow::getRandomAction()
{
    return QRandomGenerator::global()->bounded(1,7) ;
}

void GameWindow::beAttackFuc(int x )
{

    if(x == 2 || x == 1)
    {
        Card * c2 = new Card(2,":/MainWindowScene/card/recover.png") ;
        c2->setParent(this);
        c2->move(400,115);
        c2->show();
        QTimer::singleShot(1000,this,[=](){ //执行的函数体
            this->m_player2->m_currentLife += 20 ;
            this->m_player2->m_life += 20 ;
            this->h2->reFreshImg(m_player2->m_currentLife,m_player2->m_life);
            c2->close() ;
        });

    }
    else if(x == 3)
    {
        Card * c3 = new Card(3,":/MainWindowScene/card/plus1.png") ;
        c3->setParent(this);
        c3->move(400,115);
        c3->show();
        QTimer::singleShot(1000,this,[=](){ //执行的函数体
            this->m_player->m_currentLife -= m_player2->m_attack *1 ;
            if(m_player->m_currentLife <= 0) m_player->m_currentLife = 0;
            this->m_topWidget->m_heart->reFreshImg(m_player->m_currentLife,m_player->m_life);
            isLose(m_player->m_currentLife);
            c3->close() ;
        });
    }
    else if(x == 4)
    {
        Card * c4 = new Card(4,":/MainWindowScene/card/plus4.png") ;
        c4->setParent(this);
        c4->move(400,115);
        c4->show();
        QTimer::singleShot(1000,this,[=](){ //执行的函数体
            this->m_player->m_currentLife -= m_player2->m_attack *4 ;
            if(m_player->m_currentLife <= 0) m_player->m_currentLife = 0;
            this->m_topWidget->m_heart->reFreshImg(m_player->m_currentLife,m_player->m_life);
            isLose(m_player->m_currentLife);
            c4->close() ;
        });
    }
    else if(x == 5 || x == 6)
    {
        Card * c5 = new Card(5,":/MainWindowScene/card/laser.png") ;
        c5->setParent(this);
        c5->move(400,115);
        c5->show();

        QTimer::singleShot(1000,this,[=](){ //执行的函数体
            this->m_player->m_currentLife /= 2;
            if(m_player->m_currentLife <= 0) m_player->m_currentLife = 0;
            this->m_topWidget->m_heart->reFreshImg(m_player->m_currentLife,m_player->m_life);
            isLose(m_player->m_currentLife);
            c5->close() ;
        });
    }


}

