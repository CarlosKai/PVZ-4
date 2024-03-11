#ifndef PEA_H
#define PEA_H
#include<QSound>
#include "other.h"
//子弹类

class Pea : public Other
{
public:
    Pea(int attack = 0, bool flag = false);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
private:
    bool snow;
    int atk;
    qreal speed;
    QSound *pea;
    QSound *snowpea;
};

#endif // PEA_H
