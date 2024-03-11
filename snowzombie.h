#ifndef SNOWZOMBIE_H
#define SNOWZOMBIE_H
#include "zombie.h"
#include "plant.h"

class SnowZombie:public Zombie
{
public:
    SnowZombie();
    SnowZombie(int hp,int atk, qreal speed);
    void advance(int phase) override;
};

#endif // SNOWZOMBIE_H
