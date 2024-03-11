#include "help.h"
#include<QPainter>
Help::Help(QWidget *parent) : QMainWindow(parent)
{
   this->setFixedSize(950,650);
}


void Help::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    //绘制背景
    pix.load(":/res/Help.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}

