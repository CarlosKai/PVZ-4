#ifndef PLANT_H
#define PLANT_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>

class Plant : public QGraphicsItem
{
public:
    int hp;//血量
    int state;//状态
    enum { Type = UserType + 1};
    Plant();
    ~Plant() override;
    QRectF boundingRect() const override;//返回植物的边界矩形
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;//碰撞检测
    int type() const override;
    void setMovie(QString path);//设置动画的方便接口
    int num;
    float xP;
    float yP;
    int getAtk();
protected:
    QMovie *movie;
    int atk;
    int counter;//计时
    int time;//判定行动
};

#endif // PLANT_H
