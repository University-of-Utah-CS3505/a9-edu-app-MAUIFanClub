#include "box2dmanager.h"

Box2DManager::Box2DManager(NodeLineConnectionManager *lineManager)
{
    this->lineManager = lineManager;

    physicsActive = false;

    worldTimer = new QTimer(this);
    connect(worldTimer, &QTimer::timeout, [this]() { updateWorld(); });

    gravity = b2Vec2(0.0f, -200.0f);

    // Construct a world object, which will hold and simulate the rigid bodies.
    world = new b2World(gravity);

    // Define the ground body.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, 0.0f);

    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    groundBody = world->CreateBody(&groundBodyDef);

    // Define the ground box shape.
    b2PolygonShape groundBox;

    // The extents are the half-widths of the box.
    nodesBodySize = 200 * (*lineManager->currentZoom) / 2; // 200 = Node Base Size
    groundBox.SetAsBox(2000.0f, nodesBodySize);

    // Add the ground fixture to the ground body.
    groundBodyFixture = groundBody->CreateFixture(&groundBox, 0.0f);
}

void Box2DManager::addNode(CircuitNode *node)
{
    nodesBodySize = node->nodeSize * (*lineManager->currentZoom) / 2;

    // Define the dynamic body. We set its position and call the body factory.
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.fixedRotation = true;
    b2Vec2 bodyPos = convertPosition(node->pos());
    bodyDef.position.Set(bodyPos.x, bodyPos.y);

    b2Body *body = world->CreateBody(&bodyDef);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(nodesBodySize, nodesBodySize);

    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;

    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDef.density = 1000.0f;

    // Override the default friction.
    fixtureDef.friction = 0.3f;

    // Add the shape to the body.
    b2Fixture *bodyFixture = body->CreateFixture(&fixtureDef);

    NodePhysics nodePhysics;
    nodePhysics.node = node;
    nodePhysics.body = body;
    nodePhysics.bodyFixture = bodyFixture;

    nodesPhysics.push_back(nodePhysics);
}

void Box2DManager::nodeDeleted(CircuitNode *node)
{
    NodePhysics nodePhysics = findNodePhysics(node);
    if (nodePhysics == NodePhysics()) {
        return;
    }

    // Removes node body from world
    world->DestroyBody(nodePhysics.body);

    // Removes nodesPhysics from vector
    nodesPhysics.erase(std::remove(nodesPhysics.begin(), nodesPhysics.end(), nodePhysics),
                       nodesPhysics.end());
}

void Box2DManager::nodeMoved(CircuitNode *node)
{
    NodePhysics nodePhysics = findNodePhysics(node);
    if (nodePhysics.node == nullptr) {
        return;
    }

    // Sets awake, incase it is not awake from collision.
    nodePhysics.body->SetActive(true);
    nodePhysics.body->SetAwake(true);
    nodePhysics.body->SetTransform(convertPosition(node->pos()), 0.0f);
}

void Box2DManager::nodesScaled()
{
    // 200 = Node Base Size
    nodesBodySize = 200 * (*lineManager->currentZoom) / 2;

    updateGroundBody();

    for (int i = 0; i < nodesPhysics.size(); i++) {
        NodePhysics nodePhysics = nodesPhysics[i];

        nodePhysics.body->SetActive(false);
        nodePhysics.body->SetAwake(false);

        nodePhysics.body->DestroyFixture(nodePhysics.bodyFixture);

        // Creates a new body fixture for the size of node. For when the node is scaled.

        // Define another box shape for our dynamic body.
        b2PolygonShape dynamicBox;
        dynamicBox.SetAsBox(nodesBodySize, nodesBodySize);

        // Define the dynamic body fixture.
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;

        // Set the box density to be non-zero, so it will be dynamic.
        fixtureDef.density = 1000.0f;

        // Override the default friction.
        fixtureDef.friction = 0.3f;

        // Add the shape to the body.
        b2Fixture *bodyFixture = nodePhysics.body->CreateFixture(&fixtureDef);
        nodePhysics.bodyFixture = bodyFixture;

        nodeMoved(nodePhysics.node);
    }
}

Box2DManager::NodePhysics Box2DManager::findNodePhysics(CircuitNode *node)
{
    for (int i = 0; i < nodesPhysics.size(); i++) {
        if (nodesPhysics[i].node == node) {
            return nodesPhysics[i];
        }
    }
    return NodePhysics();
}

void Box2DManager::updateGroundBody()
{
    // Updates ground -- move to own function.
    groundBody->DestroyFixture(groundBodyFixture);

    // Define the ground box shape.
    b2PolygonShape groundBox;

    // The extents are the half-widths of the box.
    groundBox.SetAsBox(2000.0f, nodesBodySize);

    // Add the ground fixture to the ground body.
    groundBodyFixture = groundBody->CreateFixture(&groundBox, 0.0f);
}

void Box2DManager::startWorld()
{
    if (worldTimer->isActive()) {
        return;
    }

    physicsActive = true;

    startZoom = (*lineManager->currentZoom);

    for (int i = 0; i < nodesPhysics.size(); i++) {
        nodesPhysics[i].body->SetAwake(true);
        nodesPhysics[i].startPos = nodesPhysics[i].body->GetPosition();
    }

    worldTimer->start(8);
}

void Box2DManager::stopWorld()
{
    if (!worldTimer->isActive()) {
        return;
    }

    physicsActive = false;

    worldTimer->stop();

    *lineManager->currentZoom = startZoom;

    for (int i = 0; i < nodesPhysics.size(); i++) {
        nodesPhysics[i].body->SetTransform(nodesPhysics[i].startPos, 0.0f);
        nodesPhysics[i].body->SetAwake(false);
        nodesPhysics[i].node->drawNode(startZoom, convertPosition(nodesPhysics[i].startPos));
        nodesPhysics[i].node->move(convertPosition(nodesPhysics[i].startPos));
    }

    for (int i = 0; i < nodesPhysics.size(); i++) {
        lineManager->updateCanvas(nodesPhysics[i].node);
    }
}

void Box2DManager::updateWorld()
{
    // Instruct the world to perform a single step of simulation.
    // It is generally best to keep the time step and iterations fixed.
    world->Step(timeStep, velocityIterations, positionIterations);

    // Loops over each node widget updating its position in the scene
    for (int i = 0; i < nodesPhysics.size(); i++) {
        b2Vec2 position = nodesPhysics[i].body->GetPosition();
        float32 angle = nodesPhysics[i].body->GetAngle();

        //800 being window height QPoint nodePos(position.x, (800 - position.y));
        nodesPhysics[i].node->move(convertPosition(position));
        emit nodesPhysics[i].node->circuitSignalHandler->updateLines();
    }
}

b2Vec2 Box2DManager::convertPosition(QPoint scenePos)
{
    return b2Vec2(scenePos.x(), (800 - scenePos.y()));
}

QPoint Box2DManager::convertPosition(b2Vec2 physicsPos)
{
    return QPoint(physicsPos.x, (800 - physicsPos.y));
}
