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

    static Player * p9 = new Player(":/MainWindowScene/pl/tangjiafeng.png",":/MainWindowScene/Info/tangjiafengInfo.png",":/MainWindowScene/stationery/tangjiafeng.png",100,10) ;
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

    static Player * p10 = new Player(":/MainWindowScene/pl/songhao.png",":/MainWindowScene/Info/shaoInfo.png",":/MainWindowScene/stationery/songhao.png",100,10) ;
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

    static Player * p11 = new Player(":/MainWindowScene/chouxiangren/08.png",":/MainWindowScene/chouxiangren/chouxiangren.png",":/MainWindowScene/res/pencile.png",100,10) ;
    p11->setParent(this);
    p11->move(600,50);

    static CheckCharacter * checkScene11 = new CheckCharacter(p11) ; // 这里传入this指针，给check 的Player 参数；

    connect( p11 , &Player::checkSignal , this ,[=](){

        //延时，等待动画执行完毕
        QTimer::singleShot(100,this,[=](){ //执行的函数体
            //跳转到选择界面
            this->hide();
            checkScene11->setGeometry(this->geometry());
            checkScene11->show();
        });
    }) ;
    p11->num =11;

    connect(checkScene11, &CheckCharacter::checkSceneBack , this , [=](){
        checkScene11->hide();
        //设置相同位置
        this->setGeometry(checkScene11->geometry());
        this->show();
    });

    static Player * p12 = new Player(":/MainWindowScene/chouxiangren/lant.png",":/MainWindowScene/chouxiangren/chouxiangren.png",":/MainWindowScene/res/pencile.png",100,10) ;
    p12->setParent(this);
    p12->move(850,50);

    static CheckCharacter * checkScene12 = new CheckCharacter(p12) ; // 这里传入this指针，给check 的Player 参数；

    connect( p12 , &Player::checkSignal , this ,[=](){

        //延时，等待动画执行完毕
        QTimer::singleShot(100,this,[=](){ //执行的函数体
            //跳转到选择界面
            this->hide();
            checkScene12->setGeometry(this->geometry());
            checkScene12->show();
        });
    }) ;
    p12->num =12;

    connect(checkScene12, &CheckCharacter::checkSceneBack , this , [=](){
        checkScene12->hide();
        //设置相同位置
        this->setGeometry(checkScene12->geometry());
        this->show();
    });

    static Player * p13 = new Player(":/MainWindowScene/chouxiangren/kun.png",":/MainWindowScene/chouxiangren/chouxiangren.png",":/MainWindowScene/res/pencile.png",100,10) ;
    p13->setParent(this);
    p13->move(100,400);

    static CheckCharacter * checkScene13 = new CheckCharacter(p13) ; // 这里传入this指针，给check 的Player 参数；

    connect( p13 , &Player::checkSignal , this ,[=](){

        //延时，等待动画执行完毕
        QTimer::singleShot(100,this,[=](){ //执行的函数体
            //跳转到选择界面
            this->hide();
            checkScene13->setGeometry(this->geometry());
            checkScene13->show();
        });
    }) ;
    p13->num =13;

    connect(checkScene13, &CheckCharacter::checkSceneBack , this , [=](){
        checkScene13->hide();
        //设置相同位置
        this->setGeometry(checkScene13->geometry());
        this->show();
    });

    static Player * p14 = new Player(":/MainWindowScene/chouxiangren/laoda.png",":/MainWindowScene/chouxiangren/chouxiangren.png",":/MainWindowScene/res/pencile.png",100,10) ;
    p14->setParent(this);
    p14->move(350,400);

    static CheckCharacter * checkScene14 = new CheckCharacter(p14) ; // 这里传入this指针，给check 的Player 参数；

    connect( p14 , &Player::checkSignal , this ,[=](){

        //延时，等待动画执行完毕
        QTimer::singleShot(100,this,[=](){ //执行的函数体
            //跳转到选择界面
            this->hide();
            checkScene14->setGeometry(this->geometry());
            checkScene14->show();
        });
    }) ;
    p14->num =14;

    connect(checkScene14, &CheckCharacter::checkSceneBack , this , [=](){
        checkScene14->hide();
        //设置相同位置
        this->setGeometry(checkScene14->geometry());
        this->show();
    });

    static Player * p15 = new Player(":/MainWindowScene/chouxiangren/laohuo.png",":/MainWindowScene/chouxiangren/chouxiangren.png",":/MainWindowScene/res/pencile.png",100,10) ;
    p15->setParent(this);
    p15->move(600,400);

    static CheckCharacter * checkScene15 = new CheckCharacter(p15) ; // 这里传入this指针，给check 的Player 参数；

    connect( p15 , &Player::checkSignal , this ,[=](){

        //延时，等待动画执行完毕
        QTimer::singleShot(100,this,[=](){ //执行的函数体
            //跳转到选择界面
            this->hide();
            checkScene15->setGeometry(this->geometry());
            checkScene15->show();
        });
    }) ;
    p15->num =15;

    connect(checkScene15, &CheckCharacter::checkSceneBack , this , [=](){
        checkScene15->hide();
        //设置相同位置
        this->setGeometry(checkScene15->geometry());
        this->show();
    });

    static Player * p16 = new Player(":/MainWindowScene/chouxiangren/menjiang.png",":/MainWindowScene/chouxiangren/chouxiangren.png",":/MainWindowScene/res/pencile.png",100,10) ;
    p16->setParent(this);
    p16->move(850,400);

    static CheckCharacter * checkScene16 = new CheckCharacter(p16) ; // 这里传入this指针，给check 的Player 参数；

    connect( p16 , &Player::checkSignal , this ,[=](){

        //延时，等待动画执行完毕
        QTimer::singleShot(100,this,[=](){ //执行的函数体
            //跳转到选择界面
            this->hide();
            checkScene16->setGeometry(this->geometry());
            checkScene16->show();
        });
    }) ;
    p16->num =16;

    connect(checkScene16, &CheckCharacter::checkSceneBack , this , [=](){
        checkScene15->hide();
        //设置相同位置
        this->setGeometry(checkScene15->geometry());
        this->show();
    });


}
