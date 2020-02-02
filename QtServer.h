#ifndef QTSERVER_H
#define QTSERVER_H


#include <QTcpServer>
#include <QList>
#include <QTextStream>
#include <QDebug>
#include <QObject>
#include "QtSocket.h"

class QtSocket;

class QtServer : public QTcpServer{
    Q_OBJECT
    QList <QtSocket *> sockets;

protected:
    void incomingConnection(qintptr handle);

public:
    QtServer(QObject *parent);
    bool start_server(qint16 port);
    ~QtServer();
};

#endif // QTSERVER_H
