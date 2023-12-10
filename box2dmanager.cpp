#include "box2dmanager.h"

Box2DManager::Box2DManager()
{
    worldTimer = new QTimer(this);
    connect(worldTimer, &QTimer::timeout, [this]() { updateWorld(); });

    gravity = b2Vec2(0.0f, -10.0f);

    // Construct a world object, which will hold and simulate the rigid bodies.
    world = new b2World(gravity);

    // Define the ground body.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);

    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    groundBody = world->CreateBody(&groundBodyDef);

    // Define the ground box shape.
    b2PolygonShape groundBox;

    // The extents are the half-widths of the box.
    groundBox.SetAsBox(1000.0f, 110.0f);

    // Add the ground fixture to the ground body.
    groundBody->CreateFixture(&groundBox, 0.0f);
}

void Box2DManager::addNode(CircuitNode *node)
{
    // Define the dynamic body. We set its position and call the body factory.
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    b2Vec2 bodyPos = convertPosition(node->pos());
    bodyDef.position.Set(bodyPos.x, bodyPos.y);
    b2Body *body = world->CreateBody(&bodyDef);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(100.0f, 100.0f);

    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;

    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDef.density = 1.0f;

    // Override the default friction.
    fixtureDef.friction = 0.3f;

    // Add the shape to the body.
    body->CreateFixture(&fixtureDef);

    NodePhysics nodePhysics;
    nodePhysics.node = node;
    nodePhysics.body = body;

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
    nodePhysics.body->SetAwake(true);
    nodePhysics.body->SetTransform(convertPosition(node->pos()), 0.0f);
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

void Box2DManager::startWorld()
{
    if (worldTimer->isActive()) {
        return;
    }

    worldTimer->start(16);
}

void Box2DManager::stopWorld()
{
    if (!worldTimer->isActive()) {
        return;
    }

    worldTimer->stop();
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
