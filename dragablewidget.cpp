#include "dragablewidget.h"

DragableWidget::DragableWidget(QWidget *parent) {}

DragableWidget::~DragableWidget() {}

void DragableWidget::mousePressEvent(QMouseEvent *event)
{
    dragOffset = (event->scenePosition().toPoint() - this->pos());
    raise();
    // Note: need clicked for the border. On hover with style change it moves the widget, without clicking or dragging.
    clicked = true;
}

void DragableWidget::mouseReleaseEvent(QMouseEvent *event)
{
    clicked = false;
}

void DragableWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (!clicked) {
        return;
    }

    QPoint movePos = event->scenePosition().toPoint() - dragOffset;

    // BOUNDS :: X: 0 - 600 | Y: 0 - 500
    if ((movePos.x() <= 0 || movePos.x() >= 600) || (movePos.y() <= 0 || movePos.y() >= 500)) {
        return;
    }

    this->move(movePos);
}
