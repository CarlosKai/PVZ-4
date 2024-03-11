#ifndef CARD_H
#define CARD_H

#include "other.h"

class Card : public Other
{
public:
    int counter;
    QString text;
    Card(QString s);
    const static QMap<QString, int> map;
    const static QVector<QString> name;//卡片名字
    const static QVector<int> cost;//花费
    const static QVector<int> cool;//冷却时间
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;//卡片槽中卡片的状态
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
private:
};

#endif // CARD_H
