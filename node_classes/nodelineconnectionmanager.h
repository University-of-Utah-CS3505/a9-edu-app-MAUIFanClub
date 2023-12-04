#ifndef NODELINECONNECTIONMANAGER_H
#define NODELINECONNECTIONMANAGER_H

#include <QLabel>
#include <QPainter>
#include <QWidget>
#include "circuitnode.h"
#include <vector>

using std::vector;

class NodeLineConnectionManager
{
public:
    NodeLineConnectionManager(vector<CircuitNode *> *nodes, QWidget *mainWindow);

    void updateLines();
    void updateLinesDrag(QPoint slotPos, QPoint mousePos);

private:
    QPixmap *pixmap;
    QPixmap clearPixmap;
    QPainter *painter;
    QLabel *paintCanvas;
    QWidget mainWindow;

    void drawLine(QPoint p1, QPoint p2);
    void clearCanvas();

    vector<CircuitNode *> *nodes;
};

#endif // NODELINECONNECTIONMANAGER_H
