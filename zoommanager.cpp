#include "zoommanager.h"
#include "ui_zoommanager.h"

zoomManager::zoomManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zoomManager)
{
    ui->setupUi(this);
}

zoomManager::~zoomManager()
{
    delete ui;
}
