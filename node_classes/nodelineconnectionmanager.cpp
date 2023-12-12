#include "nodelineconnectionmanager.h"
#include <QDebug>
#include <QLayout>
#include <QMainWindow>

NodeLineConnectionManager::NodeLineConnectionManager(float *currentZoom,
                                                     vector<CircuitNode *> *nodes,
                                                     QWidget *mainWindow)
{
    this->nodes = nodes;
    this->mainWindow = mainWindow;
    this->currentZoom = currentZoom;

    clearPixmap = new QPixmap(1200, 800);
    clearPixmap->fill(Qt::transparent);
}

void NodeLineConnectionManager::createCanvas(CircuitNode *circuitNode)
{
    NodeCanvas *nodeCanvas = new NodeCanvas();

    // Creates pixmap / painter
    nodeCanvas->pixmap = new QPixmap(1200, 800);
    nodeCanvas->pixmap->fill(Qt::transparent);
    nodeCanvas->painter = new QPainter(nodeCanvas->pixmap);
    nodeCanvas->painter->setBackgroundMode(Qt::TransparentMode);

    QPen pen;
    pen.setWidth(4);

    // Assigns painter values
    nodeCanvas->painter->setPen(pen);
    nodeCanvas->painter->setRenderHint(QPainter::Antialiasing, true);
    nodeCanvas->painter->setRenderHint(QPainter::SmoothPixmapTransform, true);

    nodeCanvas->paintCanvas = new QLabel();

    // Adds canvas to ui.
    mainWindow->layout()->addWidget(nodeCanvas->paintCanvas);
    nodeCanvas->paintCanvas->setGeometry(QRect(0, 0, 1200, 800));
    nodeCanvas->paintCanvas->lower();
    nodeCanvas->paintCanvas->setPixmap(*nodeCanvas->pixmap);

    canvases.insert(pair<CircuitNode *, NodeCanvas *>(circuitNode, nodeCanvas));
}

void NodeLineConnectionManager::nodeDeleted(CircuitNode *deletedNode)
{
    clearCanvas(canvases[deletedNode]);

    delete canvases[deletedNode]->paintCanvas;
    delete canvases[deletedNode]->painter;
    delete canvases[deletedNode]->pixmap;
    delete canvases[deletedNode];

    canvases.erase(deletedNode);
}

void NodeLineConnectionManager::drawLine(NodeCanvas *nodeCanvas, QPointF p1, QPointF p2)
{
    QLine line(p1.x(), p1.y(), p2.x(), p2.y());
    nodeCanvas->painter->drawLine(line);
    nodeCanvas->paintCanvas->setPixmap(*nodeCanvas->pixmap);
}

void NodeLineConnectionManager::updateCanvas(CircuitNode *circuitNode)
{
    clearCanvas(canvases[circuitNode]);

    if (circuitNode->output && circuitNode->output->connection) {
        connectSlots(circuitNode, circuitNode->output, circuitNode->output->connection);
    }
}

void NodeLineConnectionManager::drawSlotDrag(
    CircuitNode *circuitNode, QPoint parentPos, QPoint slotPos, QPointF offset, QPoint mousePos)
{
    updateCanvas(circuitNode);

    offset *= (*currentZoom);

    QPointF drawStartPos = parentPos + slotPos + offset;

    drawLine(canvases[circuitNode], drawStartPos, mousePos);
}

void NodeLineConnectionManager::connectSlots(CircuitNode *circuitNode,
                                             NodeOutputSlot *outSlot,
                                             NodeInputSlot *inSlot)
{
    QPointF outPoint = outSlot->parentWidget()->pos().toPointF() + outSlot->pos().toPointF()
                       + (QPointF((float) (outSlot->size - 2.0f), ((float) (outSlot->size / 2.0f)))
                          * (*currentZoom));

    QPointF inPoint = inSlot->parentWidget()->pos().toPointF() + inSlot->pos().toPointF()
                      + (QPointF(2.0f, ((float) (inSlot->size / 2.0f))) * (*currentZoom));

    drawLine(canvases[circuitNode], outPoint, inPoint);
}

void NodeLineConnectionManager::nodeMoved(CircuitNode *circuitNode)
{
    updateCanvas(circuitNode);

    // Loops over each input. If connection exists it updates its canvas.
    for (int i = 0; i < circuitNode->inputs.size(); i++) {
        if (circuitNode->inputs[i]->connection) {
            updateCanvas(circuitNode->inputs[i]->connection->node);
        }
    }
}

void NodeLineConnectionManager::clearCanvas(NodeCanvas *nodeCanvas)
{
    // Sets pixmap data to clear pixmap
    nodeCanvas->painter->end();
    *nodeCanvas->pixmap = *clearPixmap;
    nodeCanvas->painter->begin(nodeCanvas->pixmap);

    // Assigns pen / painter values
    QPen pen;
    pen.setWidth(4);
    nodeCanvas->painter->setPen(pen);
    nodeCanvas->painter->setRenderHint(QPainter::Antialiasing, true);
    nodeCanvas->painter->setRenderHint(QPainter::SmoothPixmapTransform, true);

    nodeCanvas->paintCanvas->setPixmap(*nodeCanvas->pixmap);
}
