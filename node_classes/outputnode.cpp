#include "outputnode.h"

OutputNode::OutputNode(QWidget *parent)
{
    this->setParent(parent);
    this->setObjectName("Output Node");
    this->setStyleSheet("* {background-color:red;}");
    this->setGeometry(QRect(180, 90, size, size));
}

OutputNode::~OutputNode() {}

void OutputNode::mousePressEvent(QMouseEvent *event) {}

void OutputNode::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint pos = event->globalPosition().toPoint();
    InputNode *inNode = dynamic_cast<InputNode *>(QApplication::widgetAt(pos));

    if (inNode == NULL) {
        qDebug() << "NO INPUT NODE FOUND";
        return;
    }

    qDebug() << "INPUT NODE FOUND: " << inNode->objectName() << " AT: " << pos;
}
