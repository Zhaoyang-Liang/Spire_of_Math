#include "choosecharacterscene.h"
#include <QLabel>
#include "mypushbtn.h"
#include <QMenuBar>
#include <QPainter>
#include "player.h"
#include <QTimer>
#include "checkcharacter.h"
ChooseCharacterScene::ChooseCharacterScene(QWidget *parent): QMainWindow{parent}
{
    this->setFixedSize(1080,720);
    this->setWindowTitle("选择角色");

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
        emit this->chooseSceneBack(); // 发送
    });







    //实例化plyaer对象————————————————————————————————————————————————————————————
    Player * p1 = new Player(":/MainWindowScene/res/testp1.png",":/MainWindowScene/Info/huochaiInfo.png") ;
    p1->setParent(this);
    p1->move(50,50);

    CheckCharacter * checkScene1 = new CheckCharacter(p1) ; // 这里传入this指针，给check 的Player 参数；

    connect( p1 , &Player::checkSignal , this ,[=](){

        //延时，等待动画执行完毕
        QTimer::singleShot(100,this,[=](){ //执行的函数体
            //跳转到选择界面
            this->hide();
            checkScene1->setGeometry(this->geometry());
            checkScene1->show();
        });
    }) ;

    connect(checkScene1 , &CheckCharacter::checkSceneBack , this , [=](){

            checkScene1->hide();
            //设置相同位置
            this->setGeometry(checkScene1->geometry());
            this->show();

    });

    Player * p2 = new Player(":/MainWindowScene/res/hanyongji.png",":/MainWindowScene/Info/HInfo.png") ;
    p2->setParent(this);
    p2->move(300,50);

    CheckCharacter * checkScene2 = new CheckCharacter(p2) ; // 这里传入this指针，给check 的Player 参数；

    connect( p2 , &Player::checkSignal , this ,[=](){

        //延时，等待动画执行完毕
        QTimer::singleShot(100,this,[=](){ //执行的函数体
            //跳转到选择界面
            this->hide();
            checkScene2->setGeometry(this->geometry());
            checkScene2->show();
        });
    }) ;
    connect(checkScene2, &CheckCharacter::checkSceneBack , this , [=](){

        checkScene2->hide();
        //设置相同位置
        this->setGeometry(checkScene2->geometry());
        this->show();

    });


    //——————————————————————————————————————————————————————————————————————————



}
 void ChooseCharacterScene::paintEvent(QPaintEvent *)
{
     QPainter painter(this);
     QPixmap  pix;
     pix.load(":/MainWindowScene/res/BackGround.png") ;
     pix = pix.scaled(pix.width() , pix.height()  , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
     painter.drawPixmap(0,0,pix);

}
