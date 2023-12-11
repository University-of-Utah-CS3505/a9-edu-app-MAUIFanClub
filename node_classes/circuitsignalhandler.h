#ifndef CIRCUITSIGNALHANDLER_H
#define CIRCUITSIGNALHANDLER_H

#include <QObject>
#include <QPoint>
#include "nodeinputslot.h"

class CircuitSignalHandler : public QObject
{
    Q_OBJECT
signals:
    void nodeDeleted();
    void updateLines();
    void nodeSlotDrag(QPoint slotPos, QPoint mousePos);
    void nodeMoved();
    void outputDragConnect(QPoint mousePos);
    void inputDragConnect(QPoint mousePos, NodeInputSlot *inSlot);

public:
    CircuitSignalHandler();
};
#endif // CIRCUITSIGNALHANDLER_H
