#include "main_window.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    serverManagement = new ServerManagement(this);
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
}

MainWindow::~MainWindow() {
    delete ui;
    delete serverManagement;
}

void MainWindow::on_actionConnect_triggered() {
    ConnectDialog* dialog = new ConnectDialog(this);
    if (dialog->exec() == 1) {
        userNick = dialog->nick;
        serverManagement->connectToServer(dialog->nick, dialog->host, dialog->port);
    }
    delete dialog;
}

void MainWindow::on_actionHost_triggered() {
    HostDialog* dialog = new HostDialog(this);
    if (dialog->exec() == 1) {
        userNick = dialog->nick;
        serverManagement->hostServer(dialog->port);
    }
    delete dialog;
}

