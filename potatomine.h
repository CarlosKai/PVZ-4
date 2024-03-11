#ifndef POTATOMINE_H
#define POTATOMINE_H

#include "plant.h"
#include "zombie.h"
//土豆雷
class PotatoMine : public Plant
{
public:
    PotatoMine();
     PotatoMine(int hp,int atk);
    QRectF boundingRect() const override;
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // POTATOMINE_H
