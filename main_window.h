#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTcpSocket>
#include <QTextCodec>
#include "network/server/server.h"
#include "network/server/dialogs/host_dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_actionConnect_triggered();
    void on_actionHost_triggered();
private:
    Ui::MainWindow *ui;
    QTcpSocket* socket;
    Server* server;
    QString userNick;
};

#endif // MAINWINDOW_H
