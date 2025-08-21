#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "pane.h"
#include <QMouseEvent>
#include <QPoint>

class Rectangle : public Shape
{
public:
    Rectangle(QPoint &startPoint, QPoint &finishPoint);

    virtual void draw(QPainter *painter) override;
    virtual bool contains(const QPoint &point) const override;
    virtual void updateShape(const QPoint &to) override;
    virtual void moveBy(const QPoint &to) override;
    virtual QPointF getCenter() const override;
    virtual ~Rectangle();

protected:

private:

    QRectF rect;
    //QPoint startPoint;
    //QPoint finishPoint;


};

#endif // RECTANGLE_H
