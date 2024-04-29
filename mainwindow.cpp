#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "mypushbtn.h"
#include <QMenuBar>
#include <QLabel>
#include "choosecharacterscene.h"
#include <QTimer>
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1080,720);

    setWindowTitle("开始界面");

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


    //实例化chooseScene界面
    this->chooseCharacterScene = new ChooseCharacterScene ;


    /*----------------------------------------*/
    startBtn = new MyPushBtn(":/MainWindowScene/res/normalStartBtn.png",":/MainWindowScene/res/pressedStartBtn.png",200,50) ;
    startBtn->setParent(this);
    startBtn->move(150,400 );


    connect( startBtn, &MyPushBtn::clicked , this ,[=](){

        //延时，等待动画执行完毕
        QTimer::singleShot(100,this,[=](){ //执行的函数体

            //跳转到选择界面
            this->hide();
            chooseCharacterScene->setGeometry(this->geometry());
            chooseCharacterScene->show();
        });
    }) ;

    //监听返回信号：
    connect(chooseCharacterScene,&ChooseCharacterScene::chooseSceneBack,this,[=](){
        chooseCharacterScene->hide();
        //设置相同位置
        this->setGeometry(chooseCharacterScene->geometry()   );
        this->show();
    });

}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing) ;
    QPixmap  pix;
    pix.load(":/MainWindowScene/res/BackGround.png") ;
    pix = pix.scaled(pix.width() , pix.height() , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(0,0,pix);

    // pix.load("");
    // pix = pix.scaled(pix.width() *0.2 , pix.height() *0.2 ) ;
    // painter.drawPixmap(10,10,pix);
}
