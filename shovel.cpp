#include "shovel.h"
#include<QPixmap>


Shovel::Shovel()
{

}

QRectF Shovel::boundingRect() const
{
    return QRectF(-60, -60, 120, 120);
}

void Shovel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //画出右上角的铲子
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QPixmap pix;
    pix.load(":/images/ShovelBank.png");
    pix=pix.scaled(pix.width()*1.5,pix.height()*1.5);
    painter->drawPixmap(QRect(-60, -60, 120, 120), pix);
    pix.load(":/images/Shovel.png");
    pix=pix.scaled(pix.width()*1.5,pix.height()*1.5);
    painter->drawPixmap(QRect(-52.5, -52.5, 105, 105),pix);
}

void Shovel::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    setCursor(Qt::ArrowCursor);
}

void Shovel::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length()
            < QApplication::startDragDistance())
        return;
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    QImage image;
    image.load(":/images/Shovel.png");
    image=image.scaled(image.width()*1.5,image.height()*1.5);
    mime->setText("Shovel");
    mime->setImageData(image);
    drag->setMimeData(mime);
    drag->setPixmap(QPixmap::fromImage(image).scaled(105, 105));
    drag->setHotSpot(QPoint(52.5, 52.5));
    drag->exec();
    setCursor(Qt::ArrowCursor);
}

void Shovel::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    setCursor(Qt::ArrowCursor);
}

void Shovel::removePlant(QPointF pos)
{
    QList<QGraphicsItem *> items = scene()->items(pos);
    foreach (QGraphicsItem *item, items)
        if (item->type() == Plant::Type)
        {
            delete item;
            return;
        }
}
