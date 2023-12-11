#include "xorgate.h"

xOrGate::xOrGate(QWidget *parent)
    : CircuitNode(2, true, parent)
{
    std::random_device rd;

    QString name = "xOrGateNode_" + QString::number(rd());
    this->setObjectName(name);
    this->setAccessibleName("xOrGateNode");

    // Gets image from Resources.qrc file.
    imagePath = ":logicGates/images/XOR.png";
    QPixmap pixmap(imagePath);
    QLabel *imageLabel = new QLabel(this);

    imageLabel->setGeometry(QRect(0, 0, 200, 200));
    imageLabel->setPixmap(
        pixmap.scaled(QSize(200, 200), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    imageLabel->lower();

    QPoint i0(0, 71);
    inputs[0]->setObjectName("inputSlot_" + QString::number(rd()));
    inputs[0]->move(i0);
    inputs[0]->position = i0;

    QPoint i1(0, 112);
    inputs[1]->setObjectName("inputSlot_" + QString::number(rd()));
    inputs[1]->move(i1);
    inputs[1]->position = i1;

    output->setObjectName("outputSlot_" + QString::number(rd()));
}

bool xOrGate::run()
{
    return (inputs[0]->connection->node->run() && !inputs[1]->connection->node->run())
           || (!inputs[0]->connection->node->run() && inputs[1]->connection->node->run());
}
