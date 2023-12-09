#include "zoomwidget.h"
#include "ui_zoomwidget.h"
#include <QDebug>
zoomWidget::zoomWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zoomWidget)
{
    ui->setupUi(this);
}

zoomWidget::~zoomWidget()
{
    delete ui;
}
void zoomWidget::updateZoom(int newValue)
{
    ui->horizontalSlider->setValue(newValue);
}
void zoomWidget::on_progressBar_valueChanged(int value)
{
    emit barChanged(value);
}

//void zoomWidget::on_horizontalSlider_valueChanged(int value)
//{
//    ui->label->setText(QString::number(value));
//}


void zoomWidget::on_horizontalSlider_sliderMoved(int position)
{
    emit barChanged(ui->horizontalSlider->value()+0.9);
}


void zoomWidget::on_horizontalSlider_valueChanged(int value)
{
    double val = (((double)value - 40.0) / (100.0 - 40.0)) * (100.0 - 0.0);
    ui->label->setText(QString::number((int)val) + "%");
}

