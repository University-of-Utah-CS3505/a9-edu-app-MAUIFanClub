#ifndef ZOOMWIDGET_H
#define ZOOMWIDGET_H

#include <QDebug>
#include <QWidget>
#include "circuitmanager.h"

namespace Ui {
class ZoomWidget;
}

class ZoomWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ZoomWidget(CircuitManager *circuitManager, QWidget *parent = nullptr);
    ~ZoomWidget();
    CircuitManager *circuitManager;
    void updateZoom(float newValue);

public slots:
    void on_horizontalSlider_sliderMoved(int position);
    void on_horizontalSlider_valueChanged(int value);

    //signals:
    //    void barChanged(int value);

private:
    Ui::ZoomWidget *ui;
};

#endif // ZOOMWIDGET_H
