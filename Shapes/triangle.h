#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class triangle : public Shape
{
public:
    triangle(QPoint &startPoint, QPoint &finishPoint);

    virtual void draw(QPainter *painter) override;
    virtual bool contains(const QPoint &point) const override;
    virtual void updateShape(const QPoint &to) override;
    virtual void moveBy(const QPoint &to) override;
    virtual QPointF getCenter() const override;
    virtual ~triangle();

private:

    QPolygonF finishedTriangle;
    QPointF triaCenter;

};

#endif // TRIANGLE_H
