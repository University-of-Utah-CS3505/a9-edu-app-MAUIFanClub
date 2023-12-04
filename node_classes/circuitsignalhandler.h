#ifndef CIRCUITSIGNALHANDLER_H
#define CIRCUITSIGNALHANDLER_H

#include <QObject>
#include <QPoint>

class CircuitSignalHandler : public QObject
{
    Q_OBJECT
signals:
    void nodeDeleted();
    void updateLines();
    void nodeSlotDrag(QPoint slotPos, QPoint mousePos);

public:
    CircuitSignalHandler();
};
#endif // CIRCUITSIGNALHANDLER_H
