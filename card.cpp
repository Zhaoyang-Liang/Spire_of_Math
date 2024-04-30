#include "card.h"
#include <QPainter>


Card::Card(int Rarity,QString type) //构造函数
{
    m_type = type ;
    m_rarity = Rarity ;
    setFixedSize(260,395);

    if(m_rarity == 1)
    {
        m_price = 10 ;
    }
    else if(m_rarity == 2)
    {
        m_price = 30 ;
    }
    else
    {
        m_price = 70 ;
    }

}


void Card::setClick(bool b)
{
    isClick = b ;
    if(isClick)
    {
        move(this->x(),this->y()-30);
    }
    else
    {
        move(this->x(),this->y()+30);
    }
    update();
}

void Card::setSelected(bool b)
{
    isSelected=b;
    update();
}


void Card::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event) ;

    QPainter painter(this);//定义画板为自己背景，相当于VS中DC pDC
    //设置去毛边 高质量模式
    painter.setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform);
    //透明覆盖
    painter.fillRect(this->rect(), QBrush(Qt::transparent));
    //定义一个图像用来绘到背景
    QPixmap thisPix(width(),height());
    thisPix.fill(Qt::transparent);//透明填充
    thisPix.load(this->m_type) ;

    painter.drawPixmap(0,0,this->width()*0.7,this->height()*0.7,thisPix);


    QPainter painter2;//重新定义一个画板为 thisPix
    painter2.begin(&thisPix);//画板开始
    //设置去毛边 高质量模式
    painter2.setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform);

    //_______________________________________________________________________________________
    QPixmap pix2 ;
    pix2.load(this->m_type) ;
    painter2.drawPixmap(20,20,160,160,pix2) ;
    //______________________________________________________________________________________

    // if(isSelected)//如果选中了，上面添加一层透明度为100的颜色
    // {
    //     // painter2.setBrush(QColor(44,44,44,100));
    //     // painter2.drawRoundedRect(20,20,160,160,);
    // }
    // painter2.end();//画板结束


    // //如果角度不是0
    // if(angle!=0)
    // {
    //     QMatrix matrix;//定义一个矩阵
    //     matrix.rotate(angle);//旋转n度
    //     //运用到图像中去
    //     thisPix=thisPix.transformed(matrix, Qt::SmoothTransformation);
    // }
    // //绘制到背景上去
    // painter.drawPixmap(this->rect(),thisPix);

    // ————————————————


}
