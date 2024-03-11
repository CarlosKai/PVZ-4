#ifndef BASICZOMBIE_H
#define BASICZOMBIE_H

#include "zombie.h"
#include "plant.h"

class BasicZombie : public Zombie
{
public:
    BasicZombie();
    BasicZombie(int hp,int atk,qreal speed);
    void advance(int phase) override;
};

#endif // BASICZOMBIE_H
