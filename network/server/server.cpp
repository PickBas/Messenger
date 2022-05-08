#include "server.h"

Server::Server(QObject *parent) : QTcpServer{parent} {}

Server::~Server() {}

bool Server::startServer(quint16 port) {
    return listen(QHostAddress::Any, port);
}

void Server::incomingConnections(qintptr socketDesc) {
    Socket* socket = new Socket(socketDesc, this);
    socketManagement->addSocket(socket);
    connect(socket, &Socket::MsReadyRead, socketManagement, &SocketManagement::writeData);
    connect(socket, &Socket::MsStateChanged, socketManagement, &SocketManagement::removeSocket);
}
