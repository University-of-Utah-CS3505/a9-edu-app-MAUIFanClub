#include "andgate.h"

AndGate::AndGate(QWidget *parent)
    : CircuitNode(2, true, parent)
{
    std::random_device rd;

    QString name = "andGateNode_" + QString::number(rd());
    this->setObjectName(name);
    this->setAccessibleName("andGateNode");

    // Gets image from Resources.qrc file.
    imagePath = ":logicGates/images/andGate.png";
    QPixmap pixmap(imagePath);
    QLabel *imageLabel = new QLabel(this);

    imageLabel->setGeometry(QRect(0, 0, 200, 200));
    imageLabel->setPixmap(
        pixmap.scaled(QSize(200, 200), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    imageLabel->lower();

    QPoint i0(0, 70);
    inputs[0]->setObjectName("inputSlot_" + QString::number(rd()));
    inputs[0]->move(i0);
    inputs[0]->position = i0;

    QPoint i1(0, 110);
    inputs[1]->setObjectName("inputSlot_" + QString::number(rd()));
    inputs[1]->move(i1);
    inputs[1]->position = i1;

    output->setObjectName("outputSlot_" + QString::number(rd()));
}

bool AndGate::run()
{
    return inputs[0]->connection->node->run() && inputs[1]->connection->node->run();
}
