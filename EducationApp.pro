QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    circuitelementsmenu.cpp \
    level1window.cpp \
    level2window.cpp \
    level3window.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    node_classes/andgate.cpp \
    node_classes/circuitnode.cpp \
    dragablewidget.cpp \
    node_classes/circuitsignalhandler.cpp \
    node_classes/inputnode.cpp \
    node_classes/nodeinputslot.cpp \
    node_classes/nodelineconnectionmanager.cpp \
    node_classes/nodeoutputslot.cpp \
    node_classes/orgate.cpp \
    node_classes/outputnode.cpp

HEADERS += \
    circuitelementsmenu.h \
    level1window.h \
    level2window.h \
    level3window.h \
    mainmenu.h \
    mainwindow.h \
    node_classes/andgate.h \
    node_classes/circuitnode.h \
    dragablewidget.h \
    node_classes/circuitsignalhandler.h \
    node_classes/inputnode.h \
    node_classes/nodeinputslot.h \
    node_classes/nodelineconnectionmanager.h \
    node_classes/nodeoutputslot.h \
    node_classes/orgate.h \
    node_classes/outputnode.h

FORMS += \
    circuitelementsmenu.ui \
    level1window.ui \
    level2window.ui \
    level3window.ui \
    mainmenu.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagesResources.qrc
