#ifndef CIRCUITSIGNALHANDLER_H
#define CIRCUITSIGNALHANDLER_H

#include <QObject>

class CircuitSignalHandler : public QObject
{
    Q_OBJECT
signals:
    void nodeDeleted();

public:
    CircuitSignalHandler();
};
#endif // CIRCUITSIGNALHANDLER_H
