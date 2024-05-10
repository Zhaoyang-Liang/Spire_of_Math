#include "mypushbtn.h"
#include <QString>
#include <QDebug>
#include <QPropertyAnimation>


MyPushBtn::MyPushBtn(QString normalImg , QString pressImg , int w, int h)
{
    this->w = w ;
    this->h = h ;
    this->normalImgPath = normalImg ;
    this->pressImgPath = pressImg ;
    QPixmap pix ;

    isWin = false ;

    bool ret = pix.load(normalImg) ;
    if(!ret)
    {
        qDebug()<<"图片加载失败";
        return;
    }
    // pix = pix.scaled(pix.width()*w,pix.height()*h) ;
    //设置固定大小
    pix.setDevicePixelRatio(this->devicePixelRatio());
    this->setFixedSize(w,h);
    //不规则图片
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pix);
    //设大小
    this->setIconSize(QSize(w,h));
}



void MyPushBtn::mousePressEvent(QMouseEvent *e) // 这两个mousepressEvent和releaseEvent用于完成照片切换
{
    if(this->pressImgPath != "" )
    {
        QPixmap pix ;
        bool ret = pix.load(pressImgPath) ;
        if(!ret)
        {
            qDebug()<<"图片加载失败";
            return;
        }
            // pix = pix.scaled(pix.width()*w,pix.height()*h) ;
        //设置固定大小
        this->setFixedSize(w,h);
        //不规则图片
        this->setStyleSheet("QPushButton{border:0px;}");
        //设置图标
        this->setIcon(pix);
        //设大小
        this->setIconSize(QSize(w,h));
    }
    return QPushButton::mousePressEvent(e); // 交还给父类！！！
}


void MyPushBtn::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->normalImgPath != ""  )
    {
        QPixmap pix ;
        bool ret = pix.load(normalImgPath) ;
       // pix = pix.scaled(pix.width()*this->w , pix.height()*this->h ) ;
        if(!ret)
        {
            qDebug()<<"图片加载失败";
            return;
        }
        //设置固定大小
        this->setFixedSize(w,h);
        //不规则图片
        this->setStyleSheet("QPushButton{border:0px;}");
        //设置图标
        this->setIcon(pix);
        //设大小
        this->setIconSize(QSize(w,h));
    }
    return QPushButton::mouseReleaseEvent(e);
}








