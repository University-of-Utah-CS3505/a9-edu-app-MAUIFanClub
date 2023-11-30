#include "inputnode.h"

InputNode::InputNode(QWidget *parent)
{
    this->setParent(parent);
    this->setObjectName("Input Node");
    this->setStyleSheet("* {background-color:green;}");
    this->setGeometry(QRect(0, 90, size, size));
}

InputNode::~InputNode() {}

void InputNode::mousePressEvent(QMouseEvent *event) {}

void InputNode::mouseReleaseEvent(QMouseEvent *event) {}
