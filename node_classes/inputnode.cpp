#include "inputnode.h"

InputNode::InputNode()
    : CircuitNode(0, true)
{
    state = false;

    // Button for user to click. Toggles state of input node.
    toggleBtn = new QPushButton(this);
    toggleBtn->setText("0");
    toggleBtn->setGeometry(QRect(25, 25, 150, 150));

    // Increases font size for btn
    QFont font = toggleBtn->font();
    font.setPointSize(50);
    toggleBtn->setFont(font);

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
