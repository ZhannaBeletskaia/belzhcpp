#include "rectangle.h"

Rectangle::Rectangle(QPoint &startPoint, QPoint &finishPoint)
    : Shape(startPoint, finishPoint) {}


void Rectangle::draw(QPainter *painter)
{
    painter->setPen(Qt::black);
    rect = QRect(startPoint, finishPoint).normalized();
    painter->drawRect(rect);
}
bool Rectangle::contains(const QPoint &point) const
{
    return rect.contains(point);
}

void Rectangle::updateShape(const QPoint &to)
{
    finishPoint = to;
}

void Rectangle::moveBy(const QPoint &to)
{
    startPoint += to;
    finishPoint += to;
    rect.translate(to);

}

QPointF Rectangle::getCenter() const
{
    return rect.center();
}

Rectangle::~Rectangle() {}
