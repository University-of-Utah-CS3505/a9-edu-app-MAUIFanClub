#include "notgate.h"

NotGate::NotGate(QWidget *parent)
    : CircuitNode(1, true, parent)
{
    std::random_device rd;

    QString name = "notGateNode_" + QString::number(rd());
    this->setObjectName(name);
    this->setAccessibleName("notGateNode");

    // Gets image from Resources.qrc file.
    imagePath = ":logicGates/images/NOT.png";
    QPixmap pixmap(imagePath);
    QLabel *imageLabel = new QLabel(this);

    imageLabel->setGeometry(QRect(0, 0, 200, 200));
    imageLabel->setPixmap(
        pixmap.scaled(QSize(200, 200), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    imageLabel->lower();

    QPoint i0(0, 90);
    inputs[0]->setObjectName("inputSlot_" + QString::number(rd()));
    inputs[0]->move(i0);
    inputs[0]->position = i0;

    output->setObjectName("outputSlot_" + QString::number(rd()));
}

bool NotGate::run()
{
    return !inputs[0]->connection->node->run();
}
