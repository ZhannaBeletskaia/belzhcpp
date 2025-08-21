#include "triangle.h"

triangle::triangle(QPoint &startPoint, QPoint &finishPoint)
    : Shape(startPoint, finishPoint)
{}

void triangle::draw(QPainter *painter)
{
    painter->setPen(Qt::black);

    int leftX = std::min(startPoint.x(), finishPoint.x());
    int rightX = std::max(startPoint.x(), finishPoint.x());
    int topY = std::min(startPoint.y(), finishPoint.y());
    int bottomY = std::max(startPoint.y(), finishPoint.y());
    int centerX = (leftX + rightX) / 2;

    QPolygonF tria;
    tria << QPointF(centerX, topY)
             << QPointF(leftX, bottomY)
             << QPointF(rightX, bottomY);

    triaCenter = (QPointF(centerX, topY) + QPointF(leftX, bottomY) + QPointF(rightX, bottomY)) / 3;
    finishedTriangle = tria;

    painter->drawPolygon(finishedTriangle);


}
bool triangle::contains(const QPoint &point) const
{
    return finishedTriangle.containsPoint(QPointF(point), Qt::OddEvenFill);
}
void triangle::updateShape(const QPoint &to)
{
    finishPoint = to;
}

void triangle::moveBy(const QPoint &to)
{
    startPoint += to;
    finishPoint += to;
    finishedTriangle.translate(to);

}

QPointF triangle::getCenter() const
{
    return triaCenter;
}

triangle::~triangle() {}
