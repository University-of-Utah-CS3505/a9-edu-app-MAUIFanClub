#ifndef INPUTNODE_H
#define INPUTNODE_H

#include <QObject>
#include <QPushButton>
#include "circuitnode.h"

class InputNode : public CircuitNode
{
public:
    InputNode(QWidget *parent = nullptr);
    ~InputNode();

    QPushButton *toggleBtn;
    bool state;

    virtual bool run();

signals:

public slots:
    void toggleState();
};

#endif // INPUTNODE_H
