#include "socket_management.h"

SocketManagement::SocketManagement(QList<Socket*> socketList, QObject *parent)
    : QObject{parent} {
    this->socketList = socketList;
}

void SocketManagement::addSocket(Socket *socket) {
    socketList << socket;
}

void SocketManagement::removeSocket(Socket *socket, qint32 state) {
    if (state == QTcpSocket::UnconnectedState) {
        socketList.removeOne(socket);
    }
}

void SocketManagement::writeData(Socket* incomingSocket)
{
    QString text = incomingSocket->readToString();
    for (Socket* socket : socketList){
        QTextStream outcomingTextStream(socket);
        outcomingTextStream << text;
        socket->flush();
    }
}
