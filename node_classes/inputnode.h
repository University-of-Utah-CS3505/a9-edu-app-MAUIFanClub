#ifndef INPUTNODE_H
#define INPUTNODE_H

#include <QWidget>

class InputNode : public QWidget
{
public:
    InputNode(QWidget *parent = nullptr);
    ~InputNode();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    int size = 20;
};

#endif // INPUTNODE_H
