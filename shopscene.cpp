#include "shopscene.h"
#include "mypushbtn.h"
#include <QPainter>
#include <QRandomGenerator>
#include <QVector>
#include <QSound>
QVector<Card *> haveCards;

ShopScene::ShopScene(Player * p , TopWidegt * tp , Money & m , QVector<Card*> & v )
{

    this->setFixedSize(1080,720);
    this->setWindowTitle("商店界面");

    //到时候按下购买按钮触发类似指令即可
    m_m = &m ;

    m_m->cl();
    m_m->reFreshImg(m.currentMoney);

    haveCards = &v ;

    // reFreshBtn = new MyPushBtn(":/MainWindowScene/card/refresh.png",":/MainWindowScene/card/pressedre.png",50,50);
    // reFreshBtn->setParent(this);
    // reFreshBtn->move(200,800);

    // connect(reFreshBtn,&MyPushBtn::clicked,this,[=](){

    // });*/

    m_p = p  ;
    m_top = tp  ;

    //返回按钮
    MyPushBtn * backBtn = new MyPushBtn(":/MainWindowScene/res/backBtn.png",":/MainWindowScene/res/pressedBackBtn.png",200,50);
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width() , this->height() - backBtn->height());
    connect(backBtn, &MyPushBtn::clicked , this , [=](){
        emit this->ShopSceneBack(); // 发送
    });

    //实例化
    shili();
    showCard1(this->randomGetCard());

    showCard2(this->randomGetCard());
    //————————————————————————————————

    //

}



void ShopScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap  pix;
    pix.load(":/MainWindowScene/res/BackGround.png") ;
    pix = pix.scaled(pix.width() , pix.height()  , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(0,0,pix);

    pix.load(":/MainWindowScene/card/shopBack.png") ;
    pix = pix.scaled(this->width()*0.66 , this->height() *0.66, Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(125,107,pix);

    pix.load(":/MainWindowScene/pl/liyusen.png") ;
    pix = pix.scaled(this->width()*0.4 , this->height() *0.4, Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(780,400,pix);


}

int ShopScene::randomGetCard ()
{
    return QRandomGenerator::global()->bounded(1,101) ;
}

void ShopScene::shili()
{
    this->cardInk = new Card(1,":/MainWindowScene/card/Ink.png") ;
    cardInk->setParent(this);
    cardInk->hide();
    allCards.push_back(cardInk);

    this->cardRecover = new Card(2,":/MainWindowScene/card/recover.png") ;
    cardRecover->setParent(this);
    cardRecover->hide();
    allCards.push_back(cardRecover);

    this->cardPlus1 = new Card(3,":/MainWindowScene/card/plus1.png") ;
    cardPlus1->setParent(this);
    cardPlus1->hide();
    allCards.push_back(cardPlus1);

    this->cardplus4 = new Card(4,":/MainWindowScene/card/plus4.png") ;
    cardplus4->setParent(this);
    cardplus4->hide();
    allCards.push_back(cardplus4);

    this->cardLaser = new Card(5,":/MainWindowScene/card/laser.png") ;
    cardLaser->setParent(this);
    cardLaser->hide();
    allCards.push_back(cardLaser);

    this->cardDerive = new Card(6,":/MainWindowScene/card/derive.png") ;
    cardDerive->setParent(this);
    cardDerive->hide();
    allCards.push_back(cardDerive);

    //_______________________________

}



void ShopScene::showCard1(int x)
{
    if( x>=1 && x <= 21)
    {
        allCards[0]->show();
        allCards[0]->move(200,200);
        allCards[0]->raise();
    }
    else if( x>= 22 && x <=42)
    {
        allCards[1]->show();
        allCards[1]->move(200,200);
        allCards[1]->raise();
    }
    else if( x>= 43 && x <=63)
    {
        allCards[2]->show();
        allCards[2]->move(200,200);
        allCards[2]->raise();
    }
    else if( x>= 64 && x <=76)
    {
        allCards[3]->show();
        allCards[3]->move(200,200);
        allCards[3]->raise();
    }
    else if( x>= 77 && x <=90)
    {
        allCards[4]->show();
        allCards[4]->move(200,200);
        allCards[4]->raise();
    }
    else if( x>= 91 && x <=100)
    {
        allCards[5]->show();
        allCards[5]->move(200,200);
        allCards[5]->raise();
    }
    buy1 = new MyPushBtn(":/MainWindowScene/card/buyBtn1.png",":/MainWindowScene/card/pressedBuyBtn1.png",250,55);
    buy1->setParent(this);
    buy1->move(160,510);

    if( x>=1 && x <= 21 )
    {

        connect(buy1,&MyPushBtn::clicked,this,[=](){
            if(m_m->currentMoney >= 10 )
            {
                this->haveCards->push_back(allCards[0]);
                allCards[0]->hide();
                buy1->setEnabled(false);
                m_m->currentMoney -= 10 ;
                m_m->cl();
                m_m->reFreshImg(m_m->currentMoney);

                QSound::play(":/MainWindowScene/soud/money.wav");


            }
        });
    }
    else if( x>= 22 && x <=42 )
    {

        connect(buy1,&MyPushBtn::clicked,this,[=](){
            if(m_m->currentMoney >= 10)
            {
                this->haveCards->push_back(allCards[1]);
                allCards[1]->hide();
                 buy1->setEnabled(false);
                m_m->currentMoney -= 10 ;
                m_m->cl();
                m_m->reFreshImg(m_m->currentMoney);

                QSound::play(":/MainWindowScene/soud/money.wav");


            }

        });
    }
    else if( x>= 43 && x <=63 )
    {
        connect(buy1,&MyPushBtn::clicked,this,[=](){
            if(m_m->currentMoney >= 10)
            {
                this->haveCards->push_back(allCards[2]);
                allCards[2]->hide();
                 buy1->setEnabled(false);
                m_m->currentMoney -= 10 ;
                m_m->cl();
                m_m->reFreshImg(m_m->currentMoney);

                QSound::play(":/MainWindowScene/soud/money.wav");


            }


        });
    }
    else if( x>= 64 && x <=76 )
    {
        connect(buy1,&MyPushBtn::clicked,this,[=](){
            if(m_m->currentMoney >= 20)
            {
                this->haveCards->push_back(allCards[3]);
                allCards[3]->hide();
                 buy1->setEnabled(false);
                m_m->currentMoney -= 20 ;
                m_m->cl();
                m_m->reFreshImg(m_m->currentMoney);

                QSound::play(":/MainWindowScene/soud/money.wav");



            }
        });
    }
    else if( x>= 77 && x <=90 )
    {

        connect(buy1,&MyPushBtn::clicked,this,[=](){
            if(m_m->currentMoney >= 20)
            {
                this->haveCards->push_back(allCards[4]);
                allCards[4]->hide();
                 buy1->setEnabled(false);
                m_m->currentMoney -= 20 ;
                m_m->cl();
                m_m->reFreshImg(m_m->currentMoney);

                QSound::play(":/MainWindowScene/soud/money.wav");


            }
        });
    }
    else if( x>= 91 && x <=100 )
    {
        connect(buy1,&MyPushBtn::clicked,this,[=](){
            if(m_m->currentMoney >= 60)
            {
                this->haveCards->push_back(allCards[5]);
                allCards[5]->hide();
                buy1->setEnabled(false);
                m_m->currentMoney -= 60 ;
                m_m->cl();
                m_m->reFreshImg(m_m->currentMoney);

                QSound::play(":/MainWindowScene/soud/money.wav");


            }
        });
    }

}


void ShopScene::showCard2(int x)
{
    if( x>=1 && x <= 21)
    {
        allCards[0]->show();
        allCards[0]->move(565,200);
    }
    else if( x>= 22 && x <=42)
    {
        allCards[1]->show();
        allCards[1]->move(565,200);
    }
    else if( x>= 43 && x <=63)
    {
        allCards[2]->show();
        allCards[2]->move(565,200);
    }
    else if( x>= 64 && x <=76)
    {
        allCards[3]->show();
        allCards[3]->move(565,200);
    }
    else if( x>= 77 && x <=90)
    {
        allCards[4]->show();
        allCards[4]->move(565,200);
    }
    else if( x>= 91 && x <=100)
    {
        allCards[5]->show();
        allCards[5]->move(565,200);
    }

    buy2 = new MyPushBtn(":/MainWindowScene/card/buyBtn2.png",":/MainWindowScene/card/pressedBuyBtn2.png",270,75);

    buy2->setParent(this);
    buy2->move(520,490);
    if( x>=1 && x <= 21 )
    {
        connect(buy2,&MyPushBtn::clicked,this,[=](){
            if(m_m->currentMoney >= 10)
            {
                QSound::play(":/MainWindowScene/soud/money.wav");

                this->haveCards->push_back(allCards[0]);
                allCards[0]->hide();
                 buy2->setEnabled(false);
                m_m->currentMoney -= 10 ;
                m_m->cl();
                m_m->reFreshImg(m_m->currentMoney);

            }
        });
    }
    else if( x>= 22 && x <=42 )
    {

        connect(buy2,&MyPushBtn::clicked,this,[=](){
            if(m_m->currentMoney >= 10)
            {
                QSound::play(":/MainWindowScene/soud/money.wav");

                this->haveCards->push_back(allCards[1]);
                allCards[1]->hide();
                 buy2->setEnabled(false);
                m_m->currentMoney -= 10 ;
                m_m->cl();
                m_m->reFreshImg(m_m->currentMoney);



            }

        });
    }
    else if( x>= 43 && x <=63 )
    {
        connect(buy2,&MyPushBtn::clicked,this,[=](){
            if(m_m->currentMoney >= 10)
            {
                this->haveCards->push_back(allCards[2]);
                allCards[2]->hide();
                 buy2->setEnabled(false);
                m_m->currentMoney -= 10 ;
                m_m->cl();
                m_m->reFreshImg(m_m->currentMoney);
                QSound::play(":/MainWindowScene/soud/money.wav");


            }
        });
    }
    else if( x>= 64 && x <=76 )
    {
        connect(buy2,&MyPushBtn::clicked,this,[=](){
            if(m_m->currentMoney >= 20)
            {
                this->haveCards->push_back(allCards[3]);
                allCards[3]->hide();
                 buy2->setEnabled(false);
                m_m->currentMoney -= 20 ;
                m_m->cl();
                m_m->reFreshImg(m_m->currentMoney);
                QSound::play(":/MainWindowScene/soud/money.wav");


            }
        });
    }
    else if( x>= 77 && x <=90 )
    {

        connect(buy2,&MyPushBtn::clicked,this,[=](){
            if(m_m->currentMoney >= 20)
            {
                this->haveCards->push_back(allCards[4]);
                allCards[4]->hide();
                 buy2->setEnabled(false);
                m_m->currentMoney -= 20 ;
                m_m->cl();
                m_m->reFreshImg(m_m->currentMoney);
                QSound::play(":/MainWindowScene/soud/money.wav");


            }
        });
    }
    else if( x>= 91 && x <=100 )
    {
        connect(buy2,&MyPushBtn::clicked,this,[=](){
            if(m_m->currentMoney >= 60)
            {
                this->haveCards->push_back(allCards[5]);
                allCards[5]->hide();
                 buy2->setEnabled(false);
                m_m->currentMoney -= 60 ;
                m_m->cl();
                m_m->reFreshImg(m_m->currentMoney);
                QSound::play(":/MainWindowScene/soud/money.wav");

            }
        });
    }
}


