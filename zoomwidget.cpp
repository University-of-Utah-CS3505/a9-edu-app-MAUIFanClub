#include "zoomwidget.h"
#include "ui_zoomwidget.h"

ZoomWidget::ZoomWidget(CircuitManager *circuitManager, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ZoomWidget)
{
    ui->setupUi(this);
    this->circuitManager = circuitManager;
}

ZoomWidget::~ZoomWidget()
{
    delete ui;
}

void ZoomWidget::updateZoom(float newValue)
{
    ui->horizontalSlider->setValue(newValue * 100);
}

void ZoomWidget::on_horizontalSlider_sliderMoved(int position)
{
    circuitManager->zoomCustom(ui->horizontalSlider->value());
}

void ZoomWidget::on_horizontalSlider_valueChanged(int value)
{
    double val = ((double) value / 100.0) * 100;
    ui->label->setText(QString::number((int) val) + "%");
}

