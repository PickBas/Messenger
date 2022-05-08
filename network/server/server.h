#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include "network/socket/socket.h"
#include "network/socket/socket_management.h"

class Server : public QTcpServer {
    Q_OBJECT
    SocketManagement* socketManagement;
protected:
    void incomingConnections(qintptr socketDesc);
public:
    explicit Server(QObject *parent = nullptr);
    ~Server();
    bool startServer(quint16 port);
};

#endif // SERVER_H
