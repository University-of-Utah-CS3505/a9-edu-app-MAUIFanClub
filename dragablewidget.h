#ifndef DRAGABLEWIDGET_H
#define DRAGABLEWIDGET_H

#include <QDebug>
#include <QMouseEvent>
#include <QObject>
#include <QWidget>

class DragableWidget : public QWidget
{
public:
    DragableWidget(QWidget *parent = nullptr);
    ~DragableWidget();

    virtual void moveWidget();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    int dragableWidgetSize;

private:
    QPoint dragOffset;
    bool clicked;

    QPoint movePos;
};

#endif // DRAGABLEWIDGET_H
