#include "bucketzombie.h"
//铁桶僵尸

BucketZombie::BucketZombie()
{
    hp = 1370;
    atk = 100 * 33 / 1000;
    speed = 80.0 * 33 / 1000 / 4.7*1.5*2;
    setMovie(":/images/BucketZombieWalk.gif");
}
BucketZombie::BucketZombie(int hp,int atk,qreal speed){
    this->hp=hp;
    this->atk=atk;
    this->speed=speed;
    setMovie(":/images/BucketZombieWalk.gif");
}
void BucketZombie::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
    {
        if (state < 2)
        {
            state = 2;
            setMovie(":/images/ZombieDie.gif");
            setHead(":/images/ZombieHead.gif");
        }
        else if (movie->currentFrameNumber() == movie->frameCount() - 1)
            delete this;
        return;
    }
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty())
    {
        Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
        plant->hp -= atk;
        if (state != 1)
        {
            state = 1;
            setMovie(":/images/BucketZombieAttack.gif");
        }
        return;
    }
    if (state)
    {
        state = 0;
        setMovie(":/images/BucketZombieWalk.gif");
    }
    setX(x() - speed);
    this->setXP(x() - speed);
}
