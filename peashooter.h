#ifndef PEASHOOTER_H
#define PEASHOOTER_H
#include<QSound>
#include "plant.h"
#include "zombie.h"
#include "pea.h"
#include<vector>
using namespace std;
class Peashooter : public Plant
{
public:
    Peashooter();
    Peashooter(int hp,int atk);
    vector<Pea*> sBox;
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
private:
    QSound *pea;
};

#endif // PEASHOOTER_H
