#ifndef SOCKETMANAGEMENT_H
#define SOCKETMANAGEMENT_H

#include <QObject>
#include "socket.h"

class SocketManagement : public QObject {
    Q_OBJECT
    QList<Socket*> socketList;
public:
    explicit SocketManagement(QObject *parent = nullptr);
    ~SocketManagement();
    void addSocket(Socket* socket);
    void removeSocket(Socket* socket, qint32 state);
public slots:
    void writeData(Socket* incomingSocket);
};

#endif // SOCKETMANAGEMENT_H
