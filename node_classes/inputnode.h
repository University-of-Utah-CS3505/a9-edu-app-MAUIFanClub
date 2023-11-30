#ifndef INPUTNODE_H
#define INPUTNODE_H

#include <QObject>
#include <QPushButton>
#include "circuitnode.h"

class InputNode : public CircuitNode
{
public:
    InputNode();
    ~InputNode();

    QPushButton *toggleBtn;
    bool state;

signals:

public slots:
    void toggleState();
};

#endif // INPUTNODE_H
