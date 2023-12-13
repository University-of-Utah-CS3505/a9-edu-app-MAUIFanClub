#include "mainmenu.h"
#include <QGraphicsRectItem>
#include "ui_mainmenu.h"
void MyContactListener::BeginContact(b2Contact *contact)
{
    b2Body *bodyA = contact->GetFixtureA()->GetBody();
    b2Body *bodyB = contact->GetFixtureB()->GetBody();

    // Check if both bodies are dynamic
    if (bodyA->GetType() == b2_dynamicBody && bodyB->GetType() == b2_dynamicBody) {
        // Calculate the direction from A to B
        b2Vec2 direction = bodyB->GetPosition() - bodyA->GetPosition();
        direction.Normalize();

        // Apply a force to push bodies away
        float forceMagnitude = 1000.0f; // Adjust as needed
        bodyA->ApplyForceToCenter(-forceMagnitude * direction, true);
        bodyB->ApplyForceToCenter(forceMagnitude * direction, true);
    }
    // You can perform actions when a collision begins, for example:
    // - Access the fixtures involved in the collision: contact->GetFixtureA(), contact->GetFixtureB()
    // - Access the bodies involved in the collision: contact->GetFixtureA()->GetBody(), contact->GetFixtureB()->GetBody()
}

void MyContactListener::EndContact(b2Contact *contact)
{
    // You can perform actions when a collision ends
}

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    ui->mmLogicGateLvlBtns->hide();
    ui->mmCircuitExampleBtn->hide();

    // Initializes Levels
    andGateLvl = new LevelWindow(this, "and_d");
    nAndGateLvl = new LevelWindow(this, "nand_d");
    orGateLvl = new LevelWindow(this, "or_d");
    nOrGateLvl = new LevelWindow(this, "nor_d");
    xOrGateLvl = new LevelWindow(this, "xor_d");
    xnOrGateLvl = new LevelWindow(this, "xnor_d");
    notGateLvl = new LevelWindow(this, "not_d");

    allLvl = new LevelWindow(this, "all_1");
    andOrLvl = new LevelWindow(this, "andor_1");
    andOrNotLvl = new LevelWindow(this, "andornot_1");
    andOrNot2Lvl = new LevelWindow(this, "andornot_2");
    fishLvl = new LevelWindow(this, "level_fish");
    starLvl = new LevelWindow(this, "level_star");
    xnOrLvl = new LevelWindow(this, "xnor_2");
    xOrLvl = new LevelWindow(this, "xor_2");

    sandboxWindow = new LevelSandboxWindow(this);

    // Preseting a list with paths to icons to spawn them at random
    listOfIcons.push_back(":/menuIcons/menuIcons/andGateIcon.png");
    listOfIcons.push_back(":/menuIcons/menuIcons/nAndGateIcon.png");
    listOfIcons.push_back(":/menuIcons/menuIcons/nOrGateIcon.png");
    listOfIcons.push_back(":/menuIcons/menuIcons/orGateIcon.png");
    listOfIcons.push_back(":/menuIcons/menuIcons/inputPlaceholderIcon.png");
    listOfIcons.push_back(":/menuIcons/menuIcons/outputPlaceholderIcon.png");
    listOfIcons.push_back(":/menuIcons/menuIcons/notIcon.png");
    listOfIcons.push_back(":/menuIcons/menuIcons/xNORIcon.png");
    listOfIcons.push_back(":/menuIcons/menuIcons/xOrIcon.png");

    // Physics Objects Initializations
    b2Vec2 gravity(0.0f, -4.0f);
    world = new b2World(gravity);

    MyContactListener *contactListener = new MyContactListener;
    world->SetContactListener(contactListener);

    ui->graphicsView->setScene(new QGraphicsScene());

    updateTimer = new QTimer(this);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(updatePhysics()));

    updateTimer->start(16); // About 60 FPS

    spawnTimer = new QTimer(this);
    connect(spawnTimer, SIGNAL(timeout()), this, SLOT(spawnPhysicsIcons()));

    spawnTimer->start(30); // About 60 FPS
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
}

void MainMenu::updatePhysics()
{
    if (!this->isVisible()) {
        return;
    }

    world->Step(1.0f / 60.0f, 8, 3);
    for (int i = 0; i < ui->graphicsView->scene()->items().size(); i++) {
        if (mapWorldToScene(getBoxPosition(i)).y() >= height() - 200) {
            ui->graphicsView->scene()->removeItem(ui->graphicsView->scene()->items()[i]);
        } else {
            ui->graphicsView->scene()->items()[i]->setPos(mapWorldToScene(getBoxPosition(i)));
        }
    }
}

void MainMenu::spawnPhysicsIcons()
{
    if (!this->isVisible()) {
        return;
    }

    std::uniform_real_distribution<float> distribution(-30.0, 100);
    std::random_device rd;
    std::mt19937 gen(rd());

    // Generate a random float for the X coordinate to spawn the icons
    float randomX = distribution(gen);
    createPhysicsIcon(randomX, 80.0f, 2.0f, 2.0f, ui->graphicsView->scene());
}

void MainMenu::on_logicGateLvlsBtn_clicked()
{
    if (ui->mmLogicGateLvlBtns->isHidden()) {
        if (!ui->mmCircuitExampleBtn->isHidden()) {
            ui->mmCircuitExampleBtn->hide();
        }

        ui->mmLogicGateLvlBtns->show();
    } else {
        ui->mmLogicGateLvlBtns->hide();
    }
}

void MainMenu::on_exampleCircuitsBtn_clicked()
{
    if (ui->mmCircuitExampleBtn->isHidden()) {
        if (!ui->mmLogicGateLvlBtns->isHidden()) {
            ui->mmLogicGateLvlBtns->hide();
        }

        ui->mmCircuitExampleBtn->show();
    } else {
        ui->mmCircuitExampleBtn->hide();
    }
}

void MainMenu::on_sandboxLevelButton_clicked()
{
    sandboxWindow->show();
    this->close();
}

void MainMenu::on_allLvlBtn_clicked()
{
    allLvl->show();
    this->close();
}

void MainMenu::on_andOrLvlBtn_clicked()
{
    andOrLvl->show();
    this->close();
}

void MainMenu::on_andOrNotLvlBtn_clicked()
{
    andOrNotLvl->show();
    this->close();
}

void MainMenu::on_andOrNot2LvlBtn_clicked()
{
    andOrNot2Lvl->show();
    this->close();
}

void MainMenu::on_fishLvlBtn_clicked()
{
    fishLvl->show();
    this->close();
}

void MainMenu::on_starLvlBtn_clicked()
{
    starLvl->show();
    this->close();
}

void MainMenu::on_xOrLvlBtn_clicked()
{
    xOrLvl->show();
    this->close();
}

void MainMenu::on_xnOrLvlBtn_clicked()
{
    xnOrLvl->show();
    this->close();
}

void MainMenu::on_XnOrGateLvlBtn_clicked()
{
    xnOrGateLvl->show();
    QMessageBox::information(xnOrGateLvl,
                             tr("XNOR Gate"),
                             tr("").append(andGateLvl->instance->xnOrGateInfo));
    this->close();
}

void MainMenu::on_andGateLvlBtn_clicked()
{
    andGateLvl->show();
    QMessageBox::information(andGateLvl,
                             tr("AND Gate"),
                             tr("").append(andGateLvl->instance->andGateInfo));
    this->close();
}

void MainMenu::on_nAndGateLvlBtn_clicked()
{
    nAndGateLvl->show();
    QMessageBox::information(nAndGateLvl,
                             tr("NAND Gate"),
                             tr("").append(andGateLvl->instance->nAndGateInfo));
    this->close();
}

void MainMenu::on_nOrGateLvlBtn_clicked()
{
    nOrGateLvl->show();
    QMessageBox::information(nOrGateLvl,
                             tr("NOR Gate"),
                             tr("").append(andGateLvl->instance->nOrGateInfo));
    this->close();
}

void MainMenu::on_notGateLvlBtn_clicked()
{
    notGateLvl->show();
    QMessageBox::information(notGateLvl,
                             tr("NOT Gate"),
                             tr("").append(andGateLvl->instance->notGateInfo));
    this->close();
}

void MainMenu::on_orGateLvlBtn_clicked()
{
    orGateLvl->show();
    QMessageBox::information(orGateLvl,
                             tr("OR Gate"),
                             tr("").append(andGateLvl->instance->orGateInfo));
    this->close();
}

void MainMenu::on_xOrGateLvlBtn_clicked()
{
    xOrGateLvl->show();
    QMessageBox::information(xOrGateLvl,
                             tr("XOR Gate"),
                             tr("").append(andGateLvl->instance->xOrGateInfo));
    this->close();
}

void MainMenu::createPhysicsIcon(float x, float y, float width, float height, QGraphicsScene *scene)
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(width / 2, height / 2);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    b2Body *body = world->CreateBody(&bodyDef);
    body->CreateFixture(&fixtureDef);

    std::random_device rd;
    std::mt19937 gen(rd());

    // Create a uniform integer distribution between min and max (min = 0, max = size of the list - 1)
    std::uniform_int_distribution<int> distribution(0, listOfIcons.size() - 1);

    // Generate a random integer to pick an icon at random from the preset list of icons
    int randomInt = distribution(gen);

    QPixmap pixmap(listOfIcons[randomInt]);

    // Adding a pixmap with an icon to attach it to a physics body
    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);

    pixmapItem->setPos(mapWorldToScene(body->GetPosition()));
    pixmapItem->setTransformOriginPoint(pixmapItem->boundingRect().center());
    pixmapItem->setRotation(body->GetAngle() * 180.0 / b2_pi);
    pixmapItem->setScale(0.1);

    scene->addItem(pixmapItem); // Adding our item to the scene
}

b2Vec2 MainMenu::getBoxPosition(int index)
{
    b2Body *body = world->GetBodyList();
    for (int i = 0; i < index; ++i) {
        body = body->GetNext();
    }
    return body->GetPosition();
}

QPointF MainMenu::mapWorldToScene(const b2Vec2 &worldPoint) const
{
    // Map Box2D world coordinates to QGraphicsScene coordinates
    return QPointF(worldPoint.x * 10,
                   -worldPoint.y * 10); // Scale factor 10 for better visualization
}
