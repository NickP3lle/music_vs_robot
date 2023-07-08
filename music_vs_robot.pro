######################################################################
# Automatically generated by qmake (3.1) Tue Jul 4 17:53:11 2023
######################################################################

TEMPLATE = app
TARGET = music_vs_robot
INCLUDEPATH += .
QT += widgets

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_UP_TO=0x060000 # disables all APIs deprecated in Qt 6.0.0 and earlier

# Input
HEADERS += game/cash.h \
           game/define.h \
           game/entity.h \
           game/include.h \
           game/playground.h \
           game/timer.h \
           music/music_instrument.h \
           robot/robot.h \
           robot/robotwtool.h \
           robot/tool.h \
           util/dataManager.h \
           util/deque.h \
           util/independentfn.h \
           util/iterator.h \
           util/ptr.h \
           util/util.h \
           view/mainWindow.h \
           view/playgroundWidget.h \
           view/startWidget.h \
           view/observers/cashObserverInterface.h \
           view/observers/timerObserverInterface.h \
           view/observers/playgroundObserverInterface.h \
           view/playgroundComponents/cashWidget.h \
           view/playgroundComponents/timerWidget.h \
           view/playgroundComponents/instrumentButton.h \
           view/playgroundComponents/playgroundCellWidget.h \
           view/visitors/entityVisitorInterface.h \
           view/visitors/imageVisitor.h
SOURCES += main.cpp \
           game/cash.cpp \
           game/entity.cpp \
           game/playground.cpp \
           game/timer.cpp \
           music/music_instrument.cpp \
           robot/robot.cpp \
           robot/robotwtool.cpp \
           robot/tool.cpp \
           util/independentfn.cpp \
           util/dataManager.cpp \
           view/mainWindow.cpp \
           view/playgroundWidget.cpp \
           view/startWidget.cpp \
           view/playgroundComponents/cashWidget.cpp \
           view/playgroundComponents/timerWidget.cpp \
           view/playgroundComponents/instrumentButton.cpp \
           view/playgroundComponents/playgroundCellWidget.cpp \
           view/visitors/imageVisitor.cpp
RESOURCES += resources.qrc

ICON = assets/icon.icns
