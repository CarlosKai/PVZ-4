#include "card.h"
#include "shop.h"

const QMap<QString, int> Card::map = {{"SunFlower", 0}, {"Peashooter", 1}, {"CherryBomb", 2}, {"WallNut", 3},
                                      {"SnowPea", 4}, {"PotatoMine", 5}, {"Repeater", 6}};
const QVector<QString> Card::name = {"SunFlower", "Peashooter", "CherryBomb", "WallNut",
                                     "SnowPea", "PotatoMine", "Repeater"};
const QVector<int> Card::cost = {50, 100, 150, 50, 175, 25, 200};
const QVector<int> Card::cool = {227, 227, 606, 606, 227, 606, 227};

Card::Card(QString s)
{
    text = s;
    counter = 0;
}

QRectF Card::boundingRect() const
{
    return QRectF(-75, -45, 150, 90);
}

void Card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->scale(0.6, 0.58);//图片缩放
    QPixmap pix1(":/images/Card.png");
    pix1=pix1.scaled(pix1.width()*1.5,pix1.height()*1.5);
    painter->drawPixmap(QRect(-75, -105, 150, 210), pix1);
    QPixmap pix2(":/images/" + text + ".png");
    pix2=pix2.scaled(pix2.width()*1.5,pix2.height()*1.5);
    painter->drawPixmap(QRect(-52.5, -63, 105, 105), pix2);
    QFont font;
    font.setPointSizeF(22.5);
    painter->setFont(font);
    painter->drawText(-40, 90, QString().sprintf("%3d", cost[map[text]]));
    if (counter < cool[map[text]])
    {
        QBrush brush(QColor(0, 0, 0, 300));
        painter->setBrush(brush);
        // 根据冷却时间计算冷却形态矩形的高度
        painter->drawRect(QRectF(-72, -102, 147, 198 * (1 - qreal(counter) / cool[map[text]])));
    }
}

void Card::advance(int phase)
{
    //冷却好了
    if (!phase)
        return;
    update();
    //冷却没好
    if (counter < cool[map[text]])
        ++counter;
}

void Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    if (counter < cool[map[text]])
        event->setAccepted(false);  //操作无效
    Shop *shop = qgraphicsitem_cast<Shop *>(parentItem());
    if (cost[map[text]] > shop->sun)  //价格大于玩家已经拥有的阳光值
        event->setAccepted(false);    //操作无效
    setCursor(Qt::ArrowCursor);         //改变鼠标的形状
}

void Card::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // 小于最小移动距离
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length()
            < QApplication::startDragDistance())
        return;

    // 传递拖放数据
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;//Qdrag拖动事件只能用mime容器保存信息
    QImage image(":/images/" + text + ".png");
    image=image.scaled(image.width()*1.5,image.height()*1.5);
    mime->setText(text);
    mime->setImageData(image);
    drag->setMimeData(mime);
    drag->setPixmap(QPixmap::fromImage(image));
    drag->setHotSpot(QPoint(52.5, 52.5));//返回相对于鼠标左上角52.5,52.5的的焦点
    drag->exec();//拖放保持，阻塞
    setCursor(Qt::ArrowCursor);
}

void Card::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    setCursor(Qt::ArrowCursor);
}
