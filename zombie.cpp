#include "zombie.h"
#include "plant.h"
#include <QDebug>

Zombie::Zombie()
{
    movie = head = nullptr;
    hp = atk = state = 0;
    speed = 0.0;
}

Zombie::~Zombie()
{
    delete movie;
    delete head;
}

QRectF Zombie::boundingRect() const
{
    return QRectF(-120, -150, 300, 210);
}
void Zombie::setXP(double x){
    this->xP=x;
}
void Zombie::setYP(double y){
    this->yP=y;
}
void Zombie::setNum(int num){
    this->num=num;
}
int Zombie::getNum(){
    return this->num;
}
double Zombie::getXP(){
    return this->xP;
}
double Zombie::getYP(){
    return this->yP;
}
void Zombie::setCollide(bool isCollide) {
    this->collide=isCollide;
}
bool Zombie::getCollide(){
    return this->collide;
}
void Zombie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QImage image = movie->currentImage();
    if (speed < 0.55*1.5 && state != 3)
    {
        if (state != 2)
            movie->setSpeed(50*1.5);
        int w = image.width();
        int h = image.height();
        for (int i = 0; i < h; ++i)
        {
            uchar *line = image.scanLine(i);
            for (int j = 5; j < w - 5; ++j)
                line[j << 2] = 200;
        }
    }
    painter->drawImage(QRectF(-105, -150, 210, 210), image);
    if (head)
    {
        image = head->currentImage();
        if (speed < 0.55*1.5)
        {
            int w = image.width();
            int h = image.height();
            for (int i = 0; i < h; ++i)
            {
                uchar *line = image.scanLine(i);
                for (int j = 5; j < w - 5; ++j)
                    line[j << 2] = 200;
            }
        }
        painter->drawImage(QRectF(0, -150, 210, 210), image);
    }

}

bool Zombie::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    //碰撞检测，是一棵植物&&高度相同（即植物和僵尸在同一行）&&植物和僵尸的距离<30，安排僵尸开始吃
    //Zombie::setCollide(other->type() == Plant::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 45);
    return other->type() == Plant::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 45;
}

int Zombie::type() const
{
    return Type;
}

void Zombie::setMovie(QString path)
{
    if (movie)
        delete movie;
    movie = new QMovie(path);
    movie->start();
}

void Zombie::setHead(QString path)
{
    if (head)
        delete head;
    head = new QMovie(path);
    head->start();
}
