#include "socket.h"

Socket::Socket(qintptr socketDesc, QObject *parent)
    : QTcpSocket(parent) {
    setSocketDescriptor(socketDesc);
    connect(this, &Socket::readyRead, [&]() {
        emit MsReadyRead(this);
    });
    connect(this, &Socket::stateChanged, [&](int state) {
        emit MsStateChanged(this, state);
    });
}

QString Socket::readToString() {
    QTextStream incomingTextStream(this);
    return incomingTextStream.readAll();
}
