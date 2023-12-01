#include "nodelineconnectionmanager.h"
#include <QDebug>
NodeLineConnectionManager::NodeLineConnectionManager(QWidget *mainWindow)
{
    pixmap = new QPixmap(800, 600);
    pixmap->fill(Qt::transparent);
    painter = new QPainter(pixmap);
    painter->setBackgroundMode(Qt::TransparentMode);

    QPen pen;
    pen.setWidth(4);

    painter->setPen(pen);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setRenderHint(QPainter::SmoothPixmapTransform, true);

    paintCanvas = new QLabel(mainWindow);
    paintCanvas->setGeometry(QRect(0, 0, 800, 600));
    paintCanvas->lower();
    paintCanvas->setPixmap(*pixmap);
}

void NodeLineConnectionManager::startLineDraw(QPoint startPoint)
{
    draw = true;

    clearCanvas();

    paintCanvas->setPixmap(*pixmap);
    this->startPoint = startPoint;
}

void NodeLineConnectionManager::updateLineDraw(QPoint drawPoint)
{
    if (!draw) {
        return;
    }

    clearCanvas();

    line.setLine(startPoint.x(), startPoint.y(), drawPoint.x(), drawPoint.y());
    painter->drawLine(line);
    paintCanvas->setPixmap(*pixmap);
}

void NodeLineConnectionManager::endLineDraw()
{
    draw = false;
}

void NodeLineConnectionManager::clearCanvas()
{
    painter->end();
    pixmap = new QPixmap(800, 600);
    pixmap->fill(Qt::transparent);
    painter->begin(pixmap);

    QPen pen;
    pen.setWidth(4);
    painter->setPen(pen);
}
