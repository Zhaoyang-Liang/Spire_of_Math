#ifndef MYPUSHBTN_H
#define MYPUSHBTN_H

#include <QPushButton>

class MyPushBtn : public QPushButton
{
    Q_OBJECT
public:
    MyPushBtn(QString normalImg , QString pressImg = "",int w = 10 , int h=10) ;

    QString normalImgPath ;
    QString pressImgPath ;

    //图片切换：

    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    int w , h;
    bool isWin ;

signals:
};

#endif // MYPUSHBTN_H
