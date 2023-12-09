#include "inputnode.h"

InputNode::InputNode(QWidget *parent)
    : CircuitNode(0, true, parent)
{
    std::random_device rd;

    QString name = "inputNode_" + QString::number(rd());
    this->setObjectName(name);
    this->setAccessibleName("inputNode");

    state = false;

    // Button for user to click. Toggles state of input node.
    toggleBtn = new QPushButton(this);
    toggleBtn->setText("0");
    toggleBtn->setGeometry(QRect(25, 25, 150, 150));

    // Increases font size for btn
    QFont font = toggleBtn->font();
    font.setPointSize(50);
    toggleBtn->setFont(font);

    output->setObjectName("outputSlot_" + QString::number(rd()));

    connect(toggleBtn, &QPushButton::clicked, this, &InputNode::toggleState);
}

InputNode::~InputNode() {}

void InputNode::toggleState()
{
    state = !state;
    toggleBtn->setText(state ? "1" : "0");
}

bool InputNode::run()
{
    return state;
}
