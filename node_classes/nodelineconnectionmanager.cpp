#include "nodelineconnectionmanager.h"
#include <QDebug>
#include <QLayout>
#include <QMainWindow>
NodeLineConnectionManager::NodeLineConnectionManager(vector<CircuitNode *> *nodes,
                                                     QWidget *mainWindow)
{
    this->nodes = nodes;

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

void NodeLineConnectionManager::updateLines()
{
    clearCanvas();

    CircuitNode *currentNode;

    // Loops over each node in the circuit
    for (int i = 0; i < nodes->size(); i++) {
        currentNode = (*nodes)[i];

        //    Input Connection Draws     //

        // Loops over each input slot
        for (int inputIndex = 0; inputIndex < currentNode->inputs.size(); inputIndex++) {
            // Checks if input has a connection
            if (currentNode->inputs[inputIndex]->connection == nullptr) {
                continue;
            }

            // Current Node Input Point
            QPoint inputScenePos = currentNode->inputs[inputIndex]->parentWidget()->pos()
                                   + currentNode->inputs[inputIndex]->pos()
                                   + QPoint(2, currentNode->inputs[inputIndex]->size / 2);

            // Current Node Input Connection Point
            QPoint inputConnectionScenePos
                = currentNode->inputs[inputIndex]->connection->parentWidget()->pos()
                  + currentNode->inputs[inputIndex]->connection->pos()
                  + QPoint(currentNode->inputs[inputIndex]->connection->size - 2,
                           currentNode->inputs[inputIndex]->connection->size / 2);

            drawLine(inputScenePos, inputConnectionScenePos);
        }

        // Checks if output slot exists / has a connection
        if (currentNode->output == nullptr || currentNode->output->connection == nullptr) {
            continue;
        }

        //    Output Connection Draws     //

        // Current Node Output Point
        QPoint outputScenePos = currentNode->output->parentWidget()->pos()
                                + currentNode->output->pos()
                                + QPoint(currentNode->output->size - 2,
                                         currentNode->output->size / 2);

        // Current Node Output Connection Point
        QPoint outputConnectionScenePos = currentNode->output->connection->parentWidget()->pos()
                                          + currentNode->output->connection->pos()
                                          + QPoint(2, currentNode->output->connection->size / 2);

        drawLine(outputScenePos, outputConnectionScenePos);
    }
}

void NodeLineConnectionManager::updateLinesDrag(QPoint slotPos, QPoint mousePos)
{
    updateLines();
    drawLine(slotPos, mousePos);
}

void NodeLineConnectionManager::drawLine(QPoint p1, QPoint p2)
{
    QLine line(p1.x(), p1.y(), p2.x(), p2.y());
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
