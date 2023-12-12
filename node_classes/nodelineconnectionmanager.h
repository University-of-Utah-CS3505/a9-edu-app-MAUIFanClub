#ifndef NODELINECONNECTIONMANAGER_H
#define NODELINECONNECTIONMANAGER_H

#include <QLabel>
#include <QPainter>
#include <QWidget>
#include "circuitnode.h"
#include <map>
#include <vector>

using std::vector, std::map, std::pair;

class NodeLineConnectionManager
{
public:
    struct NodeCanvas
    {
        QPixmap *pixmap;
        QPainter *painter;
        QLabel *paintCanvas;
    };

    float *currentZoom;

    NodeLineConnectionManager(float *currentZoom, vector<CircuitNode *> *nodes, QWidget *mainWindow);

    /// Creates a new canvas for the circuit node. Adding the canvas to the main Ui.
    void createCanvas(CircuitNode *circuitNode);
    /// Handles when a node is deleted. Deleting created data.
    void nodeDeleted(CircuitNode *deletedNode);

    /// Updates the circuit nodes canvas. Clearing the canvas and drawing new lines to its connections.
    void updateCanvas(CircuitNode *circuitNode);
    /// Draws a line from the dragged slot pos to the mouse pos.
    void drawSlotDrag(
        CircuitNode *, QPoint parentPos, QPoint slotPos, QPointF offset, QPoint mousePos);
    /// Takes in a Output & Input slot and draws a line between them. The circuit node in the arguments is the canvas to draw to.
    void connectSlots(CircuitNode *circuitNode, NodeOutputSlot *outSlot, NodeInputSlot *inSlot);
    /// Handles when a node is moved. Updating its Ui and the connections Ui.
    void nodeMoved(CircuitNode *circuitNode);

private:
    map<CircuitNode *, NodeCanvas *> canvases;

    QPixmap *clearPixmap;
    QWidget *mainWindow;

    vector<CircuitNode *> *nodes;

    /// Helper method to draw a line on the canvas.
    void drawLine(NodeCanvas *nodeCanvas, QPointF p1, QPointF p2);
    /// Clears the canvas of all drawings.
    void clearCanvas(NodeCanvas *nodeCanvas);
};

#endif // NODELINECONNECTIONMANAGER_H
