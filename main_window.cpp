#include "main_window.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
}

MainWindow::~MainWindow() {
    delete ui;
    delete socket;
    delete server;
}


void MainWindow::on_actionConnect_triggered() {


}


void MainWindow::on_actionHost_triggered() {
    HostDialog* dialog = new HostDialog(this);
    if (dialog->exec() == 1) {
        server = new Server(this);
        if (!server->startServer(dialog->port)) {
            QMessageBox::warning(
                        this,
                        "Error",
                        "Server error: " + server->errorString(),
                        "Close");
        }
        userNick = dialog->nick;
    }
}

