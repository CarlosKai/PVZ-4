#include "pea.h"
#include "zombie.h"

Pea::Pea(int attack, bool flag)
{
    snow = flag;
    atk = attack;
    speed = 360.0 * 33 / 1000*1.5;
    pea=new QSound(":/res/kernelpult2.wav");
    snowpea =new QSound(":/res/frozen.wav");
}

QRectF Pea::boundingRect() const
{
    return QRectF(-18, -42, 36, 36);
}

void Pea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    //判断画冰豌豆还是绿豌豆
    QPixmap pix1(":/images/PeaSnow.png");
    pix1=pix1.scaled(pix1.width()*1.5,pix1.height()*1.5);
    QPixmap pix2(":/images/Pea.png");
    pix2=pix2.scaled(pix2.width()*1.5,pix2.height()*1.5);
    painter->drawPixmap(QRect(-18, -42, 36, 36), QPixmap(snow ? pix1:pix2));
}

bool Pea::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    //碰撞检测
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 22.5;
}

void Pea::advance(int phase)
{
    if (!phase)
        return;
    update();
    QList<QGraphicsItem *> items = collidingItems();//有东西碰到僵尸了
    if (!items.isEmpty())
    {
        Zombie *zombie = qgraphicsitem_cast<Zombie *>(items[qrand() % items.size()]);
        zombie->hp -= atk;
        if(snow){
            snowpea->play();

        }
        else{
            pea->play();

        }
        if (snow && zombie->speed > 0.55*1.5)
            zombie->speed /= 2;
        delete this;//每一颗豌豆发射完成都需要删除
        return;
    }
    setX(x() + speed);
    if (x() > 1603.5)
        delete this;
}
