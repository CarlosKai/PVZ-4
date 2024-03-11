#include "map.h"
#include<QSound>
QSound *plant=new QSound(":/res/plant1.wav");
Map::Map()
{
    dragOver = false;
    setAcceptDrops(true);
}

QRectF Map::boundingRect() const
{
    return QRectF(-553.5, -352.5, 1107, 705);
}

void Map::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter)
    Q_UNUSED(option)
    Q_UNUSED(widget)
    // painter->setPen(Qt::black);
    // painter->drawRect(boundingRect());
}

void Map::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if (event->mimeData()->hasText())//有内容
    {
        event->setAccepted(true);
        dragOver = true;
        update();
    }
    else
        event->setAccepted(false);
}

void Map::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    Q_UNUSED(event);
    dragOver = false;
    update();
}

void Map::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    dragOver = false;//放置结束
    if (event->mimeData()->hasText())
    {
        //将拖动的鼠标坐标对应到地面的种植坐标中
        QString s = event->mimeData()->text();
        QPointF pos = mapToScene(event->pos());
        qDebug()<<pos.x()<<pos.y();
        pos.setX((int(pos.x()) - 374) / 123 * 123 + 435);
         pos.setY((int(pos.y()) - 122) / 147 * 147 + 195);
        qDebug()<<pos.x()<<pos.y();
        //如果拖动物为铲子
        if (s == "Shovel")
        {
            //把植物删除
            Shovel *shovel = qgraphicsitem_cast<Shovel *>(scene()->items(QPointF(1245, 22.5))[0]);
            shovel->removePlant(pos);
        }
        else
        {
            //种植物
            Shop *shop = qgraphicsitem_cast<Shop *>(scene()->items(QPointF(450, 22.5))[0]);
            shop->addPlant(s, pos);
            plant->play();

        }
    }
    update();
}
