#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class circle : public Shape
{
public:
    circle(QPoint startPoint, QPoint finishPoint);

    void draw(QPainter *painter) override;
    bool contains(const QPoint &point) const override;
    void updateShape(const QPoint &to) override;
    void moveBy(const QPoint &to) override;
    virtual QPointF getCenter() const override;
    virtual ~circle();

private:

     QRectF finishedCircle;

};

#endif // CIRCLE_H
