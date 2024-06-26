#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "mypushbtn.h"
#include <QMenuBar>
#include <QLabel>
#include "choosecharacterscene.h"
#include <QTimer>
#include <QSound>
#include "seestawindow.h"
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setFixedSize(1080,720);

    setWindowTitle("开始界面");

    //实例化chooseScene界面
    this->chooseCharacterScene = new ChooseCharacterScene ;
    seeStaWindow = new SeeStaWindow ;


    /*----------------------------------------*/
    startBtn = new MyPushBtn(":/MainWindowScene/res/normalStartBtn.png",":/MainWindowScene/res/pressedStartBtn.png",200,50) ;
    startBtn->setParent(this);
    startBtn->move(150,430 );

    stationeryBtn = new MyPushBtn(":/MainWindowScene/stationery/intro.png",":/MainWindowScene/stationery/pressedIntro.png",236,47) ;
    stationeryBtn->setParent(this);
    stationeryBtn->move(132,500 );

    connect( stationeryBtn, &MyPushBtn::clicked , this ,[=](){

        //延时，等待动画执行完毕
        QTimer::singleShot(100,this,[=](){ //执行的函数体
            //跳转到选择界面
            this->hide();
            seeStaWindow->setGeometry(this->geometry());
            seeStaWindow->show();

        });
    }) ;

    connect(seeStaWindow,&SeeStaWindow::seeStaSceneBack,this,[=](){
        seeStaWindow->hide();
        //设置相同位置
        this->setGeometry(seeStaWindow->geometry());
        this->show();
    });


    connect( startBtn, &MyPushBtn::clicked , this ,[=](){

        //延时，等待动画执行完毕
        QTimer::singleShot(100,this,[=](){ //执行的函数体
            //跳转到选择界面
            this->hide();
            chooseCharacterScene->setGeometry(this->geometry());
            chooseCharacterScene->show();
            QSound::play(":/MainWindowScene/soud/choose.wav");
        });
    }) ;

    //监听返回信号：
    connect(chooseCharacterScene,&ChooseCharacterScene::chooseSceneBack,this,[=](){
        chooseCharacterScene->hide();
        //设置相同位置
        this->setGeometry(chooseCharacterScene->geometry());
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
    pix.load(":/MainWindowScene/res/MainBack.png") ;
    pix = pix.scaled(pix.width() , pix.height() , Qt::KeepAspectRatio , Qt::SmoothTransformation) ;
    painter.drawPixmap(0,0,pix);

    // pix.load("");
    // pix = pix.scaled(pix.width() *0.2 , pix.height() *0.2 ) ;
    // painter.drawPixmap(10,10,pix);
}
