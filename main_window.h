#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTcpSocket>
#include <QTextCodec>
#include <QFileDialog>

#include "file_management/file_management.h"
#include "network/server/server_management.h"
#include "network/server/dialogs/host_dialog.h"
#include "network/socket/dialogs/connect_dialog.h"

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
    void on_sendMessageBtn_clicked();
    void on_actionSave_triggered();
private:
    Ui::MainWindow *ui;
    ServerManagement* serverManagement;
    FileManagement* fileManagement;
    QString userNick;
};

#endif // MAINWINDOW_H
