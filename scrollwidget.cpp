#include "scrollwidget.h"
#include "ui_scrollwidget.h"

ScrollWidget::ScrollWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ScrollWidget)
{
    ui->setupUi(this);
}

ScrollWidget::~ScrollWidget()
{
    delete ui;
}
