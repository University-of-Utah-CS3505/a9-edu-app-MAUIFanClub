#ifndef ZOOMWIDGET_H
#define ZOOMWIDGET_H

#include <QWidget>

namespace Ui {
class zoomWidget;
}

class zoomWidget : public QWidget
{
    Q_OBJECT

public:
    explicit zoomWidget(QWidget *parent = nullptr);
    ~zoomWidget();
    void updateZoom(int newValue);

private slots:
    void on_progressBar_valueChanged(int value);
    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_valueChanged(int value);

signals:
    void barChanged(int value);
private:
    Ui::zoomWidget *ui;
};

#endif // ZOOMWIDGET_H
