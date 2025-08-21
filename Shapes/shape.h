#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>

class Shape
{
public:
    Shape(const QPoint& start, const QPoint& finish);
    virtual void draw(QPainter *painter) = 0;
    virtual bool contains(const QPoint &point) const = 0;
    virtual void updateShape(const QPoint &to) = 0;
    virtual void moveBy(const QPoint &to) = 0;
    virtual QPointF getCenter() const = 0;
    virtual ~Shape() = default;

    QPoint getStartPoint()
    {
        return startPoint;
    }
    QPoint getFinishPoint()
    {
        return finishPoint;
    }
    void setFinishPoint(QPoint finishPoint)
    {
        this->finishPoint = finishPoint;
    }

protected:

    QPoint startPoint;
    QPoint finishPoint;
    QPoint selectedPoint;

};

#endif // SHAPE_H
