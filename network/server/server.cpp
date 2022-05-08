#include "server.h"

Server::Server(QObject *parent) : QTcpServer{parent} {

}

Server::~Server() {
    for (Socket*& socket : socketList) {
        delete socket;
    }
}

bool Server::startServer(quint16 port) {
    return listen(QHostAddress::Any, port);
}

void Server::incomingConnections(qintptr socketDesc) {
    Socket* socket = new Socket(socketDesc, this);
    socketList << socket;
    connect(socket, &Socket::MsReadyRead, this, [&] (Socket *incomingSocket) {
        QTextStream incomingTextStream(incomingSocket);
        QString text = incomingTextStream.readAll();
        for (Socket* socket : socketList){
            QTextStream outcomingTextStream(socket);
            outcomingTextStream << text;
            socket->flush();
        }
    });
    connect(socket, &Socket::MsStateChanged, this, [&] (Socket *soc, int state){
        if (state == QTcpSocket::UnconnectedState) {
            socketList.removeOne(soc);
        }
    });
}
