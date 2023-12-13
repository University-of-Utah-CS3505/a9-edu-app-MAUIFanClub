#ifndef BOX2DMANAGER_H
#define BOX2DMANAGER_H

#include <QDebug>
#include <QObject>
#include <QTimer>

#include "node_classes/circuitnode.h"
#include "node_classes/nodelineconnectionmanager.h"
#include <Box2D/Box2D.h>
#include <vector>

using std::vector;

class Box2DManager : public QObject
{
    Q_OBJECT

public:
    Box2DManager(NodeLineConnectionManager *lineManager);

    struct NodePhysics
    {
        CircuitNode *node = nullptr;
        b2Body *body = nullptr;
        b2Fixture *bodyFixture;
        b2Vec2 startPos;

        bool operator==(NodePhysics compareNodePhysics) const
        {
            return node == compareNodePhysics.node && body == compareNodePhysics.body;
        }
    };

    NodeLineConnectionManager *lineManager;

    float32 startZoom;

    bool physicsActive;

    void addNode(CircuitNode *node);
    void nodeDeleted(CircuitNode *node);

    void nodesScaled();
    void nodeMoved(CircuitNode *node);

    void updateGroundBody();

    void startWorld();
    void stopWorld();

    b2Vec2 convertPosition(QPoint scenePos);
    QPoint convertPosition(b2Vec2 physicsPos);

private:
    QTimer *worldTimer;
    NodePhysics findNodePhysics(CircuitNode *node);

    void updateWorld();

    /*  Box2D Variables  */

    vector<NodePhysics> nodesPhysics;

    float32 nodesBodySize;

    // Prepare for simulation. Typically we use a time step of 1/60 of a
    // second (60Hz) and 10 iterations. This provides a high quality simulation
    // in most game scenarios.
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 100;
    int32 positionIterations = 100;

    // Define the gravity vector.
    b2Vec2 gravity;
    // Construct a world object, which will hold and simulate the rigid bodies.
    b2World *world;
    b2Body *groundBody;
    b2Fixture *groundBodyFixture;
};

#endif // BOX2DMANAGER_H
