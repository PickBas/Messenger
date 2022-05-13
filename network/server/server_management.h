#ifndef SERVERMANAGEMENT_H
#define SERVERMANAGEMENT_H

#include <QObject>
#include <QMainWindow>
#include <QTextEdit>
#include <QMessageBox>
#include <QTcpSocket>
#include <QAbstractSocket>

#include "network/server/server.h"

class ServerManagement : public QObject {
    Q_OBJECT
    QString nick;
    Server* server;
    QTcpSocket* socket;
    QMainWindow* mainWindow;
    QTextEdit* messageDisplayBox;
public:
    explicit ServerManagement(QMainWindow* mainWindow,
                              QTextEdit* messageDisplayBox,
                              QObject *parent = nullptr);
    ~ServerManagement();
    void hostServer(QString nick, quint16 port);
    void connectToServer(QString nick, QString host, quint16 port);
private slots:
    void readIncomingData();
};


#endif // SERVERMANAGEMENT_H
