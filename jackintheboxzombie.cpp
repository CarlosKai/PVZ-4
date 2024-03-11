#include "jackintheboxzombie.h"
#include<QSound>

QSound *appearance =new QSound(":/other/jackinthebox.wav");

JackinTheBoxZombie::JackinTheBoxZombie()
{
    appearance->play();
    appearance->setLoops(2);
    hp = 320;
    atk = 100 * 33 / 1000;
    speed = 80.0 * 33 / 1000 / 2.5*1.4;
    setMovie(":/other/JackinTheBoxZombieWalk.gif");
}
JackinTheBoxZombie::JackinTheBoxZombie(int hp,int atk,qreal speed){
    appearance->play();
    appearance->setLoops(2);
    this->hp=hp;
    this->atk=atk;
    this->speed=speed;
    setMovie(":/other/JackinTheBoxZombieWalk.gif");
}

void JackinTheBoxZombie::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
    {
        appearance->stop();
        if (state < 2)
        {

            state = 2;
            setMovie(":/other/JackinTheBoxZombieDie.gif");
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
            setMovie(":/other/JackinTheBoxZombieAttack.gif");
        }
        return;
    }
    if (state)
    {
        state = 0;
        setMovie(":/other/JackinTheBoxZombieWalk.gif");
    }
    setX(x() - speed);
    this->setXP(x() - speed);
}


