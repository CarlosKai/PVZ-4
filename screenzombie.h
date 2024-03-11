#ifndef SCREENZOMBIE_H
#define SCREENZOMBIE_H

#include "zombie.h"
#include "plant.h"
//铁网僵尸
class ScreenZombie : public Zombie
{
public:
    ScreenZombie();
    ScreenZombie(int hp,int atk,qreal speed);
    void advance(int phase) override;
};

#endif // SCREENZOMBIE_H
