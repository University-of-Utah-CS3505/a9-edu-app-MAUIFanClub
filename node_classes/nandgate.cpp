#include "nandgate.h"

nAndGate::nAndGate(QWidget *parent)
    : CircuitNode(2, true, parent)
{
    this->setObjectName("nAndGateNode");
    this->setAccessibleName("nAndGateNode");

    // Gets image from Resources.qrc file.
    imagePath = ":logicGates/images/nAndGate.png";
    QPixmap pixmap(imagePath);
    QLabel *imageLabel = new QLabel(this);

    imageLabel->setGeometry(QRect(0, 0, 200, 200));
    imageLabel->setPixmap(
        pixmap.scaled(QSize(200, 200), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    imageLabel->lower();

    QPoint i0(0, 70);
    inputs[0]->move(i0);
    inputs[0]->position = i0;

    QPoint i1(0, 110);
    inputs[1]->move(i1);
    inputs[1]->position = i1;
}

bool nAndGate::run()
{
    return !(inputs[0]->connection->node->run() && inputs[1]->connection->node->run());
}
