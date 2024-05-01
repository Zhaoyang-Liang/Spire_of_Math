#include "choosecharacterwindow2.h"
#include <QLabel>
#include "mypushbtn.h"
#include <QMenuBar>
#include <QPainter>
#include "player.h"
#include <QTimer>
#include "checkcharacter.h"
#include "choosecharacterscene.h"

ChooseCharacterWindow2::ChooseCharacterWindow2(QWidget *parent): QMainWindow{parent}
{
    this->setFixedSize(1080,720);
    this->setWindowTitle("选择角色");

    shili( );


    MyPushBtn * nextWindow = new MyPushBtn(":/MainWindowScene/stationery/nextBtn2.png",":/MainWindowScene/stationery/pressedNext2.png",70,70);
    nextWindow->setParent(this);
    nextWindow->move(10,320);



    connect(nextWindow,&MyPushBtn::clicked,this,[=](){
        emit back();
    });
}
void ChooseCharacterWindow2::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap  pix;
    pix.load(":/MainWindowScene/res/BackGround.png") ;
    pix = pix.scaled(pix.width() , pix.height()  , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(0,0,pix);

}



void ChooseCharacterWindow2::shili( )
{

    static Player * p9 = new Player(":/MainWindowScene/pl/tangjiafeng.png",":/MainWindowScene/Info/tangjiafengInfo.png",":/MainWindowScene/stationery/tangjiafeng.png",700,50) ;
    p9->setParent(this);
    p9->move(100,50);

    static CheckCharacter * checkScene9 = new CheckCharacter(p9) ; // 这里传入this指针，给check 的Player 参数；

    connect( p9 , &Player::checkSignal , this ,[=](){

        //延时，等待动画执行完毕
        QTimer::singleShot(100,this,[=](){ //执行的函数体
            //跳转到选择界面
            this->hide();
            checkScene9->setGeometry(this->geometry());
            checkScene9->show();
        });
    }) ;
    p9->num =9;

    connect(checkScene9, &CheckCharacter::checkSceneBack , this , [=](){
        checkScene9->hide();
        //设置相同位置
        this->setGeometry(checkScene9->geometry());
        this->show();
    });

    static Player * p10 = new Player(":/MainWindowScene/pl/songhao.png",":/MainWindowScene/Info/tangjiafengInfo.png",":/MainWindowScene/stationery/songhao.png",700,50) ;
    p10->setParent(this);
    p10->move(350,50);

    static CheckCharacter * checkScene10 = new CheckCharacter(p10) ; // 这里传入this指针，给check 的Player 参数；

    connect( p10 , &Player::checkSignal , this ,[=](){

        //延时，等待动画执行完毕
        QTimer::singleShot(100,this,[=](){ //执行的函数体
            //跳转到选择界面
            this->hide();
            checkScene10->setGeometry(this->geometry());
            checkScene10->show();
        });
    }) ;
    p10->num =10;

    connect(checkScene10, &CheckCharacter::checkSceneBack , this , [=](){
        checkScene10->hide();
        //设置相同位置
        this->setGeometry(checkScene10->geometry());
        this->show();
    });


}
