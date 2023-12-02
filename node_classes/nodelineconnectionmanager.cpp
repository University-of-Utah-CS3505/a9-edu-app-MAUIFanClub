#include "nodelineconnectionmanager.h"
#include <QDebug>
#include <QLayout>
#include <QMainWindow>
NodeLineConnectionManager::NodeLineConnectionManager(QWidget *mainWindow)
{
    pixmap = new QPixmap(1200, 800);
    pixmap->fill(Qt::transparent);
    painter = new QPainter(pixmap);
    painter->setBackgroundMode(Qt::TransparentMode);

    QPen pen;
    pen.setWidth(4);

    painter->setPen(pen);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setRenderHint(QPainter::SmoothPixmapTransform, true);

    paintCanvas = new QLabel();

    mainWindow->layout()->addWidget(paintCanvas);
    paintCanvas->setGeometry(QRect(0, 0, 1200, 800));
    paintCanvas->lower();
    paintCanvas->setPixmap(*pixmap);
}

void NodeLineConnectionManager::startLineDraw(QPoint startPoint)
{
    draw = true;

    clearCanvas();

    this->startPoint = startPoint;
}

void NodeLineConnectionManager::updateLineDraw(QPoint drawPoint)
{
    if (!draw) {
        return;
    }

    drawLine(startPoint, drawPoint);
}

void NodeLineConnectionManager::endLineDraw()
{
    draw = false;
}

void NodeLineConnectionManager::drawLine(QPoint p1, QPoint p2)
{
    clearCanvas();

    line.setLine(p1.x(), p1.y(), p2.x(), p2.y());
    painter->drawLine(line);
    paintCanvas->setPixmap(*pixmap);
}

void NodeLineConnectionManager::clearCanvas()
{
    painter->end();
    delete pixmap;

    pixmap = new QPixmap(1200, 800);
    pixmap->fill(Qt::transparent);
    painter->begin(pixmap);

    QPen pen;
    pen.setWidth(4);
    painter->setPen(pen);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setRenderHint(QPainter::SmoothPixmapTransform, true);

    paintCanvas->setPixmap(*pixmap);
}
