#include "outputnode.h"

OutputNode::OutputNode()
    : CircuitNode(1, false)
{
    outputLabel = new QLabel(this);
    outputLabel->setGeometry(QRect(25, 25, 150, 150));
    outputLabel->setText("0");
    outputLabel->setAlignment(Qt::AlignCenter);

    QFont font = outputLabel->font();
    font.setPointSize(50);
    outputLabel->setFont(font);
}

OutputNode::~OutputNode() {}
