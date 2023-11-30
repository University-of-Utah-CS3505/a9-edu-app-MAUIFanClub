#ifndef OUTPUTNODE_H
#define OUTPUTNODE_H

#include <QApplication>
#include <QMouseEvent>
#include <QWidget>
#include "inputnode.h"

class OutputNode : public QWidget
{
public:
    OutputNode(QWidget *parent = nullptr);
    ~OutputNode();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    int size = 20;
};

#endif // OUTPUTNODE_H
