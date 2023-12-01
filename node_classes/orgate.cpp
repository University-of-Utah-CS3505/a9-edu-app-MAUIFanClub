#include "orgate.h"

OrGate::OrGate(QWidget *parent)
    : CircuitNode(2, true, parent)
{
    // Gets image from Resources.qrc file.
    QPixmap pixmap(":i/images/orGate.png");
    QLabel *imageLabel = new QLabel(this);

    imageLabel->setGeometry(QRect(0, 0, 200, 200));
    imageLabel->setPixmap(pixmap.scaled(QSize(200, 200), Qt::KeepAspectRatio));

    imageLabel->lower();

    inputs[0]->move(QPoint(0, 62));
    inputs[1]->move(QPoint(0, 118));
}

bool OrGate::run()
{
    return inputs[0]->connection->node->run() || inputs[1]->connection->node->run();
}
