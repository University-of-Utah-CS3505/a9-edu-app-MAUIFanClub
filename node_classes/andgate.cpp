#include "andgate.h"

AndGate::AndGate()
    : CircuitNode(2, true)
{
    // Gets image from Resources.qrc file.
    QPixmap pixmap(":i/images/andGate.png");
    QLabel *imageLabel = new QLabel(this);

    imageLabel->setGeometry(QRect(0, 0, 200, 200));
    imageLabel->setPixmap(pixmap.scaled(QSize(200, 200), Qt::KeepAspectRatio));

    imageLabel->lower();

    inputs[0]->move(QPoint(0, 70));
    inputs[1]->move(QPoint(0, 110));
}

void AndGate::Run() {}
