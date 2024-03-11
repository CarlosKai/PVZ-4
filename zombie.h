#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>

class Zombie : public QGraphicsItem
{
public:
    int hp;//血量
    int atk;//攻击力
    int state;//状态，1 为攻击状态，0为行走状态
    qreal speed;//qreal类型可以理解为double或者float类型，移动速度
    enum { Type = UserType + 2};
    Zombie();
    double getXP();
    double getYP();
    int getNum();
    void setXP(double x);
    void setYP(double y);
    void setNum(int num);
    void setCollide(bool isCollide) ;
    bool getCollide();
    ~Zombie() override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;//画僵尸
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;//碰撞检测
    int type() const override;//
    void setMovie(QString path);//设置动画方便接口
    void setHead(QString path);//

protected:
    QMovie *movie;
    QMovie *head;
private:
    double xP;
    double yP;
    int num;
    bool collide;
};

#endif // ZOOMBIE_H
