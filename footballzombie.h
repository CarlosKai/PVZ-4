#ifndef FOOTBALLZOMBIE_H
#define FOOTBALLZOMBIE_H

#include "zombie.h"
#include "plant.h"
//橄榄球僵尸
class FootballZombie : public Zombie
{
public:
    FootballZombie();
    FootballZombie(int hp,int atk,qreal speed);
    void advance(int phase) override;
};

#endif // FOOTBALLZOMBIE_H
