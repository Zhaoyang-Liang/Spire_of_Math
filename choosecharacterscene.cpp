#include "choosecharacterscene.h"
#include <QLabel>
#include "mypushbtn.h"
#include <QMenuBar>
#include <QPainter>
#include "player.h"
#include <QTimer>
#include "checkcharacter.h"
#include "choosecharacterwindow2.h"

ChooseCharacterScene::ChooseCharacterScene(QWidget *parent): QMainWindow{parent}
{
    this->setFixedSize(1080,720);
    this->setWindowTitle("选择角色");


    //实例化plyaer对象————————————————————————————————————————————————————————————
    shili( );


    //——————————————————————————————————————————————————————————————————————————

    MyPushBtn * nextWindow = new MyPushBtn(":/MainWindowScene/stationery/nextBtn.png",":/MainWindowScene/stationery/pressedNext.png",70,70);
    nextWindow->setParent(this);
    nextWindow->move(1000,320);

    ChooseCharacterWindow2 * win = new ChooseCharacterWindow2;

    connect(nextWindow,&MyPushBtn::clicked,this,[=](){
        this->hide();
        win->setGeometry(this->geometry() );
        win->show();
    });

    connect(win,&ChooseCharacterWindow2::back,this,[=](){
        win->hide();
        this->setGeometry(win->geometry() );
        this->show();
    });


    //     connect(yes,&MyPushBtn::clicked,this,[=](){
    //         this->hide();
    //         gameWindow->setGeometry(this->geometry() );
    //         gameWindow->show();
    //     });

    // connect(gameWindow,&GameWindow::gameWindowBack,this,[=](){
    //     gameWindow->hide();
    //     //设置相同位置
    //     this->setGeometry(gameWindow->geometry()   );
    //     this->show();
    // });



}
 void ChooseCharacterScene::paintEvent(QPaintEvent *)
{
     QPainter painter(this);
     QPixmap  pix;
     pix.load(":/MainWindowScene/res/BackGround.png") ;
     pix = pix.scaled(pix.width() , pix.height()  , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
     painter.drawPixmap(0,0,pix);

}




void ChooseCharacterScene::shili( )
{

        static Player * p1 = new Player(":/MainWindowScene/res/testp1.png",":/MainWindowScene/Info/huochaiInfo.png",":/MainWindowScene/res/pencile.png",50,1) ;
        p1->setParent(this);
        p1->move(50,50);

        static CheckCharacter * checkScene1 = new CheckCharacter(p1) ; // 这里传入this指针，给check 的Player 参数；

        connect( p1 , &Player::checkSignal , this ,[=](){

            //延时，等待动画执行完毕
            QTimer::singleShot(100,this,[=](){ //执行的函数体
                //跳转到选择界面
                this->hide();
                checkScene1->setGeometry(this->geometry());
                checkScene1->show();
            });
        }) ;
        p1->num = 1 ;

        connect(checkScene1 , &CheckCharacter::checkSceneBack , this , [=](){

            checkScene1->hide();
            //设置相同位置
            this->setGeometry(checkScene1->geometry());
            this->show();

        });

        static Player * p2 = new Player(":/MainWindowScene/res/hanyongji.png",":/MainWindowScene/Info/HInfo.png" , ":/MainWindowScene/res/gua.png",50,10) ;
        p2->setParent(this);
        p2->move(300,50);

        static CheckCharacter * checkScene2 = new CheckCharacter(p2) ; // 这里传入this指针，给check 的Player 参数；
        p2->num = 2 ;
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


        static Player * p3 = new Player(":/MainWindowScene/res/shao.png",":/MainWindowScene/Info/shaoInfo.png",":/MainWindowScene/res/Ink.png",250,0) ;
        p3->setParent(this);
        p3->move(550,50);
        p3->num = 3 ;

        static CheckCharacter * checkScene3 = new CheckCharacter(p3) ; // 这里传入this指针，给check 的Player 参数；

        connect( p3 , &Player::checkSignal , this ,[=](){

            //延时，等待动画执行完毕
            QTimer::singleShot(100,this,[=](){ //执行的函数体
                //跳转到选择界面
                this->hide();
                checkScene3->setGeometry(this->geometry());
                checkScene3->show();
            });
        }) ;

        connect(checkScene3 , &CheckCharacter::checkSceneBack , this , [=](){

            checkScene3->hide();
            //设置相同位置
            this->setGeometry(checkScene3->geometry());
            this->show();
        });


        static Player * p4 = new Player(":/MainWindowScene/res/zang.png",":/MainWindowScene/Info/zangInfo.png",":/MainWindowScene/res/pencileCompass.png",10,100) ;
        p4->setParent(this);
        p4->move(800,50);
        p4->num = 4 ;

        static CheckCharacter * checkScene4 = new CheckCharacter(p4) ; // 这里传入this指针，给check 的Player 参数；

        connect( p4 , &Player::checkSignal , this ,[=](){

            //延时，等待动画执行完毕
            QTimer::singleShot(100,this,[=](){ //执行的函数体
                //跳转到选择界面
                this->hide();
                checkScene4->setGeometry(this->geometry());
                checkScene4->show();
            });
        }) ;

        connect(checkScene4 , &CheckCharacter::checkSceneBack , this , [=](){

            checkScene4->hide();
            //设置相同位置
            this->setGeometry(checkScene4->geometry());
            this->show();
        });



        static Player * p5 = new Player(":/MainWindowScene/pl/yang.png",":/MainWindowScene/Info/yanggeInfo.png",":/MainWindowScene/stationery/xiaoyuan.png",1,1000) ;
        p5->setParent(this);
        p5->move(50,400);
        p5->num = 5 ;

        static CheckCharacter * checkScene5 = new CheckCharacter(p5) ; // 这里传入this指针，给check 的Player 参数；

        connect( p5 , &Player::checkSignal , this ,[=](){

            //延时，等待动画执行完毕
            QTimer::singleShot(100,this,[=](){ //执行的函数体
                //跳转到选择界面
                this->hide();
                checkScene5->setGeometry(this->geometry());
                checkScene5->show();
            });
        }) ;

        connect(checkScene5 , &CheckCharacter::checkSceneBack , this , [=](){

            checkScene5->hide();
            //设置相同位置
            this->setGeometry(checkScene5->geometry());
            this->show();
        });


        static Player * p6 = new Player(":/MainWindowScene/pl/dage.png",":/MainWindowScene/Info/dageInfo.png",":/MainWindowScene/stationery/qian.png",70,70) ;
        p6->setParent(this);
        p6->move(300,400);
        p6->num = 6 ;

        static CheckCharacter * checkScene6 = new CheckCharacter(p6) ; // 这里传入this指针，给check 的Player 参数；

        connect( p6 , &Player::checkSignal , this ,[=](){

            //延时，等待动画执行完毕
            QTimer::singleShot(100,this,[=](){ //执行的函数体
                //跳转到选择界面
                this->hide();
                checkScene6->setGeometry(this->geometry());
                checkScene6->show();
            });
        }) ;

        connect(checkScene6 , &CheckCharacter::checkSceneBack , this , [=](){
            checkScene6->hide();
            //设置相同位置
            this->setGeometry(checkScene6->geometry());
            this->show();
        });



        static Player * p7 = new Player(":/MainWindowScene/pl/yuyang.png",":/MainWindowScene/Info/yuyangInfo.png",":/MainWindowScene/stationery/pencileCase.png",70,70) ;
        p7->setParent(this);
        p7->move(550,400);
        p7->num = 7 ;

        static CheckCharacter * checkScene7 = new CheckCharacter(p7) ; // 这里传入this指针，给check 的Player 参数；

        connect( p7 , &Player::checkSignal , this ,[=](){

            //延时，等待动画执行完毕
            QTimer::singleShot(100,this,[=](){ //执行的函数体
                //跳转到选择界面
                this->hide();
                checkScene7->setGeometry(this->geometry());
                checkScene7->show();
            });
        }) ;

        connect(checkScene7 , &CheckCharacter::checkSceneBack , this , [=](){
            checkScene7->hide();
            //设置相同位置
            this->setGeometry(checkScene7->geometry());
            this->show();
        });

        static Player * p8 = new Player(":/MainWindowScene/pl/chenyulu.png",":/MainWindowScene/Info/chenyuluInfo.png",":/MainWindowScene/res/eraser.png",100,10) ;
        p8->setParent(this);
        p8->move(800,400);
        p8->num = 8 ;

        static CheckCharacter * checkScene8 = new CheckCharacter(p8) ; // 这里传入this指针，给check 的Player 参数；

        connect( p8 , &Player::checkSignal , this ,[=](){

            //延时，等待动画执行完毕
            QTimer::singleShot(100,this,[=](){ //执行的函数体
                //跳转到选择界面
                this->hide();
                checkScene8->setGeometry(this->geometry());
                checkScene8->show();
            });
        }) ;

        connect(checkScene8 , &CheckCharacter::checkSceneBack , this , [=](){
            checkScene8->hide();
            //设置相同位置
            this->setGeometry(checkScene8->geometry());
            this->show();
        });



}
