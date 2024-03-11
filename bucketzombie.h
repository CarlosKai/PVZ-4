#ifndef BUCKETZOMBIE_H
#define BUCKETZOMBIE_H

#include "zombie.h"
#include "plant.h"
#include "button.h"
class BucketZombie : public Zombie
{
public:
    BucketZombie();
    BucketZombie(int hp,int atk,qreal speed);
    void advance(int phase) override;
    Button* bt;
};

#endif // BUCKETZOMBIE_H
