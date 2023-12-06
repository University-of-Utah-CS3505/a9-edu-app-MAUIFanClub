#ifndef ZOOMMANAGER_H
#define ZOOMMANAGER_H

#include <QWidget>

namespace Ui {
class zoomManager;
}

class zoomManager : public QWidget
{
    Q_OBJECT

public:
    explicit zoomManager(QWidget *parent = nullptr);
    ~zoomManager();

private:
    Ui::zoomManager *ui;
};

#endif // ZOOMMANAGER_H
