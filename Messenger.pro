QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += $$files(src/*.cpp)

HEADERS += $$files(headers/*.h)

FORMS += $$files(ui/*.ui)

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    pic.qml

RESOURCES += \
    pic/pictures.qrc
