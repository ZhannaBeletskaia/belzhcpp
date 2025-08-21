#ifndef PANE_H
#define PANE_H

#include <QWidget>
#include "shape.h"
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>

namespace Ui {
class Pane;
}

enum class Mode {
    None,
    DrawRectangle,
    DrawCircle,
    DrawTriangle,
    Move,
    Link,
    Delete
};

class Pane : public QWidget
{
    Q_OBJECT

public:
    explicit Pane(QWidget *parent = nullptr);
    ~Pane();

    Mode currentMode;
    void addShape(Shape* shape);
    void saveToFile(const QString& fileName);
    void loadFromFile(const QString& fileName);

private:
    Ui::Pane *ui;
    QVector<Shape*> shapes;
    QVector<QPair<Shape*, Shape*>> vLinkedShapes;
    Shape* linkStart = nullptr;  // Первая фигура для связи
    QPoint linkFinish;
    Shape *selectedShape = nullptr;
    Shape *tempShape = nullptr;
    QPoint startPoint;
    QPoint currentPoint;
    QPoint selectedPoint;
    QPoint currentMousePos;
    QPoint offset;
    bool drawing = false;




protected:

    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // PANE_H
