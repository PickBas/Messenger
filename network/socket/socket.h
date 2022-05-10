#ifndef SOCKET_H
#define SOCKET_H

#include <QObject>
#include <QTcpSocket>

class Socket : public QTcpSocket {
    Q_OBJECT
public:
    explicit Socket(qintptr socketDesc, QObject *parent = nullptr);
    QString readToString();
signals:
    void MsReadyRead(Socket *);
    void MsStateChanged(Socket *, int);
};

#endif // SOCKET_H
