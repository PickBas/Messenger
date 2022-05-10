QT += core gui network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

CONFIG += c++17

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
    main.cpp \
    main_window.cpp \
    network/server/dialogs/host_dialog.cpp \
    network/server/server.cpp \
    network/socket/socket.cpp \
    network/socket/socket_management.cpp

HEADERS += \
    main_window.h \
    network/server/dialogs/host_dialog.h \
    network/server/server.h \
    network/socket/socket.h \
    network/socket/socket_management.h

FORMS += \
    main_window.ui \
    network/server/dialogs/host_dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
