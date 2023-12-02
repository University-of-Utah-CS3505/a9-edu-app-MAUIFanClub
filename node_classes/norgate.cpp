#include "norgate.h"

nOrGate::nOrGate(QWidget *parent)
    : CircuitNode(2, true, parent)
{
    this->setObjectName("nOrGateNode");
    this->setAccessibleName("nOrGateNode");

    // Gets image from Resources.qrc file.
    QPixmap pixmap(":logicGates/images/nOrGate.png");
    QLabel *imageLabel = new QLabel(this);

    imageLabel->setGeometry(QRect(0, 0, 200, 200));
    imageLabel->setPixmap(
        pixmap.scaled(QSize(200, 200), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    imageLabel->lower();

    inputs[0]->move(QPoint(0, 79));
    inputs[1]->move(QPoint(0, 106));
}

bool nOrGate::run()
{
    return !(inputs[0]->connection->node->run() || inputs[1]->connection->node->run());
}
