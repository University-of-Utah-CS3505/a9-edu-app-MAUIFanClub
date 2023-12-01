#ifndef NODELINECONNECTIONMANAGER_H
#define NODELINECONNECTIONMANAGER_H

#include <QLabel>
#include <QPainter>
#include <QWidget>

class NodeLineConnectionManager
{
public:
    NodeLineConnectionManager(QWidget *mainWindow);

    void startLineDraw(QPoint startPoint);
    void updateLineDraw(QPoint drawPoint);
    void endLineDraw();

    bool draw = false;

private:
    QPixmap *pixmap;
    QPainter *painter;
    QLine line;
    QPoint startPoint;

    QLabel *paintCanvas;
    QWidget mainWindow;

    void clearCanvas();
};

#endif // NODELINECONNECTIONMANAGER_H
