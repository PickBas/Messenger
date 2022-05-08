#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include "network/socket/socket.h"

class Server : public QTcpServer {
    Q_OBJECT
    QList<Socket*> socketList;
protected:
    void incomingConnections(qintptr socketDesc);
public:
    explicit Server(QObject *parent = nullptr);
    ~Server();
    bool startServer(quint16 port);
};

#endif // SERVER_H
