#include "mower.h"
#include<QSound>
//铲车
Mower::Mower()
{
    flag = false;
    speed = 270.0 * 33 / 1000*1.5;
     send=new QSound(":/res/lawnmower.wav");
}

QRectF Mower::boundingRect() const
{
    return QRectF(-45, -45, 90, 90);
}

void Mower::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QPixmap pix(":/images/LawnMower.png");
    pix=pix.scaled(pix.width()*1.5,pix.height()*1.5);
    painter->drawPixmap(QRect(-45, -45, 90, 90), pix);
}

bool Mower::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 22.5;
}

void Mower::advance(int phase)
{

    if (!phase)
        return;
    update();
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.empty())
    {
        if(flag==false){

            send->play();
        }
        flag = true;
        foreach (QGraphicsItem *item, items)
            delete item;
    }
    //小车冲出
    if (flag)
        setX(x() + speed);
    if (x() > 1603.5)
        delete this;
}
