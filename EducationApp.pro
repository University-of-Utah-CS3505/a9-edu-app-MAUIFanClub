QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Box2D/Collision/Shapes/b2ChainShape.cpp \
    Box2D/Collision/Shapes/b2CircleShape.cpp \
    Box2D/Collision/Shapes/b2EdgeShape.cpp \
    Box2D/Collision/Shapes/b2PolygonShape.cpp \
    Box2D/Collision/b2BroadPhase.cpp \
    Box2D/Collision/b2CollideCircle.cpp \
    Box2D/Collision/b2CollideEdge.cpp \
    Box2D/Collision/b2CollidePolygon.cpp \
    Box2D/Collision/b2Collision.cpp \
    Box2D/Collision/b2Distance.cpp \
    Box2D/Collision/b2DynamicTree.cpp \
    Box2D/Collision/b2TimeOfImpact.cpp \
    Box2D/Common/b2BlockAllocator.cpp \
    Box2D/Common/b2Draw.cpp \
    Box2D/Common/b2Math.cpp \
    Box2D/Common/b2Settings.cpp \
    Box2D/Common/b2StackAllocator.cpp \
    Box2D/Common/b2Timer.cpp \
    Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp \
    Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp \
    Box2D/Dynamics/Contacts/b2CircleContact.cpp \
    Box2D/Dynamics/Contacts/b2Contact.cpp \
    Box2D/Dynamics/Contacts/b2ContactSolver.cpp \
    Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp \
    Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp \
    Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp \
    Box2D/Dynamics/Contacts/b2PolygonContact.cpp \
    Box2D/Dynamics/Joints/b2DistanceJoint.cpp \
    Box2D/Dynamics/Joints/b2FrictionJoint.cpp \
    Box2D/Dynamics/Joints/b2GearJoint.cpp \
    Box2D/Dynamics/Joints/b2Joint.cpp \
    Box2D/Dynamics/Joints/b2MotorJoint.cpp \
    Box2D/Dynamics/Joints/b2MouseJoint.cpp \
    Box2D/Dynamics/Joints/b2PrismaticJoint.cpp \
    Box2D/Dynamics/Joints/b2PulleyJoint.cpp \
    Box2D/Dynamics/Joints/b2RevoluteJoint.cpp \
    Box2D/Dynamics/Joints/b2RopeJoint.cpp \
    Box2D/Dynamics/Joints/b2WeldJoint.cpp \
    Box2D/Dynamics/Joints/b2WheelJoint.cpp \
    Box2D/Dynamics/b2Body.cpp \
    Box2D/Dynamics/b2ContactManager.cpp \
    Box2D/Dynamics/b2Fixture.cpp \
    Box2D/Dynamics/b2Island.cpp \
    Box2D/Dynamics/b2World.cpp \
    Box2D/Dynamics/b2WorldCallbacks.cpp \
    Box2D/Rope/b2Rope.cpp \
    circuitelementsmenu.cpp \
    circuitmanager.cpp \
    levelsandboxwindow.cpp \
    levelwindow.cpp \
    main.cpp \
    mainmenu.cpp \
    node_classes/andgate.cpp \
    node_classes/circuitnode.cpp \
    dragablewidget.cpp \
    node_classes/circuitsignalhandler.cpp \
    node_classes/inputnode.cpp \
    node_classes/nandgate.cpp \
    node_classes/nodeinputslot.cpp \
    node_classes/nodelineconnectionmanager.cpp \
    node_classes/nodeoutputslot.cpp \
    node_classes/norgate.cpp \
    node_classes/notgate.cpp \
    node_classes/orgate.cpp \
    node_classes/outputnode.cpp \
    zoommanager.cpp \
    zoomwidget.cpp \
    node_classes/xnorgate.cpp \
    node_classes/xorgate.cpp

HEADERS += \
    Box2D/Box2D.h \
    Box2D/Collision/Shapes/b2ChainShape.h \
    Box2D/Collision/Shapes/b2CircleShape.h \
    Box2D/Collision/Shapes/b2EdgeShape.h \
    Box2D/Collision/Shapes/b2PolygonShape.h \
    Box2D/Collision/Shapes/b2Shape.h \
    Box2D/Collision/b2BroadPhase.h \
    Box2D/Collision/b2Collision.h \
    Box2D/Collision/b2Distance.h \
    Box2D/Collision/b2DynamicTree.h \
    Box2D/Collision/b2TimeOfImpact.h \
    Box2D/Common/b2BlockAllocator.h \
    Box2D/Common/b2Draw.h \
    Box2D/Common/b2GrowableStack.h \
    Box2D/Common/b2Math.h \
    Box2D/Common/b2Settings.h \
    Box2D/Common/b2StackAllocator.h \
    Box2D/Common/b2Timer.h \
    Box2D/Dynamics/Contacts/b2ChainAndCircleContact.h \
    Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.h \
    Box2D/Dynamics/Contacts/b2CircleContact.h \
    Box2D/Dynamics/Contacts/b2Contact.h \
    Box2D/Dynamics/Contacts/b2ContactSolver.h \
    Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.h \
    Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.h \
    Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h \
    Box2D/Dynamics/Contacts/b2PolygonContact.h \
    Box2D/Dynamics/Joints/b2DistanceJoint.h \
    Box2D/Dynamics/Joints/b2FrictionJoint.h \
    Box2D/Dynamics/Joints/b2GearJoint.h \
    Box2D/Dynamics/Joints/b2Joint.h \
    Box2D/Dynamics/Joints/b2MotorJoint.h \
    Box2D/Dynamics/Joints/b2MouseJoint.h \
    Box2D/Dynamics/Joints/b2PrismaticJoint.h \
    Box2D/Dynamics/Joints/b2PulleyJoint.h \
    Box2D/Dynamics/Joints/b2RevoluteJoint.h \
    Box2D/Dynamics/Joints/b2RopeJoint.h \
    Box2D/Dynamics/Joints/b2WeldJoint.h \
    Box2D/Dynamics/Joints/b2WheelJoint.h \
    Box2D/Dynamics/b2Body.h \
    Box2D/Dynamics/b2ContactManager.h \
    Box2D/Dynamics/b2Fixture.h \
    Box2D/Dynamics/b2Island.h \
    Box2D/Dynamics/b2TimeStep.h \
    Box2D/Dynamics/b2World.h \
    Box2D/Dynamics/b2WorldCallbacks.h \
    Box2D/Rope/b2Rope.h \
    circuitelementsmenu.h \
    circuitmanager.h \
    levelsandboxwindow.h \
    levelwindow.h \
    mainmenu.h \
    node_classes/andgate.h \
    node_classes/circuitnode.h \
    dragablewidget.h \
    node_classes/circuitsignalhandler.h \
    node_classes/inputnode.h \
    node_classes/nandgate.h \
    node_classes/nodeinputslot.h \
    node_classes/nodelineconnectionmanager.h \
    node_classes/nodeoutputslot.h \
    node_classes/norgate.h \
    node_classes/notgate.h \
    node_classes/orgate.h \
    node_classes/outputnode.h \
    zoommanager.h \
    zoomwidget.h \
    node_classes/xnorgate.h \
    node_classes/xorgate.h

FORMS += \
    circuitelementsmenu.ui \
    levelsandboxwindow.ui \
    levelwindow.ui \
    mainmenu.ui \
    zoommanager.ui \
    zoomwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagesResources.qrc

DISTFILES += \
    Box2D/Box2DConfig.cmake \
    Box2D/CMakeLists.txt
