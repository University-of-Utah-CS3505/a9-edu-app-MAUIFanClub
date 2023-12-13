#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "levelsandboxwindow.h"
#include "levelwindow.h"
#include <QGraphicsView>
#include <QPointF>
namespace Ui {
class MainMenu;
}
class MyContactListener : public b2ContactListener {
public:
    void BeginContact(b2Contact* contact) override;
    void EndContact(b2Contact* contact) override;
};

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:

    void on_logicGateLvlsBtn_clicked();

    void on_exampleCircuitsBtn_clicked();

    void on_sandboxLevelButton_clicked();

    void on_allLvlBtn_clicked();

    void on_andOrLvlBtn_clicked();

    void on_andOrNotLvlBtn_clicked();

    void on_andOrNot2LvlBtn_clicked();

    void on_fishLvlBtn_clicked();

    void on_starLvlBtn_clicked();

    void on_xOrLvlBtn_clicked();

    void on_xnOrLvlBtn_clicked();

    void on_XnOrGateLvlBtn_clicked();

    void on_andGateLvlBtn_clicked();

    void on_nAndGateLvlBtn_clicked();

    void on_nOrGateLvlBtn_clicked();

    void on_notGateLvlBtn_clicked();

    void on_orGateLvlBtn_clicked();

    void on_xOrGateLvlBtn_clicked();

    // Physics Objects slots for timers
    void updatePhysics();

    void spawnPhysicsIcons();

private:
    Ui::MainMenu *ui;

    LevelWindow *andGateLvl;
    LevelWindow *nAndGateLvl;
    LevelWindow *orGateLvl;
    LevelWindow *nOrGateLvl;
    LevelWindow *xOrGateLvl;
    LevelWindow *xnOrGateLvl;
    LevelWindow *notGateLvl;

    LevelWindow *allLvl;
    LevelWindow *andOrLvl;
    LevelWindow *andOrNotLvl;
    LevelWindow *andOrNot2Lvl;
    LevelWindow *fishLvl;
    LevelWindow *starLvl;
    LevelWindow *xnOrLvl;
    LevelWindow *xOrLvl;
    LevelSandboxWindow *sandboxWindow = nullptr;
    // Physics Members
    void createPhysicsIcon(float x, float y, float width, float height, QGraphicsScene *scene);
    b2World* world;
   // b2Body* boxBody;
    QTimer* updateTimer;
    QTimer* spawnTimer;
    b2Vec2 getBoxPosition(int index);
    QPointF mapWorldToScene(const b2Vec2 &worldPoint) const;
    QGraphicsRectItem *bottomBoxItem;
    vector <QString> listOfIcons;
protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // MAINMENU_H
