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

    movePos = event->scenePosition().toPoint() - dragOffset;

    // BOUNDS :: X: 0 - 1200  | Y: 0 - 800 | - 200 (Size of Widget)
    if ((movePos.x() <= 0 || movePos.x() >= 1000) || (movePos.y() <= 0 || movePos.y() >= 600)) {
        return;
    }
    moveWidget();
}

void DragableWidget::moveWidget()
{
    this->move(movePos);
}
