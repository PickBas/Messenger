#ifndef SERVERMANAGEMENT_H
#define SERVERMANAGEMENT_H

#include <QObject>
#include <QMainWindow>
#include <QMessageBox>
#include <QTcpSocket>
#include <QAbstractSocket>

#include "network/server/server.h"

class ServerManagement : public QObject {
    Q_OBJECT
    Server* server;
    QTcpSocket* socket;
    QMainWindow* mainWindow;
public:
    explicit ServerManagement(QMainWindow* mainWindow, QObject *parent = nullptr);
    ~ServerManagement();
    void hostServer(quint16 port);
    void connectToServer(QString nick, QString host, quint16 port);
};


#endif // SERVERMANAGEMENT_H
