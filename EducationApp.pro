QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    node_classes/andgate.cpp \
    node_classes/circuitnode.cpp \
    dragablewidget.cpp \
    node_classes/inputnode.cpp \
    main.cpp \
    mainwindow.cpp \
    node_classes/outputnode.cpp

HEADERS += \
    node_classes/andgate.h \
    node_classes/circuitnode.h \
    dragablewidget.h \
    node_classes/inputnode.h \
    mainwindow.h \
    node_classes/outputnode.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
