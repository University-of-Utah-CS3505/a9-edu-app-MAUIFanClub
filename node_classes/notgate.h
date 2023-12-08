#ifndef NOTGATE_H
#define NOTGATE_H

#include <QDebug>
#include <QImage>
#include <QLabel>
#include <QLayout>
#include <QPixmap>
#include "circuitnode.h"

class NotGate : public CircuitNode
{
public:
    NotGate(QWidget *parent = nullptr);

    virtual bool run();
};

#endif // NOTGATE_H
