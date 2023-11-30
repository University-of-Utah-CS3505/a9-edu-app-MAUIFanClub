#ifndef DRAGABLEWIDGET_H
#define DRAGABLEWIDGET_H

#include <QDebug>
#include <QMouseEvent>
#include <QWidget>
#include "./node_classes/nodeinputslot.h"
#include "./node_classes/nodeoutputslot.h"

class DragableWidget : public QWidget
{
public:
    DragableWidget(QWidget *parent = nullptr);
    ~DragableWidget();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QPoint dragOffset;
    bool clicked;
};

#endif // DRAGABLEWIDGET_H
