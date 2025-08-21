#include "circle.h"

circle::circle(QPoint startPoint, QPoint finishPoint) :
    Shape(startPoint, finishPoint){}

void circle::draw(QPainter *painter)
{
    painter->setPen(Qt::black);
    finishedCircle = QRect(startPoint, finishPoint);
    painter->drawEllipse(finishedCircle);

}

bool circle::contains(const QPoint &point) const
{
    if(finishedCircle.contains(point))
        return true;
    return false;
}

void circle::updateShape(const QPoint &to)
{
    finishPoint = to;
}

void circle::moveBy(const QPoint &to)
{
    startPoint += to;
    finishPoint += to;
    finishedCircle.translate(to);

}


QPointF circle::getCenter() const
{
    return finishedCircle.center();
}

circle::~circle() {}
