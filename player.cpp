#include "player.h"
#include <QPainter>
#include "mypushbtn.h"
#include <QRandomGenerator>
#include <QTimer>
// Player::Player(QWidget *parent): QWidget{parent}
// {

// }

Player::Player(QString playerImg ,QString Info, QString stationery ,int life , int attack , QString playerAttackImg ,QString playerBeAttackedImg )
{

    m_Info.load(Info) ;
    m_currentLife = m_life = life ;
    m_currentLife -= 5;
    m_attack = attack ;
    m_playerImg.load(playerImg)   ;
    m_playerAttackImg.load(playerAttackImg) ;
    m_playerBeAttackedImg.load(playerBeAttackedImg) ;
    m_stationery.load(stationery) ;

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

int Player::getPlayer()
{
    return QRandomGenerator::global()->bounded(1,5) ;
}
