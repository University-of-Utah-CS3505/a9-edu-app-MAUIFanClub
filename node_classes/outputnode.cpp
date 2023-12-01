#include "outputnode.h"

OutputNode::OutputNode(QWidget *parent)
    : CircuitNode(1, false, parent)
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

bool OutputNode::run()
{
    bool runResult = inputs[0]->connection->node->run();

    outputLabel->setText(runResult ? "1" : "0");

    return true;
}
