#ifndef JACKINTHEBOXZOMBIE_H
#define JACKINTHEBOXZOMBIE_H

#include "zombie.h"
#include "plant.h"
class JackinTheBoxZombie: public Zombie
{
public:
    JackinTheBoxZombie();
    void advance(int phase) override;
    JackinTheBoxZombie(int hp,int atk,qreal speed);
};

#endif // JACKINTHEBOXZOMBIE_H
