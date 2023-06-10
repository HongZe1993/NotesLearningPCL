QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(C:/PCL1.12.1/pcl1.12.1.pri)

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/Main/main.cpp \
    src/Main/mainwindow.cpp \
    src/PCLFuction/PCL_Function.cpp \
    src/PublicPart/IOVariableTable.cpp

HEADERS += \
    src/Main/mainwindow.h \
    src/PCLFuction/PCL_Function.h \
    src/PublicPart/IOVariableTable.h

FORMS += \
    src/Main/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
