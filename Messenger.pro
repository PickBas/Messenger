QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES +=  \
    src/QtServer.cpp \
    src/QtSocket.cpp \
    src/dialog.cpp \
    src/dialog_creating_server.cpp \
    src/info.cpp \
    src/main.cpp \
    src/widget.cpp

HEADERS += \
    include/QtServer.h \
    include/QtSocket.h \
    include/dialog.h \
    include/dialog_creating_server.h \
    include/info.h \
    include/widget.h

FORMS += \
    ui/dialog.ui \
    ui/dialog_creating_server.ui \
    ui/info.ui \
    ui/widget.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    pic.qml

RESOURCES += \
    pic/pictures.qrc
