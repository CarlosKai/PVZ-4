#include "peashooter.h"

Peashooter::Peashooter()
{
    atk = 25;
    hp = 300;
    time = int(1.4 * 1000 / 33);
    setMovie(":/images/Peashooter.gif");
}
Peashooter::Peashooter(int hp,int atk){
    this->hp=hp;
    this->atk=atk;
    time = int(1.4 * 1000 / 33);
    setMovie(":/images/Peashooter.gif");
}
void Peashooter::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (++counter >= time)
    {
        counter = 0;
        if (!collidingItems().isEmpty())
        {
            Pea *pea = new Pea(atk);
            this->sBox.push_back(pea);
            pea->setX(x() + 32*1.5);
            pea->setY(y());
            scene()->addItem(pea);
            return;
        }
    }
}

bool Peashooter::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y());
}
