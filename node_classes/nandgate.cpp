#include "nandgate.h"

nAndGate::nAndGate(QWidget *parent)
    : CircuitNode(2, true, parent)
{
    this->setObjectName("nAndGateNode");
    this->setAccessibleName("nAndGateNode");

    // Gets image from Resources.qrc file.
    QPixmap pixmap(":logicGates/images/nAndGate.png");
    QLabel *imageLabel = new QLabel(this);

    imageLabel->setGeometry(QRect(0, 0, 200, 200));
    imageLabel->setPixmap(
        pixmap.scaled(QSize(200, 200), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    imageLabel->lower();

    inputs[0]->move(QPoint(0, 70));
    inputs[1]->move(QPoint(0, 110));
}

bool nAndGate::run()
{
    return !(inputs[0]->connection->node->run() && inputs[1]->connection->node->run());
}
