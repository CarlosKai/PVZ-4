#include "button.h"
#include"fstream"
Button::Button(QSound *s, QTimer *t)
{
    sound = s;
    timer = t;
}

QRectF Button::boundingRect() const
{
    return QRectF(-120, -30, 240, 60);
}
void Button::setShop(Shop* shop){
    this->shop=shop;
}
Shop* Button::getShop(){
    return this->shop;
}
void Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QPixmap pix(":/images/Button.png");
    pix=pix.scaled(pix.width()*1.5,pix.height()*1.5);
    painter->drawPixmap(QRect(-120, -30, 240, 60), pix);
    painter->setPen(Qt::white);
    QFont font("Calibri", 27, QFont::Bold, true);
    painter->setFont(font);
    if (timer->isActive())
        painter->drawText(boundingRect(), Qt::AlignCenter, "PAUSE");
    else
        painter->drawText(boundingRect(), Qt::AlignCenter, "CONTINUE");
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //控制全局计时器的开启与关闭
    if (event->button() == Qt::LeftButton)
    {
        if (timer->isActive())
        {
            sound->stop();
            timer->stop();
            ofstream mcfile; //创建个对象
                       //这里填保存地址
                        mcfile.open("/Users/89368/Desktop/PVZ 4/1.txt"); //创建文件
                        int count=zBox.size();
                        for(int i=0;i<zBox.size();i++){
                            if(this->zBox[i]->getNum() >6||this->zBox[i]->getXP()<1||this->zBox[i]->getYP()<1||this->zBox[i]->atk==0||this->zBox[i]->speed==0){      count--;
                            }
                        }
                        mcfile<<count<<endl;
                        for (int i=0;i<this->zBox.size();i++) {
                         if(this->zBox[i]->getXP()>=1&&this->zBox[i]->getYP()>=1&&this->zBox[i]->getNum()<=6&&this->zBox[i]->atk!=0&&this->zBox[i]->speed!=0){
                          mcfile<<this->getZBox()[i]->hp<<endl;
                          mcfile<<this->getZBox()[i]->atk<<endl;
                          mcfile<<this->getZBox()[i]->speed<<endl;
                          mcfile<<this->getZBox()[i]->getXP()<<endl;
                          mcfile<<this->getZBox()[i]->getYP()<<endl;
                          mcfile<<this->getZBox()[i]->getNum()<<endl;}
                        }
                         count=this->shop->pBox.size();
                        for(int i=0;i<this->shop->pBox.size();i++){
                            if(this->shop->pBox[i]->xP<1||this->shop->pBox[i]->yP<1||this->shop->pBox[i]->hp<=0){
                                count--;
                            }
                        }
                        mcfile<<count<<endl;
                        for(int i=0;i<this->shop->pBox.size();i++){
                            if(this->shop->pBox[i]->xP>=1&&this->shop->pBox[i]->yP>=1&&this->shop->pBox[i]->hp>0){
                            mcfile<<this->shop->pBox[i]->hp<<endl;
                            mcfile<<this->shop->pBox[i]->getAtk()<<endl;
                            mcfile<<this->shop->pBox[i]->state<<endl;
                            mcfile<<this->shop->pBox[i]->num<<endl;
                            mcfile<<this->shop->pBox[i]->xP<<endl;
                            mcfile<<this->shop->pBox[i]->yP<<endl;}
                        }
                        mcfile<<this->shop->sun;
                        mcfile.close();
        }
        else
        {
            sound->play();
            timer->start();
        }
    }
    update();
}
void Button::addZombie(Zombie* zom){
    this->zBox.push_back(zom);
}
vector <Zombie*> Button::getZBox(){
    return this->zBox;
}

