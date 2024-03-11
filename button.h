#ifndef BUTTON_H
#define BUTTON_H

#include <QTimer>
#include <QSound>
#include "other.h"
#include<zombie.h>
#include<vector>
#include<shop.h>
using namespace std;
class Button : public Other
{
public:
    Button(QSound *s, QTimer *t);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void addZombie(Zombie* zom);
    vector <Zombie*> getZBox();
    Shop* getShop();
    void setShop(Shop* shop);
private:
    QSound *sound;
    QTimer *timer;//全局的计时器
    vector <Zombie*> zBox;
    Shop* shop;
};

#endif // BUTTON_H
