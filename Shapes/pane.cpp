#include "pane.h"
#include "ui_pane.h"
#include <qevent.h>
#include "Rectangle.h"
#include "circle.h"
#include "triangle.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

Pane::Pane(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Pane)
{
    ui->setupUi(this);
    currentMode = Mode::None;
    setMouseTracking(true);
}

Pane::~Pane()
{
    delete ui;
    delete tempShape;
    qDeleteAll(shapes); // Удалить
    shapes.clear();
}

void Pane::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    for (Shape *shape : shapes)
    {
        shape->draw(&painter);
    }

    if (tempShape)
        tempShape->draw(&painter);

    painter.setPen(Qt::red);

    // Рисуем связи
    for (const auto& pair : vLinkedShapes)
    {
        QPointF p1 = pair.first->getCenter();
        QPointF p2 = pair.second->getCenter();
        painter.drawLine(p1, p2);
    }

    // Живая линия от выбранной фигуры к курсору
    if (currentMode == Mode::Link && linkStart != nullptr)
    {
        painter.setPen(Qt::DashLine); // стиль пунктиром для временной линии
        painter.drawLine(linkStart->getCenter(), currentMousePos);
    }


}

void Pane::mousePressEvent(QMouseEvent *event)
{
    // отменить рисование, если ЩПК
    if (event->button() == Qt::RightButton)
    {
        tempShape = nullptr;
        linkStart = nullptr;
        drawing = false;
        update();
        return;
    }

    startPoint = event->pos();
    currentPoint = startPoint;
    drawing = true;

    if(currentMode == Mode::DrawRectangle)
    {
        tempShape = new Rectangle(startPoint, currentPoint);
    }
    else if(currentMode == Mode::DrawCircle)
    {
        tempShape = new circle(startPoint, currentPoint);
    }
    else if(currentMode == Mode::DrawTriangle)
    {
        tempShape = new triangle(startPoint, currentPoint);
    }
    else if(currentMode == Mode::Move)
    {
        drawing = false;
        selectedPoint = event->pos();

        for(const auto& it : shapes)
        {
            if(it->contains(selectedPoint))
            {
                selectedShape = it;
                break;
            }
            else
                 qDebug() << "doesn't contain";
        }
    }
    if (currentMode == Mode::Link)
    {
        bool found = false;
        drawing = false;
        for (auto shape : shapes)
        {
            if (shape->contains(event->pos()))
            {
                found = true;
                if (linkStart == nullptr)
                {
                    linkStart = shape;
                }
                else
                {
                    if (shape != linkStart)
                    {
                        vLinkedShapes.append(qMakePair(linkStart, shape));
                    }
                    linkStart = nullptr;
                }
                break;
            }
        }
        if (!found && linkStart != nullptr)
        {
            linkStart = nullptr;
        }
        update();
    }
    else if (currentMode == Mode::Delete)
    {
        for (int i = 0; i < shapes.size(); ++i)
        {
            if (shapes[i]->contains(event->pos()))
            {
                // Удалить связи с этой фигурой
                for (int j = vLinkedShapes.size() - 1; j >= 0; --j)
                {
                    auto pair = vLinkedShapes[j];
                    if (pair.first == shapes[i] || pair.second == shapes[i])
                    {
                        vLinkedShapes.remove(j);
                    }
                }

                delete shapes[i];       // Удалить фигуру
                shapes.remove(i);       // Удалить из списка
                update();               // Перерисовка
                break;
            }
        }
    }

}

void Pane::mouseMoveEvent(QMouseEvent *event)
{
    currentMousePos = event->pos();
    if (drawing && tempShape)
    {
        tempShape->updateShape(currentMousePos);
        update();  // перерисовать виджет
    }
    else if(currentMode == Mode::Move && selectedShape)
    {
        QPoint offset = event->pos() - selectedPoint;
        selectedShape->moveBy(offset);
        selectedPoint = event->pos();
        update();

    }
    else if (currentMode == Mode::Link && linkStart != nullptr)
    {
        update();
    }





}
void Pane::mouseReleaseEvent(QMouseEvent *event)
{
    currentPoint = event->pos();
    if(currentMode == Mode::DrawRectangle)
    {
        if(drawing)
        {
            Shape *rect = new Rectangle(startPoint, currentPoint);
            addShape(rect);
        }
    }
    else if(currentMode == Mode::DrawCircle)
    {
        if(drawing)
        {
            Shape *cir = new circle(startPoint, currentPoint);
            addShape(cir);
        }

    }
    else if(currentMode == Mode::DrawTriangle)
    {
        if(drawing)
        {
            Shape *tria = new triangle(startPoint, currentPoint);
            addShape(tria);
        }
    }
    else if(currentMode == Mode::Move)
    {
        selectedShape = nullptr;
    }

    if (tempShape)
    {
        delete tempShape;
        tempShape = nullptr;
    }


    drawing = false;
    update();
}


void Pane::addShape(Shape* shape)
{
    shapes.append(shape);
    update();
}

void Pane::saveToFile(const QString& fileName)
{
    QJsonObject rootObj;

    // Сохраняем фигуры
    QJsonArray shapesArray;
    for (Shape* shape : shapes)
    {
        QJsonObject shapeObj;
        QString type;

        if (dynamic_cast<Rectangle*>(shape)) type = "Rectangle";
        else if (dynamic_cast<circle*>(shape)) type = "Circle";
        else if (dynamic_cast<triangle*>(shape)) type = "Triangle";

        shapeObj["type"] = type;

        // Сохраняем координаты
        shapeObj["startX"] = shape->getStartPoint().x();
        shapeObj["startY"] = shape->getStartPoint().y();
        shapeObj["finishX"] = shape->getFinishPoint().x();
        shapeObj["finishY"] = shape->getFinishPoint().y();

        shapesArray.append(shapeObj);
    }
    rootObj["shapes"] = shapesArray;

    // Сохраняем связи
    QJsonArray linksArray;
    for (auto &pair : vLinkedShapes)
    {
        int index1 = shapes.indexOf(pair.first);
        int index2 = shapes.indexOf(pair.second);

        QJsonObject linkObj;
        linkObj["from"] = index1;
        linkObj["to"] = index2;
        linksArray.append(linkObj);
    }
    rootObj["links"] = linksArray;

    // Записываем в файл
    QJsonDocument doc(rootObj);
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) return;

    file.write(doc.toJson());
    file.close();
}

void Pane::loadFromFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) return;

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (doc.isNull() || !doc.isObject()) return;

    QJsonObject rootObj = doc.object();

    shapes.clear();
    vLinkedShapes.clear();

    QJsonArray shapesArray = rootObj["shapes"].toArray();
    for (const QJsonValue &val : shapesArray)
    {
        QJsonObject shapeObj = val.toObject();
        QString type = shapeObj["type"].toString();

        QPoint start(shapeObj["startX"].toInt(), shapeObj["startY"].toInt());
        QPoint finish(shapeObj["finishX"].toInt(), shapeObj["finishY"].toInt());

        if (type == "Rectangle")
            shapes.append(new Rectangle(start, finish));
        else if (type == "Circle")
            shapes.append(new circle(start, finish));
        else if (type == "Triangle")
            shapes.append(new triangle(start, finish));
    }

    QJsonArray linksArray = rootObj["links"].toArray();
    for (const QJsonValue &val : linksArray)
    {
        QJsonObject linkObj = val.toObject();
        int index1 = linkObj["from"].toInt();
        int index2 = linkObj["to"].toInt();

        if (index1 >= 0 && index1 < shapes.size() &&
            index2 >= 0 && index2 < shapes.size())
        {
            vLinkedShapes.append(qMakePair(shapes[index1], shapes[index2]));
        }
    }

    update();

}


