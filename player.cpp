#include "player.h"
#include <QPainter>
#include "mypushbtn.h"

#include <QTimer>
// Player::Player(QWidget *parent): QWidget{parent}
// {

// }

Player::Player(QString playerImg ,QString Info, QString playerAttackImg , QString playerBeAttackedImg  ,int life , int attack )
{

    m_Info.load(Info) ;
    m_life = life ;
    m_attack = attack ;
    m_playerImg.load(playerImg)   ;
    m_playerAttackImg.load(playerAttackImg) ;
    m_playerBeAttackedImg.load(playerBeAttackedImg) ;


    resize(m_playerImg.width(),m_playerImg.height());

    //查看按钮：--------------------------------------------------------
    MyPushBtn * chooseBtn = new MyPushBtn(":/MainWindowScene/res/normalCheck.png",":/MainWindowScene/res/pressedCheck.png",150,40);
    chooseBtn->setParent(this);
    chooseBtn->move( (this->width() - chooseBtn->width())/2 - 40  , m_playerImg.height() - 100);

    connect(chooseBtn,&MyPushBtn::clicked,this,[=](){
        emit checkSignal();
    });




    //-----------------------------------------------------------------


}


void Player::paintEvent(QPaintEvent *)//也就是我需要保证每个图片的大小完全一样
{

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing) ;
    if(flag1 == 0)
    {
        flag1  = 1 ;
        m_playerImg = m_playerImg.scaled(m_playerImg.width() *0.7 , m_playerImg.height() * 0.7 , Qt::KeepAspectRatio , Qt::SmoothTransformation ) ;
    }
    painter.drawRect(0, 0, m_playerImg.width(), m_playerImg.height() );
    painter.drawPixmap(0,0,m_playerImg);


}
