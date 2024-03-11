#include "snowzombie.h"
#include<QSound>
QSound *snowzombie =new QSound(":/other/SnowZombie.wav");
SnowZombie::SnowZombie()
{
    snowzombie->play();
    hp = 1920;
    atk = 1800;
    speed = 80.0 * 33 / 1000 / 2.5*1.2;
    setMovie(":/other/SnowZombieWalk.gif");
}
SnowZombie::SnowZombie(int hp,int atk,qreal speed){
    snowzombie->play();
    this->hp=hp;
    this->atk=atk;
    this->speed=speed;
    setMovie(":/other/SnowZombieWalk.gif");
}
void SnowZombie::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
    {
        if (state < 2)
        {

            state = 2;
            setMovie(":/other/SnowZombieDie.gif");
            setHead(":/images/ZombieHead.gif");

        }
        else if (movie->currentFrameNumber() == movie->frameCount() - 1){
            delete this;}
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
            setMovie(":/other/SnowZombieWalk.gif");
        }
        return;
    }
    if (state)
    {
        state = 0;
        setMovie(":/other/SnowZombieWalk.gif");
    }
    setX(x() - speed);
    this->setXP(x() - speed);
}


